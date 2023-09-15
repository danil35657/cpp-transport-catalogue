#include "transport_router.h"

namespace transport_router {

    using namespace std::literals;

    bool RouteWeight::operator<(const RouteWeight& right) const {
        return time < right.time;
    }

    bool RouteWeight::operator>(const RouteWeight& right) const {
        return time > right.time;
    }

    RouteWeight operator+(const RouteWeight& left, const RouteWeight& right) {
        RouteWeight temp{ ""sv, 0, left.time + right.time, true };
        return temp;
    }

    void TransportRouter::SetRouter(transport_catalogue::TransportCatalogue& catalogue, double bus_wait_time, double bus_velocity) {

        size_t index = 0;

        const auto stops = catalogue.GetAllStops();

        graph::DirectedWeightedGraph<transport_router::RouteWeight> transport_graph(stops.size() * 2);

        for (const auto& stop : stops) {
            stops_id_[stop.first] = index;
            transport_graph.AddEdge({ index, index + 1, { stop.first, 0, bus_wait_time, false } });
            index += 2;
        }

        size_t stops_count = 0;

        for (const auto& bus : catalogue.GetAllBuses()) {
            const auto& bus_stops = bus.second->stops;
            stops_count = bus.second->is_roundtrip == false ? bus_stops.size() / 2 : bus_stops.size() - 1;
            for (size_t i = 0; i < stops_count; i++) {
                double time = 0.0;
                for (size_t j = i + 1; j <= stops_count; j++) {
                    time += ((catalogue.GetDistance({ bus_stops[j - 1], bus_stops[j] }) * 0.001 / bus_velocity) * 60);
                    transport_graph.AddEdge({ stops_id_[bus_stops[i]->name] + 1, stops_id_[bus_stops[j]->name], { bus.first, j - i, time, true} });
                }
            }
            if (bus.second->is_roundtrip == false) {
                for (size_t i = stops_count; i < bus_stops.size() - 1; i++) {
                    double time = 0.0;
                    for (size_t j = i + 1; j < bus_stops.size(); j++) {
                        time += ((catalogue.GetDistance({ bus_stops[j - 1], bus_stops[j] }) * 0.001 / bus_velocity) * 60);
                        transport_graph.AddEdge({ stops_id_[bus_stops[i]->name] + 1, stops_id_[bus_stops[j]->name], { bus.first, j - i, time, true} });
                    }
                }
            }
        }
        graph_ = std::move(transport_graph);
        router_ = std::make_unique<graph::Router<RouteWeight>>(graph_);
    }

    std::optional<graph::Router<RouteWeight>::RouteInfo> TransportRouter::GetRoute(const std::string_view from, const std::string_view to) {
        return router_->BuildRoute(stops_id_.at(from), stops_id_.at(to));
    }

    const RouteWeight& TransportRouter::GetStep(size_t id) {
        return graph_.GetEdge(id).weight;
    }

}
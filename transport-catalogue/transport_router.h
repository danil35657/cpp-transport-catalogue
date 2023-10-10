#pragma once

#include <string_view>
#include <memory>
#include <optional>

#include "transport_catalogue.h"
#include "router.h"
#include "graph.h"

namespace transport_router {

    struct RouteWeight {
        std::string_view name;
        size_t span_count = 0;
        double time = 0.0;
        bool is_bus = true;

        bool operator<(const RouteWeight& right) const;

        bool operator>(const RouteWeight& right) const;
    };

    RouteWeight operator+(const RouteWeight& left, const RouteWeight& right);

    class TransportRouter {

    public:

        TransportRouter() = default;

        void SetRouter(transport_catalogue::TransportCatalogue& catalogue, double bus_wait_time, double bus_velocity);

        std::optional<graph::Router<RouteWeight>::RouteInfo> GetRoute(const std::string_view from, const std::string_view to);

        const RouteWeight& GetStep(size_t id);
        
        graph::DirectedWeightedGraph<RouteWeight>& GetGraph();
        
        void SetGraph(transport_catalogue::TransportCatalogue& catalogue, graph::DirectedWeightedGraph<RouteWeight>&& graph);

    private:
        std::unique_ptr<graph::Router<RouteWeight>> router_;
        graph::DirectedWeightedGraph<RouteWeight> graph_;
        std::unordered_map<std::string_view, size_t> stops_id_;
    };

}

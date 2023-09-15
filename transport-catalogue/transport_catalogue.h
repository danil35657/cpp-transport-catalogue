#pragma once

#include <string>
#include <vector>
#include <string_view>
#include <deque>
#include <unordered_map>
#include <set>
#include <tuple>
#include <optional>
#include <iostream>
#include <utility>
#include <map>
#include <memory>

#include "geo.h"
#include "router.h"
#include "transport_router.h"

namespace transport_catalogue {

class TransportCatalogue {
    
public:

    struct Stop {
        std::string name;
        double x;
        double y;
    };
    
    struct PairStopPointHasher {
        std::hash<const void*> hasher;
        size_t operator () (const std::pair<Stop*, Stop*>& pair) const {
            size_t h1 = hasher(pair.first);
            size_t h2 = hasher(pair.second);
            return h1*37 + h2;
        }
    };
    
    struct Bus {
        std::string name;
        std::vector<Stop*> stops;
        bool is_roundtrip;
        double route_lenght = 0.0;
        double curvature = 0.0;
        int stops_count = 0.0;
        int unique_stops_count = 0.0;
    };

    void AddStop(const std::string& stop_name, const double x, const double y);
        
    Stop* FindStop(std::string_view stop_name);
    
    void AddBus(const std::string& bus_name, const std::vector<std::string>& bus_stops, const bool is_roundtrip);
    
    Bus* FindBus(std::string_view bus_name);
    
    std::tuple<int, int, double, double> GetBusInfo(std::string_view bus_name);
    
    std::set<std::string_view> GetStopInfo(std::string_view stop_name);
    
    void AddDistance(const std::pair<std::pair<std::string, std::string>, int>& distance);
    
    double GetDistance(const std::pair<Stop*, Stop*>& stops);
    
    std::map<std::string_view, Stop*> GetAllStops();
    
    std::map<std::string_view, Bus*> GetAllBuses();

    void SetRouter(graph::DirectedWeightedGraph<RouteWeight>&& graph_, std::unordered_map<std::string_view, size_t>&& stops_id);

    std::optional<graph::Router<RouteWeight>::RouteInfo> GetRoute(const std::string_view from, const std::string_view to);

    const RouteWeight& GetStep(size_t id);

private:
    std::deque<Stop> stops_;
    std::unordered_map<std::string_view, Stop*> stopname_to_stop_;
    std::deque<Bus> buses_;
    std::unordered_map<std::string_view, Bus*> busname_to_bus_;
    std::unordered_map<Stop*, std::set<std::string_view>> busnames_to_stop_;
    std::unordered_map<std::pair<Stop*, Stop*>, double, PairStopPointHasher> distances_;
    std::unique_ptr<graph::Router<RouteWeight>> router_;
    graph::DirectedWeightedGraph<RouteWeight> graph_;
    std::unordered_map<std::string_view, size_t> stops_id_;
};

}
#include "transport_catalogue.h"

namespace transport_catalogue {

void TransportCatalogue::AddStop(const std::string& stop_name, const double x, const double y) {
	Stop stop{stop_name, x, y};
	auto it = stops_.emplace(stops_.end(), std::move(stop));
	stopname_to_stop_.emplace(it->name, &*it);
}
	
TransportCatalogue::Stop* TransportCatalogue::FindStop(std::string_view stop_name) {
	return stopname_to_stop_.count(stop_name) ? stopname_to_stop_.at(stop_name) : nullptr;
}

void TransportCatalogue::AddBus(const std::string& bus_name, const std::vector<std::string>& bus_stops) {
	Bus bus{bus_name, {}};
	auto it = buses_.emplace(buses_.end(), std::move(bus));
	for (const std::string& stop : bus_stops) {
		auto stop_point = stopname_to_stop_[stop];
		it->stops.push_back(stop_point);
		busnames_to_stop_[stop_point].insert(it->name);
	}
	busname_to_bus_.emplace(it->name, &*it);
}

TransportCatalogue::Bus* TransportCatalogue::FindBus(std::string_view bus_name) {
	return busname_to_bus_.at(bus_name);
}

std::tuple<int, int, double> TransportCatalogue::GetBusInfo(std::string_view bus_name) {
	if (!busname_to_bus_.count(bus_name)) {
		return std::tuple(0, 0, 0.0);
	}
	const auto& bus_stops = busname_to_bus_[bus_name]->stops;
	int stops_count = bus_stops.size();
	std::set<Stop*> unique(bus_stops.begin(), bus_stops.end());
	int unique_stops_count = unique.size();
	double route_lenght = 0.0;
	for (int i = 0; i < stops_count - 1; ++i) {
		route_lenght += ComputeDistance({bus_stops[i]->x, bus_stops[i]->y}, {bus_stops[i+1]->x, bus_stops[i+1]->y});
	};
	return std::tuple(stops_count, unique_stops_count, route_lenght);
}

std::set<std::string_view> TransportCatalogue::GetStopInfo(std::string_view stop_name){
	auto stop_point = FindStop(stop_name);
	if (!busnames_to_stop_.count(stop_point)) {
		return {};
	}
	return busnames_to_stop_.at(stop_point);
}
	
}

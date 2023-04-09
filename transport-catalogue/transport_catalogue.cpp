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
	const auto& stops_points = it->stops;
	std::set<Stop*> unique(stops_points.begin(), stops_points.end());
	it->stops_count = stops_points.size();
	it->unique_stops_count = unique.size();
	double geographical_distance = 0.0;
	for (int i = 0; i < stops_points.size() - 1; ++i) {
		geographical_distance += geo::ComputeDistance({stops_points[i]->x, stops_points[i]->y}, {stops_points[i+1]->x, stops_points[i+1]->y});
		it->route_lenght += GetDistance(std::make_pair(stops_points[i], stops_points[i+1]));
	};
	it->curvature = it->route_lenght/geographical_distance;
}

TransportCatalogue::Bus* TransportCatalogue::FindBus(std::string_view bus_name) {
	return busname_to_bus_.count(bus_name) ? busname_to_bus_.at(bus_name) : nullptr;
}

std::tuple<int, int, double, double> TransportCatalogue::GetBusInfo(std::string_view bus_name) {
	const auto it = busname_to_bus_.find(bus_name);
	return it == busname_to_bus_.end() ? std::tuple(0, 0, 0.0, 0.0) : std::tuple(it->second->stops_count, it->second->unique_stops_count, it->second->route_lenght, it->second->curvature);
}

std::set<std::string_view> TransportCatalogue::GetStopInfo(std::string_view stop_name){
	auto stop_point = FindStop(stop_name);
	if (!busnames_to_stop_.count(stop_point)) {
		return {};
	}
	return busnames_to_stop_.at(stop_point);
}

void TransportCatalogue::AddDistance(const std::pair<std::pair<std::string, std::string>, int>& distance) {
	distances_.emplace(std::make_pair(stopname_to_stop_[distance.first.first], stopname_to_stop_[distance.first.second]), distance.second);
}

double TransportCatalogue::GetDistance(const std::pair<Stop*, Stop*>& stops){
	return distances_.count(stops) ? distances_.at(stops) : distances_.at(std::make_pair(stops.second, stops.first));
}


	
}



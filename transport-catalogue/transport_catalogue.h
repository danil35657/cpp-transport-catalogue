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

#include "geo.h"

namespace transport_catalogue {

class TransportCatalogue {
	
public:

	struct Stop {
		std::string name;
		double x;
		double y;
	};
	
	struct Bus {
		std::string name;
		std::vector<Stop*> stops;
	};

	void AddStop(const std::string& stop_name, const double x, const double y);
		
	Stop* FindStop(std::string_view stop_name);
	
	void AddBus(const std::string& bus_name, const std::vector<std::string>& bus_stops);
	
	Bus* FindBus(std::string_view bus_name);
	
	std::tuple<int, int, double> GetBusInfo(std::string_view bus_name);
	
	std::set<std::string_view> GetStopInfo(std::string_view stop_name);
	

private:
	std::deque<Stop> stops_;
	std::unordered_map<std::string_view, Stop*> stopname_to_stop_;
	std::deque<Bus> buses_;
	std::unordered_map<std::string_view, Bus*> busname_to_bus_;
	std::unordered_map<Stop*, std::set<std::string_view>> busnames_to_stop_;
	std::unordered_map<std::pair<Stop*, Stop*>, double> distances_;
};

}
#include "input_reader.h"

namespace input_reader {

void ReadStop(transport_catalogue::TransportCatalogue& catalogue, std::string& stop, std::deque<std::pair<std::pair<std::string, std::string>, int>>& distances) {
	if (stop.back() == '\r') {
		stop.resize(stop.size() - 1);
	}
	size_t name_begin = stop.find_first_not_of(' ', 4);
	size_t name_end = stop.find(':');
	size_t latitude_begin = stop.find_first_not_of(' ', name_end + 1);
	size_t latitude_end = stop.find(',', latitude_begin);
	size_t longitude_begin = stop.find_first_not_of(' ', latitude_end + 1);
	size_t longitude_end = stop.find(',', longitude_begin);
	longitude_end = (longitude_end == stop.npos ? stop.size() : longitude_end); 
	std::string name = stop.substr(name_begin, name_end - name_begin);
	std::stringstream ss;
	ss << stop.substr(latitude_begin, latitude_end - latitude_begin) << " " << stop.substr(longitude_begin, longitude_end - longitude_begin);
	double latitude, longitude;
	ss >> latitude >> longitude;
	if (longitude_end == stop.size()) {
		catalogue.AddStop(name, latitude, longitude);
		return;
	}
	size_t stop_begin, stop_end, distance_begin, distance_end;
	stop_end = longitude_end;
	while (stop_end != stop.size()) {
		distance_begin = stop.find_first_not_of(' ', stop_end + 1);
		distance_end = stop.find('m', distance_begin);
		stop_begin = stop.find_first_not_of(' ', stop.find("to", distance_end) + 2);
		stop_end = stop.find(',', stop_begin);
		stop_end = (stop_end == stop.npos ? stop.size() : stop_end);
		distances.emplace(distances.end(), std::make_pair(std::make_pair(name, stop.substr(stop_begin, stop_end - stop_begin)), stoi(stop.substr(distance_begin, distance_end - distance_begin))));
	}
	catalogue.AddStop(name, latitude, longitude);
}

void ReadBus(transport_catalogue::TransportCatalogue& catalogue, std::string& bus) {
	if (bus.back() == '\r') {
		bus.resize(bus.size() - 1);
	}
	size_t from = bus.find(' ') + 1;
	size_t to = bus.find(':');
	std::string name = bus.substr(from, to - from);
	std::vector<std::string> stops;
	char c = bus.find('>') == bus.npos ? '-' : '>';
	while (to != bus.npos) {
		from = to;
		to = bus.find(c, from + 1);
		stops.push_back(bus.substr(bus.find_first_not_of(' ', from + 1), bus.find_last_not_of(' ', to - 1) - from - 1));
	}
	if (c == '-') {
		for (int i = stops.size() - 2; i >= 0; --i) {
			stops.push_back(stops[i]);
		}
	}
	catalogue.AddBus(name, stops);
}

void ReadInput(transport_catalogue::TransportCatalogue& catalogue) {
	int queries_count;;
	std::cin >> queries_count;
	std::string query;
	std::vector<std::string> buses;
	std::deque<std::pair<std::pair<std::string, std::string>, int>> distances;
	std::getline(std::cin, query); // очистить строку
	for (int i = 0; i < queries_count; ++i) {
		std::getline(std::cin, query);
		query[0] == 'S' ? ReadStop(catalogue, query, distances) : buses.push_back(std::move(query));
	};
	for (int i = 0; i < buses.size(); ++i) {
		ReadBus(catalogue, buses[i]);
	};
	for (const auto& distance : distances) {
		catalogue.AddDistance(distance);
	};
}

}
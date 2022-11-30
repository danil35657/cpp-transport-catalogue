#include "input_reader.h"

void ReadStop(transport_catalogue::TransportCatalogue& catalogue, const std::string& stop) {
	size_t one = stop.find(" ");
	size_t two = stop.find(":");
	size_t three = stop.find(",");
	std::string name = stop.substr(one + 1, two - one - 1);
	std::stringstream ss;
	double latitude, longitude;
	ss << stop.substr(two + 2, three - two - 2) << " " << stop.substr(three + 2, stop.size() - three - 2);
	ss >> latitude >> longitude;
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
	std::getline(std::cin, query); // очистить строку
	for (int i = 0; i < queries_count; ++i) {
		std::getline(std::cin, query);
		query[0] == 'S' ? ReadStop(catalogue, query) : buses.push_back(std::move(query));
	};
	for (int i = 0; i < buses.size(); ++i) {
		ReadBus(catalogue, buses[i]);
	};
}
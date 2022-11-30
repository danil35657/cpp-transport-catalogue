#include "stat_reader.h"

void ReadStat(transport_catalogue::TransportCatalogue& catalogue) {
	int queries_count;;
	std::cin >> queries_count;
	std::string query;
	std::vector<std::string> queries;
	std::getline(std::cin, query); // очистить строку
	for (int i = 0; i < queries_count; ++i) {
		std::getline(std::cin, query);
		queries.push_back(query);
	}
	for (const std::string& s : queries) {
		size_t name_length = (s.back() == '\r' ? s.find_last_not_of(' ') - 4 : s.find_last_not_of(' ') - 3);
		std::string name = s.substr(4, name_length);
		auto info = catalogue.GetBusInfo(name);
		if (!std::get<0>(info)) {
			std::cout << "Bus "s << name << ": " << "not found"s << std::endl;
			continue;
		}
		std::cout << "Bus "s << name << ": " << std::get<0>(info) << " stops on route, "s << std::get<1>(info) << " unique stops, "s << std::get<2>(info) << " route length"s << std::endl;
	}
}
#include "stat_reader.h"

namespace stat_reader {

void GetStop(transport_catalogue::TransportCatalogue& catalogue, const std::string& s, std::ostream& out) {
	size_t name_length = (s.back() == '\r' ? s.find_last_not_of(' ') - 5 : s.find_last_not_of(' ') - 4);
	std::string name = s.substr(5, name_length);
	if (!catalogue.FindStop(name)) {
		out << "Stop "s << name << ": " << "not found"s << std::endl;
		return;
	}
	auto info = catalogue.GetStopInfo(name);
	if (info.size() == 0) {
		out << "Stop "s << name << ": " << "no buses"s << std::endl;
		return;
	}
	out << "Stop "s << name << ": buses"s;
	for (auto a : info) {
		out << " "s << a;
	}
	out << std::endl;
}

void GetBus(transport_catalogue::TransportCatalogue& catalogue, const std::string& s, std::ostream& out) {
	size_t name_length = (s.back() == '\r' ? s.find_last_not_of(' ') - 4 : s.find_last_not_of(' ') - 3);
	std::string name = s.substr(4, name_length);
	auto info = catalogue.GetBusInfo(name);
	if (!std::get<0>(info)) {
		out << "Bus "s << name << ": " << "not found"s << std::endl;
		return;
	}
	out << "Bus "s << name << ": " << std::get<0>(info) << " stops on route, "s << std::get<1>(info) << " unique stops, "s << std::get<2>(info) << " route length, "s << std::get<3>(info) << " curvature"s << std::endl;
}

void ReadStat(transport_catalogue::TransportCatalogue& catalogue, std::istream& in) {
	int queries_count;
	in >> queries_count;
	std::string query;
	std::vector<std::string> queries;
	std::getline(in, query); // очистить строку
	for (int i = 0; i < queries_count; ++i) {
		std::getline(in, query);
		queries.push_back(query);
	}
	for (const std::string& s : queries) {
		s[0] == 'S' ? GetStop(catalogue, s, std::cout) : GetBus(catalogue, s, std::cout);
	}
}

}




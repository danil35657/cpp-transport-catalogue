#include "json_reader.h"

namespace json_reader {
	
using namespace json;

void GetStop(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out) {
	std::string name = dic.at("name"s).AsString();
	if (!catalogue.FindStop(name)) {
		Print(Document{Node{Dict{{"request_id"s, dic.at("id"s).AsInt()}, {"error_message"s, "not found"s}}}}, out);
		return;
	}
	Array buses;
	for (const auto a : catalogue.GetStopInfo(name)) {
		buses.push_back(Node{std::string{a}});
	}
	Print(Document{Node{Dict{{"request_id"s, dic.at("id"s).AsInt()}, {"buses"s, buses}}}}, out);
}

void GetBus(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out) {
	std::string name = dic.at("name"s).AsString();
	if (!catalogue.FindBus(name)) {
		Print(Document{Node{Dict{{"request_id"s, dic.at("id"s).AsInt()}, {"error_message"s, "not found"s}}}}, out);
		return;
	}
	auto info = catalogue.GetBusInfo(name);
	Print(Document{Node{Dict{{"curvature"s, std::get<3>(info)}, {"request_id"s, dic.at("id"s).AsInt()}, {"route_length"s, std::get<2>(info)}, {"stop_count"s, std::get<0>(info)}, {"unique_stop_count"s, std::get<1>(info)}}}}, out);
}

void ReadStat(transport_catalogue::TransportCatalogue& catalogue, const Array& stat) {
	std::cout << '[';
	if (stat.size() > 0) {
		std::cout << std::endl;
		const Dict& dic = stat[0].AsMap();
		dic.at("type"s).AsString() == "Stop"s ? GetStop(catalogue, dic, std::cout) : GetBus(catalogue, dic, std::cout);
	}
	if (stat.size() > 1) {
		for (int i = 1; i < stat.size(); ++i) {
			std::cout << ',' << std::endl;
			const Dict& dic = stat[i].AsMap();
			dic.at("type"s).AsString() == "Stop"s ? GetStop(catalogue, dic, std::cout) : GetBus(catalogue, dic, std::cout);
		}
		std::cout << std::endl;
	}
	
	std::cout << ']' << std::endl;
}

void ReadBase(transport_catalogue::TransportCatalogue& catalogue, const Array& base) {
	std::deque<std::pair<std::pair<std::string, std::string>, int>> distances;
	for (const auto& a : base) {
		const Dict& dic = a.AsMap();
		if (dic.at("type"s).AsString() == "Stop"s) {
			catalogue.AddStop(dic.at("name"s).AsString(), dic.at("latitude"s).AsDouble(), dic.at("longitude"s).AsDouble());
			for (const auto& b : dic.at("road_distances"s).AsMap()) {
				distances.emplace(distances.end(), std::make_pair(std::make_pair(dic.at("name"s).AsString(), b.first), b.second.AsInt()));
			}
		}
	}
	for (const auto& distance : distances) {
		catalogue.AddDistance(distance);
	}
	for (const auto& a : base) {
		const Dict& dic = a.AsMap();
		if (dic.at("type"s).AsString() == "Bus"s) {
			std::vector<std::string> stops;
			for (const auto& b : dic.at("stops"s).AsArray()) {
				stops.push_back(b.AsString());
			}
			if (!dic.at("is_roundtrip"s).AsBool()) {
				for (int i = stops.size() - 2; i >= 0; --i) {
					stops.push_back(stops[i]);
				}
			}
			catalogue.AddBus(dic.at("name"s).AsString(), std::move(stops));
		}
	}
}
	
void ReadInput(transport_catalogue::TransportCatalogue& catalogue, std::istream& in) {
	const auto input = Load(in).GetRoot().AsMap();
	ReadBase(catalogue, input.at("base_requests"s).AsArray());
	ReadStat(catalogue, input.at("stat_requests"s).AsArray());
}

}
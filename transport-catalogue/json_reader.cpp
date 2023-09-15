#include "json_reader.h"


namespace json_reader {
    
using namespace json;

void JsonReader::PrintStop(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out) {
    std::string name = dic.at("name"s).AsString();
    if (!catalogue.FindStop(name)) {
        Print(Document{Builder{}.StartDict().Key("request_id"s).Value(dic.at("id"s).AsInt()).Key("error_message"s).Value("not found"s).EndDict().Build()}, out);
        return;
    }
    Array buses;
    for (const auto a : catalogue.GetStopInfo(name)) {
        buses.push_back(Node{std::string{a}});
    }
    Print(Document{Builder{}.StartDict().Key("request_id"s).Value(dic.at("id"s).AsInt()).Key("buses"s).Value(buses).EndDict().Build()}, out);
}

void JsonReader::PrintBus(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out) {
    std::string name = dic.at("name"s).AsString();
    if (!catalogue.FindBus(name)) {
        Print(Document{Builder{}.StartDict().Key("request_id"s).Value(dic.at("id"s).AsInt()).Key("error_message"s).Value("not found"s).EndDict().Build()}, out);
        return;
    }
    auto info = catalogue.GetBusInfo(name);
    Print(Document{Builder{}.StartDict().Key("curvature"s).Value(std::get<3>(info)).Key("request_id"s).Value(dic.at("id"s).AsInt()).Key("route_length"s).Value(std::get<2>(info)).Key("stop_count"s).Value(std::get<0>(info)).Key("unique_stop_count"s).Value(std::get<1>(info)).EndDict().Build()}, out);
}

void JsonReader::PrintMap(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, const Dict& dic, std::ostream& out) {
    Print(Document{Builder{}.StartDict().Key("map"s).Value(renderer.GetMap(catalogue)).Key("request_id"s).Value(dic.at("id"s).AsInt()).EndDict().Build()}, out);
}

void JsonReader::PrintRoute(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out) {
    
    auto route = catalogue.GetRoute(dic.at("from"s).AsString(), dic.at("to"s).AsString());
    
    if (route == std::nullopt) {
        Print(Document{ Builder{}.StartDict().Key("request_id"s).Value(dic.at("id"s).AsInt()).Key("error_message"s).Value("not found"s).EndDict().Build() }, out);
        return;
    }

    Array steps;

    for (const size_t step : route->edges) {
        RouteWeight weight = catalogue.GetStep(step);
        if (weight.is_bus) {
            steps.push_back(Node(Dict{ {"type"s, Node("Bus"s)}, {"bus"s, Node(std::string(weight.name))}, {"span_count"s, Node(int(weight.span_count))}, {"tyme"s, Node(weight.time)} }));
        }
        else {
            steps.push_back(Node(Dict{ {"type"s, Node("Wait"s)}, {"stop_name"s, Node(std::string(weight.name))}, {"tyme"s, Node(weight.time)} }));
        }
    }

    Print(Document{ Builder{}.StartDict().Key("request_id"s).Value(dic.at("id"s).AsInt()).Key("total_time").Value(route->weight.time).Key("items").Value(steps).EndDict().Build()}, out);

}

void JsonReader::ReadStat(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, const Array& stat, std::ostream& out) {
    out << '[';
    if (stat.size() > 0) {
        out << std::endl;
        const Dict& dic = stat[0].AsMap();
        if (dic.at("type"s).AsString() == "Stop"s) {
            PrintStop(catalogue, dic, out);
        }
        if (dic.at("type"s).AsString() == "Bus"s) {
            PrintBus(catalogue, dic, out);
        }
        if (dic.at("type"s).AsString() == "Map"s) {
            PrintMap(catalogue, renderer, dic, out);
        }
        if (dic.at("type"s).AsString() == "Route"s) {
            PrintRoute(catalogue, dic, out);
        }
    }
    if (stat.size() > 1) {
        for (size_t i = 1; i < stat.size(); ++i) {
            out << ',' << std::endl;
            const Dict& dic = stat[i].AsMap();
            if (dic.at("type"s).AsString() == "Stop"s) {
                PrintStop(catalogue, dic, out);
            }
            if (dic.at("type"s).AsString() == "Bus"s) {
                PrintBus(catalogue, dic, out);
            }
            if (dic.at("type"s).AsString() == "Map"s) {
                PrintMap(catalogue, renderer, dic, out);
            }
            if (dic.at("type"s).AsString() == "Route"s) {
                PrintRoute(catalogue, dic, out);
            }
        }
        out << std::endl;
    }
    out << ']' << std::endl;
}

void JsonReader::ReadBase(transport_catalogue::TransportCatalogue& catalogue, const Array& base) {
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
            bool is_roundtrip = dic.at("is_roundtrip"s).AsBool();
            if (!is_roundtrip) {
                for (int i = stops.size() - 2; i >= 0; --i) {
                    stops.push_back(stops[i]);
                }
            }
            catalogue.AddBus(dic.at("name"s).AsString(), std::move(stops), is_roundtrip);
        }
    }
}

void JsonReader::ReadMapSettings(map_renderer::MapRenderer& renderer, const Dict& settings) {
    Array temp = settings.at("bus_label_offset"s).AsArray();
    const svg::Point bus_label_offset(temp[0].AsDouble(), temp[1].AsDouble());
    temp = settings.at("stop_label_offset"s).AsArray();
    const svg::Point stop_label_offset(temp[0].AsDouble(), temp[1].AsDouble());
    std::vector<svg::Color> color_palette;
    for (auto a : settings.at("color_palette"s).AsArray()) {
        if (a.IsString()) {
            color_palette.push_back(a.AsString());
            continue;
        }
        Array arr = a.AsArray();
        if (arr.size() == 3) {
            color_palette.push_back(svg::Rgb(arr[0].AsInt(), arr[1].AsInt(), arr[2].AsInt()));
            continue;
        }
        color_palette.push_back(svg::Rgba(arr[0].AsInt(), arr[1].AsInt(), arr[2].AsInt(), arr[3].AsDouble()));
    }
    svg::Color underlayer_color;
    Node node = settings.at("underlayer_color"s);
    if (node.IsString()) {
        underlayer_color = node.AsString();
    } else {
        Array arr = node.AsArray();
        if (arr.size() == 3) {
            underlayer_color = svg::Rgb(arr[0].AsInt(), arr[1].AsInt(), arr[2].AsInt());
        } else {
            underlayer_color = svg::Rgba(arr[0].AsInt(), arr[1].AsInt(), arr[2].AsInt(), arr[3].AsDouble());
        }
    }
    
    map_renderer::MapRendererSettings renderer_settings(settings.at("width"s).AsDouble(), settings.at("height"s).AsDouble(), settings.at("padding"s).AsDouble(), settings.at("line_width"s).AsDouble(), settings.at("stop_radius"s).AsDouble(), settings.at("bus_label_font_size"s).AsInt(), bus_label_offset, settings.at("stop_label_font_size"s).AsInt(), stop_label_offset, underlayer_color, settings.at("underlayer_width"s).AsDouble(), color_palette);
    renderer.SetSettings(renderer_settings);
}

void JsonReader::SetRouter(transport_catalogue::TransportCatalogue& catalogue, const Dict& settings) {
    const double bus_wait_time = settings.at("bus_wait_time"s).AsDouble();
    const double bus_velocity = settings.at("bus_velocity"s).AsDouble();

    size_t index = 0;

    std::unordered_map<std::string_view, size_t> stops_id;

    const auto stops = catalogue.GetAllStops();

    graph::DirectedWeightedGraph<RouteWeight> transport_graph(stops.size() * 2);

    for (const auto& stop : stops) {
        stops_id[stop.first] = index;
        transport_graph.AddEdge({ index, index + 1, { stop.first, 0, bus_wait_time, false }});
        index += 2;
    }

    size_t stops_count = 0;

    for (const auto& bus : catalogue.GetAllBuses()) {
        const auto& bus_stops = bus.second->stops;
        stops_count = bus.second->is_roundtrip == false ? bus_stops.size() / 2 : bus_stops.size() - 1;
        for (size_t i = 0; i < stops_count; i++) {
            double time = 0.0;
            for (size_t j = i + 1; j <= stops_count; j++) {
                time += ((catalogue.GetDistance({ bus_stops[j - 1], bus_stops[j] }) * 0.001 / bus_velocity) * 60);
                transport_graph.AddEdge({ stops_id[bus_stops[i]->name] + 1, stops_id[bus_stops[j]->name], { bus.first, j - i, time, true} });
            }
        }
        if (bus.second->is_roundtrip == false) {
            for (size_t i = stops_count; i < bus_stops.size() - 1;  i++) {
                double time = 0.0;
                for (size_t j = i + 1; j < bus_stops.size();  j++) {
                    time += ((catalogue.GetDistance({ bus_stops[j - 1], bus_stops[j] }) * 0.001 / bus_velocity) * 60);
                    transport_graph.AddEdge({ stops_id[bus_stops[i]->name] + 1, stops_id[bus_stops[j]->name], { bus.first, j - i, time, true} });
                }
            }
        }
    }
    catalogue.SetRouter(std::move(transport_graph), std::move(stops_id));
}
    
void JsonReader::ReadInput(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, std::istream& in, std::ostream& out) {
    const auto input = Load(in).GetRoot().AsMap();
    ReadBase(catalogue, input.at("base_requests"s).AsArray());
    ReadMapSettings(renderer, input.at("render_settings"s).AsMap());
    SetRouter(catalogue, input.at("routing_settings"s).AsMap());
    ReadStat(catalogue, renderer, input.at("stat_requests"s).AsArray(), out);
}

}
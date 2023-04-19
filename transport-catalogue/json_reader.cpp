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

void GetMap(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, const Dict& dic, std::ostream& out) {
    Print(Document{Node{Dict{{"map"s, renderer.GetMap(catalogue)}, {"request_id"s, dic.at("id"s).AsInt()}}}}, out);
}

void ReadStat(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, const Array& stat, std::ostream& out) {
    out << '[';
    if (stat.size() > 0) {
        out << std::endl;
        const Dict& dic = stat[0].AsMap();
        if (dic.at("type"s).AsString() == "Stop"s) {
            GetStop(catalogue, dic, out);
        }
        if (dic.at("type"s).AsString() == "Bus"s) {
            GetBus(catalogue, dic, out);
        }
        if (dic.at("type"s).AsString() == "Map"s) {
            GetMap(catalogue, renderer, dic, out);
        } 
    }
    if (stat.size() > 1) {
        for (size_t i = 1; i < stat.size(); ++i) {
            out << ',' << std::endl;
            const Dict& dic = stat[i].AsMap();
            if (dic.at("type"s).AsString() == "Stop"s) {
                GetStop(catalogue, dic, out);
            }
            if (dic.at("type"s).AsString() == "Bus"s) {
                GetBus(catalogue, dic, out);
            }
            if (dic.at("type"s).AsString() == "Map"s) {
                GetMap(catalogue, renderer, dic, out);
            } 
        }
        out << std::endl;
    }
    out << ']' << std::endl;
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

void ReadMapSettings(map_renderer::MapRenderer& renderer, const Dict& settings) {
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
    
void ReadInput(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, std::istream& in, std::ostream& out) {
    const auto input = Load(in).GetRoot().AsMap();
    ReadBase(catalogue, input.at("base_requests"s).AsArray());
    ReadMapSettings(renderer, input.at("render_settings"s).AsMap());
    ReadStat(catalogue, renderer, input.at("stat_requests"s).AsArray(), out);
}

}
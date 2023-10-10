#include "serialization.h"

namespace serialization {
    
    
    proto::Color GetColor(const svg::Color& color) {
        
        proto::Color col;
        
        if(std::holds_alternative<std::string>(color)) {
            col.mutable_color_string()->set_color(std::get<std::string>(color));
            
        } else if(std::holds_alternative<svg::Rgb>(color)) {
            proto::ColorArray colorar;
            svg::Rgb rgb = std::get<svg::Rgb>(color);
            colorar.add_color(rgb.red);
            colorar.add_color(rgb.green);
            colorar.add_color(rgb.blue);
            *col.mutable_color_array() = colorar;
        }
        else if(std::holds_alternative<svg::Rgba>(color)) {
            proto::ColorArray colorar;
            svg::Rgba rgb = std::get<svg::Rgba>(color);
            colorar.add_color(rgb.red);
            colorar.add_color(rgb.green);
            colorar.add_color(rgb.blue);
            colorar.add_color(rgb.opacity);
            *col.mutable_color_array() = colorar;
        }
        
        return col;
    }
    
    svg::Color ParsingColor(const proto::Color& color) {
        if (color.has_color_array()) {
            proto::ColorArray colorArray = color.color_array();
            if (colorArray.color_size() == 4){
                return svg::Color(svg::Rgba(colorArray.color(0), colorArray.color(1), colorArray.color(2), colorArray.color(3)));
            }

            return svg::Color(svg::Rgb(colorArray.color(0), colorArray.color(1), colorArray.color(2)));
        } else {
            return svg::Color(color.color_string().color());
        }
    }
    
    
    void SerializeCat(transport_catalogue::TransportCatalogue& catalogue, proto::TransportCatalogue& cat) {
        
        proto::Stop stop;
        
        proto::Bus bus;
        
        proto::Distance distance;
        
        std::unordered_map<transport_catalogue::TransportCatalogue::Stop*, uint32_t> stops_id;
        
        uint32_t id = 0;
        
        for (const auto& s : catalogue.GetAllStops()) {
            stop.set_name(s.second->name);
            stop.set_x(s.second->x);
            stop.set_y(s.second->y);
            *cat.add_stop() = stop;
            stop.Clear();
            stops_id[s.second] = id++;
        }
        
        for (const auto& b : catalogue.GetAllBuses()) {
            bus.set_name(b.second->name);
            bus.set_is_roundtrip(b.second->is_roundtrip);
            for (auto s_ptr : b.second->stops) {
                bus.add_stop(stops_id[s_ptr]);
            }
            *cat.add_bus() = bus;
            bus.Clear();
        }
        
        for (const auto& d : catalogue.GetAllDistances()) {
            distance.set_stop_from(stops_id[d.first.first]);
            distance.set_stop_to(stops_id[d.first.second]);
            distance.set_length(d.second);
            *cat.add_distance() = distance;
            distance.Clear();
        }
        
    }
    
    
    void SerializeMap(map_renderer::MapRenderer& renderer, proto::TransportCatalogue& cat) {
        
        proto::MapRendererSettings render;
        
        proto::Point point;
        
        auto settings = renderer.GetSettings();
        
        render.set_width(settings.width_);
        render.set_height(settings.height_);
        render.set_padding(settings.padding_);
        render.set_line_width(settings.line_width_);
        render.set_stop_radius(settings.stop_radius_);
        render.set_bus_label_font_size(settings.bus_label_font_size_);
        render.set_stop_label_font_size(settings.stop_label_font_size_);
        render.set_underlayer_width(settings.underlayer_width_);
        
        render.mutable_bus_label_offset()->set_x(settings.bus_label_offset_.x);
        render.mutable_bus_label_offset()->set_y(settings.bus_label_offset_.y);
        
        render.mutable_stop_label_offset()->set_x(settings.stop_label_offset_.x);
        render.mutable_stop_label_offset()->set_y(settings.stop_label_offset_.y);

        *render.mutable_underlayer_color() = GetColor(settings.underlayer_color_);

        for (const auto& color : settings.color_palette_) {
            *render.add_color_palette() = GetColor(color);
        }

        *cat.mutable_map_settings() = std::move(render);
    }
    
    
    void SerializeRoute(transport_router::TransportRouter& router, proto::TransportCatalogue& cat) {
        
        proto::Weight weight;
        
        proto::Edge edge;
        
        proto::Graph graph;
        
        auto gr = router.GetGraph();
        
        for (const auto& ed : gr.GetEdges()) {
            weight.set_name(std::string(ed.weight.name));
            weight.set_span_count(ed.weight.span_count);
            weight.set_time(ed.weight.time);
            weight.set_is_bus(ed.weight.is_bus);
            edge.set_from(ed.from);
            edge.set_to(ed.to);
            *edge.mutable_weight() = weight;
            *graph.add_edge() = edge;
            weight.Clear();
            edge.Clear();
        }
        
        graph.set_vertex_count(gr.GetVertexCount());
        
        *cat.mutable_graph() = std::move(graph);
    }
    
    
    void Serialize(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, transport_router::TransportRouter& router, std::string file_name) {
        
        proto::TransportCatalogue cat;
        
        SerializeCat(catalogue, cat);
        
        SerializeMap(renderer, cat);
        
        SerializeRoute(router, cat);
        
        std::ofstream fout(file_name, std::ios::binary);
        
        cat.SerializeToOstream(&fout);
        
        fout.close();
        
    }
    
    void DeserializeCat(transport_catalogue::TransportCatalogue& catalogue, proto::TransportCatalogue& cat) {
        
        proto::Stop stop;
        
        proto::Bus bus;
        
        proto::Distance distance;
        
        std::unordered_map<uint32_t, std::string> stops_id;
        
        uint32_t id = 0;
        
        for (const auto& s : cat.stop()) {
            catalogue.AddStop(s.name(), s.x(), s.y());
            stops_id[id++] = s.name();
        }
        
        for (const auto& d : cat.distance()) {
            catalogue.AddDistance(std::make_pair(std::make_pair(stops_id[d.stop_from()], stops_id[d.stop_to()]), d.length()));
        }
        
        for (const auto& b : cat.bus()) {
            std::vector<std::string> bus_stops;
            for (const auto& s : b.stop()) {
                bus_stops.push_back(stops_id[s]);
            }
            catalogue.AddBus(b.name(), std::move(bus_stops), b.is_roundtrip());
        }
    }
    
    void DeserializeMap(map_renderer::MapRenderer& renderer, proto::TransportCatalogue& cat) {
        
        map_renderer::MapRendererSettings settings;
        
        settings.width_ = cat.map_settings().width();
        settings.height_ = cat.map_settings().height();
        settings.padding_ = cat.map_settings().padding();
        settings.line_width_ = cat.map_settings().line_width();
        settings.stop_radius_ = cat.map_settings().stop_radius();
        settings.bus_label_font_size_ = cat.map_settings().bus_label_font_size();
        
        settings.bus_label_offset_.x = cat.map_settings().bus_label_offset().x();
        settings.bus_label_offset_.y = cat.map_settings().bus_label_offset().y();
        
        settings.stop_label_font_size_ = cat.map_settings().stop_label_font_size();
        settings.stop_label_offset_.x = cat.map_settings().stop_label_offset().x();
        settings.stop_label_offset_.y = cat.map_settings().stop_label_offset().y();    
        settings.underlayer_color_ = ParsingColor(cat.map_settings().underlayer_color());
        settings.underlayer_width_ = cat.map_settings().underlayer_width();

        for (const proto::Color& i : cat.map_settings().color_palette() ) {
            if (i.has_color_string())
                settings.color_palette_.push_back(i.color_string().color());
            else {
                settings.color_palette_.push_back(ParsingColor(i));
            }
            
        }

        renderer.SetSettings(settings);
    }
    
    void DeserializeRoute(transport_router::TransportRouter& router, transport_catalogue::TransportCatalogue& catalogue, proto::TransportCatalogue& cat) {
        
        if (!cat.has_graph()) {
            return;
        }
        
        graph::DirectedWeightedGraph<transport_router::RouteWeight> graph(cat.graph().vertex_count());
        
        auto stops = catalogue.GetAllStops();
        auto buses = catalogue.GetAllBuses();
    
        for (const auto& ed : cat.graph().edge()) {
            std::string_view name = ed.weight().is_bus() ? std::string_view{buses[ed.weight().name()]->name} : std::string_view{stops[ed.weight().name()]->name};
            graph.AddEdge({ ed.from(), ed.to(), { name, ed.weight().span_count(), ed.weight().time(), ed.weight().is_bus()} });
        }
        
        router.SetGraph(catalogue, std::move(graph));
        
    }
    
    void Deserialize(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, transport_router::TransportRouter& router, std::string file_name) {
        
        std::ifstream fin(file_name, std::ios::binary);
        
        proto::TransportCatalogue cat;
        
        cat.ParseFromIstream(&fin);
        
        DeserializeCat(catalogue, cat);
         
        DeserializeMap(renderer, cat);
        
        DeserializeRoute(router, catalogue, cat);
        
        fin.close();
    }
    
    
}
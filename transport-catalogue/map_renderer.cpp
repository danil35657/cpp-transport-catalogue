#include "map_renderer.h"

namespace map_renderer {
    
using namespace std::literals;

bool IsZero(double value) {
    return std::abs(value) < EPSILON;
}

// Проецирует широту и долготу в координаты внутри SVG-изображения
svg::Point SphereProjector::operator()(geo::Coordinates coords) const {
    return {
        (coords.lng - min_lon_) * zoom_coeff_ + padding_,
        (max_lat_ - coords.lat) * zoom_coeff_ + padding_
    };
}

void MapRenderer::SetSettings(const MapRendererSettings& settings) {
    settings_ = settings;
}

std::string MapRenderer::GetMap(transport_catalogue::TransportCatalogue& catalogue) {
    svg::Document route_map;
    const auto buses = catalogue.GetAllBuses();
    const auto stops = catalogue.GetAllStops();
    std::vector<geo::Coordinates> coordinates;
    coordinates.reserve(stops.size());
    for(const auto& stop : stops) {
        if (catalogue.GetStopInfo(stop.first).size() > 0) {
            coordinates.push_back({stop.second->x, stop.second->y});
        }
    }
    const SphereProjector proj{coordinates.begin(), coordinates.end(), settings_.width_, settings_.height_, settings_.padding_};
    size_t color_number = 0u;
    size_t max_color_number = settings_.color_palette_.size() - 1;
    for (const auto& bus : buses) {
        const auto& bus_stops = bus.second->stops;
        if (bus_stops.size() > 0) {
            svg::Polyline route;
            route.SetFillColor("none"s).SetStrokeColor(settings_.color_palette_[color_number]).SetStrokeWidth(settings_.line_width_).SetStrokeLineJoin(svg::StrokeLineJoin::ROUND).SetStrokeLineCap(svg::StrokeLineCap::ROUND);
            for(const auto stop : bus_stops) {
                route.AddPoint(proj({stop->x, stop->y}));
            }
            route_map.AddPtr(std::make_unique<svg::Polyline>(std::move(route)));
            color_number == max_color_number ? color_number = 0u : ++color_number;
        }
    }
    color_number = 0u;
    for (const auto& bus : buses) {
        const auto& bus_stops = bus.second->stops;
        if (bus_stops.size() > 0) {
            svg::Text base_text = svg::Text().SetFontFamily("Verdana"s).SetFontWeight("bold"s).SetFontSize(settings_.bus_label_font_size_).SetPosition(proj({bus_stops[0]->x, bus_stops[0]->y})).SetOffset(settings_.bus_label_offset_).SetData(std::string(bus.first));
            route_map.AddPtr(std::make_unique<svg::Text>(std::move(svg::Text{base_text}.SetStrokeColor(settings_.underlayer_color_).SetFillColor(settings_.underlayer_color_).SetStrokeLineJoin(svg::StrokeLineJoin::ROUND).SetStrokeLineCap(svg::StrokeLineCap::ROUND).SetStrokeWidth(settings_.underlayer_width_))));
            route_map.AddPtr(std::make_unique<svg::Text>(std::move(svg::Text{base_text}.SetFillColor(settings_.color_palette_[color_number]))));
            if (!bus.second->is_roundtrip && bus_stops[0] != bus_stops[bus_stops.size() / 2]) {
                base_text = svg::Text().SetFontFamily("Verdana"s).SetFontWeight("bold"s).SetFontSize(settings_.bus_label_font_size_).SetPosition(proj({bus_stops[bus_stops.size() / 2]->x, bus_stops[bus_stops.size() / 2]->y})).SetOffset(settings_.bus_label_offset_).SetData(std::string(bus.first));
            route_map.AddPtr(std::make_unique<svg::Text>(std::move(svg::Text{base_text}.SetStrokeColor(settings_.underlayer_color_).SetFillColor(settings_.underlayer_color_).SetStrokeLineJoin(svg::StrokeLineJoin::ROUND).SetStrokeLineCap(svg::StrokeLineCap::ROUND).SetStrokeWidth(settings_.underlayer_width_))));
            route_map.AddPtr(std::make_unique<svg::Text>(std::move(svg::Text{base_text}.SetFillColor(settings_.color_palette_[color_number]))));
            }
            color_number == max_color_number ? color_number = 0u : ++color_number;
        }
    }
    for (const auto& stop : stops) {
        if (catalogue.GetStopInfo(stop.first).size() > 0) {
            route_map.AddPtr(std::make_unique<svg::Circle>(std::move(svg::Circle().SetCenter(proj({stop.second->x, stop.second->y})).SetRadius(settings_.stop_radius_).SetFillColor("white"s))));
        }
    }
    for (const auto& stop : stops) {
        if (catalogue.GetStopInfo(stop.first).size() > 0) {
            svg::Text base_text = svg::Text().SetFontFamily("Verdana"s).SetFontSize(settings_.stop_label_font_size_).SetPosition(proj({stop.second->x, stop.second->y})).SetOffset(settings_.stop_label_offset_).SetData(stop.second->name);
            route_map.AddPtr(std::make_unique<svg::Text>(std::move(svg::Text{base_text}.SetStrokeColor(settings_.underlayer_color_).SetFillColor(settings_.underlayer_color_).SetStrokeLineJoin(svg::StrokeLineJoin::ROUND).SetStrokeLineCap(svg::StrokeLineCap::ROUND).SetStrokeWidth(settings_.underlayer_width_))));
            route_map.AddPtr(std::make_unique<svg::Text>(std::move(svg::Text{base_text}.SetFillColor("black"s))));
        }
    }
    std::stringstream out;
    route_map.Render(out);
    std::string result;
    std::string temp;
    std::getline(out, temp);
    result.append(temp);
    while (std::getline(out, temp)) {
        result.append("\n"s);
        result.append(temp);
    }
    return result;
}
    

}
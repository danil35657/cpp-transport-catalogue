#include "svg.h"

namespace svg {

using namespace std::literals;

// -------------Object-------------------

void Object::Render(const RenderContext& context) const {
    context.RenderIndent();

    // Делегируем вывод тега своим подклассам
    RenderObject(context);

    context.out << std::endl;
}

std::ostream& operator << (std::ostream& out, const StrokeLineCap& line_cap) {
    switch(line_cap) {
        case StrokeLineCap::BUTT : return out << "butt"sv;
        case StrokeLineCap::ROUND : return out << "round"sv;
        case StrokeLineCap::SQUARE : return out << "square"sv;
    }
    return out;
}

std::ostream& operator << (std::ostream& out, const StrokeLineJoin& line_join) {
    switch(line_join) {
        case StrokeLineJoin::ARCS : return out << "arcs"sv;
        case StrokeLineJoin::BEVEL : return out << "bevel"sv;
        case StrokeLineJoin::MITER : return out << "miter"sv;
        case StrokeLineJoin::MITER_CLIP : return out << "miter-clip"sv;
        case StrokeLineJoin::ROUND : return out << "round"sv;
    }
    return out;
}

std::ostream& operator << (std::ostream& out, Color color) {
    std::visit(PrintColor{out}, color);
    return out;
}

// ---------- Circle ------------------

Circle& Circle::SetCenter(Point center)  {
    center_ = center;
    return *this;
}

Circle& Circle::SetRadius(double radius)  {
    radius_ = radius;
    return *this;
}

void Circle::RenderObject(const RenderContext& context) const {
    auto& out = context.out;
    out << "<circle cx=\""sv << center_.x << "\" cy=\""sv << center_.y << "\" "sv;
    out << "r=\""sv << radius_ << "\" "sv;
    RenderAttrs(context.out);
    out << "/>"sv;
}

// ------------ Polyline ------------------

Polyline& Polyline::AddPoint(Point point) {
    points_.push_back(point);
    return *this;
}

void Polyline::RenderObject(const RenderContext& context) const {
    auto& out = context.out;
    out << "<polyline points=\""sv;
    if (!points_.empty()) {
        out << points_[0].x << ","sv << points_[0].y;
    }
    if (points_.size() > 1) {
        for (size_t i = 1; i < points_.size(); ++i) {
            out << " "sv << points_[i].x << ","sv << points_[i].y;
        }
    }
    out << "\" "sv;
    RenderAttrs(context.out);
    out << "/>"sv;
}

// ------------- Text ----------------------

// Задаёт координаты опорной точки (атрибуты x и y)
Text& Text::SetPosition(Point pos) {
    pos_ = pos;
    return *this;
}

// Задаёт смещение относительно опорной точки (атрибуты dx, dy)
Text& Text::SetOffset(Point offset) {
    offset_ = offset;
    return *this;
}

// Задаёт размеры шрифта (атрибут font-size)
Text& Text::SetFontSize(uint32_t size) {
    size_ = size;
    return *this;
}

// Задаёт название шрифта (атрибут font-family)
Text& Text::SetFontFamily(std::string font_family) {
    font_family_ = font_family;
    return *this;
    
}

// Задаёт толщину шрифта (атрибут font-weight)
Text& Text::SetFontWeight(std::string font_weight) {
    font_weight_ = font_weight;
    return *this;
}

// Задаёт текстовое содержимое объекта (отображается внутри тега text)
Text& Text::SetData(std::string data) {
    data_ = data;
    return *this;
}

void Text::RenderObject(const RenderContext& context) const {
    auto& out = context.out;
    out << "<text"sv;
    RenderAttrs(context.out);
    out << " x=\""sv << pos_.x << "\" y=\""sv << pos_.y << "\" dx=\""sv << offset_.x << "\" dy=\""sv << offset_.y << "\" font-size=\""sv << size_ << "\"";
    if (!font_family_.empty()) {
        out << " font-family=\""sv << font_family_ << "\"";
    }
    if (!font_weight_.empty()) {
        out << " font-weight=\""sv << font_weight_ << "\"";
    }
    out << ">"sv << data_ << "</text>"sv;

}

//------------------- Document ------------------------------

void Document::AddPtr(std::unique_ptr<Object>&& obj) {
    objects_.emplace_back(std::move(obj));
}

void Document::Render(std::ostream& out) const {
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"sv << std::endl;
    out << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">"sv << std::endl;
    RenderContext rend(out, 2, 2);
    for (const auto& object_ptr : objects_) {
        object_ptr->Render(rend);
    }
    out << "</svg>"sv << std::endl;
}

}  // namespace svg
#pragma once

#include <string_view>

struct RouteWeight {
    std::string_view name;
    size_t span_count = 0;
    double time = 0.0;
    bool is_bus = true;

    bool operator<(const RouteWeight& right) const;

    bool operator>(const RouteWeight& right) const;
};

RouteWeight operator+(const RouteWeight& left, const RouteWeight& right);

#include "transport_router.h"

using namespace std::literals;

bool RouteWeight::operator<(const RouteWeight& right) const {
    return time < right.time;
}

bool RouteWeight::operator>(const RouteWeight& right) const {
    return time > right.time;
}

RouteWeight operator+(const RouteWeight& left, const RouteWeight& right) {
    RouteWeight temp{ ""sv, 0, left.time + right.time, true };
    return temp;
}
#pragma once

#include <string>
#include <iostream>
#include <string_view>

#include "transport_catalogue.h"

using std::literals::string_literals::operator""s;

void ReadStat(transport_catalogue::TransportCatalogue& catalogue);
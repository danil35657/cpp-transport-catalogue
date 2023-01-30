#pragma once

#include <string>
#include <iostream>
#include <string_view>

#include "transport_catalogue.h"

namespace stat_reader {

using std::literals::string_literals::operator""s;

void GetStop(transport_catalogue::TransportCatalogue& catalogue, const std::string& s);

void GetBus(transport_catalogue::TransportCatalogue& catalogue, const std::string& s);

void ReadStat(transport_catalogue::TransportCatalogue& catalogue);

}
#pragma once

#include <string>
#include <iostream>
#include <string_view>

#include "transport_catalogue.h"

namespace stat_reader {

using std::literals::string_literals::operator""s;

void GetStop(transport_catalogue::TransportCatalogue& catalogue, const std::string& s, std::ostream& out);

void GetBus(transport_catalogue::TransportCatalogue& catalogue, const std::string& s, std::ostream& out);

void ReadStat(transport_catalogue::TransportCatalogue& catalogue, std::istream& in);

}
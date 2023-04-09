#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <string_view>
#include "transport_catalogue.h"
#include "json.h"

using namespace std::literals;

namespace json_reader {
	
using namespace json;
	
void GetStop(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out);

void GetBus(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out);

void ReadStat(transport_catalogue::TransportCatalogue& catalogue, const Array& base);

void ReadBase(transport_catalogue::TransportCatalogue& catalogue, const Array& base);
	
void ReadInput(transport_catalogue::TransportCatalogue& catalogue, std::istream& in);

}
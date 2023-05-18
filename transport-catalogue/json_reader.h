#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <string_view>

#include "transport_catalogue.h"
#include "json.h"
#include "map_renderer.h"
#include "json_builder.h"

using namespace std::literals;

namespace json_reader {
    
using namespace json;

class JsonReader {

public:
    
void ReadInput(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, std::istream& in, std::ostream& out);

private:

void PrintStop(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out);

void PrintBus(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out);

void PrintMap(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, const Dict& dic, std::ostream& out);

void ReadStat(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, const Array& stat, std::ostream& out);

void ReadBase(transport_catalogue::TransportCatalogue& catalogue, const Array& base);

void ReadMapSettings(map_renderer::MapRenderer& renderer, const Dict& settings);

};

}
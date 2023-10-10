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
#include "graph.h"
#include "transport_router.h"
#include "serialization.h"

using namespace std::literals;

namespace json_reader {
    
using namespace json;

class JsonReader {

public:
    
void ReadInput(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, transport_router::TransportRouter& router,  std::istream& in, std::ostream& out);

void ReadInputBase(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, transport_router::TransportRouter& router, std::istream& in);

void ReadInputStat(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, transport_router::TransportRouter& router, std::istream& in, std::ostream& out);

private:

void PrintStop(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out);

void PrintBus(transport_catalogue::TransportCatalogue& catalogue, const Dict& dic, std::ostream& out);

void PrintMap(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, const Dict& dic, std::ostream& out);

void PrintRoute(transport_router::TransportRouter& router, const Dict& dic, std::ostream& out);

void ReadStat(transport_catalogue::TransportCatalogue& catalogue, transport_router::TransportRouter& router, map_renderer::MapRenderer& renderer, const Array& stat, std::ostream& out);

void ReadBase(transport_catalogue::TransportCatalogue& catalogue, const Array& base);

void ReadMapSettings(map_renderer::MapRenderer& renderer, const Dict& settings);

void ReadRouterSettings(transport_catalogue::TransportCatalogue& catalogue, transport_router::TransportRouter& router, const Dict& settings);

};

}
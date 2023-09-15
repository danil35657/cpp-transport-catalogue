#include <iostream>

#include "json_reader.h"
#include "transport_catalogue.h"
#include "geo.h"
#include "map_renderer.h"
#include "transport_router.h"


int main() {
    transport_catalogue::TransportCatalogue catalogue;
    map_renderer::MapRenderer renderer;
    json_reader::JsonReader reader;
    transport_router::TransportRouter router;
    reader.ReadInput(catalogue, renderer, router, std::cin, std::cout);
}
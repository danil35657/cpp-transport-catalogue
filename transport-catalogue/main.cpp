#include <iostream>

#include "json_reader.h"
#include "transport_catalogue.h"
#include "geo.h"
#include "map_renderer.h"
#include <iostream>

int main() {
    transport_catalogue::TransportCatalogue catalogue;
    map_renderer::MapRenderer renderer;
    json_reader::JsonReader reader;
    reader.ReadInput(catalogue, renderer, std::cin, std::cout);
}
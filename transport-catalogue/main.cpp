#include <fstream>
#include <iostream>
#include <string_view>

#include "json_reader.h"
#include "transport_catalogue.h"
#include "geo.h"
#include "map_renderer.h"
#include "transport_router.h"

using namespace std::literals;

void PrintUsage(std::ostream& stream = std::cerr) {
    stream << "Usage: transport_catalogue [make_base|process_requests]\n"sv;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        PrintUsage();
        return 1;
    }

    const std::string_view mode(argv[1]);

    if (mode == "make_base"sv) {
        transport_catalogue::TransportCatalogue catalogue;
        json_reader::JsonReader reader;
        map_renderer::MapRenderer renderer;
        transport_router::TransportRouter router;
        reader.ReadInputBase(catalogue, renderer, router, std::cin);

    } else if (mode == "process_requests"sv) {
        transport_catalogue::TransportCatalogue catalogue;
        map_renderer::MapRenderer renderer;
        json_reader::JsonReader reader;
        transport_router::TransportRouter router;
        reader.ReadInputStat(catalogue, renderer, router, std::cin, std::cout);

    } else {
        PrintUsage();
        return 1;
    }
}

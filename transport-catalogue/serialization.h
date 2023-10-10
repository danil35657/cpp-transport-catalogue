#pragma once

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

#include "transport_catalogue.h"
#include "transport_catalogue.pb.h"
#include "map_renderer.h"
#include "transport_router.h"



namespace serialization {
    
    void Serialize(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, transport_router::TransportRouter& router, std::string file_name);
    
    void Deserialize(transport_catalogue::TransportCatalogue& catalogue, map_renderer::MapRenderer& renderer, transport_router::TransportRouter& router, std::string file_name);
    
}
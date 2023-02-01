#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <deque> 

#include "transport_catalogue.h"

namespace input_reader {

void ReadStop(transport_catalogue::TransportCatalogue& catalogue, std::string& stop, std::unordered_map<std::string, int>& distances);

void ReadBus(transport_catalogue::TransportCatalogue& catalogue, std::string& bus);

void ReadInput(transport_catalogue::TransportCatalogue& catalogue, std::istream& in);

}

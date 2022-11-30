#pragma once

#include <string>
#pragma once

#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "transport_catalogue.h"

void ReadStop(transport_catalogue::TransportCatalogue& catalogue, const std::string& stop);

void ReadBus(transport_catalogue::TransportCatalogue& catalogue, const std::string& bus);

void ReadInput(transport_catalogue::TransportCatalogue& catalogue);

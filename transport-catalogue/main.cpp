#include <iostream>

#include "json_reader.h"
#include "transport_catalogue.h"
#include "geo.h"

int main() {
	transport_catalogue::TransportCatalogue catalogue;
	json_reader::ReadInput(catalogue, std::cin);
}
#include <iostream>

#include "input_reader.h"
#include "stat_reader.h"
#include "transport_catalogue.h"
#include "geo.h"

int main() {
	transport_catalogue::TransportCatalogue catalogue;
	ReadInput(catalogue);
	ReadStat(catalogue);
}
#include <iostream>

#include "input_reader.h"
#include "stat_reader.h"
#include "transport_catalogue.h"
#include "geo.h"

int main() {
	transport_catalogue::TransportCatalogue catalogue;
	input_reader::ReadInput(catalogue);
	stat_reader::ReadStat(catalogue);
}
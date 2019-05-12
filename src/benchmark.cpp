#include "benchmarks/MapBenchmark.h"
#include "benchmarks/SetBenchmark.h"
#include "benchmarks/ListBenchmark.h"
#include <iostream>

int main(int argc, char* argv[]) {
	if(argc!=4) {
		std::cerr << "Invalid arguments! Command should be: benchmark STRUCTURE CLASS DATATYPE" << std::endl;
		return 0;
	}

	const char* typeName = argv[1];
	const char* className = argv[2];
	const char* dataType = argv[3];

	if(strcmp(dataType, "long")!=0 && strcmp(dataType, "char*")!=0) {
		std::cerr << "Unsupported DATATYPE" << std::endl;
		return 0;
	}

	if(strcmp(typeName, "list")==0) {
		ListBenchmark listBenchmark(className, dataType);
		listBenchmark.execute();
	} else if(strcmp(typeName, "map")==0) {
		MapBenchmark mapBenchmark(className, dataType);
		mapBenchmark.execute();
	} else if(strcmp(typeName, "set")==0) {
		SetBenchmark setBenchmark(className, dataType);
		setBenchmark.execute();
	} else {
		std::cerr << "Unsupported TYPE" << std::endl;
		return 0;
	}

	return 1;
}


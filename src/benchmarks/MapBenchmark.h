/*
 * MapBenchmark.h
 *
 *  Created on: Mar 25, 2016
 *      Author: aherne
 */

#ifndef BENCHMARKS_MAPBENCHMARK_H_
#define BENCHMARKS_MAPBENCHMARK_H_

#include "Benchmark.h"
#include <cstring>
#include <Hashing.h>
#include <Comparator.h>
#include <map/Map.h>

class MapBenchmark {
public:
	MapBenchmark(const char* className, const char* dataType) : className(className), dataType(dataType) {};
	void execute();
private:
	const char* className;
	const char* dataType;
	void testUnorderedMapLong();
	void testUnorderedMapString();
	void testMapLong();
	void testMapString();
	void test(Map<long, long>* ht);
	void test(Map<char*, char*>* ht);
};



#endif /* BENCHMARKS_MAPBENCHMARK_H_ */

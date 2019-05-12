/*
 * SetBenchmark.h
 *
 *  Created on: Mar 27, 2016
 *      Author: aherne
 */

#ifndef BENCHMARKS_SETBENCHMARK_H_
#define BENCHMARKS_SETBENCHMARK_H_

#include "Benchmark.h"
#include <cstring>
#include "Hashing.h"
#include "Comparator.h"
#include "set/Set.h"

class SetBenchmark {
public:
	SetBenchmark(const char* className, const char* dataType) : className(className), dataType(dataType) {};
	void execute();
private:
	const char* className;
	const char* dataType;
	void testUnorderedSetLong();
	void testUnorderedSetString();
	void testSetLong();
	void testSetString();
	void test(Set<long>* ht);
	void test(Set<char*>* ht);
};


#endif /* BENCHMARKS_SETBENCHMARK_H_ */

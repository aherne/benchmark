/*
 * ListBenchmark.h
 *
 *  Created on: May 7, 2016
 *      Author: aherne
 */

#ifndef BENCHMARKS_LISTBENCHMARK_H_
#define BENCHMARKS_LISTBENCHMARK_H_

#include "Benchmark.h"
#include "StringListGenerator.h"
#include <list/List.h>

class ListBenchmark {
public:
	ListBenchmark(const char* className, const char* dataType) : className(className), dataType(dataType) {};
	void execute();
private:
	const char* className;
	const char* dataType;
	void testVector();
	void testVector(StringListGenerator* slg);
	void testForwardList();
	void testForwardList(StringListGenerator* slg);
	void testSTDList();
	void testSTDList(StringListGenerator* slg);
	void testList(List<long>*);
	void testList(List<char*>*,StringListGenerator* slg);
};



#endif /* BENCHMARKS_LISTBENCHMARK_H_ */

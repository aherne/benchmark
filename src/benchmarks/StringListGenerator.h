/*
 * StringListGenerator.h
 *
 *  Created on: May 12, 2019
 *      Author: aherne
 */

#ifndef BENCHMARKS_STRINGLISTGENERATOR_H_
#define BENCHMARKS_STRINGLISTGENERATOR_H_


#include <vector>
#include <cstdlib>
#include <stdio.h>

class StringListGenerator {
public:
	StringListGenerator(const long& size) {
		for(long i=0; i<size; ++i) {
			char* temp = (char*) malloc(20*sizeof(char));
			sprintf(temp, "%ld", i);
			list.push_back(temp);
		}
	}

	~StringListGenerator() {
		for(char* item: list) {
			free(item);
		}
	}

	std::vector<char*>& getList() {
		return list;
	}

private:
	std::vector<char*> list;
};


#endif /* BENCHMARKS_STRINGLISTGENERATOR_H_ */

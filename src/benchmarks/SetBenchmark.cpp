/*
 * SetBenchmark.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: aherne
 */

#include "SetBenchmark.h"
#include <set/LinkedHashSet.h>
#include <set/HashSet.h>
#include <set/TreeSet.h>
#include <unordered_set>
#include <set>
#include <vector>

struct my_comparator
{
	bool operator()(char* const& left, char* const& right) const
	{ return strcmp( left, right )<0?true:false; }
};

struct my_hash_function{
	//BKDR hash algorithm
	int operator()(char * str)const
	{
		unsigned long hash = 5381;
		int c;

		while ((c = *str++)) {
			hash = ((hash << 5) + hash) + c;
		}

		return hash;
	}
};

void SetBenchmark::execute() {
	if(strcmp(dataType, "long")==0) {
		if(strcmp(className,"std::set")==0) {
			testSetLong();
		} else if(strcmp(className, "std::unordered_set")==0) {
			testUnorderedSetLong();
		} else if(strcmp(className, "HashSet")==0) {
			HashSet<long> hml(1000001);
			test(&hml);
		} else if(strcmp(className, "LinkedHashSet")==0) {
			LinkedHashSet<long> lhml(1000001);
			test(&lhml);
		} else if(strcmp(className, "TreeSet")==0) {
			TreeSet<long> tml;
			test(&tml);
		}
	} else {
		if(strcmp(className,"std::set")==0) {
			testSetString();
		} else if(strcmp(className, "std::unordered_set")==0) {
			testUnorderedSetString();
		} else if(strcmp(className, "HashSet")==0) {
			HashSet<char*> hms(1000001);
			test(&hms);
		} else if(strcmp(className, "LinkedHashSet")==0) {
			LinkedHashSet<char*> lhms(1000001);
			test(&lhms);
		} else if(strcmp(className, "TreeSet")==0) {
			TreeSet<char*> tms;
			test(&tms);
		}
	}
}

void SetBenchmark::testUnorderedSetLong() {
	std::size_t start, end;

	
	start = getTime();
	std::unordered_set<long> ht;
	ht.reserve(1000001);
	for(long i=0; i<1000000; ++i) {
		ht.insert(i);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);


	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht.erase(i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void SetBenchmark::testUnorderedSetString() {
	std::size_t start, end;

	std::unordered_set<char*, my_hash_function> ht;
	ht.reserve(1000001);
	// create strings
	std::vector<char*> list;
	for(long i=0; i<1000000; ++i) {
		char* temp = (char*) malloc(20*sizeof(char));
		sprintf(temp, "%ld", i);
		list.push_back(temp);
	}

	// foreach strings, add to set
	
	start = getTime();
	for(char* item: list) {
		ht.insert(item);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(char* item: list) {
		ht.erase(item);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
	// delete strings
	for(char* item: list) {
		free(item);
	}
}

void SetBenchmark::testSetLong() {
	std::size_t start, end;

	
	start = getTime();
	std::set<long> ht;
	for(long i=0; i<1000000; ++i) {
		ht.insert(i);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);


	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht.erase(i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void SetBenchmark::testSetString() {
	std::size_t start, end;

	std::set<char*, my_comparator> ht;
	// create strings
	std::vector<char*> list;
	for(long i=0; i<1000000; ++i) {
		char* temp = (char*) malloc(20*sizeof(char));
		sprintf(temp, "%ld", i);
		list.push_back(temp);
	}

	// foreach strings, add to set
	
	start = getTime();
	for(char* item: list) {
		ht.insert(item);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(char* item: list) {
		ht.erase(item);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
	// delete strings
	for(char* item: list) {
		free(item);
	}
}

void SetBenchmark::test(Set<long>* ht) {
	std::size_t start, end;

	
	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht->add(i);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht->begin(); *it!=*(ht->end()); ++(*it)) {
		(*(*it));
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);


	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht->remove(i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void SetBenchmark::test(Set<char*>* ht) {
	std::size_t start, end;

	// create strings
	std::vector<char*> list;
	for(long i=0; i<1000000; ++i) {
		char* temp = (char*) malloc(20*sizeof(char));
		sprintf(temp, "%ld", i);
		list.push_back(temp);
	}

	// foreach strings, add to set
	
	start = getTime();
	for(char* item: list) {
		ht->add(item);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht->begin(); *it!=*(ht->end()); ++(*it)) {
		(*(*it));
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(char* item: list) {
		ht->remove(item);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
	// delete strings
	for(char* item: list) {
		free(item);
	}
}


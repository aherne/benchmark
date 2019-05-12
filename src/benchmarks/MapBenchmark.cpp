/*
 * MapBenchmark.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: aherne
 */

#include "MapBenchmark.h"
#include <map/LinkedHashMap.h>
#include <map/HashMap.h>
#include <map/TreeMap.h>
#include <unordered_map>
#include <map>
#include <iostream>
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

void MapBenchmark::execute() {
	if(strcmp(dataType, "long")==0) {
		if(strcmp(className,"std::map")==0) {
			testMapLong();
		} else if(strcmp(className, "std::unordered_map")==0) {
			testUnorderedMapLong();
		} else if(strcmp(className, "HashMap")==0) {
			HashMap<long, long> hml;
			test(&hml);
		} else if(strcmp(className, "LinkedHashMap")==0) {
			LinkedHashMap<long, long> lhml;
			test(&lhml);
		} else if(strcmp(className, "TreeMap")==0) {
			TreeMap<long, long> tml;
			test(&tml);
		}
	} else {
		if(strcmp(className,"std::map")==0) {
			testMapString();
		} else if(strcmp(className, "std::unordered_map")==0) {
			testUnorderedMapString();
		} else if(strcmp(className, "HashMap")==0) {
			HashMap<char*, char*> hms;
			test(&hms);
		} else if(strcmp(className, "LinkedHashMap")==0) {
			LinkedHashMap<char*, char*> lhms;
			test(&lhms);
		} else if(strcmp(className, "TreeMap")==0) {
			TreeMap<char*, char*> tms;
			test(&tms);
		}
	}
}

void MapBenchmark::testUnorderedMapLong() {
	std::size_t start, end;

	
	start = getTime();
	std::unordered_map<long,long> ht;
	for(long i=0; i<1000000; ++i) {
		ht[i]=i;
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it).first;
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht[i];
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

void MapBenchmark::testUnorderedMapString() {
	std::size_t start, end;

	std::unordered_map<char*, char*, my_hash_function> ht;
	// create strings
	std::vector<char*> list;
	for(long i=0; i<1000000; ++i) {
		char* temp = (char*) malloc(20*sizeof(char));
		sprintf(temp, "%ld", i);
		list.push_back(temp);
	}

	// foreach strings, add to map
	
	start = getTime();
	for(char* item: list) {
		ht[item]= item;
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it).first;
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(char* item: list) {
		ht[item];
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

void MapBenchmark::testMapLong() {
	std::size_t start, end;

	
	start = getTime();
	std::map<long,long> ht;
	for(long i=0; i<1000000; ++i) {
		ht[i]=i;
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it).first;
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht[i];
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

void MapBenchmark::testMapString() {
	std::size_t start, end;

	std::map<char*, char*, my_comparator> ht;
	// create strings
	std::vector<char*> list;
	for(long i=0; i<1000000; ++i) {
		char* temp = (char*) malloc(20*sizeof(char));
		sprintf(temp, "%ld", i);
		list.push_back(temp);
	}

	// foreach strings, add to map
	
	start = getTime();
	for(char* item: list) {
		ht[item]= item;
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht.begin(); it!=ht.end(); ++it) {
		(*it).first;
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(char* item: list) {
		ht[item];
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

void MapBenchmark::test(Map<long, long>* ht) {
	std::size_t start, end;

	
	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht->set(i,i);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht->begin(); *it!=*(ht->end()); ++(*it)) {
		(*(*it)).first;
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht->get(i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);


	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht->removeKey(i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void MapBenchmark::test(Map<char*, char*>* ht) {
	std::size_t start, end;

	// create strings
	std::vector<char*> list;
	for(long i=0; i<1000000; ++i) {
		char* temp = (char*) malloc(20*sizeof(char));
		sprintf(temp, "%ld", i);
		list.push_back(temp);
	}

	// foreach strings, add to map
	
	start = getTime();
	for(char* item: list) {
		ht->set(item, item);
	}
	end = getTime();
	
	
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(auto it = ht->begin(); *it!=*(ht->end()); ++(*it)) {
		(*(*it)).first;
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(char* item: list) {
		ht->get(item);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(char* item: list) {
		ht->removeKey(item);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
	// delete strings
	for(char* item: list) {
		free(item);
	}
}

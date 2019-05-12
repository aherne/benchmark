/*
 * ListBenchmark.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: aherne
 */

#include "ListBenchmark.h"
#include <list/ArrayList.h>
#include <list/LinkedList.h>
#include <list/DoublyLinkedList.h>
#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

void ListBenchmark::execute() {
	if(strcmp(dataType, "long")==0) {
		if(strcmp(className,"std::vector")==0) {
			testVector();
		} else if(strcmp(className, "std::forward_list")==0) {
			testForwardList();
		} else if(strcmp(className, "std::list")==0) {
			testSTDList();
		} else if(strcmp(className, "ArrayList")==0) {
			ArrayList<long> al(1000001);
			testList(&al);
		} else if(strcmp(className, "LinkedList")==0) {
			LinkedList<long> ll;
			testList(&ll);
		} else if(strcmp(className, "DoublyLinkedList")==0) {
			DoublyLinkedList<long> dll;
			testList(&dll);
		}
	} else {
		StringListGenerator slg(1000000);
		if(strcmp(className,"std::vector")==0) {
			testVector(&slg);
		} else if(strcmp(className, "std::forward_list")==0) {
			testForwardList(&slg);
		} else if(strcmp(className, "std::list")==0) {
			testSTDList(&slg);
		} else if(strcmp(className, "ArrayList")==0) {
			ArrayList<char*> als(1000001);
			testList(&als, &slg);
		} else if(strcmp(className, "LinkedList")==0) {
			LinkedList<char*> lls;
			testList(&lls, &slg);
		} else if(strcmp(className, "DoublyLinkedList")==0) {
			DoublyLinkedList<char*> dlls;
			testList(&dlls, &slg);
		}
	}
}

void ListBenchmark::testVector() {
	std::size_t start, end;

	
	start = getTime();
	std::vector<long> ht;
	ht.reserve(1000001);
	for(long i=0; i<1000000; ++i) {
		ht.push_back(i);
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
		ht[i];
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(long i=999999; i>=0; --i) {
		ht.erase(ht.begin()+i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void ListBenchmark::testVector(StringListGenerator* slg) {
	std::vector<char*> items = slg->getList();
	std::size_t start, end;

	
	start = getTime();
	std::vector<char*> ht;
	ht.reserve(1000001);
	for(auto it = items.begin(); it!=items.end(); ++it) {
		ht.push_back(*it);
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
		ht[i];
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	start = getTime();
	for(long i=999999; i>=0; --i) {
		ht.erase(ht.begin()+i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void ListBenchmark::testForwardList() {
	std::size_t start, end;

	
	start = getTime();
	std::forward_list<long> ht;
	for(long i=0; i<1000000; ++i) {
		ht.push_front(i);
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
	for(long i=999999; i>=0; --i) {
		ht.erase_after( ht.before_begin() );
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void ListBenchmark::testForwardList(StringListGenerator* slg) {
	std::vector<char*> items = slg->getList();
	std::size_t start, end;

	
	start = getTime();
	std::forward_list<char*> ht;
	for(auto it = items.begin(); it!=items.end(); ++it) {
		ht.push_front(*it);
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
	for(long i=999999; i>=0; --i) {
		ht.erase_after( ht.before_begin() );
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void ListBenchmark::testSTDList() {
	std::size_t start, end;

	
	start = getTime();
	std::list<long> ht;
	for(long i=0; i<1000000; ++i) {
		ht.push_back(i);
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
	for(long i=999999; i>=0; --i) {
		ht.erase(ht.begin());
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void ListBenchmark::testSTDList(StringListGenerator* slg) {
	std::vector<char*> items = slg->getList();
	std::size_t start, end;

	
	start = getTime();
	std::list<char*> ht;
	for(auto it = items.begin(); it!=items.end(); ++it) {
		ht.push_front(*it);
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
	for(long i=999999; i>=0; --i) {
		ht.erase(ht.begin());
	}
	end = getTime();
	std::cout << "\t" <<  (end-start) << std::endl;
}

void ListBenchmark::testList(List<long>* ht) {
	std::size_t start, end;

	
	start = getTime();
	for(long i=0; i<1000000; ++i) {
		ht->addToTail(i);
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
		ht->get(i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);


	if(LinkedList<long>* v = dynamic_cast<LinkedList<long>*>(ht)) {
		start = getTime();
		for(long i=0; i<1000000; ++i) {
			v->removeIndex(0);
		}
		end = getTime();
		std::cout << "\t" <<  (end-start) << std::endl;
	} else {
		start = getTime();
		for(long i=999999; i>=0; --i) {
			ht->removeIndex(i);
		}
		end = getTime();
		std::cout << "\t" <<  (end-start) << std::endl;
	}
}

void ListBenchmark::testList(List<char*>* ht, StringListGenerator* slg) {
	std::vector<char*> items = slg->getList();
	std::size_t start, end;

	
	start = getTime();
	for(auto it = items.begin(); it!=items.end(); ++it) {
		ht->addToTail(*it);
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
		ht->get(i);
	}
	end = getTime();
	std::cout << "\t" <<  (end-start);

	if(LinkedList<char*>* v = dynamic_cast<LinkedList<char*>*>(ht)) {
		start = getTime();
		for(long i=0; i<1000000; ++i) {
			v->removeIndex(0);
		}
		end = getTime();
		std::cout << "\t" <<  (end-start) << std::endl;
	} else {
		start = getTime();
		for(long i=999999; i>=0; --i) {
			ht->removeIndex(i);
		}
		end = getTime();
		std::cout << "\t" <<  (end-start) << std::endl;
	}
}


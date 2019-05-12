# benchmark
Benchmark Library comparing C++ Abstract Data Types and Data Structures API to STL

To install and build this API into an executable able of performing benchmarks, you need to perform following console steps:

1. cd YOUR_PROJECTS_FOLDER
2. git clone https://github.com/aherne/c-data-structures-api.git
3. cd c-data-structures-api
4. make
5. cd ..
6. git clone https://github.com/aherne/benchmark.git
7. cd benchmark
8. make LIB="YOUR_PROJECTS_FOLDER/c-data-structures-api"

This has created an executable file called "benchmark" in folder YOUR_PROJECTS_FOLDER/benchmark. To run a benchmark
you need to run above file:

*./benchmark STRUCTURE CLASS DATATYPE*

Where STRUCTURE can be:

- *list*
- *map*
- *set*

And CLASS can be:

- ArrayList, std::vector, LinkedList, std::forward_list, DoublyLinkedList, std::list (if STRUCTURE = *list*)
- HashMap, std::unordered_map, TreeMap, std::map, LinkedHashMap (if STRUCTURE = *map*)
- HashSet, std::unordered_set, TreeSet, std::set, LinkedHashSet (if STRUCTURE = *set*)

And DATATYPE can be:

- *long*
- *char**

Example:

*./benchmark list ArrayList long*

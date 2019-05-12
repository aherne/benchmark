CC = g++
CFLAGS = -O2 -g3 -Wall -c
all:
	$(CC) $(CFLAGS) -I$(LIB)/src "src/benchmarks/ListBenchmark.cpp"
	$(CC) $(CFLAGS) -I$(LIB)/src "src/benchmarks/MapBenchmark.cpp"
	$(CC) $(CFLAGS) -I$(LIB)/src "src/benchmarks/SetBenchmark.cpp"
	$(CC) $(CFLAGS) -I$(LIB)/src "src/benchmark.cpp"
	$(CC) -L$(LIB) -lcds -o "benchmark" ListBenchmark.o MapBenchmark.o SetBenchmark.o  benchmark.o
clean:
	rm -rf *.o
	rm benchmark
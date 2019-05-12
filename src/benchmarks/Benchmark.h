/*
 * Benchmark.h
 *
 *  Created on: Sep 18, 2016
 *      Author: aherne
 */

#ifndef SRC_BENCHMARK_H_
#define SRC_BENCHMARK_H_

#include <sys/time.h>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static inline std::size_t getTime() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

#endif /* SRC_BENCHMARK_H_ */

// Pthreads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

// Thread function to generate sum of 0 to N
//void* sum_runner(void* arg)
//{
//	long long *limit_ptr = (long long*)arg;
//	long long limit = *limit_ptr;
//	//free(arg);
//
//	long long sum = 0;
//	for (long long i = 0; i <= limit; i++) {
//		sum += i;
//	}
//
//	// Pass back data in dynamically allocated memory
//	long long answer = sum;
//	pthread_exit(&answer);
//
//	return(NULL);
//}
//
//int main(int argc, char **argv)
//{
//	/*if (argc < 2) {
//		printf("Usage: %s <num>\n", argv[0]);
//		exit(-1);
//	}*/
//	long long limit = (long long) 2;
//
//	// Thread ID:
//	pthread_t tid;
//
//	// Create attributes
//	pthread_attr_t attr;
//	pthread_attr_init(&attr);
//
//	pthread_create(&tid, &attr, sum_runner, &limit);
//
//	// Wait until thread is done its work
//	long long *result;
//	pthread_join(tid, (void**)&result);
//	std::cout <<("Sum is %lld\n", *result);
//	free(result);
//}

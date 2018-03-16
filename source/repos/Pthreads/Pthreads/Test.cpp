// Pthreads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

//int NUM_LOOPS = 200000;
//long long sum;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//// Thread function to generate sum of 0 to N
//void* counting_thread(void* arg)
//{
//	int offset = *(int*)arg;
//	for (int i = 0; i < NUM_LOOPS; i++) {
//		//critical
//		pthread_mutex_lock(&mutex);
//		
//		sum += offset;
//
//		//end critical
//		pthread_mutex_unlock(&mutex);
//	}
//
//	pthread_exit(NULL);
//
//	return(NULL);
//}
//
//int main(void)
//{
//	pthread_t id1;
//	int offset1 = 4;
//
//	pthread_create(&id1, NULL, counting_thread, &offset1);
//
//	pthread_t id2;
//	int offset2 = -2;
//
//	pthread_create(&id2, NULL, counting_thread, &offset2);
//
//	pthread_join(id1, NULL);
//	pthread_join(id2, NULL);
//
//	std::cout << "Sum: " << sum;
//
//	std::getchar();
//	return 0;
//
//}

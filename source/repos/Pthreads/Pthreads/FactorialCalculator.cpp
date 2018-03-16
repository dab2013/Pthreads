// Pthreads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

int NUM_LOOPS = 0;
long long sum = 0, sum1 = 1,  sum2 = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* factorial_thread_1(void* arg)
{
	int offset = *(int*)arg;
	for (int i = 1; i <= offset; i++) {
		//critical
		pthread_mutex_lock(&mutex);
		
		sum1 = sum1 * i;

		//end critical
		pthread_mutex_unlock(&mutex);
	}

	pthread_exit(NULL);

	return(NULL);
}

void* factorial_thread_2(void* arg)
{
	int offset = *(int*)arg;
	for (int i = 1; i <= offset; i++) {
		//critical
		pthread_mutex_lock(&mutex);

		sum2 = sum2 * i;

		//end critical
		pthread_mutex_unlock(&mutex);
	}

	pthread_exit(NULL);

	return(NULL);
}

void* counting_thread(void* arg)
{
	int offset = *(int*)arg;
	for (int i = 0; i < NUM_LOOPS; i++) {
		//critical
		pthread_mutex_lock(&mutex);
		
		sum += offset;

		//end critical
		pthread_mutex_unlock(&mutex);
	}

	pthread_exit(NULL);

	return(NULL);
}

int main(void)
{
	pthread_t id1, id2;
	int input1 = 0, input2 = 0, userControl =0;
	while (userControl != 3) {
		std::cout << "1: Fun with Adding \n";
		std::cout << "2: Foctorial Calculator \n";
		std::cout << "3: Exit \n\n";
		std::cout << "Choose an option: ";
		std::cin >> userControl;

		if (userControl == 1) {
			std::cout << "What would you like to add together 1 through x \n";

			std::cout << "x1 = ";
			std::cin >> input1;
			std::cout << "x2 = ";
			std::cin >> input2;
			std::cout << "How many loops: ";
			std::cin >> NUM_LOOPS;

			pthread_create(&id1, NULL, counting_thread, &input1);
			pthread_create(&id2, NULL, counting_thread, &input2);

			pthread_join(id1, NULL);
			pthread_join(id2, NULL);

			std::cout << "\n\nSum: " << sum;
		}
		else if (userControl == 2) {
			system("cls");
			int userControlFactorial = 0;
			while (userControlFactorial != 4) {
				std::cout << "Due to software limitations the factorial counter can only do numbers form 0 - 20 \n\n";

				std::cout << "1: Find a factorial\n";
				std::cout << "2: Foctorial Addition \n";
				std::cout << "3: Factorial Subtration \n";
				std::cout << "4: Exit \n\n";
				std::cout << "Choose an option: ";
				std::cin >> userControlFactorial;

				if (!(userControlFactorial >= 4) && !(userControlFactorial < 1)) {
					std::cout << "What is the value of the factorial? ";
					std::cin >> input1;

					if (userControlFactorial != 1) {
						std::cout << "What is the value of the next factorial? ";
						std::cin >> input2;
					}

					pthread_create(&id1, NULL, factorial_thread_1, &input1);
					if (userControlFactorial != 1)
						pthread_create(&id2, NULL, factorial_thread_2, &input2);

					pthread_join(id1, NULL);
					if (userControlFactorial != 1)
						pthread_join(id2, NULL);

					std::cout << input1 << "! is: " << sum1 << "\n\n";
					if (userControlFactorial != 1) {
						std::cout << input2 << "! is: " << sum2 << "\n\n";
						if (userControlFactorial == 2) {
							std::cout << input1 << "! plus " << input2 << "! is: " << sum1 + sum2 << "\n\n";
						}if (userControlFactorial == 3) {
							std::cout << input1 << "! minus " << input2 << "! is: " << sum1 - sum2 << "\n\n";
						}
					}

				}


				sum1 = 1;
				sum2 = 1;

				std::cout << "\n\nPress Enter to Continue....";
				std::getchar();
				std::getchar();

				system("cls");

			}
		}

		sum = 0;

		std::cout << "\n\nPress Enter to Continue....";
		std::getchar();
		std::getchar();
		system("cls");
	}

	return 0;

}

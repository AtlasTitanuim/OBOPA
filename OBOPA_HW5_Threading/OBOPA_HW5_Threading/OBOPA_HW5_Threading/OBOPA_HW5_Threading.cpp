// OBOPA_HW5_Threading.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <queue>
#include <condition_variable>

#include "concurrent_vector.h"

int result = 0;
bool done = false;
std::queue<int> list;

std::condition_variable consumerFlag;
std::condition_variable producerFlag;
std::mutex mutex;
std::mutex mutex2;

void producer() {
	std::unique_lock<std::mutex> locker(mutex2);
	for (int i = 0; i < 500; ++i) {
		{
			std::lock_guard<std::mutex> guard(mutex);
			list.push(i);
			result++;
		}
		consumerFlag.notify_one();
		producerFlag.wait(locker);
	}
	done = true;
	consumerFlag.notify_one();
}

void consumer() {
	std::unique_lock<std::mutex> lock(mutex);
	while (!done) {
		consumerFlag.wait(lock);
		while (!list.empty()) {
			{
				std::lock_guard<std::mutex> guard(mutex2);
				list.pop();
				result--;
			}
		}
		producerFlag.notify_one();
	}
}

int main() {
	std::cout << "	Opdracht1:	" << std::endl;
	Concurrent_vector<int>* newVector = new Concurrent_vector<int>();
	for (size_t i = 0; i < 20; i++) {
		std::thread first(&Concurrent_vector<int>::insert, newVector, 10);
		std::thread second(&Concurrent_vector<int>::insert, newVector, 20);
		first.detach();
		second.detach();

		std::cout << newVector->getPos(i) << std::endl;
	}


	std::cout << "	Opdracht2:	" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		done = false;
		std::thread consumerThread(consumer);
		std::thread producerThread(producer);

		consumerThread.detach();
		producerThread.join();
		std::cout << "Result: " << result << std::endl;
	}
	return 0;
}

/*
int main() {
	Concurrent_vector<int>* newVector = new Concurrent_vector<int>();

	for (size_t i = 0; i < 20; i++) {
		std::thread first(&Concurrent_vector<int>::insert, newVector, 10);
		std::thread second(&Concurrent_vector<int>::insert, newVector, 20);
		first.detach();
		second.detach();

		std::cout << newVector->getPos(i) << std::endl;
	}

	return 0;
}
*/
#include <iostream>
#include "PriorityQueue.h"

using namespace std;
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << "\n" << endl;


	double elapsedSeconds[4];													//declare the double array for four time count
	srand(time(0));																//intialize time for calling rand function

	for (int a = 0; a < 3; a++)
	{
		int queueBaseCap = 1000000 * pow(10, a);
		int queueCap = queueBaseCap + 100000;
		PriorityQueue <int> q(queueCap);										//declare a priorityQueue for testing
		for (int i = 0; i < queueBaseCap; i++) q.push(rand() % 2000000);			//fill the Queue with random numbers between 0~200000

		clock_t startTime = clock();											//start the clock time count
		for (int i = 0; i < 100000; i++) q.pop();								//pop the 100000 value to the queue each time
		clock_t endTime = clock();												// ...stop the virtual stop watch

		elapsedSeconds[a] = (double)(endTime - startTime) / CLOCKS_PER_SEC;     //transfer clock time to second

		if (a == 0) cout << elapsedSeconds[0] << " (expected O(log(n))) for n = " << queueBaseCap << endl;
		else cout << elapsedSeconds[a] << " (expected " << (double)(elapsedSeconds[0] * log(queueBaseCap) / log(1000000)) << ") for n = " << queueBaseCap << endl;
	}

	cout << "Testing the arrangment inside priority queue: " << endl;
	PriorityQueue <int> popOrderTest(500);
	for (int i = 0; i < 502; i++) popOrderTest.push(rand() % 2000);				//declare a priority queue to test the order after push
	popOrderTest.pop();															//pop one value from the queue
	int lastPop = 0;															//declare a last pop to chech if the value in the priority queue is in order
	for (int i = 1; i < 500; i++)												//use for loop to check if the queue is from hi to lo after poping
	{
		lastPop = popOrderTest.top();											//save the previous top value
		popOrderTest.pop();														//pop the top
		assert(lastPop >= popOrderTest.top());									//compare the top and previous top
	}
	cout << endl;

	system("pause");
	return 0;
}
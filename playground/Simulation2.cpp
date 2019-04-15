#include<iostream>
#include "Queue.h"
#include<string>
#include "DynamicArray.h"
#include "PriorityQueue.h"

using namespace std;
#include<cstdlib>
#include<ctime>
#include <iomanip>
#include <cmath>

struct Customer {
	char idTag;
	int arriveTime;
};

struct Server {
	int serverNumber;
	int endTime;
	bool busy;
	Customer servingNow;
};
bool operator>(Server &a, Server &b) { return (a.endTime < b.endTime); };			//smaller endTime, higher priority
bool operator<(Server &a, Server &b) { return (a.endTime > b.endTime); };			//greater endTime, lower priority

int getRandomNumberOfArrivals(double);
int randomServiceInterval() { return rand() % 8 + 3; }

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << endl;

	
	//declare and initialize some constant value
	const int numberOfServer = 4;													//total number of servers
	const int maxQueueLength = 8;													//max length of wait queue
	const char id[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' }; //id A-Z
	const int newArrivalStop = 25;													//the time when new arrival stop

	//declare and create and assign arrays and queues to be used in the solution
	Queue<Customer> waitQueue;														//declare a wait queue
	Array<Server> servers(numberOfServer);											//declare an array for all the servers
	for (int i = 0; i < numberOfServer; i++)										//use for loop to initialize busy and serverNumber
	{
		servers[i].busy = false;
		servers[i].serverNumber = i;
	}
	PriorityQueue<Server> eventQueue(numberOfServer);								//declare a priority queue for checking end time

	//declare and initialize some variable needed to be use in the program
	srand(time(0));																	//initialize time for random function
	int numberOfArrivals = 0;														//declare an integer for the random number of arrivals
	int customerNumber = 0;															//declare an integer for total custom count
	Customer newCustomer;															//declare a newCustomer for temporarily saving the information of the new arrival

	//format ouput
	cout << "number of servers : " << servers.capacity() << "\n"//output format
		 << "customer arrival rate : 2.5 per minute, for "<< newArrivalStop << " minutes\n"
		 << "maximum queue length : " << maxQueueLength << "\n"
		 << "minimum service time : 3 minutes\n"
		 << "maximum service time : 10 minutes\n" << endl;	

	// the clock time loop
	for (int time = 0;; time++) // the clock time
	{
		//handle all services scheduled to complete at this clock time
		while (!eventQueue.empty() && eventQueue.top().endTime == time)				//while event queue is not empty and its top's end-of-service time equals the clock time 
		{
			servers[eventQueue.top().serverNumber].busy = false;					//set the top service event's server to idle
			eventQueue.pop();														//pop the just - used service event off of the event queue
		}
				
		// handle new arrivals -- can be turned away if wait queue is at maximum length
		if (time < newArrivalStop)													//if clock time is less than the time at which new arrivals stop
		{
			numberOfArrivals = getRandomNumberOfArrivals(2.5);						//get the #of of arrivals from the "Poisson process" (a whole number >= 0)
			for (int j = 0; j < numberOfArrivals; j++)								//for each new arrival
			{
				if (waitQueue.size() < maxQueueLength)//if the wait queue is NOT full
				{
					newCustomer.idTag = id[customerNumber % 26];					//assign it an ID tag(A - Z)
					newCustomer.arriveTime = time;									//set its arrival time equal to the current clock time
					waitQueue.push(newCustomer);									//push the new customer onto the wait queue
					customerNumber++;												//total custom count++
				}
			}
		}

		// for idle servers, move customer from wait queue and begin service for each server
		for (int i = 0; i < servers.capacity(); i++)
		{
			if (servers[i].busy == false && !waitQueue.empty())						//if (server is idle AND the wait queue is not empty)
			{
				servers[i].servingNow.idTag = waitQueue.front().idTag;				//copy it to the nowServing array at that server's index
				servers[i].servingNow.arriveTime = waitQueue.front().arriveTime;
				waitQueue.pop();													//remove top customer from wait queue
				servers[i].endTime = time + randomServiceInterval();				//set service end time to current clock time PLUS "random service interval"
				servers[i].busy = true;												//mark that server as busy
				eventQueue.push(servers[i]);										//push the server on to the event queue
			}
		}

		// output the summary
		cout << "\nTime: " << time << "\n"//output the current time
			<< "---------------------------------" << "\n"//output a visual prepresentation of the servers and the wait queue
			<< "server | now serving | wait queue" << "\n"
			<< "------ + ----------- + ----------" << "\n";
		for (int j = 0; j < servers.capacity(); j++)//for each server
		{
			cout << setw(4) << j //output the server's index number (zero-based)
				<< setw(8);
			if (servers[j].busy) cout << servers[j].servingNow.idTag;//show the ID of the customer being served by that server(blank if idle)
			if (j == 0)//for server 0 only, show the IDs of customers in the wait queue
			{
				cout << setw(12);
				for (int k = 0; k < waitQueue.size(); k++) cout << id[(customerNumber - waitQueue.size() + k)%26];//output format
			}
			cout << endl;
		}
		if (time > newArrivalStop && !servers[0].busy && !servers[1].busy && !servers[2].busy && !servers[3].busy) break;
		// if the end of the simulation has been reached, break

		


		PriorityQueue<Server> copy = eventQueue;
		cout << "\nserver | time for end of service\n"
			   << "------ + -----------------------" << endl;
		while(!copy.empty())
		{
			cout << setw(4) << copy.top().serverNumber << setw(4) << "|" << setw(4) << copy.top().endTime << endl;
			copy.pop();
		}			
		cout << endl;

		system("pause");// pause for the user to press ENTER
	}
	return 0;

}

int getRandomNumberOfArrivals(double averageArrivalRate)//poission distribtuion
{
	int arrivals = 0;
	double probOfnArrivals = exp(-averageArrivalRate);
	for (double randomValue = (double)rand() / RAND_MAX;
		(randomValue -= probOfnArrivals) > 0.0;
		probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
	return arrivals;
}
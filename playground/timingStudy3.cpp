#include <iostream>
#include "DynamicArray.h"

using namespace std;
#include <ctime>
#include <algorithm>
#include <cassert>

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << "\n" << endl;
	
	Array<double> elapsedSeconds(4);				//declare an array for four time count
	for (int b = 0; b < 4; b++)						//for loop to do four times
	{
		int cap = 2000*(b+1);						//declare capacity = 2000 * counter
		Array<int> i(cap);							//declare an array with capacity
		srand(time(0));								//initialize time for rand()

		for (int a = 0; a < cap; a++) i[a] = rand() % 1000;//store random number in the array

		clock_t startTime = clock();				//declare startTime = clock time
		for (int j = 0; j < cap - 1; j++)		    //bubble sort, change the array from low to high
		{
			for (int k = 0; k < cap - j - 1; k++)
			{
				if (i[k] > i[k + 1]) swap(i[k], i[k + 1]);
			}
		}
		clock_t endTime = clock();					//declare endTime = clock time
		for (int j = 1; j < cap; j++) assert(i[j - 1] <= i[j]);//use assert to check if the number in the array is from low to high
		elapsedSeconds[b] = (double)(endTime - startTime) / CLOCKS_PER_SEC;     //transform clock time to second
		if (b == 0) cout << elapsedSeconds[0] << " (expected O(n)) for n = 2000" << endl; //output the time it takes 
		else cout << elapsedSeconds[b] << " (expected " << elapsedSeconds[0] * (b + 1) * (b + 1) << ") for n = " << cap << endl;	//compare with the expected time n^2 * first time
	}
	system("pause");
	return 0;
}
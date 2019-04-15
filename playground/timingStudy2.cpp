#include <iostream>
#include <fstream>
#include <string>
#include "DynamicArray.h"
using namespace std;

#include <cstring>
#include <ctime>
#include <algorithm>

struct CourseInfor {
	string section;
	string term;
	string course;
};

struct CheckInfor {
	string section;
	string term;
};

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << "\n" << endl;

	Array<double> elapsedSeconds(4);				//declare double array for four time count
	char* token = 0;						//declare token for strtok
	char buff[1000] = " ";					//declare buff
	const char* const tab = "\t";			//declare contant tab
	string line;							//declare a string line

	for (int a = 0; a < 4; a++)
	{
		clock_t startTime = clock();			//declare startTime = clock time
		Array <CourseInfor>courseList;			//declare an array
		int i = 0;								//declare counter i
		

		ifstream input;                             //prase the text into an array of class CourseInfor
		input.open("schedule.txt");				//open the file
		if (!input.good()) cout << "File open error.";//if cannot open cout error

		getline(input, line);						//ignore the first line
		while (i < 800*(a+1))						//repeat 800*(a+1) times
		{
			getline(input, line);					//get a line of input
			strcpy(buff, line.c_str());				//copy it with cstring

			courseList[i].term = (token = strtok(buff, tab)) ? token : "";	//prase term
			courseList[i].section = (token = strtok(0, tab)) ? token : "";	//prase section
			courseList[i].course = (token = strtok(0, "-")) ? token : "";	//prase course
			i++;
		}
		input.close();								//close file

		for (int j = 0; j < i - 1; j++)				//bubble sort, change the array into alphabet order
		{
			for (int k = 0; k < i - j - 1; k++)
			{
				if (courseList[k].course > courseList[k + 1].course) swap(courseList[k], courseList[k + 1]);
			}
		}

		Array <CheckInfor>checkList(i);				//create a new a array to store the course list after cleaning up the duplicate entrys
		int checkListCapacity = 0;					//capacity here is not the capacity of the array, just how many data store in the new array
		int duplicateCount = 0;						//count the entry
		bool duplicate = false;
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < checkListCapacity; k++)
			{
				if (courseList[j].term == checkList[k].term && courseList[j].section == checkList[k].section)		// if term and section are same
				{
					duplicateCount++;																				//duplicate entry count ++ and dont save it in the new array
					duplicate = true;
					break;
				}
			}
			if (!duplicate)
			{
				checkList[checkListCapacity].section = courseList[j].section;									// store section
				checkList[checkListCapacity].term = courseList[j].term;											// store term
				checkListCapacity++;
			}
			duplicate = false;
		}
		clock_t endTime = clock();												//declare endTime = clock time
		elapsedSeconds[a] = (double)(endTime - startTime) / CLOCKS_PER_SEC;     //transform clock time to second
		if (a == 0) cout << elapsedSeconds[0] << " (expected O(n)) for n = 800" << endl; //output the time it takes 
		else cout << elapsedSeconds[a] << " (expected " << elapsedSeconds[0] * (a+1) * (a + 1) << ") for n = " << (a + 1) * 800 << endl;	//compare with the expected time n^2 * first time
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include "DynamicArray.h"
using namespace std;

#include <cstring>
#include <ctime>

using namespace std;

struct CourseInfor {
	string section;
	string term;
	string course;
};

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << "\n" << endl;

	char* token = 0;			//declare cstring pointer token
	char buff[1000] = " ";		//declare buff
	const char* const tab = "\t";	//declare constant tab

	string line;				//declare string line
	double elapsedSeconds[4];	//declare the double array for four time count
	
	
	for (int a = 0; a < 4; a++)
	{
		int i = 0;		
		ifstream input;														    //prase the text into an array of class CourseInfor
		Array <CourseInfor>courseList;											//course list 1 for 8000 times
		input.open("schedule.txt");
		clock_t startTime = clock();											//start the clock time count
		while (i < 8000 * (a+1))														//use while loop to read 8000 line
		{
			getline(input, line);												//get the line
			strcpy(buff, line.c_str());											//transform into cstring
			courseList[i].term = (token = strtok(buff, tab)) ? token : "";		//phrase the term
			courseList[i].section = (token = strtok(0, tab)) ? token : "";		//phrase the section
			courseList[i].course = (token = strtok(0, "-")) ? token : "";		//phrase the course
			i++;																// counter ++
		}
		clock_t endTime = clock();												// ...stop the virtual stop watch
		elapsedSeconds[a] = (double)(endTime - startTime) / CLOCKS_PER_SEC;     //transfer clock time to second
		if (a == 0) cout << elapsedSeconds[0] << " (expected O(n)) for n = 8000" << endl;
		else cout << elapsedSeconds[a] << " (expected " << elapsedSeconds[0] * (a+1) << ") for n = " << (a + 1) * 8000 << endl;			 
	}

	system("pause");

	return 0;
}
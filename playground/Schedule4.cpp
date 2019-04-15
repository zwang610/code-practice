#include <iostream>
#include <fstream>
#include <string>
#include "DynamicArray.h"
using namespace std;

#include <cstring>
#include <algorithm>

struct CourseInfor{
    string section;
    string term;
    string course;
};

struct CheckInfor {
	string section;
	string term;
};

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << endl;

    Array <CourseInfor>courseList;
    int i = 0;    
    char* token = 0;                                
    char buff[1000] = " ";
    const char* const tab = "\t";

    ifstream input;                              //prase the text into an array of class CourseInfor
    input.open("schedule.txt");
    if(!input.good()) cout << "File open error.";

	string line;
	getline(input, line);						//ignore the first line
	while (input.good())
    {
        getline(input, line);
        strcpy(buff, line.c_str());

        courseList[i].term = (token = strtok(buff, tab)) ? token : "";
        courseList[i].section = (token = strtok(0, tab)) ? token : "";
        courseList[i].course = (token = strtok(0, "-")) ? token : "";
        i++;
    }
    input.close();

	for (int j = 0; j < i - 1; j++)				//bubble sort, change the array into alphabet order
	{
		for (int k = 0; k < i - j - 1; k++)
		{
			if (courseList[k].course > courseList[k + 1].course) swap(courseList[k], courseList[k + 1]);
		}
	}

	cout << courseList[0].course << ", ";
	int n = 1;																								// n is the counter for while loop
	int sectionCounter = 1;
	while (n < i)																							//use a loop to output the sections, i is the capacity of the courselist array
	{
		if (courseList[n].course != courseList[n - 1].course)
		{
			cout << sectionCounter << " sections\n";
			sectionCounter = 1;
			cout << courseList[n].course << ", ";
		}
		else sectionCounter++;
		n++;
	}
	cout << sectionCounter << " sections\n";

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
	
    cout << "\nThere are " << duplicateCount << " duplicate entrys in the text." << endl;
    system("pause");
    return 0;
}

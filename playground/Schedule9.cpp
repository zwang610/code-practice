#include <iostream>
#include <fstream>
#include <string>
#include "AssociativeArray.h"
#include "DynamicArray.h"
using namespace std;

#include <cstring>
#include <algorithm>
#include <queue>
#include <queue>

struct CourseInfor {
	string section;
	string term;
	string course;
};

struct CheckInfor {
	string term;
	int capacity;
	Array <string>sectionNumber;
};

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << endl;

	AssociativeArray<string, int>course(2700);		    //create an associative array to store all the courses and counter
	AssociativeArray<string, int>subject(200);			//create an associative array to store all the subject and counter
	Array<CourseInfor>courseList(77000);                //create a array to store all the course information
	string coursename;



	//prasing
	int i = 0;                                          //initialize counter i
	char* token = 0;                                    //initialize token, which is used for take the string from the input                       
	char buff[1000] = " ";                              //initialize buff, which is the input in c-strint type
	const char* const tab = "\t";                       //set constant \t = tab

	ifstream input;                                     //declare file input
	input.open("schedule.txt");                     //open the file
	if (!input.good()) cout << "File open error.";      //if cannot open the file, output "File open error"

	string line = " ";                                  //declare a string line for getting input
	getline(input, line);	        					//ignore the first line, which is the format
	while (input.good())                                //if it is not at the end continue loop
	{
		getline(input, line);                           //getline from input file to line
		strcpy(buff, line.c_str());                     //copy line into buff
		courseList[i].term = (token = strtok(buff, tab)) ? token : "";         //take term from start of the buff to tab and store in courselist array
		courseList[i].section = (token = strtok(0, tab)) ? token : "";         //take section from this position to next tab and store in courselist array
		courseList[i].course = (token = strtok(0, tab)) ? token : "";		   //take course from this position to next tab and store in courselist array

		if (course.containsKey(courseList[i].course))course[courseList[i].course]++; //if the key already exist, the value +1
		else course[courseList[i].course] = 1;			//if the key doesn't exist, create one and set it equal = 1

		strcpy(buff, courseList[i].course.c_str());		//use buff to copy the course into cstring
		coursename = (token = strtok(buff, "-")) ? token : "";//use strtok to take subject name from the buff
		if (subject.containsKey(coursename)) subject[coursename]++;//if the subject exist, the value +1
		else subject[coursename] = 1;					//if it doesn't exist, create it and set the value = 1
		i++;                                            //counter ++
	}
	input.close();                                      //close the file after store all the information about the course



	//sort all the course keys and subject keys
	Array <string> courseKeysArray(2700);				//create an array for all course
	std::queue <string> courseKeysQueue = course.keys();//create a queue to save the keys of course
	for (int j = 0; j < course.keys().size(); j++)		//for loop repeat the time as the number of keys
	{
		courseKeysArray[j] = courseKeysQueue.front();	//save the keys into the array
		courseKeysQueue.pop();							//pop the front
	}
	for (int j = 0; j < course.keys().size() - 1; j++)	//bubble sort, change the array into alphabet order
	{
		for (int k = 0; k < course.keys().size() - j - 1; k++)
		{
			if (courseKeysArray[k] > courseKeysArray[k+1]) swap(courseKeysArray[k], courseKeysArray[k + 1]);//swap the keys, if it is larger than the next key
		}
	}

	Array <string> subjectKeysArray(200);				//create an array for all subjects
	std::queue <string> subjectKeysQueue = subject.keys();//create a queue to save the keys of subject
	for (int j = 0; j < subject.keys().size(); j++)		//for loop repeat the time as the number of keys
	{
		subjectKeysArray[j] = subjectKeysQueue.front();	//save the keys into the array
		subjectKeysQueue.pop();							//pop the front
	}
	for (int j = 0; j < subject.keys().size() - 1; j++) //bubble sort, change the array into alphabet order
	{
		for (int k = 0; k < subject.keys().size() - j - 1; k++)
		{
			if (subjectKeysArray[k] > subjectKeysArray[k + 1]) swap(subjectKeysArray[k], subjectKeysArray[k + 1]);//swap the keys, if it is larger than the next key
		}
	}





	//cout the count of all courses and subjects
	int courseKeyCounter = 0;							//courseKeyCounter to compare with total number of the course
	for (int j = 0; j < subject.keys().size() - 1; j++) //use for loop to output all the keys before the final key
	{
		cout << subjectKeysArray[j] << ", " << subject[subjectKeysArray[j]] << " course(s)\n";//cout subject
		while (courseKeysArray[courseKeyCounter] < subjectKeysArray[j + 1])//use while loop to cout all the courses under the subject, terminate condition is when coursename is greater than the next subject name
		{
			cout << "    " << courseKeysArray[courseKeyCounter] << ", " << course[courseKeysArray[courseKeyCounter]] << " sections\n";
			courseKeyCounter++;
		}
	}
	cout << subjectKeysArray[subject.keys().size() - 1] << ", " << subject[subjectKeysArray[subject.keys().size() - 1]] << " course(s)\n";//cout the final subject
	while (courseKeyCounter < course.keys().size())		//use while loop to cout all the courses under the final subject, terminatie condition is when the courseKeyCounter is equal to the total number of the course 	
	{
		cout << "    " << courseKeysArray[courseKeyCounter] << ", " << course[courseKeysArray[courseKeyCounter]] << " sections\n";
		courseKeyCounter++;
	}
	

	
	//check duplicate entry
	Array<CheckInfor>terms(48);                         //declare a  array named terms
	int usedterms = 0;                                  //declare an variable to see how many terms have been used
	int duplicateCount = 0;

	for (int j = 0; j < i; j++)                         //since the loop before, i = the number of courses, use for loop to check duplicate entry
	{
		int k = 0;                                      //use counter k to track and compare the term
		while (k < usedterms)                           //if counter k < usedterm continue loop to check if already have the same term
		{
			if (courseList[j].term == terms[k].term)    //if term already exist
			{
				int l = 0;                              //use counter l to track and compare the section number
				while (l < terms[k].capacity)            //if counter l < capacity continue loop to check if already have the same section number
				{
					if (terms[k].sectionNumber[l] == courseList[j].section) break; //if it have same section number break, and when it break l != capacity
					l++;                                //counter l++ to check the next section number
				}
				if (l != terms[k].capacity) duplicateCount++;    //l != capacity means while loop broke, which mean it is duplicate entry, duplicateCount++
				else                                    //if it is not a duplicate entry
				{
					terms[k].sectionNumber[terms[k].capacity] = courseList[j].section;  //store the section number into the array
					terms[k].capacity++;                //capacity ++
				}
				break;                                  //if courseList[j].term is an already used term, then break, and when it break k != usedterms
			}
			k++;                                        //counter k++ to check the next usedterm
		}
		if (k == usedterms)                             //if while loop doesn't break, it means courseList[j].term hasn't been used
		{
			terms[usedterms].term = courseList[j].term; //store a new term in terms array
			terms[usedterms].capacity = 1;
			terms[usedterms].sectionNumber[0] = courseList[j].section;
			usedterms++;                                //usedterms ++
		}
	}

	
	cout << "\nThere is " << duplicateCount << " duplicate entrys." << endl;

	system("pause");
	return 0;
}

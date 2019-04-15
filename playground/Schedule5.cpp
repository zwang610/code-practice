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
};

struct CheckInfor {
	string term;
    int capacity;
    Array <string>sectionNumber;
};

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << endl;

    Array<CourseInfor>courseList(77000);                //create a  array to store all the course information
    int i = 0;                                          //initialize counter i
    char* token = 0;                                    //initialize token, which is used for take the string from the input                       
    char buff[1000] = " ";                              //initialize buff, which is the input in c-strint type
    const char* const tab = "\t";                       //set constant \t = tab

    ifstream input;                                     //declare file input
    input.open("schedule.txt");                              //open the file
    if(!input.good()) cout << "File open error.";       //if cannot open the file, output "File open error"

	string line = " ";                                  //declare a string line for getting input
	getline(input, line);	        					//ignore the first line, which is the format
	while (input.good())                                //if it is not at the end continue loop
    {
        getline(input, line);                           //getline from input file to line
        strcpy(buff, line.c_str());                     //copy line into buff

        courseList[i].term = (token = strtok(buff, tab)) ? token : "";         //take term from start of the buff to tab and store in courselist array
        courseList[i].section = (token = strtok(0, tab)) ? token : "";         //take section from this position to next tab and store in courselist array
        i++;                                            //counter ++
    }
    input.close();                                      //close the file after store all the information about the course

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
                while(l < terms[k].capacity)            //if counter l < capacity continue loop to check if already have the same section number
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

    cout << "\nThere is " << duplicateCount << " duplicate entrys.";
    return 0;
}

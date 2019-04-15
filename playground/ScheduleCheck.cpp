#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include <cstring>
#include <algorithm>
#include <map>
#include <utility>

struct CourseInfor {
	string section;
	string term;
	string course;
};

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << endl;

	const char* const tab = "\t";                       //set constant \t = tab

	CourseInfor aCourse;								//declare aCourse for prasing
	char* token = 0;                                    //initialize token, which is used for take the string from the input                       
	char buff[1000] = " ";                              //initialize buff, which is the input in c-strint type	
	string line = " ";                                  //declare a string line for getting input
	
	std::map<std::pair<string, string>, string> dvcSchedule;//declare a map dvcSchedule, key is a pair of term and section, value is string of course
	
	std::map<std::pair<string, string>, std::pair<string, string> > errorEntry;//declare an map for error Entry, key is a pair of term and section, value is a pair of two course

	//prase the txt file, and find the error entry
	ifstream input;                                     //declare file input
	input.open("schedule.txt");                     //open the file
	if (!input.good()) cout << "File open error.";      //if cannot open the file, output "File open error"

	getline(input, line);	        					//ignore the first line, which is the format
	while (input.good())                                //if it is not at the end continue loop
	{
		getline(input, line);                           //getline from input file to line
		strcpy(buff, line.c_str());                     //copy line into buff

		aCourse.term = (token = strtok(buff, tab)) ? token : "";//take season from start of the buff to tab and store in courselist array
		aCourse.section = (token = strtok(0, tab)) ? token : "";//take section from this position to next tab and store in courselist array
		aCourse.course = (token = strtok(0, tab)) ? token : "";//take course from this position to next tab and store in courselist array
		
		std::pair<string, string> termSection = make_pair(aCourse.term, aCourse.section);
		if (dvcSchedule.find(termSection) == dvcSchedule.end())//the pair of term and section can not be found in the map
			dvcSchedule[termSection] = aCourse.course;//set the pair as a new index and the value inside to the course name
		else if (dvcSchedule[termSection] != aCourse.course)//if in the map of term with index aCourse.term already have the same section number
		{
			errorEntry[termSection] = make_pair(aCourse.course, dvcSchedule[termSection]);
		}		
	}
	input.close();                                      //close the file after store all the information about the course

	
	
	//output the error
	if (errorEntry.size() > 0)                          //if the map has element, which means there is error entry
	{
		cout << "There are " << errorEntry.size() << " term - section pairs there are with multiple courses associated with them:\n" << endl;//cout how many error there are in the in the txt 

		for (std::map<std::pair<string, string>, std::pair<string, string> >::iterator it = errorEntry.begin(); it != errorEntry.end(); ++it)//use for loop to output all the term, section and courses names of the error
			cout << "\nMultiple entry in " << it->first.first << " section " << it->first.second << ": \n       " << it->second.first << " and " << it->second.second << endl;
	}
	else
		cout << "There are no duplicate entry in dvc schedule" << endl;

	return 0;
}

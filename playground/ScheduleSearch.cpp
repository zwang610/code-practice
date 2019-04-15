#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include <cstring>
#include <map>
#include <set>

struct CourseInfor {
	string season;
	string year;
	string section;
	string course;
};

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << endl;

	CourseInfor aCourse;								//declare aCourse for prasing
	char* token = 0;                                    //initialize token, which is used for take the string from the input                       
	char buff[1000] = " ";                              //initialize buff, which is the input in c-strint type
	const char* const tab = "\t";                       //set constant \t = tab
	std::map<string, std::set<string> > dvcSchedule;	//declare a map dvcSchedule, key is a string of section, value is a set of integer of term after transform
	string line = " ";                                  //declare a string line for getting input
	
	//prase the txt file
	ifstream input;                                     //declare file input
	input.open("schedule.txt");                     //open the file
	if (!input.good()) cout << "File open error.";      //if cannot open the file, output "File open error"

	
	getline(input, line);	        					//ignore the first line, which is the format
	while (input.good())                                //if it is not at the end continue loop
	{
		getline(input, line);                           //getline from input file to line
		strcpy(buff, line.c_str());                     //copy line into buff

		aCourse.season = (token = strtok(buff, " ")) ? token : "";//take season from start of the buff to tab and store in courselist array
		aCourse.year = (token = strtok(0, tab)) ? token : "";//take year from this position to next tab and store in courselist array
		aCourse.section = (token = strtok(0, tab)) ? token : "";//take section from this position to next tab and store in courselist array
		aCourse.course = (token = strtok(0, tab)) ? token : "";//take course from this position to next tab and store in courselist array

		if (aCourse.season == "Spring") aCourse.year = aCourse.year + "1";//if season is Spring add 1 at the end of the string year
		else if (aCourse.season == "Summer") aCourse.year = aCourse.year + "2";//if season is Summer add 2 at the end of the string year
		else if (aCourse.season == "Fall") aCourse.year = aCourse.year + "3";//if season is Fall add 3 at the end of the string year
		dvcSchedule[aCourse.course].insert(aCourse.year);//insert the semester into the set of the course
	}
	input.close();                                      //close the file after store all the information about the course

	while (true)
	{
		cout << "\nEnter the course you want to find, X to exist:";//get user input message
		getline(cin, line);								//get a user input of the course they want to find
		if (line == "X" || line == "x") break;			//if the input is X or x break
		if (dvcSchedule.find(line) != dvcSchedule.end())//if the input is existed key
		{
			std::string term = *dvcSchedule[line].rbegin();//delare a string equal to the largest value in the set
			if (term[4] == '1')						    //if the end of the term is 1
			{
				term[4] = ' ';							//replace it with space and add the spring at the end
				term = term + "Spring";
			}
			else if (term[4] == '2')					//if the end of the term is 2
			{
				term[4] = ' ';							//replace it with space and add the summer at the end
				term = term + "Summer";
			}
			else if (term[4] == '3')					//if the end of the term is 3
			{
				term[4] = ' ';							//replace it with space and add the fall at the end
				term = term + "Fall";
			}
			cout << "the last term of this course is " << term << endl;//after change the term with a normal one, output it
		}
		else cout << line << " could not be found as far back as the year 2000" << endl;//else, if not find in the map, cout could not be found
	}


	system("pause");
	return 0;
}

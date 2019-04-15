#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;
#include <cassert>

int main(){
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << endl;

	Queue <int> i;
	cout << "\n         Testing Interger Queue\n";              //Testing Interger Queue
	cout << "1)Testing Queue Size Getter Function:\n";          //size should be 0
	assert(0 == i.size());
	cout << "\n2)Testing Queue Push Function:\n";
	i.push(5);                                                  //push one value to the Queue
	i.push(10);                                                 //push another value to the Queue
	assert(i.size() == 2);                                      //size should be 2 now
	cout << "\n3)Testing Queue front Function:\n";
	cout << "  EXPECT: 5\n";                                    //the value at the front should be 5
	cout << "  ACTUAL: " << i.front() << endl;
	assert(i.front() == 5);                                     //use assert to check the value
	cout << "\n4)Testing Queue back Function:\n";
	cout << "  EXPECT: 10\n";                                   //the value at the back should be 10
	cout << "  ACTUAL: " << i.back() << endl;
	assert(i.back() == 10);                                     //use assert to check the value
	cout << "\n5)Testing Queue Pop Function:\n";
	i.pop();                                                    //pop the value at the top
	assert(i.size() == 1);                                      //size decreased
	cout << "\n6)Testing Queue Empty Function:\n";
	assert(i.empty() == false);                                 //size = 1, should return false
	cout << "\n7)Testing Queue Copy Constructor:\n";
	Queue <int> i1 = i;                                         //create a Queue make it equal to i
	while (i.size() > 0)                                        //use while loop to check if all the value inside is the same
	{
		assert(i1.front() == i.front());
		i.pop();
		i1.pop();
	}
	cout << "\n8)Testing Queue Assignment Operater:\n";
	Queue <int> i2;                                          //create a new Queue with different capacity
	i2 = i;                                                     //make it equal to i
	while (i.size() > 0)                                        //use while loop to check if all the value inside is the same
	{
		assert(i1.front() == i.front());
		i.pop();
		i1.pop();
	}
	cout << "\n9)Testing Queue Clear Function:\n";
	i.clear();                                                  //clear the Queue
	assert(i.size() == 0);                                      //check if the size now equal to 0

	Queue <string>s;
	cout << "\n         Testing String Queue\n";
	cout << "1)Testing Queue Size Getter Function:\n";          //Testing String Queue
	assert(0 == s.size());                                      //size should be 0
	cout << "\n2)Testing Queue Push Function:\n";
	s.push("ABC");                                              //push one value to the Queue
	s.push("abc");                                              //push another value to the Queue          
	assert(s.size() == 2);                                      //size should be 2 now
	cout << "\n3)Testing Queue front Function:\n";
	cout << "  EXPECT: ABC\n";                                  //the value at the front should be ABC
	cout << "  ACTUAL: " << s.front() << endl;
	assert(s.front() == "ABC");									//use assert to check the value
	cout << "\n4)Testing Queue back Function:\n";
	cout << "  EXPECT: abc\n";                                  //the value at the back should be abc
	cout << "  ACTUAL: " << s.back() << endl;
	assert(s.back() == "abc");                                  //use assert to check the value
	cout << "\n5)Testing Queue Pop Function:\n";
	s.pop();                                                    //pop the value at the top
	assert(s.size() == 1);                                     //size decreased
	cout << "\n6)Testing Queue Empty Function:\n";
	assert(s.empty() == false);                                //size = 1, should return false
	cout << "\n7)Testing Queue Copy Constructor:\n";
	Queue <string> s1 = s;                                      //create a Queue make it equal to i
	while (s.size() > 0)                                        //use while loop to check if all the value inside is the same
	{
		assert(s1.back() == s.back());
		s.pop();
		s1.pop();
	}
	cout << "\n8)Testing Queue Assignment Operater:\n";
	Queue <string> s2;                                      //create a new stack with different capacity
	s2 = s;                                                     //make it equal to i
	while (s.size() > 0)                                        //use while loop to check if all the value inside is the same
	{
		assert(s1.back() == s.back());
		s.pop();
		s1.pop();
	}
	cout << "\n9)Testing Queue Clear Function:\n";
	s.clear();                                                  //clear the Queue
	assert(i.size() == 0);                                     //check if the size now equal to 0
	return 0;
}
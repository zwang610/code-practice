#include <algorithm>
#include <iostream>
#include <string>
#include "AssociativeArray.h"
using namespace std;

#include <cassert>
#include <queue>

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << endl;

	cout << "\n      Testing Integer Array With String Key\n";
	cout << "\n1)Testing constructor\n";				//constructor test
	AssociativeArray <string, int>i(10);                
	cout << "\n2)Testing [] setter\n";                  //square bracket setter test
	i["abcdef"]= 50;									
	i["john"] = 30;							
	cout << "\n3)Testing the [] getter\n";              //square bracket getter test
	cout << "  EXPECT: 50\n";							                           
	cout << "  ACTUAL: " << i["abcdef"] << endl;
	assert(50 == i["abcdef"]);
    cout << "\n4)Testing object copy\n";                //copy constructor test
    AssociativeArray  <string, int>iTest1 = i;
	assert(iTest1["abcdef"] == i["abcdef"]);
	assert(iTest1["john"] == i["john"]);
	cout << "\n5)Testing object assignment\n";          //assignment operator test
	AssociativeArray  <string, int>iTest2;
	iTest2 = i;
	assert(iTest2["abcdef"] == i["abcdef"]);
	assert(iTest2["john"] == i["john"]);
	cout << "\n6)Testing contain key getter\n";         //contain key getter test
	assert(i.containsKey("abcdef") == true);
	cout << "\n7)Testing delete key setter\n";			//delete key setter test
	i.deleteKey("abcdef");
	assert(i.containsKey("abcdef") == false);
	cout << "\n8)Testing size getter\n";				//size getter test
	assert(i.size()== 1);
	cout << "\n9)Testing clear setter\n";				//clear setter test
	i.clear();
	assert(i.size() == 0);
	cout << "\n10)Testing key getter\n";				//key getter test
	assert(true == i.keys().empty());
	

	cout << "\n      Testing String Array With String Key\n";
	cout << "\n1)Testing constructor\n";				//constructor test
	AssociativeArray <string, string>s(10);
	cout << "\n2)Testing [] setter\n";                  //square bracket setter test
	s["abcdef"] = "abc";								
	s["john"] = "joh";
	cout << "\n3)Testing the [] getter\n";              //square bracket getter test
	cout << "  EXPECT: abc\n";
	cout << "  ACTUAL: " << s["abcdef"] << endl;
	assert("abc" == s["abcdef"]);
	cout << "\n4)Testing object copy\n";                //copy constructor test
	AssociativeArray  <string, string>sTest1 = s;
	assert(sTest1["abcdef"] == s["abcdef"]);
	assert(sTest1["john"] == s["john"]);
	cout << "\n5)Testing object assignment\n";          //assignment operator test
	AssociativeArray  <string, string>sTest2;
	sTest2 = s;
	assert(sTest2["abcdef"] == s["abcdef"]);
	assert(sTest2["john"] == s["john"]);
	cout << "\n6)Testing contain key getter\n";         //contain key getter test
	assert(s.containsKey("abcdef") == true);
	cout << "\n7)Testing delete key setter\n";			//delete key setter test
	s.deleteKey("abcdef");
	assert(s.containsKey("abcdef") == false);
	cout << "\n8)Testing size getter\n";				//size getter test
	assert(s.size() == 1);
	cout << "\n9)Testing clear setter\n";				//clear setter test
	s.clear();
	assert(s.size() == 0);
	cout << "\n10)Testing key getter\n";					//key getter test
	assert(true == s.keys().empty());
	system("pause");
	return 0;
}
#include <iostream>
#include "Stack.h"
#include <iostream>
#include "Stack.h"
using namespace std;

#include <cassert>

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << endl;
    
    Stack <int>i(10);
    cout << "\n         Testing Interger Stack\n";              //Testing Interger Stack
    cout <<"1)Testing Stack Size Getter Function:\n";           //size should be 0
    assert (0 == i.size());
    cout <<"\n2)Testing Stack Push Function:\n";
    i.push(5);                                                  //push one value to the stack
    i.push(10);                                                 //push another value to the stack
    assert (i.size() == 2);                                     //size should be 2 now
    cout <<"\n3)Testing Stack Peek Function:\n";
    cout <<"  EXPECT: 10\n";                                    //the value at the top should be 10
    cout <<"  ACTUAL: " << i.peek() << endl;
    assert (i.peek() == 10);                                    //use assert to check the value
    cout <<"\n4)Testing Stack Pop Function:\n";
    i.pop();                                                    //pop the value at the top
    assert (i.size() == 1);                                     //size decreased
    cout <<"\n5)Testing Stack Empty Function:\n";
    assert (i.empty() == false);                                //size = 1, should return false
    cout <<"\n6)Testing Stack Copy Constructor:\n";
    Stack <int> i1 = i;                                         //create a stack make it equal to i
    while (i.size() > 0)                                        //use while loop to check if all the value inside is the same
    {
        assert (i1.peek() == i.peek());
        i.pop();
        i1.pop();
    }
    cout <<"\n7)Testing Stack Assignment Operater:\n";         
    Stack <int> i2(20);                                         //create a new stack with different capacity
    i2 = i;                                                     //make it equal to i
    while (i.size() > 0)                                        //use while loop to check if all the value inside is the same
    {
        assert (i1.peek() == i.peek());
        i.pop();
        i1.pop();
    }
    cout <<"\n8)Testing Stack Clear Function:\n";
    i.clear();                                                  //clear the stack
    assert (i.size() == 0);                                     //check if the size now equal to 0
    
    Stack <string>s(10);                                        
    cout << "\n         Testing String Stack\n";                
    cout <<"1)Testing Stack Size Getter Function:\n";           //Testing String Stack
    assert (0 == s.size());                                     //size should be 0
    cout <<"\n2)Testing Stack Push Function:\n";                
    s.push("ABC");                                              //push one value to the stack
    s.push("abc");                                              //push another value to the stack          
    assert (s.size() == 2);                                     //size should be 2 now
    cout <<"\n3)Testing Stack Peek Function:\n";
    cout <<"  EXPECT: abc\n";                                   //the value at the top should be 10
    cout <<"  ACTUAL: " << s.() << endl;
    assert (s.peek() == "abc");                                 //use assert to check the value
    cout <<"\n4)Testing Stack Pop Function:\n";
    s.pop();                                                    //pop the value at the top
    assert (s.size() == 1);                                     //size decreased
    cout <<"\n5)Testing Stack Empty Function:\n";
    assert (s.empty() == false);                                //size = 1, should return false
    cout <<"\n6)Testing Stack Copy Constructor:\n";
    Stack <string> s1 = s;                                      //create a stack make it equal to i
    while (s.size() > 0)                                        //use while loop to check if all the value inside is the same
    {
        assert (s1.peek() == s.peek());
        s.pop();
        s1.pop();
    }
    cout <<"\n7)Testing Stack Assignment Operater:\n";
    Stack <string> s2(20);                                      //create a new stack with different capacity
    s2 = s;                                                     //make it equal to i
    while (s.size() > 0)                                        //use while loop to check if all the value inside is the same
    {
        assert (s1.peek() == s.peek());
        s.pop();
        s1.pop();
    }
    cout <<"\n8)Testing Stack Clear Function:\n";
    s.clear();                                                  //clear the stack
    assert (i.size() == 0);                                     //check if the size now equal to 0
}


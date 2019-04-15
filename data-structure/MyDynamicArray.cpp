#include <algorithm>
#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

#include <cstdlib>

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << "\n" << endl;
    
    string input;
    string strindex;
    Array <float>a;                                             //delare an dynamic array to store number
    Array <int>index;                                           //delare an dynamic array to trace the input index
    Array <float>number;                                        //delare an dynamic array to trace the input number
    int i = 0;                                                  //delare a counter to count how many valid input

    while (true)
    {
        cout << "Input an index and a value [Q to quit]:" ;
        getline(cin, input);                                    //get user input

        if (input == "q" || input == "Q") break;                //if input is q, quit
        
        bool test = true;
        int n = 0;
        while (!isspace(input.c_str()[n]))
        {
            if (!isdigit(input.c_str()[n]))                     //if there is any character not digit before space, test fail
            {
                test = false;
                break;
            }
            n++;
        }

        if (test == true)
        {
            string buff(input, input.find(' ', 0), 7);          //use buff to store number
            index[i] = atoi(input.c_str());                     //save index
            number[i] = atof(buff.c_str());                     //save number
            a[index[i]] = number[i];                            //save number in array
            i++; 
        }                  
    }

    cout << "You stored this many values: " << i << endl;
    cout << "The index-value pairs are: \n\n";
    for (int n = 0 ; n < i ; n++)
    cout << index[n] << "->" << number[n] << "\n";
    cout << "\n";
    
    while (true)
    {
        cout << "Input an index for me to look up [Q to quit]:";
        getline(cin, input);
        if (input == "q" || input == "Q") break;

        bool test = true;
        int n = 0;
        while (n < input.length())
        {
            if (!isdigit(input.c_str()[n]))                     //if there is any character not digit test fail
            {
                test = false;
                break;
            }
            n++;
        }

        bool find = false;                                      //intialize find as false
        for (int n = 0 ; n < i ; n++)
        {
            if (index[n] == atoi(input.c_str())) 
            {
                cout << "Found it -- the value stored at " << index[n] << " is "<< a[index[n]] << "\n"; // if find output Found it
                find = true;
            }
        }
        if (find == false) cout << "I didn't find it\n";        //if not find, output I didn't find it
    }
    cout << endl;    
    
    return 0;
}
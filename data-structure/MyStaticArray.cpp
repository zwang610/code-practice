#include <iostream>
#include <string>
#include "StaticArray.h"
using namespace std;

#include <cstdlib>

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << "\n" << endl;
    
    string input;    
    StaticArray <float, 100>a;
    StaticArray <int, 100>index;
    StaticArray <float, 100>number;
    int i = 0;
    
    while (true)
    {
        cout << "Input an index and a value [Q to quit]:" ;
        getline(cin, input);
        
        if (input == "q" || input == "Q") break;
        index[i] = atoi(input.c_str());
        if (index[i] > 0 && index[i] < 100)
        {
            string buff(input, input.find(' ', 0), 7);
            number[i] = atof(buff.c_str());
            a[index[i]] = number[i]; 
            i++;
        }          
    }

    cout << "You stored this many values: " << i << endl;
    cout << "The index-value pairs are: \n\n";
    for (int n = 0 ; n < i ; n++) cout << index[n] << "->" << number[n] << "\n";
    cout << "\n";
    
    while (true)
    {
        cout << "Input an index for me to look up [Q to quit]:";
        getline(cin, input);
        if (input == "q" || input == "Q") break;

        bool find = false;
        for (int n = 0 ; n < i ; n++)
        {
            if (index[n] == atoi(input.c_str())) 
            {
                cout << "Found it -- the value stored at " << index[n] << " is "<< a[index[n]] << "\n";
                find = true;
            }
        }
        if (find == false) cout << "I didn't find it\n";
    }
    cout << endl;    
    
    return 0;
}
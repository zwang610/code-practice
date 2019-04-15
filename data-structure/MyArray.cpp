#include <iostream>
#include <string>
#include "StaticArray.h"
using namespace std;

#include <cstdlib>

class Array{
    private: 
    int value[100];
    int dummy;
    
    public:
    int& operator[](int);
    int operator[](int) const;
    int capacity() const;
};

int& Array::operator[](int index){
    if (index < 0 || index > 100) return dummy;
    return value[index];
}

int Array::operator[](int index) const {
    if (index < 0 || index > 100) return 0;
    return value[index];
}

int Array::capacity() const {return 100;}

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << "\n" << endl;
    
    string input;    
    Array a;
    Array index;
    Array number;
    int i = 0;
    
    while (true)
    {
        cout << "Input an index and a value [Q to quit]:" ;
        getline(cin, input);
        
        if (input == "q" || input == "Q") break;
        index[i] = atoi(input.c_str());
        if (index[i] > 0 && index[i] < 100)
        {
            string data(input, input.find(' ', 0), 7);
            number[i] = atoi(data.c_str());
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
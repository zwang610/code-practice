#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include <cassert>

class Array{
    private: 
    int value[100];
    int dummy;
    
    public:
    Array();
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

Array::Array(){
    for (int n = 0; n < 100; n++)
    value[n] = 0;
}

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << endl;
    Array a;
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << a.capacity( ) << endl;
    assert(100 == a.capacity( ));
    cout << "\nTesting Array::Array\n";
    for (int n = 0; n < a.capacity( ); n++)
    assert(a[n] == 0);
    cout << "\nTesting Array::operator[] setter\n";
    a[6] = 5;
    cout << "EXPECTED: a[6] = 5\n";
    cout << "ACTUAL: " << a[6] << endl;
    assert(5 == a[6]);
    cout << "\nTesting the Array::operator[ ] getter\n";
    const Array b = a;
    for (int n = 0; n < 10; n++)
    assert(b[n] == a[n]);
}
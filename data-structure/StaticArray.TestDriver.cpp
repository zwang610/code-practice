#include <iostream>
#include <string>
#include "StaticArray.h"
using namespace std;

#include <cassert>

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << endl;
    
    StaticArray <int, 10>i;
    cout << "\n      Testing Integer Array\n";    
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 10\n";
    cout << "ACTUAL: " << i.capacity( ) << endl;
    assert(10 == i.capacity( ));
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int n = 0; n < i.capacity( ); n++)
    assert(i[n] == 0);
    cout << "\nTesting StaticArray::operator[] setter\n";
    i[6] = 5;
    cout << "EXPECTED: i[6] = 5\n";
    cout << "ACTUAL: " << i[6] << endl;
    assert(5 == i[6]);
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray <int, 10>iTest = i;
    for (int n = 0; n < 10; n++)
    assert(iTest[n] == i[n]);
    
    
    StaticArray <double, 11>d;
    cout << "\n      Testing Double Array\n";    
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 10\n";
    cout << "ACTUAL: " << d.capacity( ) << endl;
    assert(11 == d.capacity( ));
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int n = 0; n < d.capacity( ); n++)
    assert(d[n] == 0);
    cout << "\nTesting StaticArray::operator[] setter\n";
    d[6] = 5.1;
    cout << "EXPECTED: d[6] = 5.1\n";
    cout << "ACTUAL: " << d[6] << endl;
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray <double, 11>dTest = d;
    for (int n = 0; n < 11; n++)
    assert(dTest[n] == d[n]);

    StaticArray <char, 12>c;
    cout << "\n      Testing Character Array\n";    
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 12\n";
    cout << "ACTUAL: " << c.capacity( ) << endl;
    assert(12 == c.capacity( ));
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int n = 0; n < c.capacity( ); n++)
    assert(c[n] == 0);
    cout << "\nTesting StaticArray::operator[] setter\n";
    c[6] = 'A';
    cout << "EXPECTED: d[6] = A\n";
    cout << "ACTUAL: " << c[6] << endl;
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray <char, 12>cTest = c;
    for (int n = 0; n < 12; n++)
    assert(cTest[n] == c[n]);
    
    StaticArray <string, 13>s;
    cout << "\n      Testing String Array\n";    
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 13\n";
    cout << "ACTUAL: " << s.capacity( ) << endl;
    assert(13 == s.capacity( ));
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int n = 0; n < s.capacity( ); n++)
    assert(s[n] == "");
    cout << "\nTesting StaticArray::operator[] setter\n";
    s[6] = "Joey";
    cout << "EXPECTED: s[6] = Joey\n";
    cout << "ACTUAL: " << c[6] << endl;
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray <string, 13>strTest = s;
    for (int n = 0; n < 12; n++)
    assert(strTest[n] == s[n]);

    return 0;
}
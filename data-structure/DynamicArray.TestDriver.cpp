#include <algorithm>
#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

#include <cassert>

int main(){
    cout << "Programmer: Zheyi Wang\n";
    cout << "File: " << __FILE__ << endl;
    
    Array <int>i(10);                                   // integer array test
    cout << "\n      Testing Integer Array\n";    
    cout << "\nTesting Array::capacity\n";              // capacity getter test
    cout << "EXPECTED: 10\n";
    cout << "ACTUAL: " << i.capacity( ) << endl;
    assert(10 == i.capacity( ));
    cout << "\nTesting constructor\n";                  // constructor test
    for (int n = 0; n < i.capacity( ); n++)
    assert(i[n] == 0);
    cout << "\nTesting [] setter\n";                    // square bracket setter
    i[6] = 5;
    cout << "EXPECTED: i[6] = 5\n";
    cout << "ACTUAL: " << i[6] << endl;
    assert(5 == i[6]);
    cout << "\nTesting the [ ] getter\n";               //square bracket getter
    const Array <int>iTest = i;
    for (int n = 0; n < 10; n++)
    assert(iTest[n] == i[n]);
    cout << "\nTesting object copy\n";                  //copy constructor
    Array<int> c1 = i; 
    assert(c1.capacity() == i.capacity()); 
    for (int n = 0; n < i.capacity(); n++)
    assert(c1[n] == i[n]);
    cout << "\nTesting object assignment\n";            //assignment operator
    Array<int> a1;
    a1 = i; 
    assert(a1.capacity() == i.capacity()); 
    for (int n = 0; n < i.capacity(); n++)
    assert(a1[n] == i[n]);
    
    
    Array <double>d(11);                                //double array test with same things
    cout << "\n      Testing Double Array\n";    
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 10\n";
    cout << "ACTUAL: " << d.capacity( ) << endl;
    assert(11 == d.capacity( ));
    cout << "\nTesting constructor\n";
    for (int n = 0; n < d.capacity( ); n++)
    assert(d[n] == 0);
    cout << "\nTesting [] setter\n";
    d[6] = 5.1;
    cout << "EXPECTED: d[6] = 5.1\n";
    cout << "ACTUAL: " << d[6] << endl;
    cout << "\nTesting the [ ] getter\n";
    const Array <double>dTest = d;
    for (int n = 0; n < 11; n++)
    assert(dTest[n] == d[n]);
    cout << "\nTesting object copy\n";
    Array<double> c2 = d; 
    assert(c2.capacity() == d.capacity()); 
    for (int n = 0; n < d.capacity(); n++)
    assert(c2[n] == d[n]);
    cout << "\nTesting object assignment\n"; 
    Array<double> a2;
    a2 = d; 
    assert(a2.capacity() == d.capacity()); 
    for (int n = 0; n < d.capacity(); n++)
    assert(a2[n] == d[n]);

    Array <char>c(12);                                  //character array test
    cout << "\n      Testing Character Array\n";    
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 12\n";
    cout << "ACTUAL: " << c.capacity( ) << endl;
    assert(12 == c.capacity( ));
    cout << "\nTesting constructor\n";
    for (int n = 0; n < c.capacity( ); n++)
    assert(c[n] == 0);
    cout << "\nTesting [] setter\n";
    c[6] = 'A';
    cout << "EXPECTED: c[6] = A\n";
    cout << "ACTUAL: " << c[6] << endl;
    cout << "\nTesting the [ ] getter\n";
    const Array <char>cTest = c;
    for (int n = 0; n < 12; n++)
    assert(cTest[n] == c[n]);
    cout << "\nTesting object copy\n";
    Array<char> c3 = c; 
    assert(c3.capacity() == c.capacity()); 
    for (int n = 0; n < c.capacity(); n++)
    assert(c3[n] == c[n]);
    cout << "\nTesting object assignment\n"; 
    Array<char> a3;
    a3 = c; 
    assert(a3.capacity() == c.capacity()); 
    for (int n = 0; n < c.capacity(); n++)
    assert(a3[n] == c[n]);
    
    
    Array <string>s(13);                                //string array test
    cout << "\n      Testing String Array\n";    
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 13\n";
    cout << "ACTUAL: " << s.capacity( ) << endl;
    assert(13 == s.capacity( ));
    cout << "\nTesting constructor\n";
    for (int n = 0; n < s.capacity( ); n++)
    assert(s[n] == "");
    cout << "\nTesting [] setter\n";
    s[6] = "Joey";
    cout << "EXPECTED: s[6] = Joey\n";
    cout << "ACTUAL: " << c[6] << endl;
    cout << "\nTesting the [ ] getter\n";
    const Array <string>strTest = s;
    for (int n = 0; n < 12; n++)
    assert(strTest[n] == s[n]);
    cout << "\nTesting object copy\n";
    Array<string> c4 = s; 
    assert(c4.capacity() == s.capacity()); 
    for (int n = 0; n < s.capacity(); n++)
    assert(c4[n] == s[n]);
    cout << "\nTesting object assignment\n"; 
    Array<string> a4;
    a4 = s; 
    assert(a4.capacity() == s.capacity()); 
    for (int n = 0; n < s.capacity(); n++)
    assert(a4[n] == s[n]);

    return 0;
}
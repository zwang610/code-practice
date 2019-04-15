#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <algorithm>

template <typename V>
class Array{
private:
    V* values;                              //private data member values
    int cap;                                //private data member capacity
    V dummy;
public:
    Array(int = 2);                         //main constructor, 2 is the default capacity
    ~Array(){delete [] values;};            //destructor, clean up the dynamic memory
    Array(const Array<V>&);                 //copy constructor
    Array<V>& operator=(const Array<V>&);   //assignment operator
    V& operator[](int);                     //setter
    V operator[](int) const;                //getter
    void capacity(int);                     //adjustable capacity
    int capacity() const;                   //getter for capacity
};

template <typename V>                       //constructor
Array<V>::Array(int cap){
    this->cap = cap;                        //private data member capacity equal to capacity parameter
    values = new V[cap];                    //privata data member array pointer points at an dynamic array
    for (int i = 0; i < cap; i++ )
    values[i] = V();
    dummy = V();                            //initialize
}

template <typename V>                       //copy constructor
Array<V>::Array(const Array<V>& original){
    cap = original.cap;                     //capacity equal the capacity of the original capacity
    values = new V[cap];                    //create new dynamic memory location
    for (int i = 0; i < cap; i++)   
    values[i] = original.values[i];         //for loop to make each value equal to value of original capacity
}

template <typename V>                       //assignment operator
Array<V>& Array<V>::operator=(const Array<V>&original){
    if(this != &original)                   //if it is not copying itself
    {
        delete [] values;                   //destruct the array, then do same as copy constructor
        cap = original.cap;                 //capacity equal the capacity of the original capacity
        values = new V[cap];                //create new dynamic memory location
        for (int i = 0; i < cap; i++)   
        values[i] = original.values[i];     //for loop to make each value equal to value of original capacity
        return *this;                       //return a self reference
    }
}

template <typename V>                       //square bracket setter
V& Array<V>::operator[](int index){         
    if (index < 0) return dummy;            //if index smaller than 0 return dummy
    if (index >= cap) capacity(2 * index);  //if index greater than capacity, adjust capacity
    return values[index];                   //return reference
}

template <typename V>                       //square bracket getter
V Array<V>::operator[](int index) const {   
    if (index < 0 || index >= cap) return 0;//if out of range return 0
    return values[index];                   //return the value
}

template <typename V>                       //capacity adjust function
void Array<V>::capacity(int cap){           
    V* temp = new V[cap];                   //create a temporary dynamic array with new capacity
    int limit = std::min(cap, this->cap);        //find the smaller capacity value of original and new array
    for (int i = 0; i < limit; i++)         //use for loop to store the original values
    temp[i] = values[i];
    for (int i = limit; i < cap; i++)       //use for loop to default new value location
    temp[i] = V();
    delete [] values;                       //clean up original array
    values = temp;                          //save original array as the new array
    this ->cap = cap;                       //set the new capacity
}

template <typename V>                       //getter function for capacity
int Array<V>::capacity() const {return cap;}


#endif
#ifndef STACK_H
#define STACK_H

#include <algorithm>

template <typename V>
class Stack
{
    private:
        V* head;
        int cap;
        int siz;
        void capacity(int);                     //private capacity function to adjust the capacity
    public:
        Stack(int = 2);                         //constructor
        Stack(const Stack<V>&);                 //copy constructor
        ~Stack();                               //destructor
        Stack<V>& operator=(const Stack<V>&);   //assignment operator
        void push(const V&);                    //push
        V peek();                               //peek
        void pop();                             //pop
        int size() const;                       //size function to get the size
        bool empty() const;                     //empty function to check if it is empty                 
        void clear();                           //clear function to reintialize the stack  
};

template <typename V>                           //private capacity function to adjust the capacity                    
void Stack<V>::capacity(int newCapacity){
    V* temp = new V[newCapacity];               //create a temporary dynamic Stack with new capacity
    int limit = std::min(newCapacity, cap);     //find the smaller capacity value of original and new Stack
    for (int i = 0; i < limit; i++)             //use for loop to store the original values
    temp[i] = head[i];
    for (int i = limit; i < cap; i++)           //use for loop to default new value location
    temp[i] = V();
    delete [] head;                             //clean up original Stack
    head = temp;                                //save original Stack as the new Stack
    cap = newCapacity;                          //set the new capacity
}

template <typename V>
Stack<V>::Stack(int cap){                       //constructor
    siz = 0;                                    //initialize size = 0
    this->cap = cap;                            //initialize capacity
    head = new V[cap];                          //initialize head = new dynamic Stack
    for (int i = 0; i < cap; i++) head[i] = V();//initialize the values inside the Stack to default value
}

template <typename V>
Stack<V>::Stack(const Stack<V>& original){      //copy constructor
    siz = original.siz;                         //size equal the size of the original size
    cap = original.cap;                         //capacity equal the capacity of the original capacity
    head = new V[cap];                          //create new dynamic memory location
    for (int i = 0; i < cap; i++)   
    head[i] = original.head[i];                 //for loop to make each value equal to value of original capacity
}

template <typename V>
Stack<V>::~Stack(){delete [] head;}             //destructor

template <typename V>                       
Stack<V>& Stack<V>::operator=(const Stack<V>&original){ //assignment operator
    if(this != &original)                       //if it is not copying itself
    {
        delete [] head;                         //destruct the stack, then do same as copy constructor
        siz = original.siz;                     //size equal the size of the original size
        cap = original.cap;                     //capacity equal the capacity of the original capacity
        head = new V[cap];                      //create new dynamic memory location
        for (int i = 0; i < cap; i++)   
        head[i] = original.head[i];             //for loop to make each value equal to value of original capacity
        return *this;                           //return a self reference
    }
}

template <typename V>
void Stack<V>::push(const V& value)             //push function
{
    if (siz == cap) capacity(2*cap);            //if size = capacity, expand the capacity to 2 times the original capacity
    head[siz] = value;                          //set the value in the new top of the stack equal the give value
    siz++;                                      //size increase 1
}

template <typename V>
V Stack<V>::peek() {
	if (siz > 0) return head[siz - 1];          //if siz ! = 1, return the value at the top which is head[siz-1]
	else return V();	                        //else return 0
}

template <typename V>
void Stack<V>::pop(){                           //pop function
    if (siz > 0)                                //if siz ! = 0
    {
        head[siz] = V();                        //the initialize the top of the stack
        siz--;                                  //size decrease 1
    }
}

template <typename V>
int Stack<V>::size() const {return siz;};

template <typename V>
bool Stack<V>::empty() const {return (siz == 0);}

template <typename V>
void Stack<V>::clear(){                         //clear function
    for (int i = 0; i < siz; i++) head[i] = V();//for loop to reinitialize the value inside the stack
    siz = 0;                                    //reinitialize size to 0
}

#endif



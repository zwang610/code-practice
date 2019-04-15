#ifndef QUEUE_H
#define QUEUE_H

#include <algorithm>

template <typename V>
class Queue
{
    private:
		struct Node
		{
			V value;
			Node* next;
		};
        Node* head;
        Node* tail;
        int cap;
		V dummy;

    public:
        Queue();					//constructor
        ~Queue();                   //destructor
        void push(const V&);        //push function
        void pop();                 //pop function
        V front();                  //get front value function
        V back();                   //get back value function
        int size();                 //get size function
        bool empty();               //empty function
        void clear();               //clear function
        Queue(const Queue<V>&);     //copy constructor
        Queue<V>& operator= (const Queue<V>&); //assignment operator    
};


template <typename V>
Queue<V>::Queue(){					//constructor
	head = 0;
	tail = head;
	cap = 0;
}

template <typename V>
Queue<V>::~Queue(){                 //destructor
    Node* deleteptr = head;         //create a deleteptr pointer = head
    while (head)//use for loop to delete the queue
    {
        delete head;                //delete the value deleteptr point at
        head = deleteptr->next;     //head = next node
    }
}

template <typename V>
void Queue<V>::push(const V& newValue){//push function
	if (cap == 0)
	{
		head = new Node;            //if capacity is 0
		head->value = newValue;		//store the newValue
		head->next = 0;		        //the end point to nullptr
		tail = head;				//tail equal to head
	}
	else
	{
		tail->next = new Node;		//tail next = new Node
		tail = tail->next;			//tail = next 
		tail->value = newValue;		//store the newValue
		tail->next = 0;		        //the end point to nullptr
	}
	cap++;
}

template <typename V>
void Queue<V>::pop(){               //pop function
	if (cap != 0)					//if capacity is not 0
	{
		Node* temp = head->next;	//save the second node
		delete head;				//delete head
		head = temp;				//set head equal next node
		cap--;
	}
	if (cap == 0) tail = head;		//if capacity is 0 now, set tail = head
}

template <typename V>               //front getter funtion
V Queue<V>::front(){
    return head->value;             //return the value in head
}

template <typename V>
V Queue<V>::back(){                 //back getter function
    return tail->value;             //return the value in tail
}

template <typename V>
int Queue<V>::size(){               //size getter function
    return cap;                     //return the size
}

template <typename V>
bool Queue<V>::empty(){             //empty funtion
    return (cap == 0);              //return if siz == 0
}

template <typename V>               
void Queue<V>::clear(){             //clear function
	Node* deleteptr = head;         //create a deleteptr pointer = head
	while (head)//use for loop to delete the queue
	{
		delete head;                //delete the value deleteptr point at
		head = deleteptr->next;     //head = next node
	}
	tail = head;					//set tail = head
}

template <typename V>
Queue<V>::Queue(const Queue<V>& original){//copy constructor
    cap = 0;                        //capacity = original capacity
    head = new Node;                //head = new node
    Node* temp = original.head;     //create a temp node pointer to go through original queue
    while (temp)					//for loop to create the queue
    {
		push(temp->value);          //push the value to the queue
        temp = temp->next;          //temp pointer point at next 
    }
}

template <typename V>
Queue<V>& Queue<V>::operator= (const Queue<V>&original){//assignment operater
     if(this != &original)          //if this queue is not the original queue
    {
		 clear();						 
		 cap = 0;					//capacity = 0
		 if (original.head != 0)    //if the original queue is not empty
		 {
			 head = new Node;       //head = new node
			 Node* temp = original.head;//create a temp node pointer to go through original queue
			 while (temp)		    //for loop to create the queue
			 {
				 push(temp->value); //push the value to the queue
				 temp = temp->next; //temp pointer point at next 
			 }
		 }
    }
	 return *this;
}


#endif
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <algorithm>


template <typename V>
class PriorityQueue
{
private:
	V* value;
	int siz;
	int cap;
	void capacity(int);							//capacity setter

public:
	PriorityQueue(int = 10);					//constructor
	~PriorityQueue() { delete[] value; };       //destructor
	void push(const V&);						//push setter
	V top() const;								//top getter
	int size() const;							//size getter
	bool empty() const;							//empty getter
	void pop();									//pop setter
	void clear() { siz = 0; }					//clear setter
	PriorityQueue(PriorityQueue<V>&);           //copy constructor
	PriorityQueue<V>& operator=(PriorityQueue<V>&); //assignment operator
};

template <typename V>							//capacity setter
void PriorityQueue<V>::capacity(int newCapacity) {
	V* temp = new V[cap];						//create a temporary dynamic array with new capacity
	int limit = std::min(cap, this->cap);       //find the smaller capacity value of original and new array
	for (int i = 0; i < limit; i++) temp[i] = value[i]; //use for loop to store the original values
	for (int i = limit; i < cap; i++) temp[i] = V(); //use for loop to default new value location
	delete[] value;								//clean up original array
	value = temp;								//save original array as the new array
	this->cap = cap;							//set the new capacity
}

template <typename V>							//constructor
PriorityQueue<V>::PriorityQueue(int capacity) {
	this->cap = capacity;						//set cap = capacity
	this->siz = 0;								//set size = 0
	value = new V[cap];							//create a dynamic array
	for (int i = 0; i < cap; i++) value[i] = V(); //initialize the value in the array
}

template <typename V>							//push setter
void PriorityQueue<V>::push(const V& newValue) {
	if (siz == cap) capacity(2 * cap);			//if the array is full (siz == cap), double its capacity
	value[siz] = newValue;						//copy the new value to V* values; array at index siz
	int parentIndex = 0;						//declare parentIndex and initialize it to 0
	int index = siz;
	while (index != 0)							//for loop to promotion the newly added value to it's right place in the tree
	{
		parentIndex = (index + 1) / 2 - 1;		//compute the parent index of index
		if (value[index] < value[parentIndex]) break;//if the VALUE at index < the VALUE at parent index, break from the loop (no more promotions)
		std::swap(value[index], value[parentIndex]); //swap values at the parent index and index -- promote and demote
		index = parentIndex;					//set index = parentIndex
	}
	siz++;
}

template <typename V>
V PriorityQueue<V>::top() const { return value[0]; } //top getter

template <typename V>
int PriorityQueue<V>::size() const { return siz; } //size getter

template <typename V>
bool PriorityQueue<V>::empty() const { return (siz == 0); } //empty getter

template <typename V>							//pop setter
void PriorityQueue<V>::pop() {
	
	if (siz != 0)
	{
		int index = 0;							//declare index and initialize it to 0
		int leftChildIndex = 1;					//declare leftchildindex and initialize it to 1
		int rightChildIndex = 2;				//declare rightchildindex and initialize it to 2
		while (leftChildIndex < siz)			//if leftchildindex exist
		{
			if (rightChildIndex >= siz || value[leftChildIndex] > value[rightChildIndex]) //if left child win
			{
				value[index] = value[leftChildIndex];
				index = leftChildIndex;
			}
			else								//else right child win
			{
				value[index] = value[rightChildIndex];
				index = rightChildIndex;
			}
			leftChildIndex = 2 * index + 1;		//compute leftchildindex
			rightChildIndex = 2 * index + 2;	//compute rightchildindex
		}
		siz--;									//decrease the size
		value[index] = value[siz];				//copy the VALUE at siz to the VALUE at index
		int parentIndex = 0;					//declare parentIndex and initialize it to 0
		while(index!= 0)
		{
			parentIndex = (index + 1) / 2 - 1;	//compute the parent index of index
			if (value[index] < value[parentIndex]) break;//if the VALUE at index < the VALUE at parent index, break from the loop (no more promotions)
			std::swap(value[index], value[parentIndex]); //swap values at the parent index and index -- promote and demote
			index = parentIndex;
		}
	}
}

template <typename V>							//copy constructor
PriorityQueue<V>::PriorityQueue(PriorityQueue<V>& original) {
	cap = original.size();						//capacity = original size times 2
	value = new V[cap];
	siz = 0;
	for (int i = 0; i < cap; i++) 				//for loop to create the queue
	{
		value[i] = original.top();				//push the value to the queue
		original.pop();							//pop the top from the original
		siz++;
	}

	for (int i = 0; i < this->size(); i++) original.push(value[i]);//for loop to push back the value of original
}

template <typename V>							//assignment operator
PriorityQueue<V>& PriorityQueue<V>::operator=(PriorityQueue<V>& original) {
	if (this != &original)						//if this queue is not the original queue
	{
		delete[] value;
		cap = original.size();						//capacity = original size times 2
		value = new V[cap];
		siz = 0;
		for (int i = 0; i < cap; i++) 				//for loop to create the queue
		{
			value[i] = original.top();				//push the value to the queue
			original.pop();							//pop the top from the original
			siz++;
		}

		for (int i = 0; i < this->size(); i++) original.push(value[i]);//for loop to push back the value of original
	}
	return *this;
}

#endif // !PRIORITYQUEUE_H
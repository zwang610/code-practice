#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H

#include <queue>
#include <algorithm>

template <typename K, typename V>
class AssociativeArray {
private:
	struct Node								//structuer Node
	{
		K key;
		V value;
		bool inUse;
	};
	
	Node* data;								//private data member head pointer
	int cap;                                //private data member capacity
	V dummy;								//private data member dummy
	int siz;								//private data member size
	void capacity(int);                     //private capacity setter
	

public:
	AssociativeArray(int = 2);              //main constructor, 2 is the default capacity
	~AssociativeArray() { delete[] data; }; //destructor, clean up the dynamic memory
	AssociativeArray(const AssociativeArray<K, V>&);    //copy constructor
	AssociativeArray<K,V>& operator=(const AssociativeArray<K, V>&);//assignment operator
	V& operator[](const K&);                 //the square bracket operator setter
	V operator[](const K&) const;            //the square bracket operator getter
	bool containsKey(const K&);		        //contains key getter
	void deleteKey(const K&);				//delete key setter
	int size() const;						//size getter
	void clear();							//clear setter
	std::queue<K> keys()const;				//key getter
};

template <typename K, typename V>           //constructor
AssociativeArray<K, V>::AssociativeArray(int cap) {
	this->cap = cap;                        //private data member capacity equal to capacity parameter
	data = new Node[cap];                   //create new dynamic memory location
	siz = 0;								//set siz equal 0
	for (int i = 0; i < cap; i++)			//use for loop to initialize all the Node in the array
	{
		data[i].value = V();
		data[i].key = K();
		data[i].inUse = false;
	}
}

template <typename K, typename V>			//copy constructor
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original) {
	cap = original.cap;                     //capacity equal the capacity of the original capacity
	data = new Node[cap];                   //create new dynamic memory location
	siz = original.siz;
	for (int i = 0; i < cap; i++)			//use for loop to initialize all the Node in the array
	{
		data[i].value = V();
		data[i].key = K();
		data[i].inUse = false;
	}
	queue<K> newKeys = original.keys();
	for (int i = 0; i < siz; i++ )
	{
		data[i].value = original[newKeys.front()];
		data[i].key = newKeys.front();
		newKeys.pop();
		data[i].inUse = true;
	}
}


template <typename K, typename V>           //assignment operator
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>&original) {
	if (this != &original)                  //if it is not copying itself
	{
		delete[] data;						//destruct the array, then do same as copy constructor
		cap = original.cap;                 //capacity equal the capacity of the original capacity
		data = new Node[cap];               //create new dynamic memory location
		siz = original.siz;
		for (int i = 0; i < cap; i++)			//use for loop to initialize all the Node in the array
		{
			data[i].value = V();
			data[i].key = K();
			data[i].inUse = false;
		}
		queue<K> newKeys = original.keys();
		for (int i = 0; i < siz; i++)
		{
			data[i].value = original[newKeys.front()];
			data[i].key = newKeys.front();
			newKeys.pop();
			data[i].inUse = true;
		}
		return *this;                       //return a self reference
	}
}

template <typename K, typename V>               //square bracket setter
V& AssociativeArray<K, V>::operator[](const K& keyWord) {
	for (int i = 0; i < cap; i++)
	{
		if (data[i].inUse)
		{
			if (data[i].key == keyWord) return data[i].value;
		}
	}
	if (siz != cap)
	{
		for (int i = 0; i < cap; i++)
		{
			if (!data[i].inUse)
			{
				data[i].key = keyWord;
				data[i].inUse = true;
				siz++;
				return data[i].value;
			}
		}
	}
	capacity(cap * 2);
	data[siz].key = keyWord;
	data[siz].inUse = true;
	siz = siz + 1;
	return data[siz-1].value;
}

template <typename K, typename V>           //square bracket getter
V AssociativeArray<K, V>::operator[](const K& keyWord) const {
	for (int i = 0; i < cap; i++)
	{
		if (data[i].inUse)
		{
			if (data[i].key == keyWord) return data[i].value;
		}
	}
	return dummy;
}

template <typename K, typename V>			//contains key getter
bool AssociativeArray<K, V>::containsKey(const K& keyWord){
	for (int i = 0; i < cap; i++)
	{
		if (data[i].inUse)
		{
			if (data[i].key == keyWord) return true;
		}
	}
	return false;
}

template <typename K, typename V>			//delete key setter
void AssociativeArray<K, V>::deleteKey(const K& keyWord) {
	for (int i = 0; i < cap; i++)
		if (data[i].inUse)
			if (data[i].key == keyWord)
			{
				data[i].key = K();
				data[i].value = V();
				data[i].inUse = false;
				siz--;
				break;
			}
}

template <typename K, typename V>           //size getter
int AssociativeArray<K, V>::size() const { return siz; }

template <typename K, typename V>			//clear setter
void AssociativeArray<K, V>::clear() {
	for (int i = 0; i < cap; i++)
		if (data[i].inUse)
		{
			data[i].value = V();
			data[i].key = K();
			data[i].inUse = false;
		}
	siz = 0;
}

template <typename K, typename V>			//keys getter
std::queue<K> AssociativeArray<K, V>::keys() const {
	std::queue<K> k;
	for (int i = 0; i < cap; i++)
	{
		if (data[i].inUse) k.push(data[i].key);
	}
	return k;
}


template <typename K, typename V>               //private capacity setter
void AssociativeArray<K, V>::capacity(int cap) {
	Node* temp = new Node[cap];                 //create a temporary dynamic array with new capacity
	int limit = std::min(cap, this->cap);       //find the smaller capacity value of original and new array
	for (int i = 0; i < limit; i++)             //use for loop to store the original values
	{
		temp[i].key = data[i].key;
		temp[i].value = data[i].value;
		temp[i].inUse = data[i].inUse;
	}	
	for (int i = limit; i < cap; i++)			//use for loop to default new value location
	{
		temp[i].key = K();
		temp[i].value = V();
		temp[i].inUse = false;
	}
	delete[] data;								//clean up original array
	data = temp;								//save original array as the new array
	this->cap = cap;							//set the new capacity
}

#endif

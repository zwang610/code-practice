#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <queue>
#include <algorithm>
#include <list>

template <typename K, typename V, int CAP>
class MyHashTable {
private:
	struct Node
	{
		K key;
		V value;
	};
	
	std::list<Node> data[CAP];
	int(*hashCode)(const K&);	
	V dummy;								//private data member dummy
	int siz;								//private data member size

public:
	MyHashTable(int(*)(const K&) = 0);      //main constructor, 2 is the default capacity
	V& operator[](const K&);                //the square bracket operator setter
	V operator[](const K&) const;           //the square bracket operator getter
	bool containsKey(const K&);		        //contains key getter
	void deleteKey(const K&);				//delete key setter
	int size() const;						//size getter
	void clear();							//clear setter
	std::queue<K> keys()const;				//key getter
	double loadFactor()const { return 1.0*siz / CAP; }//load Factor getter
};

template <typename K, typename V, int CAP>	//constructor
MyHashTable<K, V, CAP>::MyHashTable(int(*hashCode)(const K&)) {
	this->hashCode = hashCode;
	siz = 0;								//set siz equal 0
	for (int i = 0; i < CAP; i++) 
	{
		data[i].key = K();
		data[i].value = V();		
	}//use for loop to initialize all the Node in the array
}

template <typename K, typename V, int CAP>	//the square bracket operator setter
V& MyHashTable<K, V, CAP>::operator[](const K& key) {
	int k = hashCode(key);
	int index = k % CAP;		//wrapping index
	if (index < 0) index += CAP;			//negative index
	typename std::list<Node>::iterator it;		//declare a pointer it
	for (it = data[index].begin(); it != data[index].end(); it++)//loop from the begining to the end
		if (it->key == key) return it->value;//find the key
	if (it == data[index].end())			//if the key doesn't exist
	{
		if (data[index].size() == 0) siz++;	//if the index is empty, siz++
		Node newNode;						//delare a newNode
		newNode.key = key;					//set the key
		newNode.value = V();				//set the value
		data[index].push_back(newNode);		//push the key into the index at the end
		return data[index].back().value;	//return the end of the index
	}
}

template <typename K, typename V, int CAP>	//the square bracket operator getter
V MyHashTable<K, V, CAP>::operator[](const K& key) const {
	int index = hashCode(key) % CAP;		//wrapping index
	if (index < 0) index += CAP;			//negative index
	typename list<Node>::const_iterator it; //declare a pointer it
	for (it = data[index].begin(); it != data[index].end(); it++)//loop from the begining to the end
		if (it->key == key) return it;		//find the key
	if (it == data[index].end()) return dummy;//if the key is not found return dummmy
}

template <typename K, typename V, int CAP>	//contains key getter
bool MyHashTable<K, V, CAP>::containsKey(const K& key) {
	int index = hashCode(key) % CAP;		//wrapping index
	if (index < 0) index += CAP;			//negative index
	typename list<Node>::const_iterator it; //declare a pointer it
	for (it = data[index].begin(); it != data[index].end(); it++)//loop from the begining to the end
		if (it->key == key) return true;		//find the key return true
	if (it == data[index].end()) return false;//else return false
}

template <typename K, typename V, int CAP>	//delete key setter
void MyHashTable<K, V, CAP>::deleteKey(const K&key) {
	int index = hashCode(key) % CAP;		//wrapping index
	if (index < 0) index += CAP;			//negative index
	typename list<Node>::const_iterator it; //declare a pointer it
	for (it = data[index].begin(); it != data[index].end(); it++)//loop from the begining to the end
	{
		if (it->key == key)					// if it is found 
		{
			data[index].erase(it);			//delete it
			siz--;
			break;							//and break
		}
	}
}

template <typename K, typename V, int CAP>	//size getter
int MyHashTable<K, V, CAP>::size() const { return siz; }

template <typename K, typename V, int CAP>	//clear setter
void MyHashTable<K, V, CAP>::clear() {
	for (int i = 0; i < CAP; i++)
	{
		data[i].key = K();
		data[i].value = V();		
	}//use for loop to initialize all the Node in the arraythe array
	siz = 0;
}

template <typename K, typename V, int CAP>	//keys getter
std::queue<K> MyHashTable<K, V, CAP>::keys()const {
	std::queue<K> k;						//declare a queue
	typename list<Node>::const_iterator it; //declare a pointer it
	for (int i = 0; i < CAP; i++)			//for loop
	{
		if (!data[i].empty)					//if index is not empty
			for (it = data[index].begin(); it != data[index].end(); it++) k.push(it->key);//for loop to push all the key into the queue
	}
	return k;								//return the queue
}

#endif
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

bool myfunction(int a, int b)
{
	if (a < b)
		return true;
	else
		return false;
}

int compvar(const void *one, const void *two)
{
	int a = *((int*)one);
	int b = *((int*)two);
	if (a < b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

int main()
{
#pragma region Vector
	vector<int> data;
	for (int i = 0; i < 10; i++) // Loop with higher count for performance check e.g 100000
	{
		data.push_back(rand());
	}

	//sort_heap(data.begin(), data.end());
	//qsort(&data[0], data.size(), sizeof(int), compvar);
	//sort(data.begin(), data.end());
	data[2] = 7;
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << endl;
	}

	// Access using iterator 
	vector<int>::iterator it;
	for (it = data.begin(); it != data.end(); ++it)
		cout << *it << endl;

	data.clear();

	// Conclusion
	// 1. qsort is faster then sort
	// If all you want is a "smart array" class that offers random access to elements, 
	// and perhaps the ability to append new elements to its end, then vector is the right choice.
	// Accessing individual elements by their position index(constant time).
	// Iterating over the elements in any order(linear time).
	// Add and remove elements from its end(constant amortized time)
#pragma endregion

#pragma region Deque
	// Deque, provides random access and the subscript notation for accessing elements, just like vector.
	// Yet unlike vector, it supports efficient insertions and deletions at both ends.
	// Individual elements can be accessed by their position index.
	// Iteration over the elements can be performed in any order.
	// Elements can be efficiently added and removed from any of its ends(either the beginning or the end of the sequence).
	// E.g.Operating system's scheduler.
#pragma endregion

#pragma region List
	// Efficient insertion and removal of elements anywhere in the container(constant time).
	// If you don't need random access (say, "15 positions from the beginning" or "three positions before the current element") 
	// and you do need to insert new elements between existing elements frequently, then list is a good choice.
	// Efficient moving elements and block of elements within the container or even between different 
	// containers: splice operation (constant time). • E.g. Window’s task manager

	list<int> *lst = new list<int>();
	for (int i = 0; i < 10; i++)
	{
		lst->push_back(rand());
	}

	list<int>::iterator it1;
	for (it1 = lst->begin(); it1 != lst->end(); ++it1)
		cout << *it1 << endl;

	lst->clear();
	delete lst;
#pragma endregion

#pragma region Map
	// As associative containers, they are especially designed to be efficient accessing its 
	// elements by their key(unlike sequence containers, which are more efficient accessing 
	// elements by their relative or absolute position).
	// Unique key values : no two elements in the map have keys that compare equal to each other.
	// Each element is composed of a key and a mapped value.
	// Maps are always sorted by Kay value.
	// Multimap are same as map but can have different value for same key. Allows same key to be added multiple time 
	map<int, int> mymap;
	for (int i = 0; i < 10; i++)
	{
		mymap[i] = rand();
	}

	// Access an value by key
	//cout << mymap[4] << endl;

	// With valid check 
	map<int, int>::iterator it2 =  mymap.find(4);
	if (it2 != mymap.end())
	{
		cout << mymap[4] << endl;
	}

	//sort(mymap.begin, mymap.end);
	for (map<int, int>::iterator it2 = mymap.begin(); it2 != mymap.end(); ++it2)
		cout << "Key: " << it2->first << " Value: " << it2->second << endl;
#pragma endregion

#pragma region Stack
	// Stack(declared in <stack>) is an ideal choice when you need to a LIFO data structure.
	// For example, think about people entering the back seat of a car that has only 
	// one door : the last person to enter is the first to exit. 
	// The four basic operations that a stack supports are push(), pop(), top(), and empty()

	stack<int> mystack;
	for (int i = 0; i < 10; i++)
	{
		mystack.push(i);
	}

	// Only way to iterate is using while and using top and popping element
	while(!mystack.empty())
	{
		cout<<mystack.top()<<endl;
		mystack.pop();
	}
#pragma endregion

#pragma region Queue
	// A queue(declared in <queue>), or FIFO, is characterized by having elements 
	// inserted into one end and removed from the other end.
	// For example : a queue of people at a theater's box office. 
	// The queue adaptor container is implemented in one of two ways: either as a deque or as a list

	queue<int>myqueue;
	for (int i = 0; i < 10; i++)
	{
		myqueue.push(i);
	}

	// Only way to iterate is using while and using top and popping element
	while (!myqueue.empty())
	{
		cout << myqueue.front() << endl;
		myqueue.pop();
	}

#pragma endregion
	return 0;
}
//pq.cpp
// Kevin Ly & James Le

#ifndef pq_cpp
#define pq_cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*===================================================
MinPriorityQueue()             // default constructor
Precondition: None
Postcondition: An empty priority queue
===================================================*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue()
{
	//capacity = 100;
	heapSize = 0 ;
	A = new KeyType* [capacity];
}

/*======================================================================
MinPriorityQueue(int n)        // construct an empty MPQ with capacity n
Precondition: Must be given a capacity size (n)
Postcondition: An empty priority queue with capacity of n
======================================================================*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n)
{
	capacity = n;
	heapSize = 0;
	A = new KeyType* [n];
}

/*=========================================================================
MinPriorityQueue(const MinPriorityQueue<KeyType>& pq);  // copy constructor
Precondition: Must be given a priority queue pq
Postcondition: Traverses the priority queue and makes a copy of its values
	to transfer to another priority queue
========================================================================*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq)
{
	heapSize = pq.heapSize;
	capacity = pq.capacity;
	A = new KeyType*[capacity];

	for (int i=0; i < heapSize; i++){
		A[i] = pq[i];
	}

	// buildHeap()
	heapSize = capacity;
	for (int i = (capacity/2); i >= 0; i--)
		heapify(i);
}

/*=================================================================
KeyType* minimum() const              // return the minimum element
Precondition: A non-empty min-heap A
Postcondition: Returns the minimum value in min-heap A
=================================================================*/
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum() const
{
	if (empty())
		throw EmptyError();
	return A[0];
}

/*==========================================================================
KeyType* extractMin()            // delete the minimum element and return it
Precondition: A non-empty min-heap A
Postcondition: Deletes the minimum value in min-heap A and returns it
==========================================================================*/
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::extractMin()
{
	if (empty())
		throw EmptyError();
	KeyType* min = (A[0]);
	A[0] = A[heapSize-1];
	heapSize--;
	heapify(0);
	return min;
}

/*============================================================================
void decreaseKey(int index, KeyType* key)  // decrease the value of an element
Precondition: A min-heap A where new key is always smaller than current key
Postcondition: The value of element index's key has the new value key
============================================================================*/
template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
{
	if (*(A[index]) < *key)
		throw KeyError();
	A[index] = key;
	while ((index > 0) && (*(A[index]) < *(A[parent(index)]))) {
		swap(index, parent(index));
		index = parent(index);
	}
}

/*==============================================================================
void insert(KeyType* key)                  // insert a new element
Precondition: Input is the key of the new element to be inserted into min-heap A
Postcondition: Key of the new node is in correct value and the heap maintains
	its min-heap property
==============================================================================*/
template <class KeyType>
void MinPriorityQueue<KeyType>::insert(KeyType* key)
{
	if (heapSize == capacity)
		throw FullError();

	if(heapSize ==0){
		A[heapSize] = key;
		heapSize++;
	}
	else{
	A[heapSize] = key;
	decreaseKey(heapSize, key);
	heapSize++;
	}
}


/*=========================================================================
bool empty() const                       // return whether the MPQ is empty
Precondition: None
Postcondition: Returns true if the priority queue is empty, false otherwise
=========================================================================*/
template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
{
	if (heapSize == 0)
		return 1;
	else
		return 0;
}


/*=====================================================
int length() const         // return the number of keys
Precondition: None
Postcondition: Returns the length of the priority queue
=====================================================*/
template <class KeyType>
int MinPriorityQueue<KeyType>::length() const
{
	return heapSize;
}


/*================================================================================
std::string toString() const          // return a string representation of the MPQ
Precondition: A priority queue to be converted to a string
Postcondition: Traverses the array and uses << to output each element of the array
================================================================================*/
template <class KeyType>
std::string MinPriorityQueue<KeyType>::toString() const
{
	stringstream result; //sets variable to be returned
	int x = 0;
	result << "[";
	int size = heapSize;

	while(x < size) // inserts values into "result" while traversing list
	{
		result << *(A[x]);
		x++;
		if(x != size)
			result << ",";
	}
	result << "]";
	return result.str();
}

/*================================================================================
std::string toString() const          // return a string representation of the MPQ
Precondition: A priority queue to be converted to a string
Postcondition: Traverses the array and uses << to output each element of the array
================================================================================*/
template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq)
{
	stream << pq.toString();
  return stream;
}


#endif

// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

// heap.cpp

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;
/*==========================================================
MinHeap(int n = DEFAULT_SIZE)      //default constructor
Precondition: Must be given a capacity size (n)
Postcondition: An empty heap with capacity of n (1000 (default))
============================================================*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(int n)
{
	heapSize = 0;
	capacity = n;
	A = new KeyType*[n];
}

/*==========================================================
MinHeap(KeyType initA[], int n)    //construct heap from array
Precondition: Must be given an array and capacity
Postcondition: Traverses and makes a copy of the array. Then creates a min-heap
		using buildHeap
============================================================*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType* initA[], int n)
{
	A = new KeyType*[n];
	for (int i=0; i < n; i++){
		A[i] = initA[i];
	}
	capacity = n;
	buildHeap();
}

/*==========================================================
MinHeap(const MinHeap<KeyType>& heap);  // copy constructor
Precondition: Must be given a heap
Postcondition: Traverses the heap and makes a copy of its values
		to transfer to another heap
============================================================*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap)
{
	heapSize = heap.heapSize;
	capacity = heap.capacity;
	A = new KeyType*[capacity];
	for (int i=0; i < heapSize; i++){
		A[i] = heap[i];
	}
	buildHeap();

}

/*==========================================================
 ~MinHeap();                             // destructor
Precondition: N/A
Postcondition: deallocates the heap
============================================================*/
template <class KeyType>
MinHeap<KeyType>::~MinHeap()
{
	delete []A;
}

/*==========================================================
heapSort(KeyType sorted[]);  // heapsort, return result in sorted
Precondition: Must be given a heap to be sorted
Postcondition: Uses the min-heap property to continuously insert
		the next smallest value of a decreasing heap in
		order to sort it. A sorted (ascending) heap is returned
============================================================*/
template <class KeyType>
void MinHeap<KeyType>::heapSort(KeyType* sorted[])
{
	int temp;
	int var = heapSize;

	for(int i=0; i < var; i++){
		sorted[i] = A[0];
		swap(0, heapSize-1);

		heapSize--;
		heapify(0);
	}


	for(int j=0; j < var; j++){
		A[j] = sorted[j];
	}

	heapSize = var;
	return;


}


/*==========================================================
operator = (const MinHeap<KeyType>& heap);  // assignment operator
Precondition: Must be given a heap to be copied
Postcondition: Copies the heap size and capacity of a heap, then
		traverses it to copy the elements into another heap
============================================================*/
template <class KeyType>
MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap)
{

	heapSize = heap.heapSize;
	capacity = heap.capacity;

	for(int i=0; i < heapSize; i++)
		A[i] = heap.A[i];

	copy(heap);
}


/*==========================================================
operator << (std::ostream& stream, const MinHeap<KeyType>& heap)
Precondition: Must be given a heap
Postcondition: Calls the function toString and returns the output
============================================================*/
template <class KeyType>
std::ostream& operator<< (std::ostream& stream, const MinHeap<KeyType>& heap)
{
	stream << heap.toString();
	return stream;
}



/*==========================================================
toString() const;     // return string representation
Precondition: A heap to be converted to a string (not as a parameter)
Postcondition: Traverses the array and uses << to output each element of
		the array
============================================================*/
template <class KeyType>
std::string MinHeap<KeyType>::toString() const
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



/*==========================================================
heapify(int index);          // heapify subheap rooted at index
Precondition: Must be given an index. Used on an array
Postcondition: Recursively compares the parent, left child, and
		right child. Places the smaller of the three values
		in the index.
============================================================*/
template <class KeyType>
void MinHeap<KeyType>::heapify(int index)
{
	int smallest;
	int l = leftChild(index);
	int r = rightChild(index);
	if (l < heapSize and *(A[l]) < *(A[index]))
		smallest = l;
	else
		smallest = index;

	if (r < heapSize and *(A[r]) < *(A[smallest]))
		smallest = r;
	if (smallest != index){
		swap(index,smallest);
		heapify(smallest);
	}
	return;
}

/*==========================================================
buildHeap();                 // build heap
Precondition: Used on a heap
Postcondition: Traverses half of the array and calls heapify(i)
============================================================*/
template <class KeyType>
void MinHeap<KeyType>::buildHeap()
{
	heapSize = capacity;
	for (int i = (capacity/2); i >= 0; i--)
		heapify(i);

}

/*==========================================================
swap(int index1, int index2);        // swap elements in A
Precondition: Must be given two indices
Postcondition: Exchanges the values of the two indices
============================================================*/
template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2)
{
	KeyType* temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;

}

/*==========================================================
copy(const MinHeap<KeyType>& heap);  // copy heap to this heap
Precondition: Must be given a heap to copy
Postcondition: Calls the copy constructor
============================================================*/
template <class KeyType>
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap)
{

	MinHeap(A);

}

/*==========================================================
destroy();                           // deallocate heap
Precondition: N/A
Postcondition: Calls the deconstructor
============================================================*/
template <class KeyType>
void MinHeap<KeyType>::destroy()
{
	~MinHeap();

}

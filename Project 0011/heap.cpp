// James Le - CS 271
// Feb 15, 2017
// heap.cpp
// C++ program for implementation of a MinHeap template class and Heap Sort algorithm

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

/*================================================================
MinHeap Default Constructor
Pre: None
Post: Construct a new MinHeap data type with default size set to n
================================================================*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(int n)
{
  heapSize = 0;
  capacity = n;
  A = new KeyType[capacity];
}
/*==============================================================================
MinHeap Array Constructor
Pre: An empty array initA with size n
Post: Construct a heap from array initA with contents from the heap from array A
==============================================================================*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType initA[], int n)
{
  capacity = n;
  A = new KeyType[capacity];
  heapSize = 0;

  // Copy the array into the heap's internal array
  for (int i = 0; i < n; i++)
    A[i] = initA[i];

  heapSize = capacity;
  // Organize the array into a proper MinHeap Tree
  buildHeap();
}

/*============================================================
MinHeap Copy Constructor
Pre: heap is a MinHeap data type
Post: Construct a MinHeap data type with same contents as heap
============================================================*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap)
{
  copy(heap);
}

/*=======================================================
MinHeap Destructor
Pre: None
Post: Clean up the MinHeap class
========================================================*/
template <class KeyType>
MinHeap<KeyType>::~MinHeap()
{
  destroy();
}

/*===================================================
Assignment Operator
Pre: heap is a MinHeap data type
Post: Allow assignment of values between MinHeap class
===================================================*/
template<class KeyType>
MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap)
{
  if(this != &heap)
  {
    delete [] A;
    copy(heap);
  }
  return *this;
}

/*===============================
String Representation for MinHeap
================================*/
template<class KeyType>
std::string MinHeap<KeyType>::toString() const
{
  string heapstr = "[";
  KeyType updatestring;
  for(int i = 0; i < capacity; i++)
  {
    ostringstream change;
    if(i != heapSize - 1)
    {
      if(i != capacity - 1)
      {
        updatestring = A[i];
        change << updatestring;
        heapstr += change.str();
        heapstr += ", ";
      }
      else
      {
        updatestring = A[i];
        change << updatestring;
        heapstr += change.str();
      }
    }
    else if(i == heapSize - 1)
    {
      updatestring = A[i];
      change << updatestring;
      heapstr += change.str() + " |";
    }
  }
  heapstr += "]";
  return heapstr;
}

/*===========================
Heapsort Algorithm
Pre: a list of Key Types
Post: sorted list of Key Types
============================*/
template <class KeyType>
void MinHeap<KeyType>::heapSort(KeyType sorted[])
{
  // One by one extract an element from heap
  for (int i = heapSize - 1; i >= 0; i--)
  {
    // Move current root to the end
    swap(0,i);
    heapSize--;
    // Call min-heapify on the reduced heap
    heapify(0);
  }

  for (int j = 0; j < capacity; j++)
  {
    sorted[(capacity - 1) - j] = A[j];
  }

  // Copy elements in A to sorted
  for (int l = 0; l < capacity; l++)
  {
    A[l] = sorted[l];
  }
}

/*==============================================
Min-Heapify Subheap Rooted At Index
Pre: 2 subtrees for the children are already heaps
Post: Root A[0] is the root of the heap
===============================================*/
template <class KeyType>
void MinHeap<KeyType>::heapify(int index)
{
  int smallest = index; // Initialize smallest as root
  int l = leftChild(index);
  int r = rightChild(index);

  // If left child is smaller than root
  if (l < heapSize && A[l] < A[smallest])
    smallest = l;

  // If right child is smaller than smallest so far
  if (r < heapSize && A[r] < A[smallest])
    smallest = r;

  // If smallest is not root
  if (smallest != index)
  {
    swap(index, smallest);
    // Recursively heapify the affected sub-tree
    heapify(smallest);
  }
}

/*============================================
Build MinHeap
Pre: None
Post: A heap that is sorted in decreasing order
=============================================*/
template <class KeyType>
void MinHeap<KeyType>::buildHeap()
{
  for (int i = ((capacity/2) - 1); i >= 0; i--)
  {
    heapify(i);
  }
}

/*===============================================
Swap Elements
Pre: 2 elements
Post: The 2 elements' index positions are swapped
===============================================*/
template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2)
{
  KeyType temp = A[index1];
  A[index1] = A[index2];
  A[index2] = temp;
}

/*============================================================
Copy Heap to another Heap
Pre: heap is a MinHeap data type
Post: Construct a MinHeap data type with same contents as heap
============================================================*/
template <class KeyType>
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap)
{
  heapSize = heap.heapSize;
  capacity = heap.capacity;

  A = new KeyType[heap.capacity];
  for (int i = 0; i < heap.heapSize; i++)
  {
    A[i] = heap.A[i];
  }
}

/*===============================================
Deallocate Heap
Pre: None
Post: Clean up the MinHeap class
===============================================*/
template <class KeyType>
void MinHeap<KeyType>::destroy()
{
  delete [] A;
  heapSize = 0;
  capacity = 0;
}

/*====================================================================
Overloading Operator
Pre: When all the heap or array is turned into a string
Post: When all of the heap is converted to a string
====================================================================*/
template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinHeap<KeyType>& heap)
{
  stream << heap.toString();
  return stream;
}

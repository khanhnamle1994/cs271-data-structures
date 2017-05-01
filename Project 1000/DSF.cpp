#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>

using namespace std;

/*=====================================================
Default Constructor
=====================================================*/
template<class T>
DisjointSets<T>::DisjointSets()
{
  elements = new DSNode<T>*[100]; // set default as 100
  length = 0;
  capacity = 100;
}

/*=====================================================
Constructor with Capacity
=====================================================*/
template<class T>
DisjointSets<T>::DisjointSets(int size)
{
  elements = new DSNode<T>*[size];
  length = 0;
  capacity = size;
}

/*=====================================================
Copy Constructor
=====================================================*/
template<class T>
DisjointSets<T>::DisjointSets (const DisjointSets<T>& ds)
{
  copy(ds);
}

/*=====================================================
Destructor
=====================================================*/
template<class T>
DisjointSets<T>::~DisjointSets()
{
  destroy();
}

/*=======================================================
Assignment Operator
========================================================*/
template<class T>
DisjointSets<T>& DisjointSets<T>::operator= (const DisjointSets<T>& ds)
{
  // only destory and copy if 2 MinHeaps are not the same MinHeap
  if(this != &ds)
  {
    destroy();
    copy(ds);
  }
  return *this;
}

/*==================================================================================
MaketSet Function
Preconditions: Elements array of disjoint sets must not be full, x must be of type T,
and a node with key x must not already be in the forest.
Postconditions: A new singleton set has been created in the disjoint set forest.
===================================================================================*/
template<class T>
DSNode<T>* DisjointSets<T>::makeSet(T* x)
{
  // error: disjoint set forest is full
  if (length == capacity)
  {
    throw FullError();
  }

  // create pointer to new node with a key of x
  DSNode<T> *xnode = new DSNode<T>(x);

  // make new node its own parent and set rank to 0
  xnode->parent = xnode;
  xnode->rank = 0;

  // insert node as a new singleton set in the elements array at the next available index
  elements[length] = xnode;

  // increment length of forest
  length++;

  return xnode;
}

/*==================================================================================
UnionSets Function
Preconditions: x and y are both pointers to nodes in the disjoint set forest.
Postconditions: The disjoint sets that contained nodes x and y have been joined
together as one set.
===================================================================================*/
template<class T>
void DisjointSets<T>::unionSets(DSNode<T>* x, DSNode<T>* y)
{
  // call find set on x and y to find their set representatives and then call link
  // with these representatives to join the sets together
  link(findSet(x), findSet(y));
}

/*==================================================================================
Link Function
Preconditions: x and y are pointers to the representative nodes of their sets.
Postconditions: The sets of x and y have been linked together into one set.
===================================================================================*/
template<class T>
void DisjointSets<T>::link(DSNode<T>* x, DSNode<T>* y)
{
  // if the rank of x is greater than the rank of y, x becomes the representative of
  // the new set
  if (x->rank > y->rank)
  {
    y->parent = x;
  }

  // if the rank of y is greater than or equal to the rank of x, y becomes the
  // representative of the new set
  else
  {
    x->parent = y;

    // if the ranks of x and y are the same, increment y's rank
    if (x->rank == y->rank)
    {
      y->rank = y->rank + 1;
    }
  }
}

/*==================================================================================
findSet Function
Preconditions: x is a node in the disjoint set forest.
Postconditions: a pointer to the representative node of the set x is returned.
===================================================================================*/
template<class T>
DSNode<T>* DisjointSets<T>::findSet(DSNode<T>* x)
{
  // error: node is not in forest
  if (x->parent == NULL)
    throw NotFoundError();

  // if we haven't reached the representative of the set, call findSet on the current
  // node's parent
  if (x->parent != x)
    x->parent = findSet(x->parent); // path compression
  return x->parent;
}

/*=====================================================
copy Function
=====================================================*/
template<class T>
void DisjointSets<T>::copy (const DisjointSets<T>& ds)
{
  length = ds.length;
  capacity = ds.capacity;

  // allocate new memory for copy of DisjointSets ds
  elements = new DSNode<T>*[capacity];

  // copy items from ds to copy of ds
  for (int i = 0; i < length; i++)
  {
    elements[i] = new DSNode<T>(ds.elements[i] -> key);
    elements[i]->index = ds.elements[i]->index;
  }

  for (int i = 0; i < length; i++)
  {
    int dad = (ds.elements[i]->parent)->index;
    elements[i]->parent = elements[dad];
  }
}

/*======================================================
destroy Function
Preconditions: None
Postconditions: Deallocate memory of disjoint set forest
=======================================================*/
template<class T>
void DisjointSets<T>::destroy()
{
  delete [] elements;
}

/*=====================================================================================
toString Function
Preconditions: called by valid DisjointSets object.
Postconditions: string representation of disjoint set forest is returned with each line
representing a node in the forest. i:j represents a node where i is the key and j is the
rank. Parent relationships of i:j are denoted with an '->' and then the parent's node
representation.
=====================================================================================*/
template<class T>
std::string DisjointSets<T>::toString()
{
  string Set;

  for(int i = 0; i < length; i++)
  {
    DSNode<T> *current = elements[i];

    ostringstream help;

    // add current node to string
    help << *(elements[i]);
    Set += help.str();

    // add parental relationships of current node to string
    while(*(current->parent) != *current)
    {
      ostringstream help2;
      Set += " -> ";
      help2 << *(current->parent);
      Set += help2.str();
      current = current->parent;
    }

    if(i != length - 1)
    {
      Set += "\n";
    }
  }
  return Set;
}

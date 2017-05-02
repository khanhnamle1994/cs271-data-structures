// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include "list.h"

using namespace std;

/*=====================================================
Node Default Constructor
Precondition: None
Postcondition: Initializes empty DSNode
=====================================================*/
template<class T>
DSNode<T>::DSNode()
{
  key = NULL;
  parent = NULL;
  rank = 0;
}

/*=======================================================
Node Constructor
Precondition: initKey is a pointer to type T
Postcondition: Creates DSNode with rank 0 and key initKey
=======================================================*/
template<class T>
DSNode<T>::DSNode(T* initKey)
{
  key = initKey;
  parent = NULL;
  rank = 0;
}

/*============================================================================
Node Constructor
Precondition: initKey and initParent are pointers to type T
Postcondition: Creates DSNode with rkey initKey, parent initParent, and rank 0
============================================================================*/
template<class T>
DSNode<T>::DSNode(T* initKey, T* initParent)
{
  key = initKey;
  parent = initParent;
  rank = 0;
}

/*===================================================================================
Node Constructor
Precondition: initKey and initParent are pointers to type T, initRank is an integer
Postcondition: Creates DSNode with key initKey, parent initParent, and rank initRank
====================================================================================*/
template<class T>
DSNode<T>::DSNode(T* initKey, T* initParent, int initRank)
{
  key = initKey;
  parent = initParent;
  rank = initRank;
}

/*=====================================================
Default Constructor
Precondition: None
Postcondition: Creates empty DisjointSets
=====================================================*/
template<class T>
DisjointSets<T>::DisjointSets()
{
  elements = new DSNode<T>*[100]; // set default as 100
  length = 0;
  capacity = 100;
}

/*==========================================================
Constructor with Capacity
Precondition: Size is an integer
Postcondition: Creates empty DisjointSets with capacity size
==========================================================*/
template<class T>
DisjointSets<T>::DisjointSets(int size)
{
  elements = new DSNode<T>*[size];
  length = 0;
  capacity = size;
}

/*=====================================================
Copy Constructor
Precondition: ds is a DisjointSets of type T
Postcondition: Creates a copy of ds
=====================================================*/
template<class T>
DisjointSets<T>::DisjointSets (const DisjointSets<T>& ds)
{
  capacity = ds.capacity;
  elements = new DSNode<T>*[capacity];
  length = ds.length;

  for (int i = 0; i < length; i++)
  {
      elements[i] = copy(ds.elements[i]);
  }
}

/*=====================================================
copy Function
Precondition: node is a pointer to DSNode
Postcondition: returns a copy of node
=====================================================*/
template<class T>
DSNode<T>* DisjointSets<T>::copy (const DSNode<T>* node)
{
  DSNode<T> *newNode = new DSNode<T>;
  if(node == NULL)
  {
    return NULL;
  }

  newNode->rank = node->rank;
  newNode->key = node->key;
  if(node->parent == node)
    newNode->parent = newNode;
  else
    newNode->parent = copy(node->parent);
  return newNode;
}

/*=====================================================
Destructor
Precondition: None
Postcondition: Deallocates the memory of DisjointSets
=====================================================*/
template<class T>
DisjointSets<T>::~DisjointSets()
{
  List<T> alreadyDeleted;
  for(int i = 0; i < length; i++)
  {
    alreadyDeleted.append(elements[i]->key);
    bool found = false;
    for(int j = 0; j < alreadyDeleted.length(); j++)
    {
      if(elements[i]->key == alreadyDeleted[j])
      {
        found = true;
      }
    }
    if(found == false)
    {
        delete [] elements[i];
    }
  }
  length = 0;
  capacity = 0;
}

/*=======================================================
Assignment Operator
Precondition: ds is a DisjointSets object
Postcondition: Creates a copy of ds
========================================================*/
template<class T>
DisjointSets<T>& DisjointSets<T>::operator= (const DisjointSets<T>& ds)
{
  if(this != &ds)
  {
    delete [] elements;
    capacity = ds.capacity;
    elements = new DSNode<T>*[capacity];
    length = ds.length;
    for(int i = 0; i < length; i++)
    {
      elements[i] = copy(ds.elements[i]);
    }
  }
  return *this;
}

/*==================================================================================
MaketSet Function
Precondition: Elements array of disjoint sets must not be full, x must be of type T,
and a node with key x must not already be in the forest.
Postcondition: A new singleton set has been created in the disjoint set forest.
===================================================================================*/
template<class T>
DSNode<T>* DisjointSets<T>::makeSet(T* x)
{
  // error: disjoint set forest is full
  if (length == capacity)
  {
    throw FullErr();
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
Precondition: x and y are both pointers to nodes in the disjoint set forest.
Postcondition: The disjoint sets that contained nodes x and y have been joined
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
Precondition: x and y are pointers to the representative nodes of their sets.
Postcondition: The sets of x and y have been linked together into one set.
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
Precondition: x is a node in the disjoint set forest.
Postcondition: a pointer to the representative node of the set x is returned.
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

/*=====================================================================================
toString Function
Precondition: called by valid DisjointSets object.
Postcondition: string representation of disjoint set forest is returned with each line
representing a node in the forest. i:j represents a node where i is the key and j is the
rank. Parent relationships of i:j are denoted with an '->' and then the parent's node
representation.
=====================================================================================*/
template<class T>
std::string DisjointSets<T>::toString()
{
  stringstream s;

  for(int i = 0; i < length; i++)
  {
    DSNode<T>* x = elements[i];
    while(x->parent != x)
    {
      s << *(x->key) << ":" << x->rank << " -> ";
      x = x->parent;
    }
    s << *(x->key) << ":" << x->rank << "\n";
  }

  string str = s.str();
  return str;
}

/*=====================================================================================
Stream Operator
Precondition: ds is a DisjointSets object
Postcondition: prints a string representation of a DisjointSets object
=====================================================================================*/
template<class T>
std::ostream& operator<<(std::ostream& stream, const DisjointSets<T>& ds)
{
  stream << ds.toString();
  return stream;
}

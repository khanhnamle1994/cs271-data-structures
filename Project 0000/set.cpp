// James Le - CS 271
// set.cpp
// Jan 25, 2017

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>

template <class Element>
Set<Element>::Set(void) // Default constructor
{}

template <class Element>
Set<Element>::Set(const Set<Element>& s) // Copy constructor
{
  N = source.N;
}

template <class Element>
Set<Element>::~Set(void) // Destructor
{}

// This method adds an non existence item into the set, do nothing if the item is in the set
template <class Element>
void Set<Element>::insert(const Element& x) // Insert Method
{
	if (contains(x) == false)
	{
		N.append(x); // add using list append
	}
}

// This method removes an item in the set, do nothing if the item does not exist
template <class Element>
void Set<Element>::remove(const Element& x) // Remove Method
{
  int i = N.index(x);
  if (i != -1) // if that item is in the set
  {

  }
}

// This method returns the size of the set
template <class Element>
int Set<Element>::cardinality() const // Cardinality Method
{
  int length;
  length = N.length;
  return length;
}

// This method returns true if the set is empty, false otherwise
template <class Element>
bool Set<Element>::empty() const // Empty Method
{

}

// This method returns true if x is in the set, false otherwise
template <class Element>
bool Set<Element>::contains(const Element& x) const // Contains Method
{
  int i = N.index(x);
  if (i == -1)
  {
    return false; // item is not in the set
  }
  return true; // else true
}

// This method returns true if the 2 sets have the same elements, false otherwise
template <class Element>
bool Set<Element>::operator==(const Set<Element>& s) const // Equality Operator
{

}

// This method returns true if one set is a subset of another, false otherwise
template <class Element>
bool Set<Element>::operator<=(const Set<Element>& s) const // Subset Operator
{

}

// This method merges 2 sets into 1, no duplicate
template <class Element>
Set<Element>& Set<Element>::operator+(const Set<Element>& s) const // Union Operator
{

}

// This method takes all the common items from 2 sets and put into 1
template <class Element>
Set<Element>& Set<Element>::operator&(const Set<Element>& s) const // Intersection Operator
{

}

// This method takes the items from 2 sets that are different from each other and put into 1
template <class Element>
Set<Element>& Set<Element>::operator-(const Set<Element>& s) const // Difference Operator
{

}

template <class Element>
Set<Element>& Set<Element>::operator=(const Set<Element>& s) // Assignment Operator
{
  N = source.N;
  return *this;
}

template <class Element>
string Set<Element>::toString() const // Return a string representation of the set
{
  string a = N.str();
  return a;
}

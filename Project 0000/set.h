// James Le - CS 271
// set.h - A Set ADT.
// Jan 25, 2017

#ifndef SET_H
#define SET_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template <class Element>
class Node
{
  public:

   Element value;
   Node<Element> *next;

   Node(Element item)
   {
      value = item;
      next = NULL;
   }
};

template <class Element>
class Set;

template <class Element>
ostream& operator<<(ostream& stream, const Set<Element>& s);

template <class Element>
class Set
{
 public:

   Set();                                   // default constructor
   Set(const Set<Element>& s);              // copy constructor
   ~Set();                                  // destructor

   void insert(const Element& x);           // add x to the set
   void remove(const Element& x);           // remove x from the set
   int cardinality() const;                 // returns size of the set
   bool empty() const;                      // returns true if empty, false o/w
   bool contains(const Element& x) const;   // true if x is in set, false o/w

   bool operator==(const Set<Element>& s) const;           // equality operator
   bool operator<=(const Set<Element>& s) const;           // subset operator
   Set<Element>& operator+(const Set<Element>& s) const;   // union operator
   Set<Element>& operator&(const Set<Element>& s) const;   // intersection operator
   Set<Element>& operator-(const Set<Element>& s) const;   // difference operator

   Set<Element>& operator=(const Set<Element>& s);         // assignment operator

   string toString() const;     // return a string representation of the set

   // stream insertion operator
   friend ostream& operator<< <Element>(ostream& stream, const Set<Element>& s);

 private:

   Node<Element> *head;
   int length;
   Node<Element> N; // inclusion to node class

   void copy(const Set<Element>& s);   // copy the set s to this set
   void destroy();                     // delete all elements in the set
};

#include "set.cpp"

#endif

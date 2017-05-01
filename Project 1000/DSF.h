// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

#ifndef DSF_H
#define DSF_H
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class DSNode
{
public:
  DSNode(T* v = NULL) : rank(-1), parent(NULL), data(v) { };
  int rank;
  DSNode * parent;
  T* data;
};

template<class T>
class DisjointSets
{
public:
  DisjointSets(); // default constructor
  DisjointSets(int size); // constructor with given capacity
  DisjointSets(const DisjointSets<T>& ds); // copy constructor
  ~DisjointSets(); // destructor

  DSNode<T>* makeSet(T* x); // make a new singleton set containing data x
  void unionSets(DSNode<T>* x, DSNode<T>* y); // union the disjoint sets containing data x and y
  DSNode<T>* findSet(DSNode<T>* x); // return the representative of the set containing x

  DisjointSets<T>& operator=(const DisjointSets<T>& ds); // assignment operator

  std::string toString(); // return a string representation of the disjoint set forest

private:
  void copy(const DisjointSets<T>& ds); // copy sets to this element list
  void destroy(); // deallocate disjoint set
  void link(DSNode<T>* x, DSNode<T>* y); // link two disjoint sets together

  DSNode<T> **elements; // array of nodes in the forest
  int capacity; // size of elements array
  int length; // number of elements in the forest
};

template<class T>
std::ostream& operator<<(std::ostream& stream, const DisjointSets<T>& ds); // ostream operator

class FullError { }; // full exception
class NotFoundError { }; // element not found exception

#include "DSF.cpp"

#endif

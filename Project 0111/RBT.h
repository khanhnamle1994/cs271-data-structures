#ifndef RBT_H
#define RBT_H

#include <iostream>
#include <cassert>
using namespace std;

int const RED = 1;
int const BLACK = 2;

/*-------------------------------
  class RedBlackNode
-------------------------------*/
template <class KeyType>
class RedBlackNode
{
public:
  RedBlackNode<KeyType> *left, *right, *parent;
  KeyType data;
  int color;

  RedBlackNode() {
    left = right = parent = NULL;
    color = BLACK;
  }

  RedBlackNode(const KeyType& val) {
    data = val;
    left = right = parent = NULL;
    color = RED;
  }
};

/*-------------------------------
  class RBT
-------------------------------*/
template <class KeyType>
class RBT
{
public:
  /*--------------Constructor and Destructor----------------*/
  RBT(); // default constructor
  RBT(const RBT<KeyType>& tree); // copy constructor
  ~RBT(); // destructor

  /*---------------Public Functions----------------*/
  bool empty() const; // return true if empty; false otherwise
  KeyType* get(const KeyType& k); // return first element with key equal to k
  void insert(KeyType k); // insert k into the tree
  void left_rotate(RedBlackNode<KeyType> *x); // do a left rotation on node x
  void right_rotate(RedBlackNode<KeyType> *y); // do a right rotation on node y
  void print(); // print out all the elements in the tree
  void clear(); // clear all the elements in the tree
  int depth(); // return the depth of the tree
  KeyType* maximum() ; // return the maximum element
  KeyType* minimum() ; // return the minimum element

private:
  /*---------Class Variables----------*/
  RedBlackNode<KeyType> *root;

  /*----------Private Functions----------*/
  void insert_fix(RedBlackNode<KeyType> * x);
  void print(RedBlackNode<KeyType> * n);
  void clear(RedBlackNode<KeyType> * n);
  int depth(RedBlackNode<KeyType> * n);
  RedBlackNode<KeyType> * maximum(RedBlackNode<KeyType> * tree);
  RedBlackNode<KeyType> * minimum(RedBlackNode<KeyType> * tree);
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const RBT<KeyType>& tree);

#include "RBT.cpp"

#endif

// RBT.h
// James Le
// Project 0111
// CS 271: Data Structure

#ifndef RBT_H
#define RBT_H

#include <iostream>
#include "node.h"
using namespace std;

template <class KeyType>
class RBT
{
public:
  /*--------------Constructor and Destructor----------------*/
  RBT(); // default constructor
  RBT(const RBT<KeyType>& rbt); // copy constructor
  ~RBT(); // destructor

  /*---------------Public Functions----------------*/
  bool empty() const; // return true if empty; false otherwise
  KeyType* get(const KeyType& k); // return first element with key equal to k
  void insert(KeyType *k); // insert k into the tree

  KeyType* maximum() ; // return the maximum element
  KeyType* minimum() ; // return the minimum element
  KeyType* successor(const KeyType& k) ; // return the successor of k
  KeyType* predecessor(const KeyType& k) ; // return the predecessor of k

  std::string preOrder() const; // return string of elements from a preorder traversal
  std::string toString() const; // return string of elements from an inorder traversal
  std::string postOrder() const; // return string of elements from a postorder traversal

  RBT<KeyType>& operator=(const RBT<KeyType>& rbt); // assignment operator

private:
  /*---------Class Variables----------*/
  Node<KeyType> *root; // root node
  Node<KeyType> *nil; // nil node

  /*----------Private Functions----------*/
  void deleteNode(Node<KeyType> *node); // delete helper function
  Node<KeyType> *copy(Node<KeyType> *node, Node<KeyType> *p, Node<KeyType> *otherNil); // copy helper function
  void ins(KeyType *k, Node<KeyType> *node); // insert helper function

  std::string pre(Node<KeyType> *node) const; // preOrder toString helper function
  std::string order(Node<KeyType> *node) const; // inOrder toString helper function
  std::string post(Node<KeyType> *node) const; // postOrder toString helper function

  void insertFixup(Node<KeyType> * node); // insert fixup to help balance the tree black-height-wise
  void leftRotate(Node<KeyType> *node); // left rotation to help rotate the tree to the left
  void rightRotate(Node<KeyType> *node); // right rotation to help rotate the tree to the right

  Node<KeyType> *getNode(const KeyType& k, Node<KeyType> *node); // get helper function
  KeyType *max(Node<KeyType> *node); // maximum method helper function
  KeyType *min(Node<KeyType> *node); // minimum method helper function
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const RBT<KeyType>& rbt); // ostream operator

class Empty { };
class Key { };

#include "RBT.cpp"

#endif

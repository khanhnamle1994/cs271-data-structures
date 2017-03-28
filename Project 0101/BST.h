#ifndef BST_H
#define BST_H

#include <iostream>
#include <cassert>
using namespace std;

/*-------------------------------
  class BinaryNode
-------------------------------*/
template <class KeyType>
class BinaryNode
{
public:
  BinaryNode<KeyType> *left, *right, *parent;
  KeyType data;

  BinaryNode() : data(KeyType()), left(NULL), right(NULL), parent(NULL) {}
  BinaryNode(const KeyType& val) : data(val), left(NULL), right(NULL), parent(NULL) {}
};

/*-------------------------------
  class BST
-------------------------------*/
template <class KeyType>
class BST
{
public:
  /*--------------Constructor and Destructor----------------*/
  BST(); // default constructor
  BST(const BST<KeyType>& tree); // copy constructor
  ~BST(); // destructor

  /*---------------Public Functions----------------*/
  bool empty() const; // return true if empty; false otherwise
  KeyType* get(const KeyType& k); // return first element with key equal to k
  void insert(KeyType k); // insert k into the tree
  void remove(const KeyType& k); // delete first element with key equal to k
  KeyType* maximum() const; // return the maximum element
  KeyType* minimum() const; // return the minimum element
  KeyType* successor(const KeyType& k); // return the successor of k
  KeyType* predecessor(const KeyType& k); // return the predecessor of k

  /*--------------Public Print Functions---------------*/
  std::string inOrder() const; // return string of elements from an inOrder traversal
  std::string preOrder() const; // return string of elements from a preOrder traversal
  std::string postOrder() const; // return string of elements from a postOrder traversal

protected:
  /*---------Class Variables----------*/
  BinaryNode<KeyType> *root;
  int tree_size;

  /*----------Private Functions----------*/
  void insert(const KeyType& k, BinaryNode<KeyType> * &ptr, BinaryNode<KeyType> * &dad);
  void remove(const KeyType& k, BinaryNode<KeyType> * &ptr);
  BinaryNode<KeyType> * get(const KeyType& k, BinaryNode<KeyType> * ptr);
  int maximum(BinaryNode<KeyType> * ptr);
  BinaryNode<KeyType> * minimum(BinaryNode<KeyType> * ptr);
  void successor(const KeyType& k, BinaryNode<KeyType> * ptr);
  void predecessor(const KeyType& k, BinaryNode<KeyType> * ptr);
  void clearTree(BinaryNode<KeyType> * &ptr);
  void clone(BinaryNode<KeyType> * ptr);
  void transplant(BinaryNode<KeyType> * u, BinaryNode<KeyType> * v);

  /*----------Private Print Functions----------*/
  std::string inOrder(BinaryNode<KeyType> *ptr) const; // recursively prints the BST in inorder format
  std::string preOrder(BinaryNode<KeyType> *ptr) const; // recursively prints the BST in preorder format
  std::string postOrder(BinaryNode<KeyType> *ptr) const; // recursively prints the BST in postorder format
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const BST<KeyType>& tree);

#include "BST.cpp"

#endif

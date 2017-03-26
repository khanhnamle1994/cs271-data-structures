#ifndef BST_H
#define BST_H

#include <iostream>
#include <cassert>
using namespace std;

/*-------------------------------
  class BinaryNode
-------------------------------*/
template <class KeyType>
struct BinaryNode
{
  BinaryNode *left, *right;
  KeyType data;

  BinaryNode() : data(KeyType()), left(NULL), right(NULL) {}
  BinaryNode(const KeyType& val) : data(val), left(NULL), right(NULL) {}
};

/*-------------------------------
  class BST
-------------------------------*/
template <class KeyType>
class BST
{
public:
  /*------Type Declaration--------*/
  typedef BinaryNode<KeyType> Node;

  /*--------------Constructor and Destructor----------------*/
  BST(); // default constructor
  BST(const BST<KeyType>& tree); // copy constructor
  ~BST(); // destructor

  /*---------------Public Functions----------------*/
  bool empty() const; // return true if empty; false otherwise
  KeyType* get(const KeyType& k); // return first element with key equal to k
  void insert(KeyType* k); // insert k into the tree
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
  Node *root;
  int tree_size;

  /*----------Private Functions----------*/
  void insert(const KeyType& k, Node * &ptr);
  void remove(const KeyType& k, Node * &ptr);
  Node *get(const KeyType* k, Node * ptr) const;
  Node *maximum(Node * ptr) const;
  Node *minimum(Node * ptr) const;
  Node *successor(const KeyType* k, Node * ptr) const;
  Node *predecessor(const KeyType* k, Node * ptr) const;
  void clearTree(Node * &ptr);
  Node *clone(Node * ptr) const;

  /*----------Private Print Functions----------*/
  std::string inOrder(Node *ptr) const; // recursively prints the BST in inorder format
  std::string preOrder(Node *ptr) const; // recursively prints the BST in preorder format
  std::string postOrder(Node *ptr) const; // recursively prints the BST in postorder format
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const BST<KeyType>& tree);

#include "BST.cpp"

#endif

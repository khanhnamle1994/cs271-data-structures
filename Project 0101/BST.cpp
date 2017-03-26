#ifndef BST_CPP
#define BST_CPP
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Default Constructor
template <class KeyType>
BST<KeyType>::BST()
{
  root = NULL;
  tree_size = 0;
}

// Copy Constructor
template <class KeyType>
BST<KeyType>::BST(const BST<KeyType>& tree)
{
  root = clone(tree.root);
  tree_size = tree.tree_size;
}

// Clone Method
// Basically a recursive preorder traversal over a tree and copy each node
template <class KeyType>
BST<KeyType>::Node * BST<KeyType>::clone(Node * ptr) const
{
  if (ptr)
  {
    Node *newNode = new Node(ptr->data);
    newNode->left = clone(ptr->left);
    newNode->right = clone(ptr->right);
    return newNode;
  }
  return NULL;
}

// Destructor
template <class KeyType>
BST<KeyType>::~BST()
{
  clearTree(root);
}

// ClearTree Method
// Basically a recursive postorder traversal over a tree and delete each node
template <class KeyType>
void BST<KeyType>::clearTree(Node * & ptr)
{
  if (ptr)
  {
    clearTree(ptr->left);
    clearTree(ptr->right);
    delete ptr; // visit => delete node
    ptr = NULL;
  }
}

template <class KeyType>
bool BST<KeyType>::empty() const
{
  return tree_size == 0;
}

template <class KeyType>
KeyType* BST<KeyType>::get(const KeyType& k)
{

}

template <class KeyType>
void BST<KeyType>::insert(KeyType* k)
{
  insert(k, root);
}

template <class KeyType>
void BST<KeyType>::remove(const KeyType& k)
{
  remove(k, root);
}

template <class KeyType>
KeyType* BST<KeyType>::maximum() const
{

}

template <class KeyType>
KeyType* BST<KeyType>::minimum() const
{

}

template <class KeyType>
KeyType* BST<KeyType>::successor(const KeyType& k)
{

}

template <class KeyType>
KeyType* BST<KeyType>::predecessor(const KeyType& k)
{

}

template <class KeyType>
std::string BST<KeyType>::inOrder() const
{

}

template <class KeyType>
std::string BST<KeyType>::preOrder() const
{

}

template <class KeyType>
std::string BST<KeyType>::postOrder() const
{

}

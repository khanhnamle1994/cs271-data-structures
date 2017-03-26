#ifndef BST_cpp
#define BST_cpp
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
void BST<KeyType>::clone(BinaryNode<KeyType> * ptr)
{
  if (ptr)
  {
    BinaryNode<KeyType> *newNode = new BinaryNode<KeyType>(ptr->data);
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
void BST<KeyType>::clearTree(BinaryNode<KeyType> * & ptr)
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
  BinaryNode<KeyType> *ptr = get(k, root);
  if (ptr)
    return &ptr->data;
  else
    return (KeyType*) NULL;
}

template <class KeyType>
void BST<KeyType>::get(const KeyType& k, BinaryNode<KeyType> * ptr)
{
  while (ptr)
  {
    if (k < ptr->data)
      ptr = ptr->left;
    else if (ptr->data < k)
      ptr = ptr->right;
    else
      break;
  }
  return ptr;
}

template <class KeyType>
void BST<KeyType>::insert(KeyType* k)
{
  insert(k, root);
}

template <class KeyType>
void BST<KeyType>::insert(const KeyType& k, BinaryNode<KeyType> * &ptr)
{
  if (ptr == NULL)
  {
    ptr = new BinaryNode<KeyType>(k);
    tree_size++;
  } else {
    if (k < ptr->data)
      insert(k, ptr->left);
    else
      insert(k, ptr->right);
  }
}

// Remove Function
template <class KeyType>
void BST<KeyType>::remove(const KeyType& k)
{
  remove(k, root);
}


template <class KeyType>
void BST<KeyType>::remove(const KeyType& k, BinaryNode<KeyType> * &ptr)
{
  if (ptr->left == NULL)
    transplant(ptr, ptr->right);
  else if (ptr->right == NULL)
    transplant(ptr, ptr->left);
  else {
    // Has 2 children -- successor(k) must be on the right
    BinaryNode<KeyType> *k = minimum(ptr->right);
    if (k->parent != ptr) {
      transplant(k, k->right);
      k->right = ptr->right;
      k->right->parent = k;
    }
    transplant(ptr, k);
    k->left = ptr->left;
    k->left->parent = k;
  }
}

// The Transplant method replaces the subtree rooted at node u with the subtree rooted at node v,
// node u's parent becomes node v's parent, and u's parent ends up having v as its appropriate child.
template <class KeyType>
void BST<KeyType>::transplant(BinaryNode<KeyType> * u, BinaryNode<KeyType> * v)
{
  if (u->parent == NULL)
    root = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else if (u == u->parent->right)
    u->parent->right = v;
  if (v != NULL)
    v->parent = u->parent;
}

// Maximum function
template <class KeyType>
KeyType* BST<KeyType>::maximum() const
{
  BinaryNode<KeyType> *ptr = maximum(root);
  assert(ptr);
  return ptr->data;
}

// Iterative version of maximum
template <class KeyType>
int BST<KeyType>::maximum(BinaryNode<KeyType> * ptr)
{
  if (ptr)
  {
    while (ptr->right)
      ptr = ptr->right;
  }
  return ptr;
}

// Minimum function
template <class KeyType>
KeyType* BST<KeyType>::minimum() const
{
  BinaryNode<KeyType> *ptr = minimum(root);
  assert(ptr);
  return ptr->data;
}

// Iterative version of minimum
template <class KeyType>
int BST<KeyType>::minimum(BinaryNode<KeyType> * ptr)
{
  if (ptr)
  {
    while (ptr->left)
      ptr = ptr->left;
  }
  return ptr;
}

// Successor Function
template <class KeyType>
KeyType* BST<KeyType>::successor(const KeyType& k)
{
  successor(k, root);
}

template <class KeyType>
void BST<KeyType>::successor(const KeyType& k, BinaryNode<KeyType> * ptr)
{
  if (ptr == NULL)
    return NULL;
  if (ptr->right) {
    return minimum(ptr->right);
  } else {
    BinaryNode<KeyType> *k = ptr->parent;
    while (k != NULL && ptr == k->right) {
      ptr = k;
      k = k->parent;
    }
    return k;
  }
}

// Predecessor Function
template <class KeyType>
KeyType* BST<KeyType>::predecessor(const KeyType& k)
{
  predecessor(k, root);
}

template <class KeyType>
void BST<KeyType>::predecessor(const KeyType& k, BinaryNode<KeyType> * ptr)
{
  if (ptr == NULL)
    return NULL;
  if (ptr->left) {
    return maximum(ptr->left);
  } else {
    BinaryNode<KeyType> *k = ptr->parent;
    while (k != NULL && ptr == k->left) {
      ptr = k;
      k = k->parent;
    }
    return k;
  }
}

// Traversal Functions
template <class KeyType>
std::string BST<KeyType>::inOrder() const
{
  inOrder(root);
}

template <class KeyType>
std::string BST<KeyType>::inOrder(BinaryNode<KeyType> *ptr) const
{
  if (ptr == NULL)
    return "";
  ostringstream ss;
  ss << inOrder(ptr->left);
  ss << ptr->data << " ";
  ss << inOrder(ptr->right);
  return ss.str();
}

template <class KeyType>
std::string BST<KeyType>::preOrder() const
{
  preOrder(root);
}

template <class KeyType>
std::string BST<KeyType>::preOrder(BinaryNode<KeyType> *ptr) const
{
  if (ptr == NULL)
    return "";
  ostringstream ss;
  ss << ptr->data << " ";
  ss << preOrder(ptr->left);
  ss << preOrder(ptr->right);
  return ss.str();
}

template <class KeyType>
std::string BST<KeyType>::postOrder() const
{
  postOrder(root);
}

template <class KeyType>
std::string BST<KeyType>::postOrder(BinaryNode<KeyType> *ptr) const
{
  if (ptr == NULL)
    return "";
  ostringstream ss;
  ss << postOrder(ptr->left);
  ss << postOrder(ptr->right);
  ss << ptr->data << " ";
  return ss.str();
}

#endif

#ifndef BST_cpp
#define BST_cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*=========================================
BST()     //default constructor
Precondition: None
Postcondition: An empty binary search tree
=========================================*/
template <class KeyType>
BST<KeyType>::BST()
{
  root = NULL;
  tree_size = 0;
}

/*==============================================================
BST(const BST<KeyType>& tree);  // copy constructor
Precondition: Must be given a binary tree
Postcondition: Traverses the tree and makes a copy of its values
		to transfer to another tree
==============================================================*/
template <class KeyType>
BST<KeyType>::BST(const BST<KeyType>& tree)
{
  root = clone(tree.root);
  tree_size = tree.tree_size;
}

/*====================================================================================
clone(BinaryNode<KeyType> * ptr) // clone method
Precondition: Must be a given binary tree
Postcondition: Basically a recursive preorder traversal over a tree and copy each node
====================================================================================*/
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

/*==========================================================
 ~BST();                             // destructor
Precondition: None
Postcondition: Deallocates the tree
============================================================*/
template <class KeyType>
BST<KeyType>::~BST()
{
  clearTree(root);
}

/*========================================================================================
// clearTree(BinaryNode<KeyType> * ptr) ClearTree Method
Precondition: Must be a given binary tree
Postcondition:  Basically a recursive postorder traversal over a tree and delete each node
========================================================================================*/
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

/*=========================================================================
bool empty() const                       // return whether the MPQ is empty
Precondition: None
Postcondition: Returns true if the binary tree is empty, false otherwise
=========================================================================*/
template <class KeyType>
bool BST<KeyType>::empty() const
{
  return tree_size == 0;
}

/*=================================================================================
get(const KeyType& k)                   // return first element with key equal to k
Precondition: Must be a given binary tree
Postcondition: Recursively calls the hidden 'get' method
=================================================================================*/
template <class KeyType>
KeyType* BST<KeyType>::get(const KeyType& k)
{
  BinaryNode<KeyType> *ptr = get2(k, root);

  if (ptr){
    //cout << ptr->data << " is in tree" << endl;
    return &ptr->data;
  }
  else{
    //cout << k << " is NOT in tree" << endl;
    cout << "Not in tree" <<endl;
    //return (KeyType*) NULL;
  }

}

/*==============================================================================================
get(const KeyType& k, BinaryNode>KeyType>* ptr)                      // Protected "get" function
Precondition: Must be a given binary tree
Postcondition: Returns a pointer to a node with key k if one exists; otherwise, returns NIL
===============================================================================================*/
template <class KeyType>
BinaryNode<KeyType> * BST<KeyType>::get2(const KeyType& k, BinaryNode<KeyType> * ptr)
{

  while (ptr)
  {
    if (ptr->data > k)
      ptr = ptr->left;
    else if (ptr->data < k)
      ptr = ptr->right;
    else
      break;
  }
  return ptr;
}

/*=================================================================================
insert(const KeyType& k)             // insert element with key equal k to the tree
Precondition: Must be a given binary tree
Postcondition: Rercursively calls the hidden 'insert' method
=================================================================================*/
template <class KeyType>
void BST<KeyType>::insert(KeyType k)
{
  insert(k, root, root);
}

/*============================================================================================================
insert(const KeyType& k, BinaryNode>KeyType>* ptr, BinaryNode<KeyType* dad)     // Protected "insert" function
Precondition: Must be a given binary tree
Postcondition: Begins at the root of the tree and the pointer ptr traces a simple path downward looking for a
NIL to replace with the input item k
============================================================================================================*/
template <class KeyType>
void BST<KeyType>::insert( KeyType& k, BinaryNode<KeyType> * &ptr, BinaryNode<KeyType> * &dad)
{
  if (ptr == NULL)
  {
    ptr = new BinaryNode<KeyType>(k);
    if(tree_size != 0){
      ptr->parent = dad;
    }
    tree_size++;
  }
  else {
    if (k < ptr->data)
      insert(k, ptr->left, ptr);
    else
      insert(k, ptr->right, ptr);
  }

  if(ptr->parent != NULL){
    //cout << "ptr->parent->data= " << ptr->parent->data <<endl;      DELETE HERE SLATE
  }
}

/*===================================================================================
remove(const KeyType& k)       // delete first element with key equal k from the tree
Precondition: Must be a given binary tree
Postcondition: Rercursively calls the hidden 'remove' method
===================================================================================*/
template <class KeyType>
void BST<KeyType>::remove(const KeyType& k)
{

  remove(k, root);
}

/*=========================================================================================================
remove(const KeyType& k, BinaryNode<KeyType> * &ptr)     // Protected "remove" function
Precondition: Must be a given binary tree
Postcondition:
1 - If k has no children, then simply remove it by modifying its parent to replace k with NIL as its child.
2 - If k has just one child, then we elevate that child to take k's position in the tree by modifying k's
parent to replace k by k's child.
3 - If k has 2 children, then we find k's successor y and have y take k's position in the tree. The rest
of k's original right subtree becomes y's new right subtree, and k's left subtree becomes y's new left subtree.
========================================================================================================*/
template <class KeyType>
void BST<KeyType>::remove(const KeyType& k, BinaryNode<KeyType> * &ptr)
{


  BinaryNode<KeyType> *temp;
  temp = ptr;

  while ((temp->data !=k) and ((temp->left !=NULL) or (temp->right!=NULL))){
    if(temp->data > k){
      temp = temp->left;
    }
    else
      temp = temp->right;
  }



  if (temp->left == NULL)
    transplant(temp, temp->right);
  else if (temp->right == NULL)
    transplant(temp, temp->left);
  else {
    // Has 2 children -- successor(k) must be on the right
//cout << "temp->left->data= " << temp->left->data <<endl;
    BinaryNode<KeyType> *y = mintree(temp->right);
//cout << "y->data="<< y->data <<endl;
    if (y->parent != temp) {
      transplant(y, y->right);
      y->right = ptr->right;
      y->right->parent = y;
    }
    transplant(temp, y);
    y->left = temp->left;
    y->left->parent = y;
  }

  tree_size--;


}

/*==============================================================================================
transplant(BinaryNode<KeyType> * u, BinaryNode<KeyType> * v)      //Transplant Method
Precondition: Must be a given binary tree
Postcondition: Replaces the subtree rooted at node u with the subtree rooted at node v,
u's parent becomes node v's parent, and u's parent ends up having v as its appropriate child.
==============================================================================================*/
template <class KeyType>
void BST<KeyType>::transplant(BinaryNode<KeyType> * u, BinaryNode<KeyType> * v)
{

  if (u->parent == NULL){
    root = v;
  }
  else if (u == u->parent->left)
    u->parent->left = v;
  else if (u == u->parent->right)
    u->parent->right = v;
  if (v != NULL)
    v->parent = u->parent;

}

/*===========================================================
maximum()             // return the maximum element
Precondition: Must be a given binary tree
Postcondition: Rercursively calls the hidden 'maxtree' method
============================================================*/
template <class KeyType>
KeyType* BST<KeyType>::maximum()
{
  BinaryNode<KeyType> *temp = maxtree(root);
  assert(temp);
  return &(temp->data);
}

/*================================================================================
maxtree()                         // Protected "maxtree" function
Precondition: Must be a given binary tree
Postcondition: Follows right child pointers from the root until we encounter a NIL
=================================================================================*/
template <class KeyType>
BinaryNode<KeyType> * BST<KeyType>::maxtree(BinaryNode<KeyType> * ptr)
{

  if (ptr)
  {
    while (ptr->right)
      ptr = ptr->right;
  }
  return ptr;
}

/*===========================================================
minimum()             // return the minimum element
Precondition: Must be a given binary tree
Postcondition: Rercursively calls the hidden 'mintree' method
============================================================*/
template <class KeyType>
KeyType* BST<KeyType>::minimum()
{
  BinaryNode<KeyType> *temp = mintree(root);
  assert(temp);
  return &(temp->data);
}

/*================================================================================
mintree()                           // Protected "mintree" function
Precondition: Must be a given binary tree
Postcondition: Follows left child pointers from the root until we encounter a NIL
=================================================================================*/
template <class KeyType>
BinaryNode<KeyType> * BST<KeyType>::mintree(BinaryNode<KeyType> * ptr)
{
  if (ptr)
  {
    while (ptr->left)
      ptr = ptr->left;
  }
  return ptr;
}

/*=================================================================================
get(const KeyType& k)                   // return the successor of k
Precondition: Must be a given binary tree
Postcondition: Recursively calls the hidden 'successor' method
=================================================================================*/
template <class KeyType>
KeyType* BST<KeyType>::successor(const KeyType& k)
{
  BinaryNode<KeyType> *temp;
  temp = successor(k, root);
  return &(temp->data);
}

/*==========================================================================================================
successor(const KeyType& k, BinaryNode<KeyType> * ptr)              // Protected "successor" function
Precondition: Must be a given binary tree
Postcondition: If the right subtree of node ptr is non-empty, then the successor of ptr is the leftmost node
in ptr's right subtree. On the other hand, if the right subtree of node ptr is empty and ptr has a successor
k, then k is the lowest ancestor of ptr whose left child is also an ancestor of ptr
==========================================================================================================*/
template <class KeyType>
BinaryNode<KeyType> * BST<KeyType>::successor(const KeyType& k, BinaryNode<KeyType> * ptr)
{
  if (ptr == NULL)
    return NULL;
  if (ptr->right) {
    return mintree(ptr->right);
  }
  else {
    BinaryNode<KeyType> *k = ptr->parent;
    while (k != NULL && ptr == k->right) {
      ptr = k;
      k = k->parent;
    }
    return k;
  }
}

/*=================================================================================
get(const KeyType& k)                   // return the predecessor of k
Precondition: Must be a given binary tree
Postcondition: Recursively calls the hidden 'predecessor' method
=================================================================================*/
template <class KeyType>
KeyType* BST<KeyType>::predecessor(const KeyType& k)
{
  predecessor(k, root);
}

/*==========================================================================================================
predecessor(const KeyType& k, BinaryNode<KeyType> * ptr)              // Protected "predecessor" function
Precondition: Must be a given binary tree
Postcondition: If the left subtree of node ptr is non-empty, then the predecessor of ptr is the rightmost node
in ptr's left subtree. On the other hand, if the left subtree of node ptr is empty and ptr has a predecessor
k, then k is the lowest ancestor of ptr whose right child is also an ancestor of ptr
==========================================================================================================*/
template <class KeyType>
void BST<KeyType>::predecessor(const KeyType& k, BinaryNode<KeyType> * ptr)
{
  if (ptr == NULL)
    return NULL;
  if (ptr->left) {
    return maxtree(ptr->left);
  } else {
    BinaryNode<KeyType> *k = ptr->parent;
    while (k != NULL && ptr == k->left) {
      ptr = k;
      k = k->parent;
    }
    return k;
  }
}

/*==========================================================================
inOrder()             // return string of elements from an inOrder traversal
Precondition: Must be a given binary tree
Postcondition: Rercursively calls the hidden 'inOrder' method
==========================================================================*/
template <class KeyType>
std::string BST<KeyType>::inOrder() const
{
  inOrder(root);
}

/*=========================================================================================
inOrder(BinaryNode<KeyType> *ptr) const                     // Protected "inOrder" function
Precondition: Must be a given binary tree
Postcondition: Prints the key of the root of a subtree between printing the values in its
left subtree and printng those in its right subtree
=========================================================================================*/
template <class KeyType>
std::string BST<KeyType>::inOrder(BinaryNode<KeyType> *ptr) const
{

  if (ptr == NULL)
    return "";

  ostringstream ss;
    ss << inOrder(ptr->left);
    ss << ptr->data << " ";
    ss << inOrder(ptr->right);
    cout << ss.str() << endl;

  return ss.str();


}

/*===========================================================================
preOrder()             // return string of elements from a preOrder traversal
Precondition: Must be a given binary tree
Postcondition: Rercursively calls the hidden 'preOrder' method
===========================================================================*/
template <class KeyType>
std::string BST<KeyType>::preOrder() const
{
  preOrder(root);
}

/*=========================================================================================
preOrder(BinaryNode<KeyType> *ptr) const                    // Protected "preOrder" function
Precondition: Must be a given binary tree
Postcondition: Prints the key of the root of a subtree before printing the values in its
left subtree and printng those in its right subtree
=========================================================================================*/
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

/*=============================================================================
postOrder()             // return string of elements from a postOrder traversal
Precondition: Must be a given binary tree
Postcondition: Rercursively calls the hidden 'postOrder' method
=============================================================================*/
template <class KeyType>
std::string BST<KeyType>::postOrder() const
{
  postOrder(root);
}

/*=========================================================================================
postOrder(BinaryNode<KeyType> *ptr) const                     // Protected "postOrder" function
Precondition: Must be a given binary tree
Postcondition: Prints the key of the root of a subtree after printing the values in its
left subtree and printng those in its right subtree
=========================================================================================*/
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

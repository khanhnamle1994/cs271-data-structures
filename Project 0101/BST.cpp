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
  if (ptr){
    cout << ptr->data << " is in tree" << endl;
    return &ptr->data;
  }
  else{
    cout << k << " is NOT in tree" << endl;
    //return (KeyType*) NULL;
  }
}

template <class KeyType>
BinaryNode<KeyType> * BST<KeyType>::get(const KeyType& k, BinaryNode<KeyType> * ptr)
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
void BST<KeyType>::insert(KeyType k)
{
  insert(k, root, root);
}

template <class KeyType>
void BST<KeyType>::insert(const KeyType& k, BinaryNode<KeyType> * &ptr, BinaryNode<KeyType> * &dad)
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

// Remove Function
template <class KeyType>
void BST<KeyType>::remove(const KeyType& k)
{

  remove(k, root);
}


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

// The Transplant method replaces the subtree rooted at node u with the subtree rooted at node v,
// node cout << "worked" << endl;u's parent becomes node v's parent, and u's parent ends up having v as its appropriate child.
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

// Maximum function
template <class KeyType>
KeyType* BST<KeyType>::maximum()
{
  BinaryNode<KeyType> *temp = maxtree(root);
  assert(temp);
  return &(temp->data);
}

// Iterative version of maximum
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

// Minimum function
template <class KeyType>
KeyType* BST<KeyType>::minimum()
{
  BinaryNode<KeyType> *temp = mintree(root);
  assert(temp);
  return &(temp->data);
}

// Iterative version of minimum
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

// Successor Function
template <class KeyType>
KeyType* BST<KeyType>::successor(const KeyType& k)
{
  BinaryNode<KeyType> *temp;
  temp = successor(k, root);
  return &(temp->data);
}

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

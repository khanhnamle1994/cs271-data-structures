// RBT.cpp
// James Le
// Project 0111
// CS 271: Data Structure

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

/*===================================================
Constructor
Precondition: None
Postcondition: A constructed RBT with root initialized
to NULL and a nil node to an empty black node.
====================================================*/
template <class KeyType>
RBT<KeyType>::RBT()
{
  root = NULL;
  nil = new Node<KeyType>("Black");
}

/*===================================================
Copy Constructor
Precondition: A constructed RBT object
Postcondition: A copy constructor of a new RBT that is
a copy of the RBT passed in as a parameter.
====================================================*/
template <class KeyType>
RBT<KeyType>::RBT(const RBT<KeyType>& rbt)
{
  root = NULL;
  nil = new Node<KeyType>("Black");
  root = copy(rbt.root, nil, rbt.nil);
}

/*======================================================
Copy Method
Precondition: A constructed RBT object
Postcondition: A copy helper method that copies a RBT.
The method is then passed into the RBT copy constructor.
======================================================*/
template <class KeyType>
Node<KeyType>* RBT<KeyType>::copy(Node<KeyType> *node, Node<KeyType> *p, Node<KeyType> *otherNil)
{
  Node<KeyType> *newNode = new Node<KeyType>(node->key);
  if(node == otherNil)
  {
    return nil;
  }

  newNode->color = node->color;
  newNode->parent = p;
  newNode->left = copy(node->left, newNode, otherNil);
  newNode->right = copy(node->right, newNode, otherNil);
  return newNode;
}

/*===================================================
Destructor
Precondition: A constructed RBT object
Postcondition: Deallocates the space that was allocated
for the RBT.
====================================================*/
template <class KeyType>
RBT<KeyType>::~RBT()
{
  deleteNode(root);
  delete nil;
}

/*====================================================
Destroy Method
Precondition: A constructed RBT object
Postcondition: A destroy helper method that destroys a
RBT. The method is then passed into the RBT destructor.
=====================================================*/
template <class KeyType>
void RBT<KeyType>::deleteNode(Node<KeyType> *node)
{
  if(node != nil and node != NULL)
  {
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
  }
}

/*===================================================
Get Method
Precondition: A constructed RBT object
Postcondition: RBT is unchanged, and a KeyType* is
returned from the tree.
====================================================*/
template <class KeyType>
KeyType* RBT<KeyType>::get(const KeyType& k)
{
  Node<KeyType> *toReturn = getNode(k, root);
  return toReturn->key;
}

/*===================================================
Get Helper Function
Precondition: A constructed RBT object
Postcondition: RBT is unchanged, and a a Node<KeyType*>
is returned from the tree.
====================================================*/
template <class KeyType>
Node<KeyType>* RBT<KeyType>::getNode(const KeyType& k, Node<KeyType> *node)
{
  if(root == NULL)
  {
    throw Empty();
  }
  if(node->item == NULL)
  {
    throw Key();
  }
  if(k == *(node->key))
  {
    return node;
  }
  else if(k < *(node->key))
  {
    return getNode(k, node->left);
  }
  else
  {
    return getNode(k, node->right);
  }
}

/*===================================================
Empty Method
Precondition: A constructed RBT object
Postcondition: RBT is unchanged, and a boolean is returned
based on if the RBT is empty or contains an item.
====================================================*/
template <class KeyType>
bool RBT<KeyType>::empty() const
{
  if(root == NULL)
  {
    return true;
  }
  return false;
}

/*===========================================================
Maximum Method
Precondition: A constructed RBT object
Postcondition: RBT is unchanged, and a pointer of type KeyType
is returned. This pointer points to the max value in the RBT
============================================================*/
template <class KeyType>
KeyType* RBT<KeyType>::maximum()
{
  KeyType *toReturn = max(root);
  return toReturn;
}

/*============================================================
Maximum Helper Function
Precondition: A constructed RBT object
Postcondition: RBT is unchanged, and a pointer of type KeyType
is returned. This pointer points to the max value in the RBT.
=============================================================*/
template <class KeyType>
KeyType* RBT<KeyType>::max(Node<KeyType> *node)
{
  if(root == NULL)
  {
    throw Empty();
  }
  if(node == NULL)
  {
    return NULL;
  }
  if(node->right == nil)
  {
    return node->key;
  }
  return max(node->right);
}

/*=============================================================
Minimum Method
Precondition: A constructed RBT object
Postcondition: RBT is unchanged, and a pointer of type KeyType
is returned. This pointer points to the min value in the RBT
=============================================================*/
template <class KeyType>
KeyType* RBT<KeyType>::minimum()
{
  KeyType *toReturn = min(root);
  return toReturn;
}

/*=============================================================
Minimum Helper Function
Precondition: A constructed RBT object
Postcondition: RBT is unchanged, and a pointer of type KeyType
is returned. This pointer points to the min value in the RBT.
=============================================================*/
template <class KeyType>
KeyType* RBT<KeyType>::min(Node<KeyType> *node)
{
  if(root == NULL)
  {
    throw Empty();
  }
  if(node == NULL)
  {
    return NULL;
  }
  if(node->left == nil)
  {
    return node->key;
  }
  return min(node->left);
}

/*=================================================================
Successor Method
Precondition: A constructed RBT object
Postcondition: Returns the successor to k of type KeyType from RBT.
=================================================================*/
template <class KeyType>
KeyType* RBT<KeyType>::successor(const KeyType& k)
{
  if(root == NULL)
  {
    throw Empty();
  }
  Node<KeyType> *nodeX = getNode(k, root);
  Node<KeyType> *nodeY;
  if(nodeX->right != nil)
  {
    return min(nodeX->right);
  }
  nodeY = nodeX->parent;
  while(nodeY != nil && nodeX == nodeY->right)
  {
    nodeX = nodeY;
    nodeY = nodeY->parent;
  }
  if(nodeY->key == NULL)
  {
    throw Key();
  }
  return nodeY->key;
}

/*=================================================================
Predecessor Method
Precondition: A constructed RBT object
Postcondition: Returns the predecessor to k of type KeyType from RBT.
=================================================================*/
template <class KeyType>
KeyType* RBT<KeyType>::predecessor(const KeyType& k)
{
  if(root == NULL)
  {
    throw Empty();
  }
  Node<KeyType> *nodeX = getNode(k, root);
  Node<KeyType> *nodeY;
  if(nodeX->left != nil)
  {
    return max(nodeX->left);
  }
  nodeY = nodeX->parent;
  while(nodeY != nil && nodeX == nodeY->left)
  {
    nodeX = nodeY;
    nodeY = nodeY->parent;
  }
  if(nodeY->key == NULL)
  {
    throw Key();
  }
  return nodeY->key;
}

/*=================================================================
Insert Method
Precondition: A constructed RBT object
Postcondition: A RBT object with KeyType *k inserted into the RBT.
=================================================================*/
template <class KeyType>
void RBT<KeyType>::insert(KeyType *k)
{
  ins(k, root);
}

/*=================================================================
Insert Helper Function
Precondition: A constructed RBT object
Postcondition: A RBT object with KeyType *k inserted into the RBT.
=================================================================*/
template <class KeyType>
void RBT<KeyType>::ins(KeyType *k, Node<KeyType> *node)
{
  Node<KeyType>  *newNode = new Node<KeyType>(k);

  if(node == NULL)
  {
    root = newNode;
    root->right = nil;
    root->left = nil;
    root->parent = nil;
    insertFixup(root);
  }
  else if(*k <= *(node->key) && node->left = nil)
  {
    node->left = newNode;
    newNode->parent = node;
    newNode->left = nil;
    newNode->right = nil;
    insertFixup(newNode);
  }
  else if(*k > *(node->key) && node->right = nil)
  {
    node->right = newNode;
    newNode->parent = node;
    newNode->left = nil;
    newNode->right = nil;
    insertFixup(newNode);
  }
  else if(*k <= *(node->key))
  {
    ins(k, node->left);
  }
  else
  {
    ins(k, node->right);
  }
}

/*=================================================================
Insert Fixup Method
Precondition: A constructed RBT object
Postcondition: A RBT that abides by the 5 rules of a RBT.
=================================================================*/
template <class KeyType>
void RBT<KeyType>::insertFixup(Node<KeyType> * node)
{
  Node<KeyType> *tempNode = new Node<KeyType>;
  while(node->parent->color == "Red")
  {
    if(node->parent == node->parent->parent->left)
    {
      tempNode = node->parent->parent->right;
      if(tempNode->color == "Red")
      {
        node->parent->color = "Black";
        tempNode->color = "Black";
        node->parent->parent->color = "Red";
        node = node->parent->parent;
      }
      else
      {
        if(node == node->parent->right)
        {
          node = node->parent;
          leftRotate(node);
        }
        node->parent->color = "Black";
        node->parent->parent->color = "Red";
        rightRotate(node->parent->parent);
      }
    }
    else
    {
      tempNode = node->parent->parent->left;
      if(tempNode->color == "Red")
      {
        node->parent->color = "Black";
        tempNode->color = "Black";
        node->parent->parent->color = "Red";
        node = node->parent->parent;
      }
      else
      {
        if(node == node->parent->left)
        {
          node = node->parent;
          rightRotate(node);
        }
        node->parent->color = "Black";
        node->parent->parent->color = "Red";
        leftRotate(node->parent->parent);
      }
    }
  }
  root->color = "Black";
}

/*===================================================================
Left Rotation Method
Precondition: A constructed RBT object
Postcondition: The method rotates the tree to the left in order to
maintain balance of the tree in regards of the black height property.
===================================================================*/
template <class KeyType>
void RBT<KeyType>::leftRotate(Node<KeyType> *node)
{
  Node<KeyType> *tempNode = new Node<KeyType>;
  tempNode = node->right;
  node->right = tempNode->left;
  if(tempNode->left != nil)
  {
    tempNode->left->parent = node;
  }
  tempNode->parent = node->parent;

  if(node->parent == nil)
  {
    root = tempNode;
  }
  else if(node == node->parent->left)
  {
    node->parent->left = tempNode;
  }
  else
  {
    node->parent->right = tempNode;
  }
  tempNode->left = node;
  node->parent = tempNode;
}

/*=================================================================
Right Rotation Method
Precondition: A constructed RBT object
Postcondition: The method rotates the tree to the right in order to
maintain balance of the tree in regards of the black height property.
=================================================================*/
template <class KeyType>
void RBT<KeyType>::rightRotate(Node<KeyType> *node)
{
  Node<KeyType> *tempNode = new Node<KeyType>;
  tempNode = node->left;
  node->left = tempNode->right;
  if(tempNode->right != nil)
  {
    tempNode->right->parent = node;
  }
  tempNode->parent = node->parent;

  if(node->parent == nil)
  {
    root = tempNode;
  }
  else if(node == node->parent->right)
  {
    node->parent->right = tempNode;
  }
  else
  {
    node->parent->left = tempNode;
  }
  tempNode->right = node;
  node->parent = tempNode;
}

/*=================================================================
Assigment Operator
Precondition: A constructed RBT object
Postcondition: The assignment operator sets a RBT that we assign to
another tree and makes it equal to the RBT we already had constructed.
=================================================================*/
template <class KeyType>
RBT<KeyType>& RBT<KeyType>::operator=(const RBT<KeyType>& rbt)
{
  root = NULL;
  nil = new Node<KeyType>("Black");

  if(this != &rbt)
  {
    root = copy(rbt.root, nil, rbt.nil);
  }
  return *this;
}

/*=================================================================
PreOrder Method
Precondition: A constructed RBT object
Postcondition: Returns a string of the elements in the RBT after a
preOrder traversal.
=================================================================*/
template <class KeyType>
string RBT<KeyType>::preOrder() const
{
  string toReturn = pre(root);
  return toReturn.substr(0, toReturn.size() - 2);
}

/*=================================================================
PreOrder Helper Function
Precondition: A constructed RBT object
Postcondition: Returns a string of the elements in the RBT after a
preOrder traversal.
=================================================================*/
template <class KeyType>
string RBT<KeyType>::pre(Node<KeyType> *node) const
{
  stringstream s;
  if(node == nil)
  {
    return "";
  } else {
    if(node != nil)
    {
      if(node == root)
      {
        s << *(node->key) << ":" << node->color << ":" << "Root" << ", ";
      } else {
        s << *(node->key) << ":" << node->color << ", ";
      }
    }
    s << pre(node->left);
    s << pre(node->right);
  }
  string returnString = s.str();
  return returnString;
}

/*=================================================================
InOrder Method
Precondition: A constructed RBT object
Postcondition: Returns a string of the elements in the RBT after an
inOrder traversal.
=================================================================*/
template <class KeyType>
string RBT<KeyType>::toString() const
{
  string toReturn = order(root);
  return toReturn.substr(0, toReturn.size() - 2);
}

/*=================================================================
InOrder Helper Function
Precondition: A constructed RBT object
Postcondition: Returns a string of the elements in the RBT after an
inOrder traversal.
=================================================================*/
template <class KeyType>
string RBT<KeyType>::order(Node<KeyType> *node) const
{
  stringstream s;
  if(node == nil)
  {
    return "";
  } else {
    s << order(node->left);
    if(node != nil)
    {
      if(node == root)
      {
        s << *(node->key) << ":" << node->color << ":" << "Root" << ", ";
      } else {
        s << *(node->key) << ":" << node->color << ", ";
      }
    }
    s << order(node->right);
  }
  string returnString = s.str();
  return returnString;
}

/*=================================================================
PostOrder Method
Precondition: A constructed RBT object
Postcondition: Returns a string of the elements in the RBT after a
postOrder traversal.
=================================================================*/
template <class KeyType>
string RBT<KeyType>::postOrder() const
{
  string toReturn = post(root);
  return toReturn.substr(0, toReturn.size() - 2);
}

/*=================================================================
PostOrder Helper Function
Precondition: A constructed RBT object
Postcondition: Returns a string of the elements in the RBT after a
postOrder traversal.
=================================================================*/
template <class KeyType>
string RBT<KeyType>::post(Node<KeyType> *node) const
{
  stringstream s;
  if(node == nil)
  {
    return "";
  } else {
    s << post(node->left);
    s << post(node->right);
    if(node != nil)
    {
      if(node == root)
      {
        s << *(node->key) << ":" << node->color << ":" << "Root" << ", ";
      } else {
        s << *(node->key) << ":" << node->color << ", ";
      }
    }
  }
  string returnString = s.str();
  return returnString;
}

/*=================================================================
Ostream Operator
Precondition: A constructed RBT object
Postcondition: Returns a string of the stream of the elements in the
RBT in an inOrder traversal.
=================================================================*/
template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const RBT<KeyType>& rbt)
{
  stream << rbt.toString();
  return stream;
}

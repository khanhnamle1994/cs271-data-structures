#ifndef dictionary_cpp
#define dictionary_cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*===================================================
Dictionary()            // default constructor
Precondition: None
Postcondition: An empty dictionary
===================================================*/
template <class KeyType>
Dictionary<KeyType>::Dictionary() : BST<KeyType>() {}

/*======================================================================
Dictionary(const Dictionary<KeyType>& dict)        // copy constructor
Precondition: Must be given a dictionary
Postcondition: Traverses the dictionary and makes a copy of its values
		to transfer to another dictionary
======================================================================*/
template <class KeyType>
Dictionary<KeyType>::Dictionary(const Dictionary<KeyType>& dict) : BST<KeyType> (dict) {}


/*=========================================================================
bool dict_empty() const            // return whether the dictionary is empty
Precondition: None
Postcondition: Returns true if the dictionary is empty, false otherwise
=========================================================================*/
template <class KeyType>
bool Dictionary<KeyType>::dict_empty() const
{
  return tree_size == 0;
}

/*=================================================================================
dict_get(const KeyType& k)              // return first element with key equal to k
Precondition: Must be a given dictionary
Postcondition: Calls the "get" method inherited from BST class
=================================================================================*/
template <class KeyType>
KeyType* Dictionary<KeyType>::dict_get(const KeyType& k)
{
  get(k);
}

/*=========================================================================================
dict_insert(const KeyType& k)          // insert element with key equal k to the dictionary
Precondition: Must be a given dictionary
Postcondition: Calls the "insert" method inherited from BST class
==========================================================================================*/
template <class KeyType>
void Dictionary<KeyType>::dict_insert(const KeyType& k)
{
  insert(k);
}

/*================================================================================================
dict_remove(const KeyType& k)         // delete first element with key equal k from the dictionary
Precondition: Must be a given dictionary
Postcondition: Calls the "remove" method inherited from BST class
================================================================================================*/
template <class KeyType>
void Dictionary<KeyType>::dict_remove(const KeyType& k)
{
  remove(k);
}

#endif

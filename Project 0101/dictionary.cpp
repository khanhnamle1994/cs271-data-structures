#ifndef dictionary_cpp
#define dictionary_cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Default Constructor
template <class KeyType>
Dictionary<KeyType>::Dictionary() : BST<KeyType>() {}

// Copy Constructor
template <class KeyType>
Dictionary<KeyType>::Dictionary(const Dictionary<KeyType>& dict) : BST<KeyType> (dict) {}


// Empty Function
template <class KeyType>
bool Dictionary<KeyType>::dict_empty() const
{
  return tree_size == 0;
}

// Get Function
template <class KeyType>
KeyType* Dictionary<KeyType>::dict_get(const KeyType& k)
{
  get(k);
}

// Insert Function
template <class KeyType>
void Dictionary<KeyType>::dict_insert(const KeyType& k)
{
  insert(k);
}

// Remove Function
template <class KeyType>
void Dictionary<KeyType>::dict_remove(const KeyType& k)
{
  remove(k);
}

#endif

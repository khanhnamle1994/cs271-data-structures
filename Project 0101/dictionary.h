#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "BST.h"


template <class KeyType>
class Dictionary : public BST<KeyType>
{
public:
  Dictionary(); // default constructor
  Dictionary(const Dictionary<KeyType>& dict); // copy constructor

  bool dict_empty() const; // return whether the dictionary is empty
  KeyType* dict_get(const KeyType& k); // return an element with key k in dictionary
  void dict_insert(const KeyType& k); // insert a new element with key k into the dictionary
  void dict_remove(const KeyType& k); // delete the element with key k from the dictionary

  // Specify that dictionary will be referring to the following members of BST<KeyType>
  using BST<KeyType>::root;
  using BST<KeyType>::tree_size;
  using BST<KeyType>::get;
  using BST<KeyType>::insert;
  using BST<KeyType>::remove;
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const Dictionary<KeyType>& dict);

#include "dictionary.cpp"

#endif

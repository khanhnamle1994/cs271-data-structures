// dict.h
// James Le
// Project 0110
// CS 271 - Data Structures

#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include "hash.h"

template <class KeyType>
class Dictionary : public HashTable<KeyType>
{
public:
  Dictionary(int tableSlots) : HashTable<KeyType> (tableSlots) { } // constructor
  bool empty(); // empty method to check whether the Dictionary is empty or not

  // inhering methods from HashTable class
  using HashTable<KeyType>::get;
  using HashTable<KeyType>::remove;
  using HashTable<KeyType>::insert;
  using HashTable<KeyType>::toString;
  using HashTable<KeyType>::slots;
  using HashTable<KeyType>::table;
};

#endif

#include "dict.cpp"

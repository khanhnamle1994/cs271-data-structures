//hash.h

#ifndef HASH_H
#define HASH_H

#include <cstdlib>
#include <iostream>
#include "list.h"


template <class KeyType>
class HashTable
{
public:

  HashTable(int numSlots);
  HashTable(const HashTable<KeyType>& h);
  ~HashTable();
  KeyType* get(const KeyType& k) const;
  void insert(KeyType *k);
  void remove(const KeyType& k);
  HashTable<KeyType>& operator=(const HashTable<KeyType>& h);
  std::string toString(int slot) const;


private:

  int slots;
  List<KeyType> *table; // an array of List<KeyType>’s
};


#include "hash.cpp"

#endif

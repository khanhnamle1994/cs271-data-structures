// hash.h
// James Le
// Project 0110
// CS 271 - Data Structures

#ifndef HASHTABLE
#define HASHTABLE

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

  std::string toString(int slot) const;

private:
  int slots;
  List<KeyType> *table;
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const HashTable<KeyType>& ht);

class Empty{ };
class Key { };
class Index { };

#endif

#include "hash.cpp"

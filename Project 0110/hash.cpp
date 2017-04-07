//hash.cpp
#ifndef hash_cpp
#define hash_cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*======================================================
HashTable(int numSlots)
=======================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots)
{
    slots = numSlots;
    List<KeyType> *table[slots];
}

/*======================================================
HashTable(const HashTable<KeyType>& h)
=======================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType>& h)
{
  slots = h.numSlots;
  table = h.table;
}

/*======================================================
~HashTable()
=======================================================*/
template <class KeyType>
HashTable<KeyType>::~HashTable()
{
    delete[] table;
}

/*======================================================
get(const KeyType& k) const
=======================================================*/
template <class KeyType>
KeyType *HashTable<KeyType>::get(const KeyType& k) const
{

}

/*======================================================
insert(KeyType *k)
=======================================================*/
template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k)
{

}

/*======================================================
remove(const KeyType& k)
=======================================================*/
template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k)
{

}

/*======================================================
operator=(const HashTable<KeyType>& h)
=======================================================*/
template <class KeyType>
HashTable<KeyType>& HashTable<KeyType>::operator=(const HashTable<KeyType>& h)
{

}

/*======================================================
toString(int slot) const
=======================================================*/
template <class KeyType>
std::string HashTable<KeyType>::toString(int slot) const
{

}


#endif

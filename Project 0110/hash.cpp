//hash.cpp
#ifndef hash_cpp
#define hash_cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*=================================================================
HashTable(int numSlots)       // Default Constructor
Preconditon: None
Postcondition: Creates an empty hashtable instance of size numSlots
=================================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots)
{
    slots = numSlots;
    List<KeyType> *table[slots];
}

/*====================================================================
HashTable(const HashTable<KeyType>& h)    // Copy Constructor
Precondition: Must be a given hashtable
Postcondition: Traverses the hash table and makes a copy of its values
  to transfer to another hash table
====================================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType>& h)
{
  slots = h.numSlots;
  table = h.table;
}

/*======================================================
~HashTable()      // Destructor
Precondition: None
Postcondition: Deallocates the hash table
=======================================================*/
template <class KeyType>
HashTable<KeyType>::~HashTable()
{
    delete[] table;
}

/*=======================================================================
get(const KeyType& k) const   // Return first record with key equal to k
Precondition: Must be a given hash table
Postcondition: Returns a pointer to a record with key k if one exists;
otherwise, return NIL
=======================================================================*/
template <class KeyType>
KeyType *HashTable<KeyType>::get(const KeyType& k) const
{

}

/*============================================================================
insert(KeyType *k)       // Insert record with key equal to k to the hashtable
Precondition: k's value >= 0. Also, if k's value is not already a key in the
hashtable, then the hashtable has space for another record
Postcondition: If the table already had a record with key equal to k's value,
then that record is replaced by k. Otherwise, k has been added as a new record
of the hashtable
=============================================================================*/
template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k)
{

}

/*=======================================================================================
remove(const KeyType& k)    // Delete first record with key equal to k from the hashtable
Precondition: Must be a given hash table
Postcondition: If a record was in the hashtable with the specified key k, then that
record has been removed; otherwise the hashtable is unchanged.
========================================================================================*/
template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k)
{

}

/*======================================================
operator=(const HashTable<KeyType>& h)    // Overloaded Operator
Precondition: Must be a given hash table
Postcondition: The hashtable that activated this will be made to have the same
records as h
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

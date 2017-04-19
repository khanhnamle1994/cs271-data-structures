// hash.cpp
// James Le
// Project 0110
// CS 271 - Data Structures

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "test.cpp"

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
    table = new List<KeyType*>[numSlots];
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
    slots = 0;
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
    int slot = k.hash(slots);
    List<KeyType*> *cur1 = &table[slot];
    Node<KeyType*> *cur = cur1->head;

    if(cur == NULL)
    {
      throw Empty();
    }

    while(cur != NULL)
    {
      if(*(cur) -> item == k)
        return cur->item;
      else
        cur = cur->next;
    }
    throw Key();
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
    int slot = k -> hash(slots);
    List<KeyType*> *cur1 = &table[slot];
    Node<KeyType*> *cur = cur1->head;

    cur1->insert(0, k);
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
    KeyType *temp = get(k);
    int slot = k.hash(slots);
    table[slot].remove(temp);
}

/*======================================================
toString(int slot) const
=======================================================*/
template <class KeyType>
std::string HashTable<KeyType>::toString(int slot) const
{
    List<KeyType*> *cur1 = &table[slot];
    Node<KeyType*> *cur = cur1->head;

    stringstream s;

    while(cur != NULL)
    {
        s << cur->item->key << ", ";
        cur = cur->next;
    }
    string returnString = s.str();
    return returnString.substr(0, returnString.size() - 2);
}

/*======================================================
stream insertion operator overload
=======================================================*/
template <class KeyType>
ostream& operator<<(ostream& stream, const HashTable<KeyType>& ht)
{
  for(int i = 0; i < ht.slots; i++)
  {
    stream << ht.toString(i) << "\n";
  }
  return stream;
}

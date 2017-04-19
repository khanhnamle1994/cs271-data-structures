// dict.cpp
// James Le
// Project 0110
// CS 271 - Data Structures

#include <iostream>
#include <fstream>
#include <string>
#include <stdib.h>
#include <sstream>

using namespace std;

/*====================================================================
Empty method
Precondition: A valid Dictionary object
Postcondition: The Dictionary is unchanged, and a boolean is returned.
=====================================================================*/
template <class KeyType>
bool Dictionary<KeyType>::empty()
{
  for(int i = 0; i < slots; i++)
  {
    List<KeyType*> *cur1 = &table[i]; // creating list object
    Node<KeyType*> *cur = cur1 -> head; // creating node within the list object

    if(cur != NULL)
      return false;
  }
  return true;
}

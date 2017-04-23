// dict.h
// James Le
// Project 0111
// CS 271: Data Structure

#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include "RBT.h"

template <class KeyType>
class Dictionary : public RBT<KeyType>
{
public:
  Dictionary() : RBT<KeyType> () { }; // constructor

  using RBT<KeyType>::insert;
  using RBT<KeyType>::get;
  using RBT<KeyType>::toString;
  using RBT<KeyType>::empty;
};

#endif

// node.cpp
// James Le
// Project 0111
// CS 271: Data Structure

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

template <class KeyType>
Node<KeyType>::Node()
{
  key = NULL;
  left = NULL;
  right = NULL;
  parent = NULL;
  color = "Red";
}

template <class KeyType>
Node<KeyType>::Node(KeyType *initKey)
{
  key = initKey;
  left = NULL;
  right = NULL;
  parent = NULL;
  color = "Red";
}

template <class KeyType>
Node<KeyType>::Node(KeyType *initKey, string initColor)
{
  key = initKey;
  left = NULL;
  right = NULL;
  parent = NULL;
  color = initColor;
}

template <class KeyType>
Node<KeyType>::Node(string initColor)
{
  key = NULL;
  left = NULL;
  right = NULL;
  parent = NULL;
  color = initColor;
}

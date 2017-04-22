// node.h
// James Le
// Project 0111
// CS 271: Data Structure

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

template <class KeyType>
class Node
{
public:
  Node();
  Node(KeyType *initKey);
  Node(KeyType *initKey, std::string initColor);
  Node(std::string initColor);

  KeyType *key;
  Node<KeyType> *left;
  Node<KeyType> *right;
  Node<KeyType> *parent;
  std::string color;
};

#include "node.cpp"
#endif

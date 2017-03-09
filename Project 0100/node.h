// node.h

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#ifndef NODE_H
#define NODE_H

//template <class KeyType>
class MinHeapNode
{
protected:
/*
  char data; // One of the input characters
  unsigned freq; // Frequency of the character
  MinHeapNode * left, * right; // Left and right child of this node
*/


public:
  char data; // One of the input characters
  string code;
  unsigned freq; // Frequency of the character
  MinHeapNode * left, * right, * parent; // Left and right child of this node

  // Default Constructor
  MinHeapNode()
  {
    data = '\0';
    freq = 0;
    left = NULL;
    right = NULL;
  }


  MinHeapNode(char character, unsigned frequency) // construct node
  {

    data = character;
    freq = frequency;

    //n.data = character;
    //n.freq = frequency;

  }




  std::string toString() const // return string representation
  {
      stringstream result;
			result << "[" << data << ":" << freq << "]";
      return result.str();
  }


  bool operator < (MinHeapNode n) {// override function
    return (freq < n.freq);
  }
};

//template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinHeapNode& n) // stream operator
{
  stream << n.toString();
  return stream;
}


//#include  "huffman.cpp"

#endif

// node.h
// Kevin Ly & James Le

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "pq.h"
using namespace std;

#ifndef NODE_H
#define NODE_H

//template <class KeyType>
class MinHeapNode
{
private:


public:


  char data; // One of the input characters
  string code;
  unsigned freq; // Frequency of the character
  MinHeapNode * left;
  MinHeapNode * right;
  MinHeapNode * parent;
  //,  right,  parent; // Left and right child of this node

//================================================
//Default Node Constructor
//================================================
  MinHeapNode()
  {
    data = '\0';
    freq = 0;
    left = NULL;
    right = NULL;
    code = "";
  }


/*================================================
MinHeapNode* newNode(char character, unsigned frequency)
Precondition: Requires a char character and a int frequency
Postcondition: Allocates a newNode with data=character and freq=frequency
================================================*/
MinHeapNode* newNode(char character, unsigned frequency) // construct node
  {
    MinHeapNode* n;

    n = new MinHeapNode();
    n->data = character;
    n->freq = frequency;
    n->left = NULL;
    n->right = NULL;
    n->code = "";
    return n;

  }



/*================================================
std::string toString() const
Converts Node into string output: [data: frequency]
================================================*/
std::string toString() const // return string representation
{
    stringstream result;
		result << "[" << data << ":" << freq << "]";
    return result.str();
}

/*================================================
bool operator < (MinHeapNode n)
Overwrites < to compare frequencies
================================================*/
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

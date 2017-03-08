// node.h

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#ifndef NODE_H
#define NODE_H

class MinHeapNode
{
private:
  char data; // One of the input characters
  unsigned freq; // Frequency of the character
  MinHeapNode * left, * right; // Left and right child of this node

public:
  std::vector<MinHeapNode> vect;

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
    MinHeapNode * n;
    n->data = character;
    n->freq = frequency;

  }

  /*
  std::string toString() const // return string representation
  {
  	stringstream result; //sets variable to be returned
  	int x = 0;
  	result << "[";
  	int size = vect.size();

  	while(x < vect.size()) // inserts values into "result" while traversing list
  	{
  		result << *(vect[x]));
  		x++;
  		if(x != size)
  			result << ",";
  	}
  	result << "]";
  	return result.str();
  }
*/

  bool operator < (MinHeapNode* n) {// override function
    return (freq < n->freq);
  }

  std::ostream& operator<<(std::ostream& stream, const MinHeapNode* n); // stream operator
};

#include  "huffman.cpp"

#endif

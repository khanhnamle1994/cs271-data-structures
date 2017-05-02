// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <string>
#include "DSF.h"
#include "list.h"
#include "pq.h"

using namespace std;

class Vertex
{
public:
  Vertex(int a);
  int indent;
  string color;
  int finish;
  int dist;
  Vertex *pred;
};

class Pair
{
public:
  Pair(); // default constructor
  Pair(Vertex *initV1, Vertex *initV2, int initW); // constructor
  bool operator<(const Pair& p) const; // overloading < operator
  Vertex *v1; // vertex
  Vertex *v2; // vertex that is connected to v1
  int w; // weight of vertex inside pair
};

template<class T>
class Graph
{
public:
  Graph(string filename); // default constructor that reads a graph from a file
  Graph(const Graph<T>& gra); // copy constructor
  ~Graph(); // destructor
  void DFS(); // Depth-First Search (search all of the vertices)
  void Kruskal(); // An algorithm to find a minimum spanning tree

private:
  int time; // used for DFS(). Record the time
  Vertex **vertices; // array of vertices read from a file
  Pair **pairElem; // pointer to a Pair object
  List<Pair> **adjElements; // array pointing to a list of pairs
  int count; // count
  int countE; // number of edges
  void DFS_Visit(Vertex *u); // Depth-First Search method to change color of visited vertex
  std::string toString() const; // toString method
};

template<class T>
std::ostream& operator<<(std::ostream& stream, const Graph<T>& graf); // ostream operator

#include "Graph.cpp"
#endif

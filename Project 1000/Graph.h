#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <string>
#include "DSF.h"
#include "min.h"

using namespace std;

class Vertex
{
public:
  Vertex(int a);
  int key;
  int discovery; // discover time of the v
  int finished; // finish time of the v
  int adj_size; // vertex's adjacency matrix size

  string color; // the color denotes the status of the vertex during DFS()

  Vertex *predecessor; // used for DFS()
  Vertex **Adj; // an array of vertices adjacent to u
};

class Edge
{
public:
  Edge(Vertex *initial_source = NULL, Vertex *initial_last = NULL, int w = 0); // default constructor
  int weight;
  Vertex *source; // pointer to the source vertex
  Vertex *last; // pointer to the destination vertex
  bool operator<(const Edge &other);
  bool operator<<(const Edge &other);
};

class Graph
{
public:
  Graph(char *txt); // constructor that reads a graph from a file
  ~Graph(); // destructor
  void DFS(); // Depth-First Search (search all of the vertices)
  void Kruskal(); // An algorithm to find a minimum spanning tree

private:
  int time; // used for DFS(). Record the time
  Vertex **V; // array of vertices read from a file
  Edge **E;
  int numVertices; // number of vertices read from a file
  int numEdges;
  void DFS_Visit(Vertex *u);
};

#include "Graph.cpp"
#endif

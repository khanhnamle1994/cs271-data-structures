// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;

/*=====================================================
Vertex Default Constructor
Precondition: None
Postcondition: Initializes generic Vertex object
=====================================================*/
Vertex::Vertex()
{
  ident = 0;
  finish = 0;
  dist = 0;
  color = "White";
  pred = NULL;
}

/*=====================================================
Pair Default Constructor
Precondition: None
Postcondition: Initializes empty Pair object
=====================================================*/
Pair::Pair()
{
  v1 = NULL;
  v2 = NULL;
  w = 0;
}

/*===========================================================================
Pair Constructor
Precondition: initV1 and initV2 are pointers to Vertices, initW is an integer
Postcondition: creates pair with vertices initV1 and initV2 and weight initW
===========================================================================*/
Pair::Pair(Vertex *initV1, Vertex *initV2, int initW)
{
  v1 = initV1;
  v2 = initV2;
  w = initW;
}

/*===========================================================================
Pair Overloading Operator
Precondition: p is a Pair object
Postcondition: returns true if p has greater weight, false otherwise
===========================================================================*/
bool Pair::operator<(const Pair& p) const
{
  if(this->w < p.w)
    return true;
  else
    return false;
}

/*==============================================================================
Graph Default Constructor
Precondition: text file with name filename exists, file filename contains a line
with an integer n followed by n rows containing n elements each
Postcondition: initializes graph based on adjacency matrix from filename
==============================================================================*/
template<class T>
Graph<T>::Graph(string filename)
{
  count = 0;
  countE = 0;
  char ch; // initializing graph object
  string line;
  int identNumb = 0;

  ifstream infile; // file to read from
  infile.open(filename.c_str()); // filename we are reading from
  getline(infile, line); // getline to get number of vertices
  int s = atoi(line.c_str()); // converting number of vertices from txt file to an int
  count = s;
  vertices = new Vertex*[s]; // dynamically allocates an array of pointer to vertices

  for(int v = 0; v < s; v++)
  {
    vertices[v] = new Vertex;
    vertices[v]->ident = v; // giving each vertex and identifcation number from 0 to n-1
  }

  adjElements = new List<Pair>*[s]; // dynamically allocates an array that points to list of pairs

  for(int i = 0; i < s; i++)
  {
    int k = 0;
    adjElements[i] = new List<Pair>; // creating list of pairs in each array slot
    getline(infile, line);

    for(int j = 0; j < line.length(); j++)
    {
      if(line[j] != '0' && line[j] != ' ')
      {
        int intLine = line[j] - 48;
        pairElem = new Pair(vertices[i], vertices[k], intLine); // dynamically allocating a pair
        // object that contains vertex, the vertex it is connected to, and the edge weight
        adjElements[i]->append(pairElem); // appending pair object to list of pairs in array
        countE++; // incrementing count
      }
      if(line[j] != ' ')
        k++;
    }
  }
}

/*===========================================================================
Graph Copy Constructor
Precondition: gra is a Graph object
Postcondition: initializes a Graph as a copy of gra
===========================================================================*/
template<class T>
Graph<T>::Graph(const Graph<T>& gra)
{
  count = gra.count;
  countE = gra.countE;
  time = gra.time;
  pairElem = gra.pairElem;
  vertices = gra.vertices;
  adjElements = new List<Pair>*[count];

  for(int i = 0; i < count; i++)
  {
    adjElements[i] = gra.adjElements[i];
  }
}

/*===========================================================================
Graph Destructor
Precondition: None
Postcondition: Deallocates memory of the graph
===========================================================================*/
template<class T>
Graph<T>::~Graph()
{
  for(int i = 0; i < count; i++)
  {
    List<Pair> tempPairList = *(adjElements[i]);
    for(int j = 0; j < adjElements[i]->length(); j++)
    {
      delete tempPairList[j];
    }
  }
}

/*==================================================================================
Graph Depth-First Search
Precondition: There is a Graph object
Postcondition: prints identifiers of vertices in the order they are visited in a DFS
==================================================================================*/
template<class T>
void Graph<T>::DFS()
{
  Vertex *u;
  for(int i = 0; i < count; i++)
  {
    // initializes vertex u, local variable
    u = vertices[i];
    u->color = "White";
    u->pred = NULL;
  }
  time = 0;
  for(int i = 0; i < count; i++)
  {
    u = vertices[i];
    if(u->color == "White")
    {
      DFS_Visit(u); // calls DFS_Visit recursively
    }
  }
}

/*============================================================================
Depth-First Search method to change color of visited vertex
Precondition: u points to a vertex in the graph
Postcondition: updates time and finish of all vertices, prints identifier of U
============================================================================*/
template<class T>
void Graph<T>::DFS_Visit(Vertex *u)
{
  Vertex *v; // local vertex
  u->color = "Gray"; // setting to "Gray", indicates visited
  time++;
  u->dist = time;
  List<Pair> temp = *(adjElements[u->ident]); // obtains adjacency list of u
  cout << u->ident << " Visit Time -> " << time << endl;

  for(int i = 0; i < temp.length(); i++)
  {
    v = temp[i]->v2;
    if(v->color == "White")
    {
      v->color = "Gray";
      v->pred = u;
      DFS_Visit(v);
    }
  }

  u->color = "Black"; // setting to "Black", indicates finished
  time++;
  u->finish = time;
  cout << u->ident << " Finish Time -> " << time << endl;
}

/*===============================================================================
Kruskal Minimum Spanning Tree algorithm
Precondition: There is a Graph object
Postcondition: prints edges in the order they are added to a spanning tree during
Kruskal's algorithm
===============================================================================*/
template<class T>
void Graph<T>::Kruskal()
{
  Vertex *Vex; // local vertex
  Pair VexPair; // pair object
  DSNode<Vertex>* VexNode; // pointer to a DSNode that contains a vertex
  DisjointSets<Vertex> DSets; // disjoint set containing vertices
  MinPriorityQueue<Pair> weightsQueue(countE); // mpq that contains pairs with capacity countE
  List< DSNode<Vertex> > VexList; // list that holds DSNodes that contain vertices

  for(int i = 0; i < count; i++)
  {
    Vertex* Vex = new Vertex; // dynamically allocates pointer to a vertex
    Vex = vertices[i]; // gets each vertex from list of vertices
    VexNode = DSets.makeSet(Vex); // makeSet called on each vertex and as signed to DSNode holding vertices
    VexList.append(VexNode); // appends DSNode holding vertices from makeSet to a list
  }

  for(int j = 0; j < count; j++)
  {
    List<Pair> tempList = *(adjElements[j]); // list of pairs representing adjacency of each certain vertex
    for(int k = 0; k < adjElements[j]->length(); k++)
    {
      weightsQueue.insert(tempList[k]); // inserting the adjacency nodes to MPQ
    }
  }

  cout << "[ ";
  for(int i = 0; i < countE; i++)
  {
    Pair *shortEdge = weightsQueue.extractMin(); // extracts min to get smallest weights
    DSNode<Vertex>* U = VexList[shortEdge->v1->ident]; // DSNodes containing vertex v1
    DSNode<Vertex>* V = VexList[shortEdge->v2->ident]; // DSNodes containing vertex v2 connected to v1

    if(DSets.findSet(U) != DSets.findSet(V))
    {
      DSets.unionSets(U, V); // calls unionSets to both vertics
      cout << "{" << U->key->ident << "," << V->key->ident << "} ";
    }
  }
  cout << "]" << endl;
}

/*==========================================================
Graph toString method
Precondition: There is a Graph object
Postcondition: returns a string representation of the Graph
==========================================================*/
template<class T>
string Graph<T>::toString() const
{
  stringstream s;

  for(int i = 0; i < count; i++)
  {
    List<Pair> tempList = *(adjElements[i]); // list of pairs representing adjacency of each certain vertex
    for(int j = 0; j < adjElements[i]->length(); j++)
    {
      Pair pr = pairElem[j]; // creating pair of each element pairElem is pointing to
      s << i << " -> " << tempList[j]->v2->ident << " with weight: " << tempList[j]->w << ", " << tempList[j]->v2->color << endl;
    }
  }

  return s.str();
}

/*====================================================
ostream operator
Precondition: graf is a Graph object
Postcondition: prints a string representation of graf
====================================================*/
template<class T>
ostream& operator<<(std::ostream& stream, const Graph<T>& graf)
{
  stream << graf.toString();
  return stream;
}

// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

#include "Graph.h"

int main()
{
  Graph<Vertex> lejames("lejames.txt");
  lejames.DFS();
  lejames.Kruskal();
  Graph<Vertex> lejames2(lejames);
  return 0;
}

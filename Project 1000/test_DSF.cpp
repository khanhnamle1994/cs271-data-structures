// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

#include "DSF.h"
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>

void test_constructor()
{
  try
  {
    // default constructor
    DisjointSets<int> set;
    assert(set.toString() == "");

    // constructor with size
    DisjointSets<int> set2(7);
    assert(set2.toString() == "");

    int *a = new int(5);
    int *b = new int(7);
    int *c = new int(20);
    int *d = new int(11);
    int *e = new int(13);
    int *f = new int(22);
    int *g = new int(3);

    DSNode<int> *node1 = set.makeSet(a);
    DSNode<int> *node2 = set.makeSet(b);
    DSNode<int> *node3 = set.makeSet(c);
    DSNode<int> *node4 = set.makeSet(d);
    DSNode<int> *node5 = set.makeSet(e);
    DSNode<int> *node6 = set.makeSet(f);
    DSNode<int> *node7 = set.makeSet(g);

    assert(set.toString() == "5:0\n7:0\n20:0\n11:0\n13:0\n22:0\n3:0");

    DisjointSets<int> set3(set);
    assert(set3.toString() == "5:0\n7:0\n20:0\n11:0\n13:0\n22:0\n3:0");

    DisjointSets<int> set4 = set3;
    assert(set4.toString() == "5:0\n7:0\n20:0\n11:0\n13:0\n22:0\n3:0");
  }

  catch (FullErr exception)
  {
    cout << "Error: forest of disjoint sets is full" << endl;
  }

  catch (NotFoundError exception)
  {
    cout << "Error: node not found" << endl;
  }
}

void test_makeSet()
{
  try
  {
    int *a = new int(5);
    int *b = new int(7);
    int *c = new int(20);
    int *d = new int(11);
    int *e = new int(13);
    int *f = new int(22);
    int *g = new int(3);

    DisjointSets<int> set(10);
    DSNode<int> *node1 = set.makeSet(a);
    DSNode<int> *node2 = set.makeSet(b);
    DSNode<int> *node3 = set.makeSet(c);
    DSNode<int> *node4 = set.makeSet(d);
    DSNode<int> *node5 = set.makeSet(e);
    DSNode<int> *node6 = set.makeSet(f);
    DSNode<int> *node7 = set.makeSet(g);

    assert(set.toString() == "5:0\n7:0\n20:0\n11:0\n13:0\n22:0\n3:0");
  }

  catch (FullErr exception)
  {
    cout << "Error: forest of disjoint sets is full" << endl;
  }

  catch (NotFoundError exception)
  {
    cout << "Error: node not found" << endl;
  }
}

void test_unionSets()
{
  try
  {
    int *a = new int(5);
    int *b = new int(7);
    int *c = new int(20);
    int *d = new int(11);
    int *e = new int(14);
    int *f = new int(22);
    int *g = new int(31);

    DisjointSets<int> set(10);
    DSNode<int> *node1 = set.makeSet(a);
    DSNode<int> *node2 = set.makeSet(b);
    DSNode<int> *node3 = set.makeSet(c);
    DSNode<int> *node4 = set.makeSet(d);
    DSNode<int> *node5 = set.makeSet(e);
    DSNode<int> *node6 = set.makeSet(f);
    DSNode<int> *node7 = set.makeSet(g);

    set.unionSets(node1, node2);
    assert(set.toString() == "5:0 -> 7:1\n7:1\n20:0\n11:0\n14:0\n22:0\n31:0");

    set.unionSets(node1, node3);
    assert(set.toString() == "5:0 -> 7:1\n7:1\n20:0 -> 7:1\n11:0\n14:0\n22:0\n31:0");

    set.unionSets(node4, node5);
    set.unionSets(node5, node6);
    set.unionSets(node6, node7);

    set.unionSets(node1, node2);
    assert(set.toString() == "5:0 -> 7:1 -> 14:2\n7:1 -> 14:2\n20:0 -> 7:1 -> 14:2\n11:0 -> 14:2\n14:2\n22:0 -> 14:2\n31:0 -> 14:2");
  }

  catch (FullErr exception)
  {
    cout << "Error: forest of disjoint sets is full" << endl;
  }

  catch (NotFoundError exception)
  {
    cout << "Error: node not found" << endl;
  }
}

void test_findSet()
{
  try
  {
    int *a = new int(5);
    int *b = new int(7);
    int *c = new int(20);
    int *d = new int(11);
    int *e = new int(14);
    int *f = new int(22);
    int *g = new int(31);

    DisjointSets<int> set(10);
    DSNode<int> *node1 = set.makeSet(a);
    DSNode<int> *node2 = set.makeSet(b);
    DSNode<int> *node3 = set.makeSet(c);
    DSNode<int> *node4 = set.makeSet(d);
    DSNode<int> *node5 = set.makeSet(e);
    DSNode<int> *node6 = set.makeSet(f);
    DSNode<int> *node7 = set.makeSet(g);

    assert(node6 == set.findSet(node6));

    set.unionSets(node1, node2);
    assert(node2 == set.findSet(node1));
    set.unionSets(node1, node3);
    assert(node2 == set.findSet(node3));

    set.unionSets(node4, node5);
    set.unionSets(node5, node6);
    set.unionSets(node6, node7);
    assert(node5 == set.findSet(node6));
    assert(node5 == set.findSet(node7));

    set.unionSets(node1, node7);
    assert(node5 == set.findSet(node1));
    assert(node5 == set.findSet(node2));
    assert(node5 == set.findSet(node3));
  }

  catch (FullErr exception)
  {
    cout << "Error: forest of disjoint sets is full" << endl;
  }

  catch (NotFoundError exception)
  {
    cout << "Error: node not found" << endl;
  }
}

int main()
{
  test_constructor();
  test_makeSet();
  test_unionSets();
  test_findSet();

  return 0;
}

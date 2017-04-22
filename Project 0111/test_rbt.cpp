// test_rbt.cpp
// James Le
// Project 0111
// CS 271: Data Structure

#include <string>
#include <iostream>
#include <cstdlib>
#include "RBT.h"
#include <cassert>

using namespace std;

void test_const()
{
  RBT<KeyType> jamesle;
}

void test_empty()
{
  RBT<KeyType> jamesle;
  assert(jamesle.empty() == 1);

  int *test1 = new int;
  *test1 = 1;

  jamesle.insert(test1);
  assert(jamesle.empty() == 0);
}

void test_copyConst()
{
  RBT<KeyType> jamesle;

  int *test1 = new int;
  *test1 = 11;
  jamesle.insert(test1);

  int *test2 = new int;
  *test1 = 5;
  jamesle.insert(test2);

  int *test3 = new int;
  *test1 = 13;
  jamesle.insert(test3);

  int *test4 = new int;
  *test1 = 23;
  jamesle.insert(test4);

  int *test5 = new int;
  *test1 = 57;
  jamesle.insert(test5);

  int *test6 = new int;
  *test1 = 9;
  jamesle.insert(test6);

  int *test7 = new int;
  *test1 = 19;
  jamesle.insert(test7);

  int *test8 = new int;
  *test1 = 92;
  jamesle.insert(test1);

  assert(jamesle.toString() == "5:Black, 9:Red, 11:Black:Root, 13:Black, 19:Red, 23:Red, 57:Black, 92:Red");

  RBT<KeyType> jamesle2(jamesle);
  assert(jamesle2.toString() == "5:Black, 9:Red, 11:Black:Root, 13:Black, 19:Red, 23:Red, 57:Black, 92:Red");
}

void test_get()
{
  RBT<KeyType> jamesle;

  try
  {
    throw jamesle.get(11);
  }
  catch(Empty Error)
  {
    cerr << "Error! Trying to get a value in an empty RBT" << endl;
  }

  int *test1 = new int;
  *test1 = 2378;
  jamesle.insert(test1);

  int *test2 = new int;
  *test1 = 5;
  jamesle.insert(test2);

  int *test3 = new int;
  *test1 = 729;
  jamesle.insert(test3);

  int *test4 = new int;
  *test1 = 311;
  jamesle.insert(test4);

  int *test5 = new int;
  *test1 = 5642;
  jamesle.insert(test5);

  int *test6 = new int;
  *test1 = 126;
  jamesle.insert(test6);

  assert(*(jamesle.get(729)) == 729);

  try
  {
    throw jamesle.get(11);
  }
  catch (Key Error)
  {
    cerr << "Error! Trying to get a value that is not in RBT" << endl;
  }
}

void test_insert()
{
  RBT<KeyType> jamesle;

  int *test1 = new int;
  *test1 = 1;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 3;
  jamesle.insert(test3);

  int *test4 = new int;
  *test4 = 4;
  jamesle.insert(test4);

  int *test5 = new int;
  *test5 = 5;
  jamesle.insert(test5);

  int *test6 = new int;
  *test6 = 6;
  jamesle.insert(test6);

  int *test7 = new int;
  *test7 = 7;
  jamesle.insert(test7);

  int *test8 = new int;
  *test8 = 8;
  jamesle.insert(test8);

  int *test9 = new int;
  *test9 = 9;
  jamesle.insert(test9);

  int *test10 = new int;
  *test10 = 10;
  jamesle.insert(test10);

  int *test11 = new int;
  *test11 = 11;
  jamesle.insert(test11);

  int *test12 = new int;
  *test12 = 12;
  jamesle.insert(test12);

  int *test13 = new int;
  *test13 = 13;
  jamesle.insert(test13);

  int *test14 = new int;
  *test14 = 14;
  jamesle.insert(test14);

  int *test15 = new int;
  *test15 = 15;
  jamesle.insert(test15);

  int *test16 = new int;
  *test16 = 16;
  jamesle.insert(test16);

  int *test17 = new int;
  *test17 = 17;
  jamesle.insert(test17);

  int *test18 = new int;
  *test18 = 18;
  jamesle.insert(test18);

  assert(jamesle.toString() == "1:Black, 2:Black, 3:Black, 4:Red, 5:Black, 6:Black, 7:Black, 8:Black:Root,
  9:Black, 10:Black, 11:Black, 12:Red, 13:Black, 14:Black, 15:Black, 16:Red, 17:Black, 18:Red");
}

void test_oper()
{
  RBT<KeyType> jamesle;
  RBT<KeyType> jamesle2;

  int *test1 = new int;
  *test1 = 4;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 5;
  jamesle.insert(test3);

  int *test16 = new int;
  *test16 = 16;
  jamesle.insert(test16);

  int *test17 = new int;
  *test17 = 17;
  jamesle.insert(test17);

  int *test18 = new int;
  *test18 = 18;
  jamesle.insert(test18);

  assert(jamesle.toString() == "2:Black, 4:Black:Root, 5:Black, 16:Red, 17:Black, 18:Red");
  assert(jamesle.empty() == 1);

  jamesle2 = jamesle;
  assert(jamesle.toString() == "2:Black, 4:Black:Root, 5:Black, 16:Red, 17:Black, 18:Red");
  assert(jamesle2.toString() == "2:Black, 4:Black:Root, 5:Black, 16:Red, 17:Black, 18:Red");

  int *test4 = new int;
  *test4 = 12;
  jamesle.insert(test4);

  assert(jamesle.toString() == "2:Black, 4:Black:Root, 5:Black, 12:Red, 16:Red, 17:Black, 18:Red");
  assert(jamesle2.toString() == "2:Black, 4:Black:Root, 5:Black, 16:Red, 17:Black, 18:Red");
}

void test_max()
{
  RBT<KeyType> jamesle;

  try
  {
    throw jamesle.maximum();
  }
  catch(Empty Error)
  {
    cerr << "Error! Trying to get maximum value in an empty RBT" << endl;
  }

  int *test1 = new int;
  *test1 = 4;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 5;
  jamesle.insert(test3);

  int *test16 = new int;
  *test16 = 16;
  jamesle.insert(test16);

  assert(*(jamesle.maximum()) == 16);
}

void test_min()
{
  RBT<KeyType> jamesle;

  try
  {
    throw jamesle.minimum();
  }
  catch(Empty Error)
  {
    cerr << "Error! Trying to get minimum value in an empty RBT" << endl;
  }

  int *test1 = new int;
  *test1 = 4;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 5;
  jamesle.insert(test3);

  int *test16 = new int;
  *test16 = 16;
  jamesle.insert(test16);

  assert(*(jamesle.minimum()) == 2);
}

void test_pred()
{
  RBT<KeyType> jamesle;

  try
  {
    throw *jamesle.predecessor(4);
  }
  catch(Empty Error)
  {
    cerr << "The RBT is currently empty!" << endl;
  }

  int *test1 = new int;
  *test1 = 4;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 5;
  jamesle.insert(test3);

  int *test16 = new int;
  *test16 = 16;
  jamesle.insert(test16);

  try
  {
    throw *jamesle.predecessor(2);
  }
  catch(Key Error)
  {
    cerr << "There is no predecessor for this value!" << endl;
  }

  try
  {
    throw *jamesle.predecessor(7);
  }
  catch(Key Error)
  {
    cerr << "Value inserted not in RBT!" << endl;
  }

  assert(*(jamesle.predecessor(4)) == 2);
  assert(*(jamesle.predecessor(5)) == 4);
  assert(*(jamesle.predecessor(16)) == 5);
}

void test_succes()
{
  RBT<KeyType> jamesle;

  try
  {
    throw *jamesle.predecessor(4);
  }
  catch(Empty Error)
  {
    cerr << "The RBT is currently empty!" << endl;
  }

  int *test1 = new int;
  *test1 = 4;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 5;
  jamesle.insert(test3);

  int *test16 = new int;
  *test16 = 16;
  jamesle.insert(test16);

  try
  {
    throw *jamesle.successor(16);
  }
  catch(Key Error)
  {
    cerr << "There is no successor for this value!" << endl;
  }

  try
  {
    throw *jamesle.successor(7);
  }
  catch(Key Error)
  {
    cerr << "Value inserted not in RBT!" << endl;
  }

  assert(*(jamesle.successor(2)) == 4);
  assert(*(jamesle.successor(4)) == 5);
  assert(*(jamesle.successor(5)) == 16);
}

void test_pre()
{
  RBT<KeyType> jamesle;

  int *test1 = new int;
  *test1 = 1;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 3;
  jamesle.insert(test3);

  int *test4 = new int;
  *test4 = 4;
  jamesle.insert(test4);

  int *test5 = new int;
  *test5 = 5;
  jamesle.insert(test5);

  int *test6 = new int;
  *test6 = 6;
  jamesle.insert(test6);

  int *test7 = new int;
  *test7 = 7;
  jamesle.insert(test7);

  int *test8 = new int;
  *test8 = 8;
  jamesle.insert(test8);

  assert(jamesle.preOrder() == "4:Black:Root, 2:Red, 1:Black, 3:Black, 6:Red, 5:Black, 7:Black, 8:Red");
}

void test_toString()
{
  RBT<KeyType> jamesle;

  int *test1 = new int;
  *test1 = 1;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 3;
  jamesle.insert(test3);

  int *test4 = new int;
  *test4 = 4;
  jamesle.insert(test4);

  int *test5 = new int;
  *test5 = 5;
  jamesle.insert(test5);

  int *test6 = new int;
  *test6 = 6;
  jamesle.insert(test6);

  int *test7 = new int;
  *test7 = 7;
  jamesle.insert(test7);

  int *test8 = new int;
  *test8 = 8;
  jamesle.insert(test8);

  assert(jamesle.toString() == "1:Black, 2:Red, 3:Black, 4:Black:Root, 5:Black, 6:Red, 7:Black, 8:Red");
}

void test_post()
{
  RBT<KeyType> jamesle;

  int *test1 = new int;
  *test1 = 1;
  jamesle.insert(test1);

  int *test2 = new int;
  *test2 = 2;
  jamesle.insert(test2);

  int *test3 = new int;
  *test3 = 3;
  jamesle.insert(test3);

  int *test4 = new int;
  *test4 = 4;
  jamesle.insert(test4);

  int *test5 = new int;
  *test5 = 5;
  jamesle.insert(test5);

  int *test6 = new int;
  *test6 = 6;
  jamesle.insert(test6);

  int *test7 = new int;
  *test7 = 7;
  jamesle.insert(test7);

  int *test8 = new int;
  *test8 = 8;
  jamesle.insert(test8);

  assert(jamesle.postOrder() == "1:Black, 3:Black, 2:Red, 5:Black, 8:Red, 7:Black, 6:Red, 4:Black:Root");
}

int main()
{
  test_const();
  test_copyConst();
  test_empty();
  test_get();
  test_insert();
  test_oper();
  test_max();
  test_min();
  test_pred();
  test_succes();
  test_pre();
  test_toString();
  test_post();
  return 0;
}

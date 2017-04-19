// test_dict.cpp
// James Le
// Project 0110
// CS 271 - Data Structures

#include "dict.h"
#include <cassert>

using namespace std;

void test_constructor()
{
  Dictionary<Test> test1(5); // constructing Dictionary
}

void test_insert()
{
  Dictionary<Test> test2(1);
  Test *str1 = new Test;
  str1->key = "Madrid";
  test2.insert(str1);

  Test *str2 = new Test;
  str2->key = "Munich";
  test2.insert(str2);

  Test *str3 = new Test;
  str3->key = "Milan";
  test2.insert(str3);

  assert(test2.toString(0) == "Milan, Munich, Madrid");
}

void test_get()
{
  Dictionary<Test> test3(10);
  Test *str1 = new Test;
  str1->key = "Oslo";
  test3.insert(str1);

  Test *str2 = new Test;
  str2->key = "Stockholm";
  test3.insert(str2);

  Test *str3 = new Test;
  str3->key = "Copenhagen";
  test3.insert(str3);

  Test find;
  find.key = "Copenhagen";
  Test *print = test3.get(find); // getting a string from dictionary
  assert(print -> hash(10) == 3) // asserting the get result
}

void test_remove()
{
  Dictionary<Test> test4(1);
  Test *str1 = new Test;
  str1->key = "Budapest";
  test4.insert(str1);

  Test *str2 = new Test;
  str2->key = "Vienna";
  test4.insert(str2);

  Test *str3 = new Test;
  str3->key = "Prague";
  test4.insert(str3);

  assert(test4.toString(0) == "Prague, Vienna, Budapest");

  Test deleteKey;
  deleteKey.key = "Prague";
  test4.remove(deleteKey);
  deleteKey.key = "Budapest";
  test4.remove(deleteKey);

  assert(test4.toString(0) == "Vienna");
}

void test_empty()
{
  Dictionary<Test> test3(1);

  Test *str1 = new Test;
  str1->key = "Barcelona"; // Inserting a string into a dictionary
  test3.insert(str1);

  assert(test3.toString(0) != "");
}

int main()
{
  test_constructor();
  test_insert();
  test_get();
  test_remove();
  test_empty();

  return 0;
}

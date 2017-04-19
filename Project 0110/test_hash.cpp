// test_hash.cpp
// James Le
// Project 0110
// CS 271 - Data Structures

#include <string>
#include "hash.h"
#include <cassert>

using namespace std;

void test_constructor()
{
  HashTable<Test> test(10);
}

void test_get()
{
  HashTable<Test> test(10);

  Test *str1 = new Test;
  str1->key = "Tokyo";
  test.insert(str1);

  Test *str2 = new Test;
  str2->key = "Seoul";
  test.insert(str2);

  Test find;
  find.key = "Seoul";
  Test *print = test.get(find);
  assert(print -> hash(10) == 5);
}

void test_insert()
{
  HashTable<Test> test(1);

  Test *str1 = new Test;
  str1->key = "London";
  test.insert(str1);

  Test *str2 = new Test;
  str2->key = "Liverpool";
  test.insert(str2);

  Test *str3 = new Test;
  str3->key = "Manchester";
  test.insert(str3);

  assert(test.toString(0) == "Manchester, Liverpool, London");
}

// Test Remove Function
void TestRemove() {
  HashTable<Test> test(1);
  Test *str1 = new Test;
  str1->key = "Amsterdam";
  test.insert(str1);

  Test *str2 = new Test;
  str2->key = "Berlin";
  test.insert(str2);

  Test *str3 = new Test;
  str3->key = "Paris";
  test.insert(str3);

  assert(test.toString(0) == "Paris, Berlin, Amsterdam");

  Test deleteKey;
  deleteKey.key = "Paris";
  test.remove(deleteKey);
  deleteKey.key = "Amsterdam";
  test.remove(deleteKey);

  assert(test.toString(0) == "Berlin");
}

nt main()
{
  test_constructor();
  test_insert();
  test_get();
  test_remove();

  return 0;
}

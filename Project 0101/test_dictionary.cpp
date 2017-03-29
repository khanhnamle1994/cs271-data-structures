#include <iostream>
#include <cassert>
#include "dictionary.h"

using namespace std;

void test_insert()
{
  Dictionary<int> dict;
  int a = 10;
  int b = 15;
  int c = 7;

  // cout << dict.dict_empty() << endl;
  dict.dict_insert(a);
  // cout << dict.dict_empty() << endl;
  // dict.dict_insert(b);
  dict.dict_insert(c);
  cout << *dict.dict_get(10) << endl;

  dict.dict_remove(10);
  if(dict.dict_empty() == 1)
    cout << "dictionary is empty" << endl;
  else
    cout << "dictionary NOT empty" << endl;

  dict.dict_remove(7);
  if(dict.dict_empty() == 1)
    cout << "dictionary is empty" << endl;
  else
    cout << "dictionary NOT empty" << endl;

  dict.dict_insert(b);
  cout << *dict.dict_get(15) << endl;
}

void test_remove()
{
  Dictionary<int> dict;
  int a = 10;
  int b = 15;
  int c = 7;
}

int main()
{
  test_insert();
  test_remove();

  return 0;
}

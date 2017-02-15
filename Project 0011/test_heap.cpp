// test_heap.cpp

#include <iostream>
#include <cassert>
#include "heap.h"

using namespace std;

void test_heapSort()
{
  KeyType sorted[] = {12, 11, 3, 5, 6, 7};
  int heapSize = sizeof(sorted)/sizeof(sorted[0]);

  heapSort(sorted);
  assert(sorted.toString() == string("{3,5,6,7,11,12}"));
}

void test_heapify()
{
  KeyType A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  int heapSize = sizeof(A)/sizeof(A[0]);

  heapify(A[0]);
  assert(A.toString() == {1, 2, 3, 4, 7, 9, 10, 14, 8});
}

void test_buildHeap()
{
  KeyType A[] = {3, 8, 2, 1, 6, 5, 4, 7};
  int heapSize = sizeof(A)/sizeof(A[0]);

  buildHeap();
  assert(A.toString() == {8, 7, 3, 5, 6, 2, 4, 1});
}

void test_swap()
{
  KeyType A[] = {2, 3, 4, 5, 6, 7};
  swap(3, 6);
  assert(A.toString() == {2, 6, 4, 5, 3, 7});
}

void test_copy()
{
  KeyType A[] = {10, 6, 7, 14, 11};
  int heapSize = sizeof(A)/sizeof(A[0]);

  copy(heap);
  assert(heap.toString() == {10, 6, 7, 14, 11});
}

void test_destroy()
{
  KeyType A[] = {1, 2, 3, 4, 5, 6};
  destroy();
  assert(A.size() == 0);
}

int main()
{
  test_heapSort();
  test_heapify();
  test_swap();
  test_copy();
  test_destroy();

  return 0;
}

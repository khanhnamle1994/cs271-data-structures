// test_heap.cpp

#include <iostream>
#include <cassert>
#include "heap.h"

using namespace std;

void test_heapSort()
{
  int sorted[] = {12, 11, 3, 5, 6, 7};
  Heap<int> h(sorted);

  h.heapSort(sorted);
  assert(sorted.toString() == string("{3,5,6,7,11,12}"));
}

void test_heapify()
{
  int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  Heap<int> h(A);

  h.heapify(A[0]);
  assert(A.toString() == {1, 2, 3, 4, 7, 9, 10, 14, 8});
}

void test_buildHeap()
{
  int A[] = {3, 8, 2, 1, 6, 5, 4, 7};
  Heap<int> h(A);

  h.buildHeap();
  assert(A.toString() == {8, 7, 3, 5, 6, 2, 4, 1});
}

void test_swap()
{
  int A[] = {2, 3, 4, 5, 6, 7};
  h.swap(3, 6);
  assert(A.toString() == {2, 6, 4, 5, 3, 7});
}

void test_copy()
{
  int A[] = {10, 6, 7, 14, 11};
  Heap<int> h(A);

  h.copy(heap);
  assert(heap.toString() == {10, 6, 7, 14, 11});
}

void test_destroy()
{
  int A[] = {1, 2, 3, 4, 5, 6};
  h.destroy();
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

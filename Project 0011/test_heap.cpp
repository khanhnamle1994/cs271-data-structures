// test_heap.cpp

#include <iostream>
#include <cassert>
#include "heap.h"

using namespace std;

void test_heapSort()
{
  int A[] = {12, 11, 3, 5, 6, 7};
  int B[] = {3, 6, 1, 9, 10, 18};

  MinHeap<int> heapA(A, 6);
  heapA.heapSort(A);
  assert(heapA.toString() == string("[3,5,6,7,11,12]"));

  MinHeap<int> heapB(B, 6);
  heapB.heapSort(B);
  assert(heapB.toString() == string("[1, 3, 6, 9, 10, 18]"));
}

void test_heapify()
{
  int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  MinHeap<int> h(A, 10);

  h.heapify(A[0]);
  assert(h.toString() == {1, 2, 3, 4, 7, 9, 10, 14, 8});
}

void test_buildHeap()
{
  int A[] = {3, 8, 2, 1, 6, 5, 4, 7};
  MinHeap<int> h(A, 8);

  h.buildHeap();
  assert(h.toString() == {8, 7, 3, 5, 6, 2, 4, 1});
}

void test_swap()
{
  int A[] = {2, 3, 4, 5, 6, 7};
  MinHeap<int> h(A, 6);

  h.swap(3, 6);
  assert(h.toString() == {2, 6, 4, 5, 3, 7});
}

void test_copy()
{
  int A[] = {10, 6, 7, 14, 11};
  MinHeap<int> h(A, 5);

  h.copy(heap);
  assert(heap.toString() == {10, 6, 7, 14, 11});
}

void test_destroy()
{
  int A[] = {1, 2, 3, 4, 5, 6};
  MinHeap<int> h(A, 6);

  h.destroy();
  assert(h.size() == 0);
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

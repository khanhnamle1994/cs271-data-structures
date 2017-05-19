// James Le - CS 271
// Feb 15, 2017
// test_heap.cpp
// a binary min heap

#include <sys/time.h>
#include "heap.h"

using namespace std;

void TestToString()
{
  float A[5] = {1.3,5.5,3.7,8.9,6.2};
  MinHeap<float> astro1(A,5);
  assert(astro1.toString() == "[1.3, 5.5, 3.7, 8.9, 6.2 |]");

  long B[5] = {234243,45345345,91872214465,1983275,9876};
  MinHeap<long> astro2(B,5);
  assert(astro2.toString() == "[9876, 234243, 91872214465, 1983275, 45345345 |]");

  int C[11] = {5,2,7,9,56,76,34,64,23,4,8};
  MinHeap<int> astro3(C,11);
  assert(astro3.toString() == "[2, 4, 7, 9, 5, 76, 34, 64, 23, 56, 8 |]");

  double D[21] = {3,445,667,9,56,76,34,64,24,8,5,2,7,9,56,76,34,64,23,4,9};
  MinHeap<double> astro4(D,21);
  assert(astro4.toString() == "[2, 4, 3, 9, 5, 7, 9, 34, 23, 8, 445, 76, 667, 34, 56, 76, 64, 64, 24, 56, 9 |]");
}

void TestHeapSort()
{
  float A[5] = {1.3,5.5,3.7,8.9,6.2};
  MinHeap<float> astro1(A,5);
  astro1.heapSort(A);
  assert(astro1.toString() == "[1.3, 3.7, 5.5, 6.2, 8.9]");

  long B[5] = {234243,45345345,91872214465,1983275,9876};
  MinHeap<long> astro2(B,5);
  astro2.heapSort(B);
  assert(astro2.toString() == "[9876, 234243, 1983275, 45345345, 91872214465]");

  int C[11] = {5,2,7,9,56,76,34,64,23,4,8};
  MinHeap<int> astro3(C,11);
  astro3.heapSort(C);
  assert(astro3.toString() == "[2, 4, 5, 7, 8, 9, 23, 34, 56, 64, 76]");

  double D[21] = {3,445,667,9,56,76,34,64,24,8,5,2,7,9,56,76,34,64,23,4,9};
  MinHeap<double> astro4(D,21);
  astro4.heapSort(D);
  assert(astro4.toString() == "[2, 3, 4, 5, 7, 8, 9, 9, 9, 23, 24, 34, 34, 56, 56, 64, 64, 76, 76, 445, 667]");
}

void TestOperator()
{
  float A[11] = {5.1,2.1,7.1,9.1,56.1,76.1,34.1,64.1,23.1,4.1,8.1};
  MinHeap<float> astro1(A,11);
  float B[11] = {3.1,445.1,667.1,9.1,56.1,76.1,34.1,64.1,23.1,4.1,8.1};
  MinHeap<float> astro2(B,11);
  assert(astro1.toString() == "[2.1, 4.1, 7.1, 9.1, 5.1, 76.1, 34.1, 64.1, 23.1, 56.1, 8.1 |]");
  assert(astro2.toString() == "[3.1, 4.1, 34.1, 9.1, 8.1, 76.1, 667.1, 64.1, 23.1, 56.1, 445.1 |]");
  astro1 = astro2;
  assert(astro1.toString() == "[3.1, 4.1, 34.1, 9.1, 8.1, 76.1, 667.1, 64.1, 23.1, 56.1, 445.1 |]");

  long C[5] = {234243,45345345,91872214465,1983275,9876};
  MinHeap<long> astro3(C,5);
  long D[5] = {1234243,145345345,191872214465,11983275,19876};
  MinHeap<long> astro4(D,5);
  assert(astro3.toString() == "[9876, 234243, 91872214465, 1983275, 45345345 |]");
  assert(astro4.toString() == "[19876, 1234243, 191872214465, 11983275, 145345345 |]");
  astro3 = astro4;
  assert(astro3.toString() == "[19876, 1234243, 191872214465, 11983275, 145345345 |]");
  assert(astro4.toString() == "[19876, 1234243, 191872214465, 11983275, 145345345 |]");

  int E[11] = {5,2,7,9,56,76,34,64,23,4,8};
  MinHeap<int> astro5(E,11);
  int F[11] = {3,445,667,9,56,76,34,64,23,4,8};
  MinHeap<int> astro6(F,11);
  assert(astro5.toString() == "[2, 4, 7, 9, 5, 76, 34, 64, 23, 56, 8 |]");
  assert(astro6.toString() == "[3, 4, 34, 9, 8, 76, 667, 64, 23, 56, 445 |]");
  astro5 = astro6;
  assert(astro5.toString() == "[3, 4, 34, 9, 8, 76, 667, 64, 23, 56, 445 |]");
  assert(astro6.toString() == "[3, 4, 34, 9, 8, 76, 667, 64, 23, 56, 445 |]");

  double G[21] = {3,445,667,9,56,76,34,64,24,8,5,2,7,9,56,76,34,64,23,4,9};
  MinHeap<double> astro7(G,21);
  double H[21] = {31,4145,6167,199,516,716,314,614,214,81,51,21,71,91,5116,716,314,614,213,41,19};
  MinHeap<double> astro8(H,21);
  assert(astro7.toString() == "[2, 4, 3, 9, 5, 7, 9, 34, 23, 8, 445, 76, 667, 34, 56, 76, 64, 64, 24, 56, 9 |]");
  assert(astro8.toString() == "[19, 31, 21, 199, 41, 71, 91, 314, 213, 81, 51, 716, 6167, 314, 5116, 716, 614, 614, 214, 516, 4145 |]");
  astro7 = astro8;
  assert(astro7.toString() == "[19, 31, 21, 199, 41, 71, 91, 314, 213, 81, 51, 716, 6167, 314, 5116, 716, 614, 614, 214, 516, 4145 |]");
  assert(astro8.toString() == "[19, 31, 21, 199, 41, 71, 91, 314, 213, 81, 51, 716, 6167, 314, 5116, 716, 614, 614, 214, 516, 4145 |]");
}

void TestTime()
{
  timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
  long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
  int A[10] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

  for (int i = 0; i < 10; i++)
  {
    int q = A[i];
    int a[q];
    int b[q];
    srand(time(NULL));
    for(int i = 0; i < q; i++)
    {
      a[i] = rand() % 100 + 1;
    }
    MinHeap<int> TheSheriff(a, q);
    int B[q];
    gettimeofday(&timeBefore, NULL); // get the time before
    TheSheriff.heapSort(B);
    gettimeofday(&timeAfter, NULL); // get the time after
    diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec; // elapsed seconds
    diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
    double time = diffSeconds + diffUSeconds / 100000.0; // total elapsed time
  }
}

int main()
{
  TestTime();
  TestToString();
  TestHeapSort();
  TestOperator();

  return 0;
}

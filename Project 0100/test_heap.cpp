// test_heap.cpp

#include <iostream>
#include <cassert>
#include "heap.h"

using namespace std;


void test_heap()
{
	int* empty[9];
	int A[] = {3,2,5,4,1,7,8,6,9};
	
	for(int i=0; i<9; i++){
		empty[i] = &A[i];	
	}
	MinHeap<int> heapA(empty, 9);
	for(int j=0; j<9; j++){
		cout << *empty[j] << ",";	
	}
	cout << endl;
	cout << heapA.toString() << endl;
	assert(heapA.toString() == string("[1,2,5,4,3,7,8,6,9]"));
	/*
	int B[] = {10,8,7,9,6};
	int C[] = {6,5,4,3,2,1};
	int D[] = {1,2,3};
	
	MinHeap<int> heap(empty, 9);
	
	assert(heap.toString() == string("[1,2,5,4,3,7,8,6,9]"));
	
	MinHeap<int> heapB(B, 5);
	assert(heapB.toString() == string("[6,8,7,9,10]"));
	
	MinHeap<int> heapC(C, 6);
	assert(heapC.toString() == string("[1,2,4,3,5,6]"));
	
	MinHeap<int> heapD(D, 3);
	assert(heapD.toString() == string("[1,2,3]"));
	*/
}



void test_sort()
{
	/*
	int A[] = {3,2,5,4,1,7,8,6,9};
	int B[] = {10,8,7,9,6};
	int C[] = {5,4,3,2};
	int D[] = {1,2,3,4,5};
	
	MinHeap<int> heap(A, 9);
	assert(heap.toString() == string("[1,2,5,4,3,7,8,6,9]"));	
	heap.heapSort(A);
	assert(heap.toString() == string("[1,2,3,4,5,6,7,8,9]"));
	
	MinHeap<int> heapB(B, 5);
	assert(heapB.toString() == string("[6,8,7,9,10]"));	
	heapB.heapSort(B);
	assert(heapB.toString() == string("[6,7,8,9,10]"));
	
	MinHeap<int> heapC(C, 4);
	heapC.heapSort(C);
	assert(heapC.toString() == string("[2,3,4,5]"));
	
	MinHeap<int> heapD(D, 5);
	heapD.heapSort(D);
	assert(heapD.toString() == string("[1,2,3,4,5]"));
	*/
	
}


void test_equal()
{
	/*
	int A[] = {3,2,5,4,1,7,8,6,9};
	int B[] = {10,8,7,9,6};
	int C[] = {5,4,3,2};
	int D[] = {1,2,3,4,5};
	
	MinHeap<int> heap(A, 9);
	assert(heap.toString() == string("[1,2,5,4,3,7,8,6,9]"));	
	heap.heapSort(A);
	assert(heap.toString() == string("[1,2,3,4,5,6,7,8,9]"));
	
	MinHeap<int> heapB(B, 5);
	assert(heapB.toString() == string("[6,8,7,9,10]"));	
	heapB.heapSort(B);
	assert(heapB.toString() == string("[6,7,8,9,10]"));
	
	heap = heapB;
	assert(heap.toString() == string("[6,7,8,9,10]"));
	
	MinHeap<int> heapC(C, 4);
	heapC.heapSort(C);
	assert(heapC.toString() == string("[2,3,4,5]"));
	
	MinHeap<int> heapD(D, 5);
	assert(heapD.toString() == string("[1,2,3,4,5]"));
	
	heapC = heapD;
	assert(heapC.toString() == string("[1,2,3,4,5]"));
	
	heap = heapC;
	assert(heap.toString() == string("[1,2,3,4,5]"));
	*/
	
}



int main()
{		
	test_heap();		
	//test_sort();
	//test_equal();
	
	return 0;
}

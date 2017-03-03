// test_pq.cpp

#include <iostream>
#include <cassert>
#include "pq.h"

using namespace std;


void test_pq()
{
	int* empty[9];
	int A[] = {3,2,5,4,1,7,8,6,9};
	
	for(int i=0; i<9; i++){
		empty[i] = &A[i];	
	}
	MinHeap<int> heapA(empty, 9);
	
	/*
	for(int j=0; j<9; j++){
		cout << *empty[j] << ",";	
	}
	cout << endl;
	cout << heapA.toString() << endl;
	assert(heapA.toString() == string("[1,2,5,4,3,7,8,6,9]"));
	*/
	int x = 5;
	int y = 2;
	int z = 4;
	int a = 1;
	int b = 3;
	MinPriorityQueue<int> pq(10);
	//cout << "is the pq empty?: " << pq.empty() << endl;
	
	pq.insert(&x);
	pq.insert(&y);
	pq.insert(&z);
	//cout << "is the pq empty?: "  << pq.empty() << endl;
	cout << "length is: " << pq.length() << endl;
	cout <<  "min is: "<< *pq.minimum() << endl;
	cout << pq.toString() << endl;
	cout << "decrease 5 to 1 " << endl;
	 pq.decreaseKey(1, &a);
	cout << pq.toString() << endl;
	cout << "decrease 4 to 3 " << endl;
	 pq.decreaseKey(2, &b);
	cout << pq.toString() << endl;
	
	//cout << "extract min: "<< *pq.extractMin() << endl;
	//cout <<  "min is: "<< *pq.minimum() << endl;
	//cout << pq.toString() << endl;
	
	//cout << "extract min: "<< *pq.extractMin() << endl;
	//cout <<  "min is: "<< *pq.minimum() << endl;
	//cout << pq.toString() << endl;
	
	
}






int main()
{		
	test_pq();		

	
	return 0;
}

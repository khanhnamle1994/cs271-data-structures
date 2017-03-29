// test_bst.cpp

#include <iostream>
#include <cassert>
#include "BST.h"

using namespace std;


void test_insert()
{
	BST<int> bst;
	int a=3;
	int b=5;
	int c=2;
	//cout << bst.empty() << endl;
	bst.insert(a);
	//cout << bst.empty() << endl;
	//bst.insert(b);
	bst.insert(c);
	cout << *bst.get(3) << endl;
	bst.remove(3);
	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
	bst.remove(2);
	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
	bst.insert(b);
	cout << *bst.get(5) << endl;
}


void test_remove()
{
	BST<int> bst;
	int a=3;
	int b=5;
	int c=2;
	//cout << bst.empty() << endl;

	*bst.get(3);
	bst.insert(a);
	cout << "3 inserted" << endl;
	//cout << bst.empty() << endl;
	//bst.insert(b);
	bst.insert(c);
	cout << "2 inserted" << endl;
	*bst.get(3);

	bst.remove(3);
	cout << "3 removed" << endl;
	*bst.get(3);


	bst.remove(2);
	cout << "2 removed" << endl;
	*bst.get(2);
	bst.insert(b);
	cout << "5 inserted" << endl;

	*bst.get(5);
	bst.remove(5);
	cout << "5 removed" << endl;
	*bst.get(5);

	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
cout << "====================" <<endl;
	bst.insert(a);
	bst.insert(b);
	bst.insert(c);
	cout << "3, 5, and 2 inserted" << endl;
	*bst.get(3);
	*bst.get(5);
	*bst.get(2);

	bst.remove(3);
	cout << "3 removed" << endl;
	*bst.get(3);

	bst.remove(5);
	cout << "5 removed" << endl;
	*bst.get(5);

	bst.remove(2);
	cout << "2 removed" << endl;
	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
cout << "====================" <<endl;
	bst.insert(a);
	bst.insert(b);
	bst.insert(c);
	cout << "3, 5, and 2 inserted" << endl;
	*bst.get(3);
	*bst.get(5);
	*bst.get(2);

	bst.remove(5);
	cout << "5 was removed" << endl;
	//*bst.get(5);
	//*bst.get(3);

	bst.remove(2);
	cout << "2 was removed" << endl;
	*bst.get(2);

	*bst.get(3);

	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;

	bst.remove(3);
	cout << "3 was removed" << endl;
	*bst.get(3);
	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;

cout << "====================" <<endl;
	int d=6;
	int e=4;
	int f=1;
	bst.insert(a);
	bst.insert(b);
	bst.insert(c);
	bst.insert(d);
	bst.insert(e);
	bst.insert(f);

	cout << "Maximum = " << *bst.maximum() << endl;

	cout << "3, 5, 2, 6, 4, 1 inserted" << endl;
	*bst.get(3);
	*bst.get(5);
	*bst.get(2);
	*bst.get(6);
	*bst.get(4);
	*bst.get(1);

	bst.remove(2);
	cout << "2 was removed" << endl;
	*bst.get(2);
	*bst.get(1);

	bst.remove(3);
	cout << "3 was removed" << endl;
	*bst.get(3);
	*bst.get(4);

	bst.remove(5);
	cout << "5 was removed" << endl;
	*bst.get(5);

	bst.remove(6);
	cout << "6 was removed" << endl;
	*bst.get(6);

	bst.remove(1);
	cout << "1 was removed" << endl;
	*bst.get(1);

	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
	*bst.get(4);


}


void test_maximum()
{
	BST<int> bst;
	int a=3;
	int b=5;
	int c=2;
	int d=6;
	int e=4;
	int f=1;
	bst.insert(a);
	cout << "Maximum = " << *bst.maximum() << endl;
	bst.insert(b);
	cout << "Maximum = " << *bst.maximum() << endl;
	bst.insert(c);
	cout << "Maximum = " << *bst.maximum() << endl;
	bst.insert(d);
	cout << "Maximum = " << *bst.maximum() << endl;
	bst.insert(e);
	cout << "Maximum = " << *bst.maximum() << endl;
	bst.insert(f);
	cout << "Maximum = " << *bst.maximum() << endl;

	cout << "3, 5, 2, 6, 4, 1 inserted" << endl;
	*bst.get(3);
	*bst.get(5);
	*bst.get(2);
	*bst.get(6);
	*bst.get(4);
	*bst.get(1);

	bst.remove(2);
	cout << "2 was removed" << endl;
	*bst.get(2);
	*bst.get(1);
	cout << "Maximum = " << *bst.maximum() << endl;

	bst.remove(3);
	cout << "3 was removed" << endl;
	*bst.get(3);
	*bst.get(4);
	cout << "Maximum = " << *bst.maximum() << endl;

	bst.remove(5);
	cout << "5 was removed" << endl;
	*bst.get(5);
	cout << "Maximum = " << *bst.maximum() << endl;

	bst.remove(6);
	cout << "6 was removed" << endl;
	*bst.get(6);
	cout << "Maximum = " << *bst.maximum() << endl;

	bst.remove(1);
	cout << "1 was removed" << endl;
	*bst.get(1);
	cout << "Maximum = " << *bst.maximum() << endl;

	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
	*bst.get(4);

}

void test_minimum()
{
	BST<int> bst;
	int a=3;
	int b=5;
	int c=2;
	int d=6;
	int e=4;
	int f=1;
	bst.insert(a);
	cout << "Minimum = " << *bst.minimum() << endl;
	bst.insert(b);
	cout << "Minimum = " << *bst.minimum() << endl;
	bst.insert(c);
	cout << "Minimum = " << *bst.minimum() << endl;
	bst.insert(d);
	cout << "Minimum = " << *bst.minimum() << endl;
	bst.insert(e);
	cout << "Minimum = " << *bst.minimum() << endl;
	bst.insert(f);
	cout << "Minimum = " << *bst.minimum() << endl;

	cout << "3, 5, 2, 6, 4, 1 inserted" << endl;
	*bst.get(3);
	*bst.get(5);
	*bst.get(2);
	*bst.get(6);
	*bst.get(4);
	*bst.get(1);

	bst.remove(2);
	cout << "2 was removed" << endl;
	*bst.get(2);
	*bst.get(1);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(3);
	cout << "3 was removed" << endl;
	*bst.get(3);
	*bst.get(4);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(5);
	cout << "5 was removed" << endl;
	*bst.get(5);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(6);
	cout << "6 was removed" << endl;
	*bst.get(6);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(1);
	cout << "1 was removed" << endl;
	*bst.get(1);
	cout << "Minimum = " << *bst.minimum() << endl;

	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
	*bst.get(4);

}

void test_successor()
{
	BST<int> bst;
	int a=3;
	int b=5;
	int c=2;
	int d=6;
	int e=4;
	int f=1;
	bst.insert(a);
	bst.insert(b);
	bst.insert(c);
	bst.insert(d);
	bst.insert(e);
	bst.insert(f);


	cout << "3, 5, 2, 6, 4, 1 inserted" << endl;
	*bst.get(3);
	*bst.get(5);
	*bst.get(2);
	*bst.get(6);
	*bst.get(4);
	*bst.get(1);


	cout <<  *bst.successor(3) << endl;
/*
	bst.remove(2);
	cout << "2 was removed" << endl;
	*bst.get(2);
	*bst.get(1);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(3);
	cout << "3 was removed" << endl;
	*bst.get(3);
	*bst.get(4);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(5);
	cout << "5 was removed" << endl;
	*bst.get(5);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(6);
	cout << "6 was removed" << endl;
	*bst.get(6);
	cout << "Minimum = " << *bst.minimum() << endl;

	bst.remove(1);
	cout << "1 was removed" << endl;
	*bst.get(1);
	cout << "Minimum = " << *bst.minimum() << endl;

	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
	*bst.get(4);
*/
}

int main()
{
	//test_insert();
	//test_remove();
	//test_maximum();
	//test_minimum();
	test_successor();

	return 0;
}

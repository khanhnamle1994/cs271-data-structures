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
	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;
	cout << *bst.get(5) << endl;
	bst.remove(5);

	bst.insert(a);
	bst.insert(b);
	bst.insert(c);

	bst.remove(3);
	cout << *bst.get(3) << endl;
	bst.remove(5);
	cout << *bst.get(5) << endl;
	bst.remove(2);
	if(bst.empty() == 1)
		cout << "tree is empty" << endl;
	else
		cout << "tree NOT empty" << endl;

}



int main()
{
	//test_insert();
	test_remove();

	return 0;
}

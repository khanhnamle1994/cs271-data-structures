// test_set.cpp

#include <iostream>
#include <cassert>
#include "set.h"

using namespace std;

void test_insert()
{
	Set<int> s;

	s.insert(4);
	assert(s.toString() == string("{4}"));
}

void test_remove()
{
	Set <int> s;

	s.insert(4);
	s.insert(5);
	s.remove(5);
	assert(s.toString() == string("{4}"));
}

void test_cardinality()
{
	Set <int> s;

	s.insert(4);
	s.insert(5);
	s.insert(6);
	assert(s.cardinality() == 3);
}

void test_empty()
{

}

void test_contains()
{

}

int main()
{
	test_insert();
	test_remove();
	test_cardinality();
	test_empty();
	test_contains();

	return 0;
}

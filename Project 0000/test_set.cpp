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

}

// etc...


int main()
{
	test_insert();
	test_remove();
	// etc...
	
	return 0;
}

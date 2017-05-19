// James Le - CS 271
// test_set.cpp
// Jan 25, 2017

#include <cmath>
#include "time.h"
#include <string>
#include <ctime>
#include "set.h"
#include <cassert>
#include <iostream>

using namespace std;

void test_insert()
{
	Set<double> star;
	star.print();
	star.insert(100.00);
	star.print();
	star.insert(25.00);
	star.print();
	star.insert(50.00);
	star.print();
	star.insert(75.00);
	star.print();
}

void test_remove()
{
	Set<double> compsci;
	compsci.print();
	compsci.insert(100.00);
	compsci.print();
	compsci.insert(25.00);
	compsci.print();
	compsci.insert(50.00);
	compsci.print();
	compsci.insert(75.00);
	compsci.print();
	compsci.remove(100.00);
	compsci.print();
}

void test_cardinality()
{
	Set<double> denison;
	denison.print();
	denison.insert(100.00);
	denison.print();
	denison.insert(25.00);
	denison.print();
	denison.insert(50.00);
	denison.print();
	denison.insert(75.00);
	denison.print();
	cout << denison.cardinality() << endl;
}

void test_empty()
{
	Set<double> granville;
	granville.print();
	granville.insert(100.00);
	granville.print();
	granville.insert(25.00);
	granville.print();
	granville.insert(50.00);
	granville.print();
	granville.insert(75.00);
	granville.print();
	cout << granville.empty() << endl;
}

void test_contains()
{
	Set<double> ohio;
	ohio.print();
	ohio.insert(100.00);
	ohio.print();
	ohio.insert(25.00);
	ohio.print();
	ohio.insert(50.00);
	ohio.print();
	ohio.insert(75.00);
	ohio.print();
	cout << ohio.contains(25.00) << endl;
}

void test_equality()
{
	Set<double> havill;
	Set<double> bressoud;
	havill.insert(100.00);
	havill.print();
	havill.insert(25.00);
	havill.print();
	bressoud.insert(100.00);
	bressoud.print();
	bressoud.insert(25.00);
	bressoud.print();
	assert(havill == bressoud);
}

void test_equals()
{
	Set<double> olin;
	Set<double> talbot;
	olin.insert(100.00);
	olin.print();
	olin.insert(25.00);
	olin.print();
	talbot.insert(120.00);
	talbot.print();
	talbot.insert(5.00);
	talbot.print();
	olin.print();
	olin = talbot;
	olin.print();
}

void test_plus()
{
	Set<double> fellows;
	Set<double> knapp;
	Set<double> higley;
	fellows.insert(100.00);
	fellows.print();
	fellows.insert(25.00);
	fellows.print();
	knapp.insert(120.00);
	knapp.print();
	knapp.insert(5.00);
	knapp.print();
	higley = fellows + knapp;
	higley.print();
}

void test_subtract()
{
	Set<double> fellows;
	Set<double> knapp;
	Set<double> higley;
	fellows.insert(100.00);
	fellows.print();
	fellows.insert(25.00);
	fellows.print();
	knapp.insert(120.00);
	knapp.print();
	knapp.insert(5.00);
	knapp.print();
	higley = fellows - knapp;
	higley.print();
}

void test_intersection()
{
	Set<double> fellows;
	Set<double> knapp;
	Set<double> higley;
	fellows.insert(100.00);
	fellows.print();
	fellows.insert(25.00);
	fellows.print();
	knapp.insert(120.00);
	knapp.print();
	knapp.insert(5.00);
	knapp.print();
	higley = fellows & knapp;
	higley.print();
}

void test_subset()
{
	Set<double> fellows;
	Set<double> knapp;
	fellows.insert(100.00);
	fellows.print();
	fellows.insert(25.00);
	fellows.print();
	knapp.insert(120.00);
	knapp.print();
	knapp.insert(5.00);
	knapp.print();
	assert(fellows <= knapp);
}

void test_destroy()
{
	Set<double> slayter;
	slayter.print();
	slayter.insert(100.00);
	slayter.print();
	slayter.insert(25.00);
	slayter.print();
	slayter.insert(50.00);
	slayter.print();
	slayter.insert(75.00);
	slayter.print();
	slayter.~Set();
	slayter.print();
}

int main()
{
	test_insert();
	test_remove();
	test_cardinality();
	test_empty();
	test_contains();
	test_equality();
	test_destroy();
	test_equals();
	test_plus();
	test_intersection();
	test_subtract();
	test_subset();

	return 0;
}

// movie.h
// James Le
// Project 0110
// CS 271 - Data Structures

#ifndef MOVIES
#define MOVIES

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "dict.h"

class Movie
{
public:
  string title; // string of movie titles
  string cast; // string of cast members

  int hash(int slots) const; // hash function method
  bool operator==(const Movie& mov); // overriding equality operator

  std::string toString() const; // toString method
};

std::ostream& operator<<(std::ostream& stream, const Movie& movie); // ostream operator

#endif

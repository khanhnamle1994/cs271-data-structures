// movie.h
// James Le
// Project 0111
// CS 271: Data Structure

#ifndef MOVIE
#define MOVIE

#include "dict.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>

class Movie
{
public:
  string title; // string of movie titles
  string cast; // string of cast members

  bool operator==(const Movie& mov) const;
  bool operator<=(const Movie& mov) const;
  bool operator>(const Movie& mov) const;

  std::string toString() const; // toString method
};

std::ostream& operator<<(std::ostream& stream, const Movie& movie); // ostream operator

#endif

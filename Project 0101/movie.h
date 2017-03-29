#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include "dictionary.h"
template <class KeyType>
class Movie
{
public:
  string title;
  string cast;

  Movie() {
    title = "";
    cast = "";
  };

  Movie(string title2, string cast2) {
    title = title2;
    cast = cast2;
  }

  ~Movie();

  bool operator != (const Movie& movie2){
    int result;
    result = strcmp(title, movie2.title);
    if (result != 0)
      return false;
    else
      return true;
  }

  bool operator > (const Movie& movie2){
    int result;
    result = strcmp(title, movie2.title);
    if (result >= 0)
      return true;
    else
      return false;
  }

  bool operator < (const Movie& movie2){
    int result;
    result = strcmp(title, movie2.title);
    if (result <= 0)
      return true;
    else
      return false;
  }

};




#endif

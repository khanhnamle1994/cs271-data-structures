#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"


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

  //~Movie();

  bool operator != (const Movie& movie2){
    return title != movie2.title;
  }

  bool operator > (const Movie& movie2){
    return title > movie2.title;
  }


  bool operator < (const Movie& movie2){
    return title < movie2.title;
  }

};


#endif

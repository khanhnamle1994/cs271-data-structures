// query_movies.cpp
// James Le
// Project 0111
// CS 271: Data Structure

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <sys/time.h>
#include "movie.cpp"

using namespace std;

int main()
{
  ifstream infile; // file I am reading from
  infile.open("movies_mpaa.txt"); // name of file I am reading from
  Dictionary<Movie> movieTable; // createinf dictionary that holds movie names in slots

  string line;

  timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
  long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
  gettimeofday(&timeBefore, NULL); // get the time before

  while(getline(infile, line)) // gets each line
  {
    Movie *movie = new Movie;
    int count = 0;
    while(line[count] != '\t')
    {
      count++;
    }
    movie->title = line.substr(0, count); // create title string from letter 0 up to length of title
    movie->cast = line.substr(count + 1); // create cast string from one letter after the title until the end of the line
    movieTable.insert(movie); // inserting the movie object in the dictionary
  }
  infile.close(); // close input file

  gettimeofday(&timeAfter, NULL); // get the time after
  diffSeconds = timeAfter.tv_sec; - timeBefore.tv_sec; // elapsed seconds
  diffUSeconds = timeAfter.tv_usec; - timeBefore.tv_usec; // elapsed microseconds
  double time = diffSeconds + diffUSeconds / 100000.0; // total elapsed time
  cout << time << endl;

  string movieTitle;
  cout << "Enter a movie title: ";
  getline(cin, movieTitle); // prompting user to enter movie title
  while(true)
  {
    if(movieTitle == "Quit")
    {
      break;
    } else {
      Movie find; // creating a movie object
      find.title = movieTitle;
      Movie *print = movieTable.get(find); // find user prompted movie title

      cout << endl << "Cast of the movie: " << movieTitle << endl << endl;

      cout << print->cast << endl; // print cast of the movie
      cout << endl;
      cout << "Enter another movie title you want to find or type Quit: ";
      getline(cin, movieTitle); // prompting user to enter another movie title
    }
  }
  return 0;
}

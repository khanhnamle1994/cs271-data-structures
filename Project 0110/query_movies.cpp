// query_movies.cpp
// James Le
// Project 0110
// CS 271 - Data Structures

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "movie.cpp"

using namespace std;

int main()
{
  ifstream infile; // file I am reading from
  infile.open("movies_mpaa.txt"); // name of file I am reading from
  ofstream outfile; // file I am outputting in movie frequencies in each slot
  outfile.open("movies_frequencies.txt"); // name of output file

  Dictionary<Movie> movieTable(1000); // create an infinite dictionary that holds movie names in slots
  string line;

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

  for(int i = 0; i < movieTable.slots; i++)
  {
    List<Movie*> *cur1 = &movieTable.table[i]; // create list object
    Node<Movie*> *cur = cur1->head; // create node within the list object

    int length = cur1->length(); // get the length of items in slots, giving us the frequency of items in each slot
    outfile << length << "\n"; // outputting frequency
  }
  outfile.close(); // close output file

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

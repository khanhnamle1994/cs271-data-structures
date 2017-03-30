// test_movie.cpp

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "movie.h"
//#include "dictionary.h"

// Kevin Ly & James Le


using namespace std;

void FileToMovie(){

  Dictionary<Movie> d;

  ifstream file ("movies_mpaa.txt");
  if ( !file.is_open() )//  see if file opened
    cout<<"Could not open file\n";
  else {
    char x;
    bool tab = false;
    string line;
    string lineT;
    string lineC;

    while(getline(file, line)){    //Reads file line by line
      Movie mov;                  // initializes mov each iteration
      int tab = line.find("\t");  // Title and Cast separated by title
      lineT = line.substr(1, tab-9);  //Title contains everything between the quotation marks
      lineC = line.substr(tab+1);  //Cast is Right after tab
      mov.title = lineT;
      mov.cast = lineC;
      d.insert(mov);
      //cout << "|" << mov.title << "| ";
      //cout << "|" << mov.cast << "|" << endl;
    }

    cout << "Please type a movie name (capital letters and spelling matters): ";
    char input[100];
    cin.get(input,100);

    Movie InMovie;
    InMovie.title = input;

    if(input == InMovie.title)
      cout << d.get(InMovie)->cast << endl;
    else
      cout << "Movie Not Fount" << endl;


  }
}

int main()
{
  FileToMovie();
}

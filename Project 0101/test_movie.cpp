#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "movie.h"
#include "dictionary.h"
// Kevin Ly & James Le


using namespace std;



void FileToMovie(){
  Movie<KeyType> mov;

  ifstream file (movies_mpaa.txt);
  if ( !file.is_open() )//  see if file opened
    cout<<"Could not open file\n";
  else {
    char x;
    string line;
    while (file.get(x)){
      if(x != "\n")
        line.append(x);
      if(x=="\n")
        mov.title = line;
        
    }
}

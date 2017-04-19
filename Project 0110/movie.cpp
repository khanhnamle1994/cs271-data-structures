// movie.cpp
// James Le
// Project 0110
// CS 271 - Data Structures

#include "movie.h"
#include "math.h"

using namespace std;

int Movie::hash(int slots) const
{
  if(title.size() == 1)
  {
    char ch;
    ch = title[0];
    int num = ch;
    return num % slots;
  }

  if(title.size() == 2)
  {
    int asciiCode;
    char cha = title[0];
    char cha1 = title[1];
    asciiCode = cha + cha1;
    int mult = cha;
    return asciiCode * mult % slots;
  }

  if(title.size() > 2)
  {
    unsigned int asciiCode, asciiCode1;
    asciiCode = 1;
    asciiCode1 = 1;
    int n = 77777;
    int numb = 776887;

    for(int i = 0; i < title.size(); i++)
    {
      char c1 = title[i];
      int num1 = c1;
      asciiCode = (asciiCode * num1 * n) % numb; // Prep step for hash function
    }

    for(int j = 0; j < title.size() - 1; j++)
    {
      char c2 = title[j];
      int num2 = c2;
      asciiCode1 = (asciiCode1 * num2 * n) % numb; // Prep step for hash function
    }
    return (asciiCode * asciiCode1) / (title.size() * title.size() * title.size()) % slots; // Hash function
  }
}

bool Movie::operator==(const Movie& mov) const
{
  if(title == mov.title)
  {
    return true;
  }
  return false;
}

string Movie::toString() const
{
  stringstream s;

  s << title << ": ";
  s << cast << '\n';

  string returnString = s.str();
  return returnString.substr(0, returnString.size() - 2);
}

ostream& operator<<(ostream& stream, const Movie& movie)
{
  stream << movie.toString() << "\n";
  return stream;
}

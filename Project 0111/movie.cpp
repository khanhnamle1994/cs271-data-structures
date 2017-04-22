// movie.cpp
// James Le
// Project 0111
// CS 271: Data Structure

#include "movie.h"
#include "math.h"

using namespace std;

bool Movie::operator==(const Movie& mov) const
{
  if(title == mov.title)
  {
    return true;
  }
  return false;
}

bool Movie::operator<=(const Movie& mov) const
{
  if(this->title <= mov.title)
  {
    return true;
  } else {
    return false;
  }
}

bool Movie::operator>(const Movie& mov) const
{
  if(this->title > mov.title)
  {
    return true;
  } else {
    return false;
  }
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

// test.cpp
// James Le
// Project 0110
// CS 271 - Data Structures

#include "test.h"
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>

using namespace std;

int Test::hash(int slots) const
{
  if(key.size() == 1)
  {
    char ch;
    ch = key[0];
    int num = ch;
    return num % slots;
  }

  if(key.size() == 2)
  {
    int asciiCode;
    char cha = key[0];
    char cha1 = key[1];
    asciiCode = cha + cha1;
    int mult = cha;
    return asciiCode * mult % slots;
  }

  if(key.size() > 2)
  {
    unsigned int asciiCode, asciiCode1;
    asciiCode = 1;
    asciiCode1 = 1;
    int n = 77777;
    int numb = 776887;

    for(int i = 0; i < key.size(); i++)
    {
      char c1 = key[i];
      int num1 = c1;
      asciiCode = (asciiCode * num1 * n) % numb; // Prep step for hash function
    }

    for(int i = 0; i < key.size() - 1; i++)
    {
      char c2 = key[i];
      int num2 = c2;
      asciiCode1 = (asciiCode1 * num2 * n) % numb; // Prep step for hash function
    }
    return (asciiCode * asciiCode1) / (key.size() * key.size() * key.size()) % slots; // Hash function
  }
}

bool Test::operator==(const Test& tes) const
{
  if(key == tes.key){
    return true;
  }
  return false;
}

string Test::toString() const
{
  return key;
}

ostream& operator<<(std::ostream& stream, const Test& testt)
{
  stream << testt.toString() << "\n";
  return stream;
}

// James Le - CS 271
// set.cpp
// Jan 25, 2017

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "set.h"

using namespace std;

Set<string> VA;
Set<string> NY;
Set<string> MA;
Set<string> OH;
Set<string> OtherState;
Set<string> Episcopalian;
Set<string> Presbyterian;
Set<string> Methodist;
Set<string> OtherReligion;
Set<string> Forties;
Set<string> Fifties;
Set<string> Sixties;
Set<string> Whig;
Set<string> Democrat;
Set<string> Republican;
Set<string> OtherParty;

void presidentNames()
{
  string line;
  int start = -1;

  ifstream input("pres.txt");
  while(getline(input, line))
  {
    string name, party, state, religion, age;
    name = line.substr(0, line.find('\t', 0));
    line = line.substr(line.find('\t', 0) + 1, 100);

    party = line.substr(0, line.find('\t', 0));
    line = line.substr(line.find('\t', 0) + 1, 100);

    state = line.substr(0, line.find('\t', 0));
    line = line.substr(line.find('\t', 0) + 1, 100);

    religion = line.substr(0, line.find('\t', 0));
    line = line.substr(line.find('\t', 0) + 1, 100);
    age = line;

    if(state == "VA")
    {
      VA.insert(name);
    }
    else if(state == "NY")
    {
      NY.insert(name);
    }
    else if(state == "MA")
    {
      MA.insert(name);
    }
    else if(state == "OH")
    {
      OH.insert(name);
    }
    else
    {
      OtherState.insert(name);
    }

    if(religion == "Episcopalian")
    {
      Episcopalian.insert(name);
    }
    else if(religion == "Presbyterian")
    {
      Presbyterian.insert(name);
    }
    else if(religion == "Methodist")
    {
      Methodist.insert(name);
    }
    else
    {
      OtherReligion.insert(name);
    }

    if(age.substr(0, 1) == "4")
    {
      Forties.insert(name);
    }
    else if(age.substr(0, 1) == "5")
    {
      Fifties.insert(name);
    }
    else
    {
      Sixties.insert(name);
    }

    if(party == "(W)")
    {
      Whig.insert(name);
    }
    else if(party == "(D)")
    {
      Democrat.insert(name);
    }
    else if(party == "(R)")
    {
      Republican.insert(name);
    }
    else
    {
      OtherParty.insert(name);
    }

  }
  input.close();
}

int main()
{
  presidentNames();
  (Democrat + Whig).print();
  (VA & Episcopalian & Whig).print();
  (OH & Methodist).print();
  (Forties).print();
  (OH - Methodist).print();
  cout << ((Democrat & OH) <= (OH)) << endl;
  return 0;
}

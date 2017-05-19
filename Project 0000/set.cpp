// James Le - CS 271
// set.cpp
// Jan 25, 2017

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

template <class Element>
Set<Element>::Set() // Default constructor
{
  head = NULL;
  length = 0;
}

template <class Element>
Set<Element>::Set(const Set<Element>& s) // Copy constructor
{
  copy(s);
}

template <class Element>
Set<Element>::~Set() // Destructor
{
  destroy();
}

// This method adds an non existence item into the set, do nothing if the item is in the set
template <class Element>
void Set<Element>::insert(const Element& x) // Insert Method
{
	for(Node<Element> *current = head; current != NULL; current = current->next)
  {
    if(current->value == x)
    {
      cerr << "Error: Item Already in Set" << endl;
      return;
    }
  }
  Node<Element> *node = new Node<Element>(x);
  Node<Element> *newNode = new Node<Element>(x);
  if(head != NULL)
  {
    Node<Element> *curr = head;
    while(curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = newNode;
  }
  else
  {
    head = newNode;
  }
  length++;
}

// This method removes an item in the set, do nothing if the item does not exist
template <class Element>
void Set<Element>::remove(const Element& x) // Remove Method
{
  Node<Element> *prev = NULL;
  Node<Element> *del = NULL;
  if(head->value == x)
  {
    del = head;
    head = del->next;
    delete del;
    length--;
    return;
  }
  prev = head;
  del = head->next;
  while(del != NULL)
  {
    if(del->value == x)
    {
      prev->next = del->next;
    }
    delete del;
    length--;
    break;
  }
  prev = del;
  del = del->next;
}

// This method returns the size of the set
template <class Element>
int Set<Element>::cardinality() const // Cardinality Method
{
  return length;
}

// This method returns true if the set is empty, false otherwise
template <class Element>
bool Set<Element>::empty() const // Empty Method
{
  return(this->head == NULL);
}

// This method returns true if x is in the set, false otherwise
template <class Element>
bool Set<Element>::contains(const Element& x) const // Contains Method
{
  for(Node<Element> *current = head; current != NULL; current = current->next)
  {
    if(current->value == x)
    {
      return true;
    }
  }
}

// This method returns true if the 2 sets have the same elements, false otherwise
template <class Element>
bool Set<Element>::operator==(const Set<Element>& s) const // Equality Operator
{
  Node<Element> *hNode = head;
  Node<Element> *sNode = s.head;
  int counter = 0;

  while(hNode != NULL)
  {
    while(sNode != NULL)
    {
      if(hNode->value == sNode->value)
      {
        counter++;
        break;
      }
      else
      {
        sNode = sNode->next;
      }
    }
    hNode = hNode->next;
    sNode = s.head;
  }

  if(counter == length)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// This method returns true if one set is a subset of another, false otherwise
template <class Element>
bool Set<Element>::operator<=(const Set<Element>& s) const // Subset Operator
{
  Node<Element> *hNode = head;
  Node<Element> *sNode = s.head;
  int counter = 0;

  while(hNode != NULL)
  {
    while(sNode != NULL)
    {
      if(hNode->value == sNode->value)
      {
        counter++;
        break;
      }
      else
      {
        sNode = sNode->next;
      }
    }
    hNode = hNode->next;
    sNode = s.head;
  }

  if(counter == length)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// This method merges 2 sets into 1, no duplicate
template <class Element>
Set<Element>& Set<Element>::operator+(const Set<Element>& s) const // Union Operator
{
  Set<Element> *result = new Set<Element>(*this);
  Node<Element> *sNode = s.head;
  Node<Element> *hNode = result->head;

  for(sNode; sNode != NULL; sNode = sNode->next)
  {
    for(hNode; hNode != NULL; hNode = hNode->next)
    {
      if(sNode->value == hNode->value)
      {
        break;
      }
    }
    result->insert(sNode->value);
  }
  return *result;
}

// This method takes all the common items from 2 sets and put into 1
template <class Element>
Set<Element>& Set<Element>::operator&(const Set<Element>& s) const // Intersection Operator
{
  Set<Element> *result = new Set<Element>();
  Node<Element> *sNode = s.head;
  Node<Element> *hNode = this->head;

  while(hNode != NULL)
  {
    bool unique = true;
    while(sNode != NULL)
    {
      if(hNode->value == sNode->value)
      {
        unique = false;
      }
      sNode = sNode->next;
    }
    if(unique == false)
    {
      result->insert(hNode->value);
    }
    hNode = hNode->next;
    sNode = s.head;
  }
  return *result;
}

// This method takes the items from 2 sets that are different from each other and put into 1
template <class Element>
Set<Element>& Set<Element>::operator-(const Set<Element>& s) const // Difference Operator
{
  Set<Element> *result = new Set<Element>();
  Node<Element> *sNode = s.head;
  Node<Element> *hNode = this->head;

  while(hNode != NULL)
  {
    bool unique = true;
    while(sNode != NULL)
    {
      if(hNode->value == sNode->value)
      {
        unique = false;
      }
      sNode = sNode->next;
    }
    if(unique == true)
    {
      result->insert(hNode->value);
    }
    hNode = hNode->next;
    sNode = s.head;
  }

  while(sNode != NULL)
  {
    bool unique = true;
    while(hNode != NULL)
    {
      if(sNode->value == hNode->value)
      {
        unique = false;
      }
      hNode = hNode->next;
    }
    if(unique == true)
    {
      result->insert(sNode->value);
    }
    sNode = sNode->next;
    hNode = this->head;
  }

  return *result;
}

template <class Element>
Set<Element>& Set<Element>::operator=(const Set<Element>& s) // Assignment Operator
{
  if(this != &s)
  {
    copy(s);
  }
  return *this;
}

template <class Element>
void Set<Element>::copy(const Set<Element>& s) // copy the set s to this set
{
  if(s.head != NULL)
  {
    head = new Node<Element>(s.head->value);

    Node<Element> *newNode = head;
    for(Node<Element> *ps(s.head->next); ps != NULL; ps = ps->next)
    {
      newNode->next = new Node<Element>(ps->value);
      assert(newNode->next != NULL);
      newNode = newNode->next;
    }
  }
  else
  {
    head = NULL;
  }
  length = s.length;
}

template <class Element>
void Set<Element>::print() // helper method
{
  Node<Element> *newNode = head;
  cout << "{";
  while(newNode != NULL)
  {
    cout << newNode->value << ", ";
    newNode = newNode->next;
  }
  cout << "Length = " << length << "}" << endl;
}

template <class Element>
void Set<Element>::destroy() // delete all elements in the set
{
  while(head != NULL)
  {
    Node<Element> *temp(head);
    head = head->next;
    delete temp;
  }
}

template <class Element>
Node<Element> * Set<Element>::pointerToNode(int index)
{
  Node<Element> *testNode = head;
  for(int j = 0; j < index; j++)
  {
    testNode = testNode->next;
  }
  return testNode;
}

template <class Element>
ostream& operator<<(ostream& stream, const Set<Element>& s) // overloading the << operator
{
  stream << s.print();
  s.print();
  return stream;
}

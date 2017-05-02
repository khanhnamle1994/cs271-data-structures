// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <iostream>

template <class T>
class Node
{
 public:

   T *item;
   Node<T> *next;

   Node();
   Node(T *initItem);
   Node(T *initItem, Node<T> *initNext);
};

template <class T> class List;

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& list);

template <class T>
class List
{
 public:

   List();                               // default constructor
   List(const List<T>& src);             // copy constructor
   ~List();                              // destructor

   void append(T *item);                 // append a new item to the end of the list
   int length() const;                   // return the number of items in the list
   int index(const T& item) const;       // return index of value item, or -1 if not found
   void insert(int index, T *item);      // insert item in position index
   T *pop(int index);                    // delete the item in position index and return it
   void remove(const T& item);           // remove the first occurrence of the value item

   T *operator[](int index);                   // indexing operator
   List<T>& operator=(const List<T>& src);     // assignment operator
   List<T>& operator+=(const List<T>& src);    // concatenation operator

 private:

   Node<T> *head;                        // head of the linked list
   int count;                            // number of items in the list

   void deepCopy(const List<T>& src);
   void deallocate();                    // deallocate the list
   Node<T>* _find(int index);            // return a pointer to the node in position index

   friend std::ostream& operator<< <T>(std::ostream& os, const List<T>& list);
};

class IndexError { };
class ValueError { };

#include "list.cpp"

#endif

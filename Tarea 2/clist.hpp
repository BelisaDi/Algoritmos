#ifndef _clist_hpp_
#define _clist_hpp_

#include <stdlib.h>
#include <iostream>
#include <cassert>
using namespace std;

template <typename dataType>
class Clist{
public:
  Clist(); //creates empty list
  ~Clist(); //destroys list

  dataType & back() const; //element at cursor
  dataType & front() const; //element next to cursor

  void insert(dataType item); //inserts Node with item as data after cursor
  void remove(); //removes Node after cursor
  void advance(); //moves cursor to next Node

  unsigned size() const; //returns number of elements
  bool empty() const; //checks if list is empty
  void clear(); //clears contents of list

private:
  struct Node{
    dataType data;
    Node *link;
    Node(dataType & d, Node *next = nullptr){
      data = d;
      link = next;
    }
  };

  Node *cursor; //cursor pointer
  unsigned count; //number of elements
  void checkrep(); //checks representation invariant

};

#include "clist.cpp"
#endif //_clist_hpp_

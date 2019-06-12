#ifndef _Stack_hpp_
#define _Stack_hpp_

#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename dataType>
class Stack{
private:
  struct Cell{
    dataType data;
    Cell *link;
  };

  Cell *stack;
  int count;

  void deepCopy(const Stack<dataType> & src);

public:
  Stack();
  ~Stack();
  size_t size();
  bool empty();
  void clear();
  void push(dataType & ch);
  dataType pop();
  dataType peek();
};

#include "Stack.cpp"
#endif //_Stack_hpp_

#ifndef _Queue_hpp_
#define _Queue_hpp_

#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename dataType>
class Queue{
private:
  static const int INITIAL_CAPACITY = 10;

  dataType *array;
  int capacity, head, tail;

  void expandCapacity();
  void deepCopy(const Queue<dataType> & src);

public:
  Queue();
  ~Queue();
  int size();
  bool empty();
  void clear();
  void enqueue(dataType & ch);
  dataType dequeue();
  dataType peek();
};

#include "Queue.cpp"
#endif //_Queue_hpp_

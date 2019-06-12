#ifndef _simple_vector_hpp_
#define _simple_vector_hpp_
#include <iostream>
#include <stdlib.h>
using namespace std;

class simple_vector{
public:
  //Constructors and destructors
  simple_vector() = default;
  simple_vector(int) = delete;
  simple_vector(const simple_vector &rhs);
  ~simple_vector();

  //Overloaded operators
  simple_vector & operator=(const simple_vector &rhs);
  friend ostream & operator<<(ostream & os, const simple_vector &rhs);

  //Getters and Setters
  void push(double value);
  void erase(int index);
  void insert(int index, double value);
  void modify(int index, double value);
  double retrieve(int index) const;
  void clear();
  bool empty() const;
  int size() const;

private:
  double *array = new double[10];
  int capacity = 10;
  int length = 0;
  void expandCapacity();
  void checkrep();

};

#endif //_simple_vector_hpp_

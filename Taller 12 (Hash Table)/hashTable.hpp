#ifndef _hashTable_hpp_
#define _hashTable_hpp_

#include <iostream>
#include <list>
using namespace std;

const size_t PRIME_INITIAL_DIMENSION = 101;
template <typename dataType> class hashFunction;

template <typename dataType>
class hashTable{
public:
  hashTable();
  ~hashTable();

  bool find(const dataType & data) const;
  bool insert(const dataType & data);
  bool remove(const dataType & data);

  void clear();
  void rehash();

  float load_factor() const;
  float max_load_factor() const;

  void display() const;

private:
  static float max_load_factor;

  size_t count;
  size_t nBuckets;
  list<dataType> *table;

  size_t hashing(const dataType & data);
};

#include "hashTable.cpp"
#endif //_hashTable_hpp_

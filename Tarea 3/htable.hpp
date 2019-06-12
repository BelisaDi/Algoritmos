#ifndef _htable_hpp_
#define _htable_hpp_

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template <typename data_type> class hashFunction;

template <typename data_type>
class hash_table{
  enum bucket_type {Active, Empty, Deleted};

  struct bucket{
    data_type elem; // actual key
    bucket_type info; // bucket status
    bucket(const data_type &e, bucket_type i = Empty){
      elem = e;
      info = i;
    }
  };

  unsigned n_buckets; // table size
  size_t count;
  vector<bucket> array; // size: n_buckets

  void rehash();
  unsigned hashing(const data_type &x) const;

public:
  hash_table(); // creates table w/101 elements
  ~hash_table(); // frees allocated resources
  void empty(); // clears content of table

  int insert(const data_type &x);
  int search(const data_type &x) const;
  int remove(const data_type &x);

  void display();
  void checkrep();
};


#include "htable.cpp"
#endif //_htable_hpp_

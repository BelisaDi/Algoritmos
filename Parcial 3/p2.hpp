//
//  heap.hpp
//  heap
//  Created by Julian Rincon on 2018-05-17.
//

#ifndef heap_hpp
#define heap_hpp

#include <vector>
#include <cstddef>
#include <iostream>
#include <algorithm>

size_t left(const size_t & p) { return 2 * p; }
size_t right(const size_t & p) { return 2 * p + 1; }
size_t parent(const size_t & p) { return p / 2; }

template <typename keyType>
class binary_heap {
    size_t count;
    std::vector<keyType> array;
    void heapify(const size_t &);

public:
    binary_heap(const int & = 0);
    keyType pop();
    keyType top() const { return array[1]; }
    void insert(const keyType &);
    bool empty() const { return count <= 1; }
    void display(std::ostream & out = std::cout) const;
    bool decrease_key(size_t x, keyType k);
};

#include "p2.cpp"

#endif /* heap_hpp */

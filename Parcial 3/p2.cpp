//
//  heap.cpp
//  heap
//  Created by Julian Rincon on 2018-05-17.
//

#ifdef heap_hpp


template <typename keyType>
binary_heap<keyType>::binary_heap(const int & capacity) {
    count = 1;
    array = std::vector<keyType>(capacity);
    array.push_back(keyType{});
}

template <typename keyType>
bool binary_heap<keyType>::decrease_key(size_t x, keyType k){
  if(k > array[x]){
    cout << "The key 'k' is bigger than my key in 'x', can't decrease." << endl;
    return false;
  }
  else{
    array[x] = k;
    for(size_t i = (count/2); i > 0; i--){
      heapify(i);
    }
    return true;
  }
}

template <typename keyType>
void binary_heap<keyType>::heapify(const size_t & hole) {
    size_t lc = left(hole), rc = right(hole), largest = hole;

    if (lc < count && array[lc] < array[largest]) largest = lc;
    if (rc < count && array[rc] < array[largest]) largest = rc;

    if (largest != hole) {
        std::swap(array[hole], array[largest]);
        heapify(largest);
    }
}


template <typename keyType>
void binary_heap<keyType>::display(std::ostream & out) const {
    out << "binary heap: " << count << "\n";

    for (size_t i = 1; i < count; i *= 2) {
        for (size_t j = 0; j < i; j++)
            if (i + j < count)
                out << array[i + j] << " ";
        out << "\n";
    }
}


template <typename keyType>
keyType binary_heap<keyType>::pop() {
    if (count < 2) throw std::underflow_error("pop: underflow error");

    keyType extreme = array[1];
    array[1] = array[--count];
    array.pop_back();
    heapify(1);

    return extreme;
}


template <typename keyType>
void binary_heap<keyType>::insert(const keyType & item) {
    count++;
    array.push_back(item);

    for (size_t i = count - 1; i > 1; i /= 2) {
        if (array[i] < array[parent(i)])
            std::swap(array[i], array[parent(i)]);
    }
}


#endif /* heap_hpp */

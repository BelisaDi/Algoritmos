#ifdef _bheap_hpp_

template <typename dataType>
void BinaryHeap<dataType>::checkrep(){
  assert(count >= 0);
  unsigned int n = 1;
  while(2*n <= count){
    assert(array[2*n] >= array[n]);
    if(2*n+1 <= count) assert(array[2*n+1] >= array[n]);
    n++;
  }
}

template <typename dataType>
BinaryHeap<dataType>::BinaryHeap(int cap){
  array.reserve(cap + 1);
  count = 0;
  checkrep();
}

template <typename dataType>
BinaryHeap<dataType>::BinaryHeap(const vector<dataType> & vec){
  count = vec.size();
  array.reserve(vec.size() + 1);
  for(unsigned int i = 1; i <= vec.size(); i++){
    array[i] = vec[i-1];
  }
  for(unsigned int i = floor(count/2); i >= 1; i--){
    percolateDown(i);
  }
  checkrep();
}

template <typename dataType>
const dataType & BinaryHeap<dataType>::findMin() const{
  if(!isEmpty()){
    return array[1];
  }
  else{
    throw underflow_error("Function findMin() invoked when heap was empty");
  }
}

template <typename dataType>
void BinaryHeap<dataType>::insert(const dataType & elem){
  checkrep();
  if(isEmpty()){
    dataType garbage;
    array.push_back(garbage);
    array.push_back(elem);
    count++;
    return;
  }
  array.push_back(elem);
  count++;
  int pos = count;
  int parent = pos/2;
  while(parent > 0 && array[parent] >= elem){
    dataType tmp = array[parent];
    array[parent] = elem;
    array[pos] = tmp;
    pos = parent;
    parent = pos/2;
  }
  checkrep();
}

template <typename dataType>
void BinaryHeap<dataType>::deleteMin(){
  checkrep();
  if(!isEmpty()){
    array[1] = array[count];
    percolateDown(1);
    count--;
    checkrep();
  }
  else{
    throw underflow_error("Function deleteMin() invoked when heap was empty");
  }
}

template <typename dataType>
bool BinaryHeap<dataType>::isEmpty() const{
  return count == 0;
}

template <typename dataType>
void BinaryHeap<dataType>::clear(){
  checkrep();
  count = 0;
  checkrep();
}

template <typename dataType>
void BinaryHeap<dataType>::display() const{
  cout << "[";
  for(unsigned int i = 1; i <= count; i++){
    if(i != count){
      cout << array[i] << ", ";
    }
    else{
      cout << array[i];
    }
  }
  cout << "]" << endl;
}

template <typename dataType>
void BinaryHeap<dataType>::percolateDown(unsigned int hole){
  unsigned int left = 2*hole;
  unsigned int right = 2*hole + 1;
  unsigned int smallest;
  if(left <= count && array[left] <= array[hole]){
    smallest = left;
  }
  else{
    smallest = hole;
  }
  if(right <= count && array[right] <= array[smallest]){
    smallest = right;
  }
  if(smallest != hole){
    dataType tmp = array[smallest];
    array[smallest] = array[hole];
    array[hole] = tmp;
    percolateDown(smallest);
  }
}

#endif //_bheap_hpp_

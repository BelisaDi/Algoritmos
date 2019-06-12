#ifdef _Queue_hpp_

template <typename dataType>
Queue<dataType>::Queue(){
  capacity = INITIAL_CAPACITY;
  array = new dataType[capacity];
  head = tail = 0;
}

template <typename dataType>
Queue<dataType>::~Queue(){
  delete[] array;
}

template <typename dataType>
int Queue<dataType>::size(){
  return (tail + capacity - head) % capacity;
}

template <typename dataType>
bool Queue<dataType>::empty(){
  return head == tail;
}

template <typename dataType>
void Queue<dataType>::clear(){
  head = tail = 0;
}

template <typename dataType>
void Queue<dataType>::enqueue(dataType & ch){
  if( size() == capacity - 1){
    expandCapacity();
  }
  array[tail] = ch;
  tail = (tail + 1) & capacity;
}

template <typename dataType>
dataType Queue<dataType>::dequeue(){
  if( empty() ){
    cout << "The queue is empty!" << endl;
    exit(EXIT_FAILURE);
  }
  else{
    dataType out = array[head];
    head = (head + 1) % capacity;
    return out;
  }
}

template <typename dataType>
dataType Queue<dataType>::peek(){
  if( empty() ){
    cout << "The queue is empty!" << endl;
    exit(EXIT_FAILURE);
  }
  else{
    return array[head];
  }
}

template <typename dataType>
void Queue<dataType>::expandCapacity(){
  dataType *old = array;
  size_t size = (tail + capacity - head) % capacity;
  capacity *= 2;
  array = new dataType[capacity];
  for(size_t i = 0; i < size; i++){
    array[i] = old[(head + i) % capacity];
  }
  head = 0;
  tail = size;
  delete[] old;
}

template <typename dataType>
void Queue<dataType>::deepCopy(const Queue<dataType> & src){
  if( array != nullptr){
    delete[] array;
  }
  array = new dataType[src.capacity] {};
  dataType *tmp = src.array;
  for( size_t i = 0; i < (src.head + src.tail) % src.capacity; i++){
    array[i] = tmp[i];
  }
  head = src.head;
  tail = src.tail;
  capacity = src.capacity;
}

#endif //_Queue_hpp_

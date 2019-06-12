#ifdef _hashTable_hpp_

template <typename dataType>
class hashFunction{
public:
  size_t operator()(const dataType & data){
    return static_cast<size_t>(data);
  }
};

template <typename dataType>
size_t hashTable<dataType>::hashing(const dataType & data){
  hashFunction<dataType> hashFunctor();
  return hashFunctor(data) % nBuckets;
}

template <typename dataType>
hashTable<dataType>::hashTable(){
  max_load_factor = 0.7;
  count = 0;
  nBuckets = PRIME_INITIAL_DIMENSION;
  table = new list<dataType>[nBuckets] {};
}

template <typename dataType>
hashTable<dataType>::~hashTable(){
  clear();
}

template <typename dataType>
bool hashTable<dataType>::find(const dataType & data) const{
  size_t idx = hashing(data);
  auto position = table[idx];
  for(auto it = position.begin(); it != position.end(); it++){
    if(it == data){
      return true;
    }
  }
  return false;
}

template <typename dataType>
bool hashTable<dataType>::insert(const dataType & data){
  if(!find(data)){
    size_t idx = hashing(data);
    table[idx].push_back(data);
    count++;
    return true;
  }
  return false;
}

template <typename dataType>
bool hashTable<dataType>::remove(const dataType & data){
  if(find(data)){
    size_t idx = hashing(data);
    auto position = table[idx];
    for(auto it = position.begin(); it != position.end(); it++){
      if(it == data){
        table[position].erase(it);
        count--;
        return true;
      }
    }
  }
  return false;
}

template <typename dataType>
void hashTable<dataType>::clear(){
  for(size_t i = 0; i < nBuckets; i++){
    table[i].clear();
  }
  count = 0;
}

template <typename dataType>
float hashTable<dataType>::load_factor() const{
  return ((float) count) / nBuckets;
}

template <typename dataType>
float hashTable<dataType>::max_load_factor() const{
  return max_load_factor;
}

template <typename dataType>
void hashTable<dataType>::display() const{
  for(size_t i = 0; i < nBuckets; i++){
    auto pos = table[idx];
    cout << "Bucket: " << i << endl;
    for(auto it = posbegin(); it != pos.end(); it++){
      cout << it << " ";
  }
  cout << endl;
}

#endif //_hashTable_hpp_

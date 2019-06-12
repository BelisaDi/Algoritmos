#ifdef _htable_hpp_

template <typename data_type>
void hash_table<data_type>::checkrep(){
  assert(n_buckets >= 0);
  assert(count >= 0);
  for(unsigned i = 0; i < n_buckets; i++){
    assert(array[i].info == Empty || array[i].info == Active || array[i].info == Deleted);
  }
}

template <typename data_type>
hash_table<data_type>::hash_table(){
  n_buckets = 101;
  count = 0;
  data_type p;
  for(size_t i = 0; i < n_buckets; i++){
    array.push_back(bucket(p));
  }
  checkrep();
}

template <typename data_type>
hash_table<data_type>::~hash_table(){
  array.clear();
  count = 0;
}

template <typename data_type>
void hash_table<data_type>::empty(){
  checkrep();
  array.clear();
  count = 0;
  checkrep();
}

template <typename data_type>
unsigned hash_table<data_type>::hashing(const data_type &x) const{
  hashFunction<data_type> p;
  return p(x) % n_buckets;
}

template <typename data_type>
int hash_table<data_type>::insert(const data_type &x){
  checkrep();
  int out;
  float load_factor = float(count) / float(n_buckets);
  if(load_factor >= 0.5){
    cout << "Hash table full, rehashing..." << endl;
    rehash();
  }
  unsigned idx = hashing(x);
  for(unsigned i = 0; i < n_buckets -1; i++){
    if (array[(idx + i) % n_buckets].info == Empty){
      out = (idx + i) % n_buckets;
      array[(idx + i) % n_buckets].elem = x;
      array[(idx + i) % n_buckets].info = Active;
      count++;
      checkrep();
      return out;
    }
  }
  checkrep();
  return -1;
}

template <typename data_type>
int hash_table<data_type>::search(const data_type &x) const{
  int out;
  unsigned idx = hashing(x);
  for(unsigned i = 0; i < n_buckets -1; i++){
    if((array[(idx + i) % n_buckets].elem == x) && (array[(idx + i) % n_buckets].info == Active)){
      out = (idx + i) % n_buckets;
      return out;
    }
    else if (array[(idx + i) % n_buckets].info == Empty){
      return -1;
    }
  }
  return -1;
}

template <typename data_type>
int hash_table<data_type>::remove(const data_type &x){
  checkrep();
  int idx = search(x);
  if(idx != -1){
    array[idx].info = Deleted;
    count--;
    checkrep();
    return idx;
  }
  else{
    checkrep();
    return -1;
  }
}

template <typename data_type>
void hash_table<data_type>::rehash(){
  checkrep();
  n_buckets *= 2;
  data_type p;
  vector<data_type> elementos;
  for(unsigned i = 0; i < n_buckets/2; i++){
    if(array[i].info == Active){
      elementos.push_back(array[i].elem);
    }
  }
  for(unsigned i = 0; i < n_buckets; i++){
    if(i < n_buckets / 2){
      array[i].info = Empty;
    }
    else{
      array.push_back(bucket(p));
    }
  }
  for(unsigned i = 0; i < elementos.size(); i++){
    insert(elementos[i]);
  }
  checkrep();
}

template <typename data_type>
void hash_table<data_type>::display(){
  for(unsigned i = 0; i < n_buckets; i++){
    if(array[i].info == Active){
      cout << array[i].elem << endl;
    }
  }
}

#endif //_htable_hpp_

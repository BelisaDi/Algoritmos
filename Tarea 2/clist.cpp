#ifdef _clist_hpp_

template <typename dataType>
void Clist<dataType>::checkrep(){
  assert(count >= 0);
  if( count > 0){
    assert(cursor != nullptr);
    assert(cursor->link != nullptr);
  }
  if( count == 0){
    assert(cursor == nullptr);
  }
}

template <typename dataType>
Clist<dataType>::Clist(){
  cursor = nullptr;
  count = 0;
  checkrep();
}

template <typename dataType>
Clist<dataType>::~Clist(){
  clear();
}

template <typename dataType>
dataType & Clist<dataType>::back() const{
  if( empty() ){
    cout << "La lista esta vacia!" << endl;
    exit(EXIT_FAILURE);
  }
  return cursor->data;
}

template <typename dataType>
dataType & Clist<dataType>::front() const{
  if( empty() ){
    cout << "La lista esta vacia!" << endl;
    exit(EXIT_FAILURE);
  }
  Node *front = cursor->link;
  return front->data;
}

template <typename dataType>
void Clist<dataType>::insert(dataType item){
  checkrep();
  if(empty()){
    Node *tmp = new Node(item);
    tmp->link = tmp;
    cursor = tmp;
  }
  else{
    Node *tmp = new Node(item, cursor->link);
    cursor->link = tmp;
  }
  count++;
  checkrep();
}

template <typename dataType>
void Clist<dataType>::remove(){
  checkrep();
  if( empty() ){
    cout << "La lista esta vacia!" << endl;
    exit(EXIT_FAILURE);
  }
  Node *tmp = cursor->link;
  cursor->link = tmp->link;
  delete tmp;
  count--;
  if(count == 0){
    cursor = nullptr;
  }
  checkrep();
}

template <typename dataType>
void Clist<dataType>::advance(){
  cursor = cursor->link;
}

template <typename dataType>
unsigned Clist<dataType>::size() const{
  return count;
}

template <typename dataType>
bool Clist<dataType>::empty() const{
  return count == 0;
}

template <typename dataType>
void Clist<dataType>::clear(){
  checkrep();
  while( count > 0 ){
    remove();
  }
  checkrep();
}

#endif //_clist_hpp_

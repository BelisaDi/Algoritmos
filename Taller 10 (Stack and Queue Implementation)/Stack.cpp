#ifdef _Stack_hpp_

template <typename dataType>
Stack<dataType>::Stack(){
  stack = nullptr;
  count = 0;
}

template <typename dataType>
Stack<dataType>::~Stack(){
  clear();
}

template <typename dataType>
size_t Stack<dataType>::size(){
  return count;
}

template <typename dataType>
bool Stack<dataType>::empty(){
  return count == 0;
}

template <typename dataType>
void Stack<dataType>::clear(){
  while(count > 0){
    pop();
  }
}

template <typename dataType>
void Stack<dataType>::push(dataType & ch){
  Cell *cell = new Cell;
  cell->data = ch;
  cell->link = stack;
  stack = cell;
  count++;
}

template <typename dataType>
dataType Stack<dataType>::pop(){
  if(stack == nullptr){
    cout << "¡No hay nada que borrar!" << endl;
    exit(EXIT_FAILURE);
  }
  else{
    Cell *cell = stack;
    dataType out = cell->data;
    stack = stack->link;
    delete cell;
    count--;
    return out;
  }
}

template <typename dataType>
dataType Stack<dataType>::peek(){
  if(stack == nullptr){
    cout << "¡No hay nada que ver!" << endl;
    exit(EXIT_FAILURE);
  }
  else{
    return stack->data;
  }
}

template <typename dataType>
void Stack<dataType>::deepCopy(const Stack<dataType> & src){
  Cell *temp = src.stack;
	if (temp != nullptr) {
		stack = new Cell;
		stack->data = temp->data;
		stack->link = nullptr;
		temp = temp->link;
	}
	Cell *begin = stack;
	while (temp != nullptr) {
		stack->link = new Cell;
		stack = stack->link;
		stack->data = temp->data;
		stack->link = nullptr;
		temp = temp->link;
	}
	stack = begin;
	count = src.count;
}

#endif //_Stack_hpp_

#ifndef _bheap_hpp_
#define _bheap_hpp_

#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

template <typename dataType>
class BinaryHeap{
public:
  BinaryHeap(int capacity = 100); //Constructor por defecto
  BinaryHeap(const vector<dataType> & vec); //Constructor a partir de un vector

  const dataType & findMin() const; //Encuentra y retorna el mínimo
  void insert(const dataType & elem); //Inserta un elemento
  void deleteMin(); //Elimina el mínimo

  bool isEmpty() const; //Revisa si el Binary Heap está vacío
  void clear(); //Limpia el Binary Heap
  void display() const; //Imprime el Binary Heap

private:
  unsigned int count; //Número de elementos
  vector<dataType> array; //Vector de elementos
  void percolateDown(unsigned int hole); //Ubica al elemento en la posicion hole en su posicion correspondiente
  void checkrep(); //Representation invariant
};

#include "bheap.cpp"
#endif //_bheap_hpp_

#include "simple_vector.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Constructors and destructors
simple_vector::simple_vector(const simple_vector &rhs){
  array = new double[rhs.capacity + 10] {};
  for(int i = 0; i < rhs.capacity; i++){
    array[i] = rhs.array[i];
  }
  length = rhs.length;
  capacity = rhs.capacity + 10;
}

simple_vector::~simple_vector(){
  delete[] array;
}

//Overloaded operators
simple_vector& simple_vector::operator=(const simple_vector &rhs){
  array = new double[rhs.capacity + 10] {};
  for(int i = 0; i < rhs.capacity; i++){
    array[i] = rhs.array[i];
  }
  length = rhs.length;
  capacity = rhs.capacity + 10;
  return *this;
}

ostream& operator<<(ostream &os, const simple_vector &rhs){
  os << "( ";
  for(int i = 0; i < rhs.length; i++){
    cout << rhs.array[i] << " ";
  }
  os << " ), len = " << rhs.length << ", cap = " << rhs.capacity;
  return os;
}

//Getters and Setters
void simple_vector::push(double value){
  if (length == capacity){
    expandCapacity();
  }
  array[length++] = value;
}

void simple_vector::erase(int index){
  if(index < 0 || index >= length){
    cout << "Index out of range." << endl;
    exit(EXIT_FAILURE);
  }
  if(length == 0){
    cout << "The vector is empty, there's nothing to erase." << endl;
    exit(EXIT_FAILURE);
  }
  else{
    for(int i = index + 1; i < capacity; i++){
      array[i - 1] = array[i];
    }
    length--;
  }
}

void simple_vector::insert(int index, double value){
  if(index < 0){
    cout << "Index out of range." << endl;
    exit(EXIT_FAILURE);
  }
  if(index >= capacity){
    expandCapacity();
  }
  double *oldArray = array;
  array = new double[capacity] {};
  length++;
  for(int i = 0; i < capacity; i++){
    if(i < index){
      array[i] = oldArray[i];
    }
    else if (i == index){
      array[i] = value;
    }
    else if(i > index){
      array[i] = oldArray[i-1];
    }
  }
  delete[] oldArray;
}

void simple_vector::modify(int index, double value){
  if(index < 0 || index >= length){
    cout << "Index out of range." << endl;
    exit(EXIT_FAILURE);
  }
  else{
    array[index] = value;
  }
}

double simple_vector::retrieve(int index) const{
  if(index < 0 || index >= length){
    cout << "Index out of range." << endl;
    exit(EXIT_FAILURE);
  }
  else{
    return array[index];
  }
}

void simple_vector::clear(){
  length = 0;
}

bool simple_vector::empty() const{
  return length == 0;
}

int simple_vector::size() const{
  return length;
}

void simple_vector::expandCapacity(){
    double *oldArray = array;
    capacity *= 2;
    array = new double[capacity];
    for (int i = 0; i < length; i++){
      array[i] = oldArray[i];
    }
    delete[] oldArray;
}

int main()
{
    simple_vector vec;

    for (int i = -10; i < +10; i += 2) vec.push(static_cast<double>(i));
    cout << vec << endl;

    auto iter = vec.size() / 2;
    for (int i = 0; i < iter; i++) vec.erase(i);
    cout << vec << endl;

    for (int i = 0; i < 2 * iter; i++) vec.insert(2 * i, i);
    cout << vec << endl;

    for (int i = 0; i < vec.size(); i += 2) {
        auto data = vec.retrieve(i);
        vec.modify(i, data + 0.1);
    }
    cout << vec << endl;

    simple_vector vac(vec), vic;
    cout << vac << endl;

    vic = vac;
    cout << vic << endl;

    vec = vac;
    cout << vec << endl;

    vac.clear();
    cout << vac << endl;

    return 0;
}

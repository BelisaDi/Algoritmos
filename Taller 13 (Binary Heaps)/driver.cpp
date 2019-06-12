#include "bheap.hpp"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main(){
  const short min = 65, max = 90, dim = 13;
  random_device rd;
  default_random_engine generator{rd()};
  uniform_int_distribution<int> distribution(min,max);

  vector<char> * vech = new vector<char>();
  for(unsigned i = 0; i < dim; i++){
    char ch = distribution(generator);
    vech->push_back(ch);
    cout << "Insertion of " << i+1 << " " << ch << endl;
  }

  BinaryHeap<char> hp(*vech);

  cout << "Extreme " << hp.findMin() << " element\n";
  hp.display();
  delete vech;

  cout << "-------------------------------------" << endl;

  for(unsigned int i = 0; i <= dim; i++){
    if(hp.isEmpty()) continue;
    cout << "Extract " << hp.findMin() << " element\n";
    hp.deleteMin();
    }
  hp.display();
  cout << "------------------------------\n";

  BinaryHeap<char> bin_ch;
  for(unsigned int i = 0; i < 2 * dim; i++){
    bin_ch.insert(distribution(generator));
  }
  bin_ch.display();

  return 0;
}

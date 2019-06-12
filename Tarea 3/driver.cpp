#include <iostream>
#include <random>
#include "htable.hpp"
using namespace std;

int main(){
  const int min = -15, max = +15;
  random_device rd;
  default_random_engine generator{rd()};
  uniform_int_distribution<int> distribution(min, max);

  hash_table<int> ht;

  for(int i = 0; i < max; i++){
    int key = distribution(generator);
    int idx = ht.insert(key);
    cout << "Insert: " << key <<  " On the index: " << idx << endl;
  }

  ht.display();

  for(int key = min; key < max; key++){
    cout << "Find: " << key << " " << ht.search(key) << endl;
  }

  for(int i = min; i < max; i++){
    int key = distribution(generator);
    cout << "Remove: " << key << " " << ht.remove(key) << endl;
  }

  for(int key = min; key < max; key++){
    cout << "Find: " << key << " " << ht.search(key) << endl;
  }

  ht.display();

  return 0;
}

#include <iostream>
using namespace std;

int *createIndexArray(int k){
  int *array = new int[k];
  for(int i = 0; i <= k; i++){
    array[i] = i;
  }
  return array;
}

int main(){
  int *array = createIndexArray(10);
  for(int i = 0; i <= 10; i++){
    cout << array[i] << ' ';
  }
  cout << endl;
  return 0;
}

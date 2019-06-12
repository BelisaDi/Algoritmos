#include <iostream>
using namespace std;

int findMaximum(int array[], int n){
  int max = array[0];
  for (int i = 0; i < n; i++){
    if (array[i] > max){
      max = array[i];
    }
  }
  return max;
}

int main(){
  int array[] = {0,5,3,-7,-10,4,2};
  int size = sizeof(array)/sizeof(int);
  int max = findMaximum(array,size);
  cout << "The maximum value is: " << max << endl;
  return 0;
}

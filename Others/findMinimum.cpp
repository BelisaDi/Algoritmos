#include <iostream>
using namespace std;

int findMinimum(int array[], int n){
  int min = array[0];
  for (int i = 0; i < n; i++){
    if (array[i] < min){
      min = array[i];
    }
  }
  return min;
}

int main(){
  int array[] = {0,5,3,-7,-10,4,2};
  int size = sizeof(array)/sizeof(int);
  int min = findMinimum(array,size);
  cout << "The minimum value is: " << min << endl;
  return 0;
}

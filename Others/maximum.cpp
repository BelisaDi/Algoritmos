#include <iostream>
#include <cmath>
using namespace std;

int findMaximum(int array[], int size){
  int lh = 0;
  int rh = size;
  while (lh <= rh){
    int med = round((lh+rh)/2);
    if ((array[med] >= array[med+1]) && (array[med] >= array[med-1])){
      return array[med];
    }
    else if((array[med] >= array[med+1]) && (array[med] <= array[med-1])){
      rh = med - 1;
    }
    else if((array[med] <= array[med+1]) && (array[med] >= array[med-1])){
      lh = med + 1;
    }
  }
  return -1;
}

int main(){
  int array[] = {-100,-23,0,23,56,21,13,0,-1};
  int size = (sizeof(array)/sizeof(int));
  int max = findMaximum(array,size);
  cout << "The maximum number is: " << max << endl;
  return 0;
}

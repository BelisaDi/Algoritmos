#include <iostream>
using namespace std;

void bubble(int array[], int n){
  int i,j;
  bool swapped;
  for (i = 0; i < n-1; i++){
    swapped = false;
    for (j = 0; j < n-i-1; j++){
      if (array[j] > array[j+1]){
        swap(array[j],array[j+1]);
        swapped = true;
      }
    }
    if (swapped == false){
      break;
    }
  }
}

void printarray(int array[], int n){
  int i;
  for (i=0; i < n; i++)
       printf("%d ", array[i]);
   printf("\n");
}

int main(){
  int array[] = {10,9,8,7,6,5,4,3,2,1};
  int size = sizeof(array)/sizeof(int);
  bubble(array,size);
  printarray(array,size);
  return 0;
}

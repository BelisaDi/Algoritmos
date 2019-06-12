#include <iostream>
#include <stdio.h>
using namespace std;

void selection(int array[], int size){
  for(int i = 0; i < size; i++){
    int minIndex = i;
    for(int j = i+1; j < size; j++){
      if(array[j] < array[minIndex]){
        minIndex = j;
      }
    }
    swap(array[i], array[minIndex]);
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
  selection(array,size);
  printarray(array,size);
  return 0;
}

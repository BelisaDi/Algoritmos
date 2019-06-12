#include <iostream>
#include <stdio.h>
using namespace std;

void insertion(int array[], int n){
  int i, key, j;
  for (i = 1; i < n; i++){
    key = array[i];
    j = i-1;
    while (j >= 0 && array[j] > key){
      array[j+1] = array[j];
      j = j - 1;
    }
    array[j+1] = key;
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
  insertion(array,size);
  printarray(array,size);
  return 0;
}

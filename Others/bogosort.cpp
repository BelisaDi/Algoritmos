#include <iostream>
#include <stdio.h>
using namespace std;

void printarray(int array[], int n){
  int i;
  for (i=0; i < n; i++)
       printf("%d ", array[i]);
   printf("\n");
}

bool sorted(int array[], int n){
  for (int i = 0; i < n; i++){
    if (array[i] >= array[i+1]){
      return false;
    }
  }
  return true;
}

void shuffle(int a[], int n)
{
    for (int i=0; i < n; i++)
        swap(a[i], a[rand()%n]);
}

void bogosort(int array[],int n){
  while(sorted(array,n) == false){
    printarray(array,n);
    shuffle(array,n);
  }
}

int main(){
  int array[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
  int size = sizeof(array)/sizeof(int);
  bogosort(array, size);
  printarray(array,size);
  return 0;
}

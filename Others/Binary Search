#include <iostream>
#include <cmath>
using namespace std;

int Binary(int array[], int x, int n){
  int lh = 0;
  int rh = n;
  while (lh <= rh){
    int med = round((rh+lh)/2);
    if (array[med] == x){
      return med;
    }
    else if (array[med] < x){
      lh = med + 1;
    }
    else{
      rh = med - 1;
    }
  }
  return -1;
}

int main(){
  int lista[] = {2,5,10,24,26,54,86,100};
  int len = sizeof(lista)/sizeof(int);
  int idx = Binary(lista, 3, len);
  cout << "Binary search result: " << idx <<endl;
  return 0;
}

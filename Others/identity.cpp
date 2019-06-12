#include <iostream>
using namespace std;

int identity(int array[],int size){
  int lh = 0;
  int rh = size;
  while (lh <= rh){
    int med = (lh+rh)/2;
    if (array[med] == med){
      return med;
    }
    else if(array[med] < med){
      lh = med+1;
    }
    else if(array[med] > med){
      rh = med-1;
    }
  }
  return -1;
}

int main(){
  int array[] = {-4,0,2,5,7,8};
  int size = 7;
  int idx = identity(array,size);
  cout << "El indice es: " << idx << endl;
  return 0;
}

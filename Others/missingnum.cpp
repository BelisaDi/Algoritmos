#include <iostream>
#include <cmath>
using namespace std;

int find_missing(int array[], int N){
  int lh = 0;
  int size = N-1;
  int rh = size;
  while (lh <= rh){
    int med = round((rh+lh)/2);
    if (array[med]-med != array[med+1]-(med+1)){
      return array[med]+1;
    }
    else{
      if (array[med]-med == 2){
        rh = med - 1;
      }
      else if (array[med]-med == 1){
        lh = med + 1;
      }
    }
    }
    return -1;
  }

int main(){
  int lista[] = {1,2,3,4,5,7,8,9,10};
  int num = find_missing(lista,10);
  cout << "The missing number is: " << num << endl;
  return 0;
}

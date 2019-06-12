#include <iostream>
using namespace std;

int Lineal(int array[], int x, int len){
	for (int i = 0; i < len; i++){
	  if (array[i] == x){
	    return i;
	  }
	}
	return -1;
}

int main(){
  int lista[] = {0,1,2,3,4,5,6,7,8,9};
  int len = sizeof(lista)/sizeof(int);
  int idx = Lineal(lista,6,len);
  cout << "El indice es: " << idx << endl;
  return 0;
}

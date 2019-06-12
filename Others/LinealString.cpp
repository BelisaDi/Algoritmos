#include <iostream>
#include <string>
using namespace std;

int LinealS(string array[], string x, int n){
  for (int i = 0; i <= n; i++){
    if (array[i] == x){
      return i;
    }
  }
  return -1;
}

int main(){
  string array[] = {"perro","gato","pajaro","caballo"};
  int index = LinealS(array, "mariquita", 4);
  cout << "Lineal Search Result: " << index << endl;
  return 0;
}

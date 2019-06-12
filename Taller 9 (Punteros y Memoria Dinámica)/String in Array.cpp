#include <iostream>
#include <string>
using namespace std;

int main(){
  string cad;
  cout << "Ingrese su linea de texto: " << endl;
  cout << ">";
  cin >> cad;
  int longitud = cad.length();
  char *array = new char[longitud];
  for(int i = 0; i < longitud; i++){
    array[i] = cad[i];
  }
  for(int i = 0; i < longitud; i++){
    cout << array[i] << ' ';
  }
  delete[] array;
  return 0;
}

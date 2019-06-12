#include <iostream>
#include <string>
using namespace std;

string inversion(string palabra){
  if(palabra.length() <= 1){
    return palabra;
  }
  char cotaS = palabra[palabra.length()-1];
  char cotaI = palabra[0];
  return cotaS + inversion(palabra.substr(1,palabra.length()-2)) + cotaI;
}

int main(){
  string cad = "murcielago";
  string newcad = inversion(cad);
  cout << newcad << endl;
  return 0;
}

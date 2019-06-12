#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

void info(map<string,string> &m, string linea){
  string llave, valor;
  int n = linea.length();
  int pos = linea.find(" = ");
  for(int i = 0; i < pos; i++){
    llave += linea[i];
  }
  for(int i = pos+3; i < n; i++){
    valor += linea[i];
  }
  m[llave] = valor;
}

int main(){
  map<string,string> m;
  ifstream archivo;
  int cont = 0;
  string linea;
  archivo.open("errores.txt",ios::in);
  while(getline(archivo, linea)){
    cont++;
  }
  archivo.close();
  archivo.open("errores.txt", ios::in);
  for(int i = 0; i < cont; i++){
    getline(archivo, linea);
    info(m, linea);
  }
  cout << "Exit code" << "\t" << "Message" << endl;
  for(map<string,string>::iterator it = m.begin(); it != m.end(); it++){
    cout << it->first << "\t" << it->second << endl;
  }
  return 0;
}

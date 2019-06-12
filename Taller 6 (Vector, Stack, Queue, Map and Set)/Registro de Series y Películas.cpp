#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void leerLinea(vector<string> &reg, string linea){
  int len = linea.length();
  string palabra;
  for(int i = 0; i <= len; i++){
    if(linea[i] != ','){
      palabra += linea[i];
    }
    else{
      if(palabra.length() > 0){
        reg.push_back(palabra);
        palabra.erase(0,palabra.size());
      }
      }
    if (i == len){
      if(palabra.length() > 0){
        reg.push_back(palabra);
        palabra.erase(0,palabra.size());
      }
    }
    }
  }

void imprimirLineas(vector<vector<string>> regs){
  int n = regs.size();
  for (int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++){
      cout << regs[i][j] << "\t";
    }
    cout << endl;
  }
}

int main(){
  ifstream registro;
  int cont = 0;
  string line;
  registro.open("registro.txt",ios::in);
  while(getline(registro,line)){
    cont++;
  }
  registro.close();
  vector<string> l;
  vector<vector<string>> reg(cont,l);
  string linea;
  registro.open("registro.txt",ios::in);
  int n = reg.size();
  for (int i = 0; i < n; i++){
    getline(registro, linea);
    leerLinea(reg[i], linea);
  }
  registro.close();
  imprimirLineas(reg);
  return 0;
}

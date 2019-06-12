#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<int> va = {};
  vector<int> ve = {};
  vector<int> vi = {};
  vector<int> vo = {};
  vector<int> vu = {};
  ifstream archivo;
  string cuento;
  archivo.open("archivo.txt",ios::in);
  while(!archivo.eof()){
    getline(archivo, cuento);
    int n = cuento.length();
    for(int i = 0; i < n; i++){
      if(cuento[i] == 'a' || cuento[i] == 'A'){
        va.push_back(1);
      }
      if(cuento[i] == 'e' || cuento[i] == 'E'){
        ve.push_back(1);
      }
      if(cuento[i] == 'i' || cuento[i] == 'I'){
        vi.push_back(1);
      }
      if(cuento[i] == 'o' || cuento[i] == 'O'){
        vo.push_back(1);
      }
      if(cuento[i] == 'u' || cuento[i] == 'U'){
        vu.push_back(1);
      }
    }
    cout << cuento << endl;
  }
  cout << "a: " << va.size() << endl;
  cout << "e: " << ve.size() << endl;
  cout << "i: " << vi.size() << endl;
  cout << "o: " << vo.size() << endl;
  cout << "u: " << vu.size() << endl;
  archivo.close();
  return 0;
}

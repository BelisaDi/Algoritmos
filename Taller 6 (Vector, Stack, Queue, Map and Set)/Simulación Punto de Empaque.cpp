#include <iostream>
#include <stack>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
  srand(time(NULL));
  int minutos;
  cout << "Por cuantos minutos simulamos el punto de empaque: ";
  cin >> minutos;
  stack<int> ag;
  stack<int> cu;
  stack<int> lib;
  stack<int> pack;
  int numag = 0, numcu = 0, numlib = 0, numpack = 0, numbox = 0;
  for(int i = 1; i <= minutos; i++){
    int element = rand()%3 + 1;
    if(element == 1){
      ag.push(element);
      numag++;
    }
    if(element == 2){
      cu.push(element);
      numcu++;
    }
    if(element == 3){
      lib.push(element);
      numlib++;
    }
    if (ag.size() >= 5 && cu.size() >= 5 && lib.size() >= 5){
      for(int i = 0; i < 3; i++){
        ag.pop();
        cu.pop();
        lib.pop();
      }
      pack.push(4);
      numpack++;
    }
    if(pack.size() == 12){
      while(!pack.empty()){
        pack.pop();
      }
      numbox++;
    }
  }
  cout << "Este es el balance de la simulacion" << endl;
  cout << "Agendas ingresadas: " << numag << endl;
  cout << "Cuadernos ingresados: " << numcu << endl;
  cout << "Libros ingresados: " << numlib << endl;
  cout << "Paquetes despachados: " << numpack << endl;
  cout << "Cajas despachadas: " << numbox << endl;
  return 0;
}

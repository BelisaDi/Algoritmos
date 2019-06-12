#include <iostream>
using namespace std;

int power(int b, int e){
  if(e == 0){
    return 1;
  }
  else{
    return b * power(b, e-1);
  }
}

int main(){
  int x = power(5,5);
  cout << x << endl;
  return 0;
}

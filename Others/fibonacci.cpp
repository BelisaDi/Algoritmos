#include <iostream>
using namespace std;

int fibonacci(int n){
  if(n < 2){
    return 1;
  }
  else{
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int additiveSequence(int n, int f0, int f1){
  if (n == 0) return f0;
  if (n == 1) return f1;
  return additiveSequence(n-1, f1, f0+f1);
}

int fibonacci2(int n){
  return additiveSequence(n, 0, 1);
}

//¡Manejan los indices de maneras distintas!
int main(){
  int x = fibonacci(5);
  int y = fibonacci2(5);
  cout << x << endl;
  cout << y << endl;
  return 0;
}

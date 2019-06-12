#include <iostream>
using namespace std;

int cofBinom(int n, int k){
  if (n == 0){
    return 0;
  }
  if (k == 0){
    return 1;
  }
  else{
    return cofBinom(n-1, k-1) + cofBinom(n-1, k);
  }
}

int main(){
  int x = cofBinom(5,3);
  cout << x << endl;
  return 0;
}

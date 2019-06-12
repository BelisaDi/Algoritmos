#include <iostream>
using namespace std;

void print_num(int n){
  if( n!= 0){
    print_num(n / 10);
    cout << n%10;
  }
}

int main(){
  print_num(50504);
  cout << endl;
  return 0;
}

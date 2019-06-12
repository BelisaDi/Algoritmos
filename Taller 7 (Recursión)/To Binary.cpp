#include <iostream>
#include <string>
using namespace std;

int to_binary(int n){
  if (n == 0){
    return 0;
  }
  else{
    return (n%2) + 10*to_binary(n/2);
  }
}

int main(){
  for(int i = -10; i <= 10; i++){
    cout << to_binary(i) << endl;
  }
  return 0;
}

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

void Criba(set<int> &s, int n){
  for(int i = 2; i <= n; i++){
    s.insert(i);
  }
  for(int i = 2; i <= sqrt(n); i++){
    for(int j = 2; i*j <= n; j++){
      s.erase(i*j);
    }
  }
}

int main(){
  set<int> s;
  Criba(s, 20);
  for(set<int>::iterator it = s.begin(); it != s.end(); it++){
    cout << *it << ' ';
  }
  cout << endl;
  return 0;
}

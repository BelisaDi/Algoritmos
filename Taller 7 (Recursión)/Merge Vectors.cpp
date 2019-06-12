#include <iostream>
#include <vector>
using namespace std;

void newOrder(vector<int> &a, vector<int> &b, vector<int> &c){
  if(a.empty() && b.empty()){
  }
  if (a.empty() || b.empty()){
    if(a.empty()){
      while(!b.empty()){
        int n = b.front();
        c.push_back(n);
        b.erase(b.begin());
      }
    }
    else if(b.empty()){
      while(!a.empty()){
        int n = a.front();
        c.push_back(n);
        a.erase(a.begin());
      }
    }
  }
  else{
    int e1 = a.front();
    int e2 = b.front();
    if ( e1 <= e2){
      c.push_back(e1);
      a.erase(a.begin());
      return newOrder(a,b,c);
    }
    else{
      c.push_back(e2);
      b.erase(b.begin());
      return newOrder(a,b,c);
    }
  }
}

int main(){
  vector<int> a = {-1,2,4,6,15,19};
  vector<int> b = {3,4,5,21,25};
  vector<int> c;
  newOrder(a,b,c);
  for(unsigned i = 0; i < c.size(); i++){
    cout << c[i] << ' ';
  }
  cout << endl;
  return 0;
}

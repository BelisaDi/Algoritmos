#include <iostream>
#include <queue>
#include <string>
using namespace std;

void Matar(queue<string> q){
  int m;
  string name;
  cout << "Cada cuanto quiere matar gente :) " << endl;
  cout << ">";
  cin >> m;
  while(q.size() > 1){
    for(int i = 0; i < m; i++){
      name = q.front();
      q.pop();
      q.push(name);
    }
    cout << "Mate a " << q.front() << endl;
    q.pop();
  }
  cout << "Sobrevivio: " << q.front() << endl;
}

int main(){
  queue<string> q;
  cout << "Empiece a mandar gente al matadero: " << endl;
  string name;
  while(true){
    cin >> name;
    if (name == "0"){
      break;
    }
    q.push(name);
  }
  Matar(q);
  return 0;
}

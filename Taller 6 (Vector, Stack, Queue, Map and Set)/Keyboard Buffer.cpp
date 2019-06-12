#include <iostream>
#include <queue>
using namespace std;

void sleep(void){
  for(int i = 0; i < 5e7; i++);
}

queue<char> store(void){
  queue<char> lista;
  char ch = ' ';
  while (ch != '\n'){
    ch = getchar();
    lista.push(ch);
  }
  return lista;
}

void retrieve(queue<char> & q){
  cout << "El mensaje fue: \n\n";
  while(!q.empty()){
    if (q.front() != '*'){
      cout << q.front() << flush;
      sleep();
      q.pop();
    }
    else{
      cout << endl << flush;
      sleep();
      q.pop();
    }
  }
}

int main(){
  queue<char> lis;
  lis = store();
  retrieve(lis);
  return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool arePair(char begin, char end){
  if(begin == '(' && end == ')') return true;
  else if(begin == '[' && end == ']') return true;
  else if(begin == '{' && end == '}') return true;
  return false;
}

bool isBalanced(string stuff){
  stack<char> s;
  int n = stuff.length();
  for(int i = 0; i < n; i++){
    if(stuff[i] == '{' || stuff[i] == '[' || stuff[i] == '('){
      s.push(stuff[i]);
    }
    else if(stuff[i] == '}' || stuff[i] == ']' || stuff[i] == ')'){
      if(s.empty()){
        return false;
      }
      else if(arePair(s.top(),stuff[i])){
      s.pop();
    }
    }
  }
  if(s.empty()){
    return true;
  }
  else{
  return false;
}
}

int main(){
  string thing;
  cout << "Ingrese su expresion: ";
  cin >> thing;
  if (isBalanced(thing)){
    cout << "Esto esta bien!" << endl;
  }
  else{
    cout << "Algo anda mal..." << endl;
  }
  return 0;
}

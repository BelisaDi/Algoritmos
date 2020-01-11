#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool check_balance(const string & expr) {
  stack<char> s;
  int n = expr.length();
  for(int i = 0; i < n; i++){
    if(expr[i] == '{' || expr[i] == '[' || expr[i] == '('){
      s.push(expr[i]);
    }
    else if(expr[i] == '}' || expr[i] == ']' || expr[i] == ')'){
      if(s.empty()){
        return false;
      }
      else{
        if (s.top() == '(' && expr[i] == ')'){
          s.pop();
        }
        else if (s.top() == '[' && expr[i] == ']'){
          s.pop();
        }
        else if (s.top() == '{' && expr[i] == '}'){
          s.pop();
        }
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

int mark_unmatched(const string & expr) {
  stack<char> s;
  int n = expr.length();
  if(check_balance(expr)){
    return -1;
  }
  for(int i = 0; i < n; i++){
    if(expr[i] == '{' || expr[i] == '[' || expr[i] == '('){
      s.push(expr[i]);
    }
    else if(expr[i] == '}' || expr[i] == ']' || expr[i] == ')'){
      if(s.empty()){
        return i;
      }
      else{
        if (s.top() == '(' && expr[i] == ')'){
          s.pop();
        }
        else if (s.top() == '[' && expr[i] == ']'){
          s.pop();
        }
        else if (s.top() == '{' && expr[i] == '}'){
          s.pop();
        }
        else{
          s.push(expr[i]);
          while(i >= 0){
          if (expr[i] == ')'){
            while(s.top() != '('){
              i--;
              s.pop();
            }
            return i;
          }
          else if (expr[i] == ']'){
            while(s.top() != '['){
              i--;
              s.pop();
            }
            return i;
          }
          else if (expr[i] == '}'){
            while(s.top() != '{'){
              i--;
              s.pop();
              }
            return i;
          }
        }
      }
    }
  }
}
return 0;
}

// Si lo primero que encuentra es un caracter cerrado, retorna 0 como el indice del primer caracter desbalanceado (que es el cerrado)

int main(){
    vector<string> expr = {"[(])", "[{(([[", ")}]])", "[()]{}{[()()]()}", "[({})]", "[]{(})"};

    for (unsigned e = 0; e < expr.size(); e++) {
        string msg = check_balance(expr[e]) ? " Balanced" : " Not balanced";
        cout << "Expression: " << expr[e] << msg << endl;
    }

    for (unsigned e = 0; e < expr.size(); e++) {
        int rc = mark_unmatched(expr[e]);
        cout << "Expression: " << expr[e] << " " << rc << endl;
    }

    return 0;
}

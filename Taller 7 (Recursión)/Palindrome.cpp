#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string str){
  int len = str.length();
  if (len <= 1){
    return true;
  }
  else{
    char c0 = tolower(str[0]);
    char c1 = tolower(str[len-1]);
    return c0 == c1 && isPalindrome(str.substr(1, len-2));
  }
}

int main(){
  string cad = "HOLA";
  cout << isPalindrome(cad) << endl;
  return 0;
}

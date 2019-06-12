#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str){
  int len = str.length();
  if (len <= 1){
    return true;
  }
  else{
    return str[0] == str[len-1] && isPalindrome(str.substr(1, len-2));
  }
}

int main(){
  string cad = "car";
  cout << isPalindrome(cad) << endl;
  return 0;
}

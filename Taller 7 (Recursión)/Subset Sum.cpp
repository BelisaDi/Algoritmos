#include <iostream>
#include <set>
using namespace std;

bool subsum(set<int> &s, int target){
  if (s.empty()){
    return target == 0;
  }
  else{
    int e = *s.begin();
    set<int> rest = s;
    rest.erase(rest.begin());
    return subsum(rest, target) || subsum(rest, target - e);
  }
}

int countSubsum(set<int> &s, int target){
  if (s.empty()){
    if (target == 0){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    int e = *s.begin();
    set<int> rest = s;
    rest.erase(rest.begin());
    return countSubsum(rest,target) + countSubsum(rest,target - e);
  }
}

int main(){
  set<int> s = {1,2,3,4,5,6,7,8,9};
  cout << subsum(s,7) << endl;
  cout << "**" << countSubsum(s,7) << endl;
  cout << subsum(s,5) << endl;
  cout << "**" << countSubsum(s,5) << endl;
  return 0;
}

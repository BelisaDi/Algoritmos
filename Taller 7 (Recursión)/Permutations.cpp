#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> test;

set<string> permutations(const string &str) {
    set<string> cf;
    if (str.empty()){
        cf.insert(string(""));
    }
    else{
        for (unsigned i = 0; i < str.length(); i++) {
            string rest = str.substr(0, i) + str.substr(i + 1);
            set<string> tmp = permutations(rest);
            for (const string &s : tmp) cf.insert(str[i] + s);
        }
    }
    return cf;
}


int main() {
	string input = "AABB";
  set<string> pp = permutations(input);
  for (const string &s : pp) cout << s << endl;
	return 0;
}

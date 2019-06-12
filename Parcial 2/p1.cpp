#include <vector>
#include <iostream>
using namespace std;

template <typename dataType>
int binary_like_search_helper(vector<dataType> & vec, dataType key, int & globalmid){
  int len = vec.size();
  int mid = len/2;
  if(len <= 1 && vec[mid] != key){
    return -1;
  }
  else if(vec[mid] == key){
    return mid + globalmid;
  }
  else{
    vector<dataType> vecleft;
    vector<dataType> vecright;
    int newglobal = mid + globalmid;
    for(int i = 0; i < len; i++){
      if(i < mid){
        vecleft.push_back(vec[i]);
      }
      else{
        vecright.push_back(vec[i]);
      }
    }
    int result = binary_like_search_helper(vecleft, key, newglobal);
    if(result != -1){
      return result;
    }
    else{
      return binary_like_search_helper(vecright, key, newglobal);
    }
  }
  return -1;
}


template <typename dataType>
int binary_like_search(const vector<dataType> &vec, dataType key) {
  vector<dataType> ref = vec;
  int initial = 0;
  return binary_like_search_helper(ref, key, initial);
}


int main()
{
    vector<int> u = {-11, -9, -7, -5, -3, -1};
    cout << "bls int  : " << binary_like_search(u, -5) << endl;
    cout << "bls int  : " << binary_like_search(u, 4) << endl;

    vector<char> v = {'u', 'U', 'o', 'V', 'i', 'W', 'e', 'X', 'a'};
    cout << "bls char : " << binary_like_search(v, 'i') << endl;
    cout << "bls char : " << binary_like_search(v, 'A') << endl;

    vector<double> w = {10.0, -5.5, 0.0, 4.0, 1.0, -2.4, 55.5};
    cout << "bls float: " << binary_like_search(w, -2.4) << endl;
    cout << "bls float: " << binary_like_search(w, 43.0) << endl;

    return 0;
}

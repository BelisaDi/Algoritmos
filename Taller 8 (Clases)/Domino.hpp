#ifndef _Domino_hpp_
#define _Domino_hpp_
#include <iostream>
using namespace std;

class Domino{

private:
  unsigned int left, right;

public:
  Domino();
  Domino(int iz, int der);

  void set_left_dots(int ldots);
  void set_right_dots(int rdots);

  int get_left_dots();
  int get_right_dots();

  string to_string();

  friend ostream & operator<<(ostream & os, Domino & d);
  friend bool operator==(Domino & d1, Domino & d2);
  friend bool operator!=(Domino & d1, Domino & d2);
  friend bool operator<(Domino & d1, Domino & d2);
  friend bool operator<=(Domino &d1, Domino & d2);
  friend bool operator>(Domino & d1, Domino & d2);
  friend bool operator>=(Domino & d1, Domino & d2);

  void flip_them();

};

#endif //_Domino_hpp_

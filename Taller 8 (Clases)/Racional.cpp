#include <iostream>
using namespace std;

int mcd(int num, int den);

class Racional{
public:
  Racional(){
    num = 0;
    den = 1;
  }
  Racional(int nc, int dc){
    num = nc;
    den = dc;
  }

  int getNum() { return num; }
  int getDen() { return den; }

  void setNum(int v) { num = v; }
  void setDen(int v){
    if(v != 0){
      den = v;
    }
    else{
      cout << "El denominador no puede ser 0!" << endl;
    }
  }

  Racional operator=(Racional r){
    num = r.getNum();
    den = r.getDen();
    this->simplify();
    return *this;
  }

  Racional operator+=(Racional r){
    num = num * r.getDen() + den * r.getNum();
    den = den * r.getDen();
    this->simplify();
    return *this;
  }

  Racional operator-=(Racional r){
    num = num * r.getDen() - den * r.getNum();
    den = den * r.getDen();
    this->simplify();
    return *this;
  }

  Racional operator*=(Racional r){
    num = num * r.getNum();
    den = den * r.getDen();
    this->simplify();
    return *this;
  }

  Racional operator/=(Racional r){
    num = num * r.getDen();
    den = den * r.getNum();
    this->simplify();
    return *this;
  }

  void simplify(){
    int max = mcd(num, den);
    while (max != 1){
      num /= max;
      den /= max;
      max = mcd(num,den);
    }
  }

  friend istream & operator>>(istream &is, Racional &r1);

private:
  int num, den;
};

ostream & operator<<(ostream &os, Racional &r1){
  return os << r1.getNum() << "/" << r1.getDen();
}

istream & operator>>(istream &is, Racional &r1){
  char ch = '/';
  is >> r1.num >> ch >> r1.den;
  return is;
}

Racional operator+(Racional &r1, Racional &r2){
  Racional r3;
  r3.setNum((r1.getNum()*r2.getDen())+(r1.getDen()*r2.getNum()));
  r3.setDen(r1.getDen()*r2.getDen());
  r3.simplify();
  return r3;
}

Racional operator-(Racional &r1, Racional &r2){
  Racional r3;
  r3.setNum((r1.getNum()*r2.getDen())-(r1.getDen()*r2.getNum()));
  r3.setDen(r1.getDen()*r2.getDen());
  r3.simplify();
  return r3;
}

Racional operator*(Racional &r1, Racional &r2){
  Racional r3;
  r3.setNum(r1.getNum()*r2.getNum());
  r3.setDen(r1.getDen()*r2.getDen());
  r3.simplify();
  return r3;
}

Racional operator/(Racional &r1, Racional &r2){
  Racional r3;
  r3.setNum(r1.getNum()*r2.getDen());
  r3.setDen(r1.getDen()*r2.getNum());
  r3.simplify();
  return r3;
}

bool operator==(Racional &r1, Racional &r2){
  return r1.getNum() == r2.getNum() && r1.getDen() == r2.getDen();
}

bool operator<(Racional &r1, Racional &r2){
  return r1.getNum()*r2.getDen() < r1.getDen()*r2.getNum();
}

bool operator>(Racional &r1, Racional &r2){
  return r1.getNum()*r2.getDen() < r1.getDen()*r2.getNum();
}

bool operator>=(Racional &r1, Racional &r2){
  return r1.getNum()*r2.getDen() >= r1.getDen()*r2.getNum();
}

bool operator<=(Racional &r1, Racional &r2){
  return r1.getNum()*r2.getDen() <= r1.getDen()*r2.getNum();
}

bool operator!=(Racional &r1, Racional &r2){
  return r1.getNum() != r2.getNum() || r1.getDen() != r2.getDen();
}

Racional & operator++(Racional &r){
  r.setNum(r.getNum() + r.getDen());
  r.simplify();
  return r;
}

Racional operator++(Racional &r, int){
  Racional temp = r;
  r.setNum(r.getNum() + r.getDen());
  temp.simplify();
  return temp;
}

Racional & operator--(Racional &r){
  r.setNum(r.getNum() - r.getDen());
  r.simplify();
  return r;
}

Racional operator--(Racional &r, int){
  Racional temp = r;
  r.setNum(r.getNum() - r.getDen());
  temp.simplify();
  return temp;
}

int mcd(int num, int den){
  long mcd, tmp, rest;
  mcd = abs(num);
  tmp = den;
  while( tmp > 0 ){
    rest = mcd % tmp;
    mcd = tmp;
    tmp = rest;
  }
  return mcd;
}

int main(){
  Racional a, b, c;
  cout << "Ingrese un racional: ";
	cin >> a;
  cout << "Ingrese otro racional: ";
	cin >> b;
	c = a+b;
  cout << "Su suma es: ";
	cout << c << endl;
}

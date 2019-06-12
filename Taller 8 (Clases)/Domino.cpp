#include "Domino.hpp"
#include <iostream>
#include <string>
using namespace std;

Domino::Domino(){
  this->left = 0;
  this->right = 0;
}

Domino::Domino(int iz, int der){
  if((iz >= 0 && iz <= 6) && (der >= 0 && der <= 6)){
    this->left = iz;
    this->right = der;
  }
  else{
    cout << "That's an unvalid value for a domino dude." << endl;
  }
}

void Domino::set_left_dots(int ldots){
  if(ldots >= 0 && ldots <= 6){
    this->left = ldots;
  }
}

void Domino::set_right_dots(int rdots){
  if(rdots >= 0 && rdots <= 6){
    this->right = rdots;
  }
}

int Domino::get_left_dots(){
  return left;
}

int Domino::get_right_dots(){
  return right;
}

string Domino::to_string(){
	string out = "+-------+-------+\n";
	if (left == 0 && right == 0) {
		out += "|       |       |\n|       |       |\n|       |       |\n";
	}
	else if (left == 0 && right == 1) {
		out += "|       |       |\n|       |   #   |\n|       |       |\n";
	}
	else if (left == 0 && right == 2) {
		out += "|       |       |\n|       | #   # |\n|       |       |\n";
	}
	else if (left == 0 && right == 3) {
		out += "|       |       |\n|       | # # # |\n|       |       |\n";
	}
	else if (left == 0 && right == 4) {
		out += "|       | #   # |\n|       |       |\n|       | #   # |\n";
	}
	else if (left == 0 && right == 5) {
		out += "|       | #   # |\n|       |   #   |\n|       | #   # |\n";
	}
	else if (left == 0 && right == 6) {
		out += "|       | # # # |\n|       |       |\n|       | # # # |\n";
	}
	else if (left == 1 && right == 0) {
		out += "|       |       |\n|   #   |       |\n|       |       |\n";
	}
	else if (left == 1 && right == 1) {
		out += "|       |       |\n|   #   |   #   |\n|       |       |\n";
	}
	else if (left == 1 && right == 2) {
		out += "|       |       |\n|   #   | #   # |\n|       |       |\n";
	}
	else if (left == 1 && right == 3) {
		out += "|       |       |\n|   #   | # # # |\n|       |       |\n";
	}
	else if (left == 1 && right == 4) {
		out += "|       | #   # |\n|   #   |       |\n|       | #   # |\n";
	}
	else if (left == 1 && right == 5) {
		out += "|       | #   # |\n|   #   |   #   |\n|       | #   # |\n";
	}
	else if (left == 1 && right == 6) {
		out += "|       | # # # |\n|   #   |       |\n|       | # # # |\n";
	}
	else if (left == 2 && right == 0) {
		out += "|       |       |\n| #   # |       |\n|       |       |\n";
	}
	else if (left == 2 && right == 1) {
		out += "|       |       |\n| #   # |   #   |\n|       |       |\n";
	}
	else if (left == 2 && right == 2) {
		out += "|       |       |\n| #   # | #   # |\n|       |       |\n";
	}
	else if (left == 2 && right == 3) {
		out += "|       |       |\n| #   # | # # # |\n|       |       |\n";
	}
	else if (left == 2 && right == 4) {
		out += "|       | #   # |\n| #   # |       |\n|       | #   # |\n";
	}
	else if (left == 2 && right == 5) {
		out += "|       | #   # |\n| #   # |   #   |\n|       | #   # |\n";
	}
	else if (left == 2 && right == 6) {
		out += "|       | # # # |\n| #   # |       |\n|       | # # # |\n";
	}
	else if (left == 3 && right == 0) {
		out += "|       |       |\n| # # # |       |\n|       |       |\n";
	}
	else if (left == 3 && right == 1) {
		out += "|       |       |\n| # # # |   #   |\n|       |       |\n";
	}
	else if (left == 3 && right == 2) {
		out += "|       |       |\n| # # # | #   # |\n|       |       |\n";
	}
	else if (left == 3 && right == 3) {
		out += "|       |       |\n| # # # | # # # |\n|       |       |\n";
	}
	else if (left == 3 && right == 4) {
		out += "|       | #   # |\n| # # # |       |\n|       | #   # |\n";
	}
	else if (left == 3 && right == 5) {
		out += "|       | #   # |\n| # # # |   #   |\n|       | #   # |\n";
	}
	else if (left == 3 && right == 6) {
		out += "|       | # # # |\n| # # # |       |\n|       | # # # |\n";
	}
	else if (left == 4 && right == 0) {
		out += "| #   # |       |\n|       |       |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 1) {
		out += "| #   # |       |\n|       |   #   |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 2) {
		out += "| #   # |       |\n|       | #   # |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 3) {
		out += "| #   # |       |\n|       | # # # |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 4) {
		out += "| #   # | #   # |\n|       |       |\n| #   # | #   # |\n";
	}
	else if (left == 4 && right == 5) {
		out += "| #   # | #   # |\n|       |   #   |\n| #   # | #   # |\n";
	}
	else if (left == 4 && right == 6) {
		out += "| #   # | # # # |\n|       |       |\n| #   # | # # # |\n";
	}
	else if (left == 5 && right == 0) {
		out += "| #   # |       |\n|   #   |       |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 1) {
		out += "| #   # |       |\n|   #   |   #   |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 2) {
		out += "| #   # |       |\n|   #   | #   # |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 3) {
		out += "| #   # |       |\n|   #   | # # # |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 4) {
		out += "| #   # | #   # |\n|   #   |       |\n| #   # | #   # |\n";
	}
	else if (left == 5 && right == 5) {
		out += "| #   # | #   # |\n|   #   |   #   |\n| #   # | #   # |\n";
	}
	else if (left == 5 && right == 6) {
		out += "| #   # | # # # |\n|   #   |       |\n| #   # | # # # |\n";
	}
	else if (left == 6 && right == 0) {
		out += "| # # # |       |\n|       |       |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 1) {
		out += "| # # # |       |\n|       |   #   |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 2) {
		out += "| # # # |       |\n|       | #   # |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 3) {
		out += "| # # # |       |\n|       | # # # |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 4) {
		out += "| # # # | #   # |\n|       |       |\n| # # # | #   # |\n";
	}
	else if (left == 6 && right == 5) {
		out += "| # # # | #   # |\n|       |   #   |\n| # # # | #   # |\n";
	}
	else if (left == 6 && right == 6) {
		out += "| # # # | # # # |\n|       |       |\n| # # # | # # # |\n";
	}
	out += "+-------+-------+";
	return out;
}

ostream & operator<<(ostream & os, Domino & d){
  return os << d.to_string();
}

bool operator==(Domino & d1, Domino & d2){
  return (d1.left == d2.left && d1.right == d2.right)||(d1.left == d2.right && d1.right == d2.left);
}

bool operator!=(Domino & d1, Domino & d2){
  return d1.left != d2.left || d1.right != d2.right;
}

bool operator<(Domino & d1, Domino & d2){
  if(d1.left < d2.left){
    return true;
  }
  else if(d1.left == d2.left && d1.right < d2.right){
    return true;
  }
  else{
    return false;
  }
}

bool operator<=(Domino & d1, Domino & d2){
  if(d1.left <= d2.left){
    return true;
  }
  else if(d1.left == d2.left && d1.right <= d2.right){
    return true;
  }
  else{
    return false;
  }
}

bool operator>(Domino & d1, Domino & d2){
  if(d1.left > d2.left){
    return true;
  }
  else if(d1.left == d2.left && d1.right > d2.right){
    return true;
  }
  else{
    return false;
  }
}

bool operator>=(Domino & d1, Domino & d2){
  if(d1.left >= d2.left){
    return true;
  }
  else if(d1.left == d2.left && d1.right >= d2.right){
    return true;
  }
  else{
    return false;
  }
}

void Domino::flip_them(){
  int iz = left;
  int der = right;
  this->left = der;
  this->right = iz;
}

int main(){
  for(int i = 0; i <= 6; i++){
    for(int j = i; j <= 6; j++){
      Domino d(i,j);
      cout << d << endl;
    }
  }
  return 0;
}

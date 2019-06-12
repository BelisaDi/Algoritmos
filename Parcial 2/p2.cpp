#include <iostream>
#include "p2.hpp"
using namespace std;

Polynomial & Polynomial::operator=(const Polynomial & src){
  if(front != nullptr){
    clear();
  }
  term *tmp = src.front;
  if(tmp != nullptr){
    front = new Polynomial::term(tmp->coef, tmp->exp, nullptr);
    tmp = tmp->next;
  }
  term *begin = front;
  while(tmp != nullptr){
    front->next = new term(tmp->coef, tmp->exp, nullptr);
    front = front->next;
    tmp = tmp->next;
  }
  front = begin;
  num_terms = src.num_terms;
  return *this;
}

Polynomial operator+(const Polynomial &p1, const Polynomial &p2){
  Polynomial res;
  Polynomial::term *tmp1 = p1.front;
  Polynomial::term *tmp2 = p2.front;
  Polynomial::term *front = res.front;
  Polynomial::term *begin;
  if(tmp1 != nullptr || tmp2 != nullptr){
    if(tmp1->exp > tmp2->exp){
      front = new Polynomial::term(tmp1->coef, tmp1->exp, nullptr);
      begin = front;
      tmp1 = tmp1->next;
      res.num_terms++;
    }
    else if(tmp1->exp < tmp2->exp){
      front = new Polynomial::term(tmp2->coef, tmp2->exp, nullptr);
      begin = front;
      tmp2 = tmp2->next;
      res.num_terms++;
    }
    else if(tmp1->exp == tmp2->exp){
      front = new Polynomial::term(tmp1->coef + tmp2->coef, tmp1->exp, nullptr);
      begin = front;
      tmp1 = tmp1->next;
      tmp2 = tmp2->next;
      res.num_terms++;
    }
  }
  while(tmp1 != nullptr || tmp2 != nullptr){
    if(tmp1 == nullptr){
      while(tmp2 != nullptr){
        front->next = new Polynomial::term(tmp2->coef, tmp2->exp, nullptr);
        front = front->next;
        tmp2 = tmp2->next;
        res.num_terms++;
      }
    }
    else if(tmp2 == nullptr){
      while(tmp1 != nullptr){
        front->next = new Polynomial::term(tmp1->coef, tmp1->exp, nullptr);
        front = front->next;
        tmp1 = tmp1->next;
        res.num_terms++;
      }
    }
    else if(tmp1->exp > tmp2->exp){
      front->next = new Polynomial::term(tmp1->coef, tmp1->exp, nullptr);
      front = front->next;
      tmp1 = tmp1->next;
      res.num_terms++;
    }
    else if(tmp1->exp < tmp2->exp){
      front->next = new Polynomial::term(tmp2->coef, tmp2->exp, nullptr);
      front = front->next;
      tmp2 = tmp2->next;
      res.num_terms++;
    }
    else if(tmp1->exp == tmp2->exp){
      front->next = new Polynomial::term(tmp1->coef + tmp2->coef, tmp1->exp, nullptr);
      front = front->next;
      tmp1 = tmp1->next;
      tmp2 = tmp2->next;
      res.num_terms++;
    }
  }
  res.front = begin;
  return res;
}

Polynomial::Polynomial(const string &str) {
    string no_spaces;
    vector<char> signs;
    vector<string> terms;

    no_spaces = strip_whitespaces(str);
    tokenize_terms_signs(no_spaces, terms, signs);
    polynomial_from_terms_signs(terms, signs);
}

void Polynomial::push_term(int coef, int expo) {
    num_terms++;
    term *just = new term(coef, expo);

    if (front == nullptr) {
        front = just;
    } else {
        term *curr = front;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = just;
    }
}


void Polynomial::clear() {
    while (front != nullptr) {
        term *curr = front->next;
        delete front;
        front = curr;
        num_terms--;
    }
}


ostream& operator<<(ostream &os, const Polynomial &p) {
    os << "[ ";
    for (Polynomial::term* t = p.front; t != nullptr; t = t->next)
        os << "(" << t->coef << "," << t->exp << ") ";
    os << "] terms " << p.num_terms;

    return os;
}


void Polynomial::polynomial_from_terms_signs(const vector<string> &terms,
                                             const vector<char> &signs) {
    for (unsigned i = 0; i < terms.size(); i++) {
        const string &curr = terms[i];
        auto pos_x = curr.find('x');

        string coef_str = signs[i] + (pos_x == 0? "1" : curr.substr(0, pos_x));
        string expo_str = curr.substr(pos_x + 2);

        int coef = stoi(coef_str), expo = stoi(expo_str);

        push_term(coef, expo);
    }
}


string strip_whitespaces(const string &str) {
    string stripped;
    for (const auto &ch : str) {
        if (ch != ' ') stripped.push_back(ch);
    }
    return stripped;
}


void tokenize_terms_signs(string str, vector<string> &terms,
                          vector<char> &signs) {
    if (str[0] == '-') {
        signs.push_back(str[0]);
        str.erase(str.begin());
    } else signs.push_back('+');

    int prev = 0;
    for (unsigned c = 0; c < str.size(); ++c) {
        char ch = str[c];
        if (ch == '-' or ch == '+') {
            terms.push_back(str.substr(prev, c - prev));
            signs.push_back(ch);
            prev = c + 1;
        } else if (c == str.size() - 1) {
            terms.push_back(str.substr(prev, str.size() - prev));
        }
    }
}

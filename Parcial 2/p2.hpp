#ifndef polynomial_hpp
#define polynomial_hpp

#include <vector>
#include <string>


class Polynomial {
    struct term {
        int coef = 0, exp = 0;
        term *next = nullptr;
        term(int c, int e, term *n = nullptr) : coef{c}, exp{e}, next{n} {}
    };

    term *front = nullptr;  // pointer to first term in polynomial
    unsigned num_terms = 0; // number of different powers in polynomial

public:
    Polynomial() = default;
    Polynomial(const std::string &str);
    ~Polynomial() { clear(); }

    void push_term(int coef, int expo);
    void clear();

    Polynomial & operator=(const Polynomial &src);
    friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);

    friend std::ostream& operator<<(std::ostream &os, const Polynomial &p);

private:
    void polynomial_from_terms_signs(const std::vector<std::string> &terms,
                                     const std::vector<char> &signs);
};


std::string strip_whitespaces(const std::string &str);
void tokenize_terms_signs(std::string str, std::vector<std::string> &terms,
                          std::vector<char> &signs);

#endif /* polynomial_hpp */

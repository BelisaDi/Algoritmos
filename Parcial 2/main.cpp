#include <iostream>
#include "p2.hpp"
using namespace std;

int main() {
    Polynomial p_poly;
    {
        Polynomial q_poly("-7 x^6 + 5 x^4 - 3 x^2 - 1 x^0");
        cout << q_poly << endl;
        p_poly = q_poly;
    }
    cout << "\nPoly asgmt\n" << p_poly << endl << endl;

    Polynomial r_poly("-5x^12 - 456x^2");
    Polynomial s_poly("8x^6 - 9x^5 + 56x^2 - 78x^1 + x^0");
    cout << r_poly << "\n" << s_poly << endl;

    Polynomial t_poly = r_poly + s_poly;
    cout << "\nPoly sum\n" << t_poly << endl;

    return 0;
}

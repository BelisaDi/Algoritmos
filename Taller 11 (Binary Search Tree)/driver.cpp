#include "bst.hpp"
#include <iostream>
using namespace std;

int main() {
	bst<int> mytree;
	mytree.insert(5);
	mytree.insert(1);
	mytree.insert(10);
	bst<int> other = mytree;
	mytree.display();
	cout << "-----------------------------------" << endl;
	mytree.remove(5);
	mytree.display();
	cout << "-----------------------------------" << endl;
	mytree.remove(1);
	mytree.remove(10);
	mytree.display();
	cout << "-----------------------------------" << endl;
	other.display();
	cout << "-----------------------------------" << endl;
	if(other.find(10)) {
		cout << "10 is in the tree" << endl;
	}
	if (other.find(25)) {
		cout << "25 is in the tree" << endl;
	}
	other.clear();
	other.display();
	cout << "-----------------------------------" << endl;
	return 0;
}

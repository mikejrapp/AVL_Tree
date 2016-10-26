#include<iostream>
#include<string>
#include "Tree.h"

using namespace std;

int main() {
	Tree<int> tree;

	cout << "adding 5" << endl;
	tree.add(5);
	cout << "adding 2" << endl;
	tree.add(2);
	cout << "adding 3" << endl;
	tree.add(3);
	cout << "adding 6" << endl;
	tree.add(6);
	cout << "adding 1" << endl;
	tree.add(1);
	cout << "adding 9" << endl;
	tree.add(9);
	cout << "adding 7" << endl;
	tree.add(7);
	cout << "adding 8" << endl;
	tree.add(8);

	tree.print();
	cin.get();
	return 0;
}
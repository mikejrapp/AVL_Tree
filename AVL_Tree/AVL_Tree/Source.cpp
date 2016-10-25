#include<iostream>
#include<string>
#include "Tree.h"

using namespace std;

int main() {
	Tree<int> tree;

	tree.add(7);
	tree.add(5);
	tree.add(2);
	tree.add(3);
	tree.add(1);
	tree.add(6);

	tree.print();
	cin.get();
	return 0;
}
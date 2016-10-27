#include<iostream>
#include<string>
#include<fstream>
#include "Tree.h"

using namespace std;

void loadData(ifstream &inFile, Tree<int> &tree);

int main() {
	ifstream inFile;
	Tree<int> tree;

	loadData(inFile, tree);
	tree.print();

	cin.ignore();
	cin.get();
	return 0;
}

void loadData(ifstream &inFile, Tree<int> &tree) {
	string fileName;

	cout << "please enter the filepath of the file to open: ";
	cin >> fileName;

	inFile.open(fileName);
	if (inFile) {
		while (!inFile.eof()) {
			int data;
			inFile >> data;
			if (data == 13) {
				cout << "test";
			}
			tree.add(data);
		}
	}
	else {
		cout << "file not found!" << endl;
	}

	inFile.close();
}
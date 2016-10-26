#pragma once
#ifndef H_TREE
#define H_TREE

#include<iostream>
#include<string>
#include<math.h>

using namespace std;


template<class T>
class Tree {
private:
	struct Node {
		T data;
		Node *right;
		Node *left;
	};

	Node *root;
	Node *temp;
	void traverse(Node *pNode);
	void descendTree(T pData, Node *pNode);
	void addLeft(T pData, Node *pNode);
	void addRight(T pData, Node *pNode);
	void balanceTree(Node *pNode);
	int getLeftHeight(Node *pNode, int height);
	int getRightHeight(Node *pNode, int height);
	int getHeight(Node *pNode, int height);
public:
	Tree();
	void print();
	void add(T pData);
};

template<class T>
Tree<T>::Tree() {
	root = nullptr;
}

template<class T>
void Tree<T>::traverse(Node *pNode) {
	if (pNode->left != nullptr) {
		traverse(pNode->left);
	}
	cout << pNode->data << endl;
	if (pNode->right != nullptr) {
		traverse(pNode->right);
	}
}

template<class T>
void Tree<T>::print() {
	traverse(root);
}

template<class T>
void Tree<T>::descendTree(T pData, Node *pNode) {
	if (root == nullptr) {
		root = new Node;
		root->data = pData;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (pNode->data > pData) {//if less than current nodes data go left
		if (pNode->left == nullptr) {//if left pointer is null, add new node
			addLeft(pData, pNode);
		}
		else {//go to next node and check again
			pNode = pNode->left;
			descendTree(pData, pNode);
		}
	}
	else if (pNode->data < pData) {//if greater than current node data go right
		if (pNode->right == nullptr) {
			addRight(pData, pNode);//if right pointer is null, add new node
		}
		else {//go to next node and check again
			pNode = pNode->right;
			descendTree(pData, pNode);
		}
	}	
}

template<class T>
void Tree<T>::add(T pData) {
	descendTree(pData, root);
	balanceTree(root);
}

template<class T>
void Tree<T>::addLeft(T pData,Node *pNode) {
	temp = new Node;
	temp->data = pData;
	temp->left = nullptr;
	temp->right = nullptr;
	pNode->left = temp;
}

template<class T>
void Tree<T>::addRight(T pData, Node *pNode) {
	temp = new Node;
	temp->data = pData;
	temp->left = nullptr;
	temp->right = nullptr;
	pNode->right = temp;
}

template<class T>
void Tree<T>::balanceTree(Node* pNode) {
	
	int balanceFactor;

	if(pNode->left != nullptr){
		balanceTree(pNode->left);
	}
	if (pNode->right != nullptr) {
		balanceTree(pNode->right);
	}
	balanceFactor = abs(getHeight(pNode, 0));//abs(getLeftHeight(pNode, 0) - getRightHeight(pNode, 0));
	if (balanceFactor >= 2) {
		cout << "tree out of balance at: " << pNode->data << endl;
	}
}

template<class T>
int Tree<T>::getLeftHeight(Node *pNode, int height) {

	if (pNode->left != nullptr) {//if there is something on the left, add to height
		height += 1;
		getLeftHeight(pNode->left, height);
	}
	if (pNode->left == nullptr && pNode->right != nullptr) {
		height = getRightHeight(pNode, height);
	}
	return height;
}

template<class T>
int Tree<T>::getRightHeight(Node *pNode, int height) {

	if (pNode->right != nullptr) {//if something on right, add to height
		height += 1;
		getRightHeight(pNode->right, height);
	}
	if (pNode->right == nullptr && pNode->left != nullptr) {
		height = getLeftHeight(pNode, height);
	}

	return height;
}

template<class T>
int Tree<T>::getHeight(Node *pNode, int height) {
	int leftHeight = height;
	int rightHeight = height;
	
	if (pNode != nullptr) {
		if (pNode->left != nullptr) {
			leftHeight = getLeftHeight(pNode->left, height + 1);
		}
		if (pNode->right != nullptr) {
			rightHeight = getRightHeight(pNode->right, height + 1);
		}

		return leftHeight - rightHeight;
	}
	else {
		return height;
	}
}

#endif
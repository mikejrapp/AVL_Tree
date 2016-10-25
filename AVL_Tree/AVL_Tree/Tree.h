#pragma once
#ifndef H_TREE
#define H_TREE

#include<iostream>
#include<string>

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
public:
	Tree();
	
	void print();
	//void descendTree(T pData, Node *pNode);
	void add(T pData);
	void addLeft(T pData, Node *pNode);
	void addRight(T pData, Node *pNode);
};

template<class T>
Tree<T>::Tree() {
	root = nullptr;
}

template<class T>
void Tree<T>::traverse(Node *pNode) {
	/*
		if someting on the left go there
		if something on the right go there
		print
	*/
	
	if (pNode->left != nullptr) {
		pNode = pNode->left;
		traverse(pNode);
	}
	cout << "Popping: " << pNode->data << endl;
	if (pNode->right != nullptr) {
		pNode = pNode->right;
		traverse(pNode);
	}
	cout << "Everything has been checked for: "<< pNode->data << endl;
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
#endif
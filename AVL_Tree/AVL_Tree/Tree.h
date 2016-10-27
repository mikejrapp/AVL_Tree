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
	void balanceTree(Node *&pNode);
	int getLeftHeight(Node *&pNode, int height);
	int getRightHeight(Node *&pNode, int height);
	int getBalance(Node *&pNode, int height);
	void rotate(Node* &pNode,int balanceFactor);
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
void Tree<T>::balanceTree(Node* &pNode) {
	
	int balanceFactor;

	if(pNode->left != nullptr){
		balanceTree(pNode->left);
	}
	if (pNode->right != nullptr) {
		balanceTree(pNode->right);
	}
	balanceFactor = getBalance(pNode, 0);//abs(getLeftHeight(pNode, 0) - getRightHeight(pNode, 0));
	if (balanceFactor <= -2 || balanceFactor >= 2) {
		rotate(pNode, balanceFactor);
	}
}

template<class T>
int Tree<T>::getLeftHeight(Node *&pNode, int height) {

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
int Tree<T>::getRightHeight(Node *&pNode, int height) {

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
int Tree<T>::getBalance(Node *&pNode, int height) {
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

template<class T>
void Tree<T>::rotate(Node *&pNode,int balanceFactor) {
	Node *parent;
	Node *child;
	Node *grandChild;
	
	if (balanceFactor < 0) {
		
		if (getBalance(pNode->right,0) > 0){//if balance factor of next node is positive than RL
			cout << "RL at " << pNode->data << endl;
			parent = pNode;
			child = pNode->right;
			grandChild = child->left;
			//if no children
			if (parent->left == nullptr) {
				temp = pNode->right->left;//grandchild
				temp->left = pNode;
				temp->right = pNode->right;
				grandChild->left->left = nullptr;
				grandChild->left->right = nullptr;
				grandChild->right->right = nullptr;
				grandChild->right->left = nullptr;
				pNode = temp;
			}
			//if children
			if (parent->left != nullptr && grandChild->left != nullptr) {
				Node *leftGGC = grandChild->left;
				Node *leftChild = parent->left;
				temp = grandChild;
				temp->right = child;
				temp->left = parent;
				leftChild->right = leftGGC;
				child->left = nullptr;
				pNode = temp;
			}
		}
		else {//RR
			cout << "RR at " << pNode->data << endl;
			parent = pNode;
			child = pNode->right;
			grandChild = pNode->right->right;
			temp = child;
			child->left = parent;
			parent->right = nullptr;
			parent->left = nullptr;
			pNode = temp;
		}
	}
	else {
		if (getBalance(pNode->left, 0) < 0) {//if balance factor of next node is negative than LR
			cout << "LR at " << pNode->data << endl;
			parent = pNode;
			child = pNode->left;
			grandChild = child->right;
			temp = grandChild;
			temp->left = child;
			temp->right = parent;
			child->right = nullptr;
			child->left = nullptr;
			parent->right = nullptr;
			parent->left = nullptr;
			pNode = temp;
		}
		else {
			cout << "LL at " << pNode->data << endl;
			parent = pNode;
			child = pNode->left;
			grandChild = child->left;
			temp = child;
			temp->right = parent;
			parent->right = nullptr;
			parent->left = nullptr;
			pNode = temp;
		}
	}
}
#endif
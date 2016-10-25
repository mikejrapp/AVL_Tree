#pragma once
#ifndef H_NODE
#define H_NODE
#include<iostream>
#include<string>

using namespace std;

template<class T>
class Node {
private:
	T data;
	Node* right;
	Node* left;

public:
	Node();
};

template<class T>
Node<T>::Node() {
	
}

#endif
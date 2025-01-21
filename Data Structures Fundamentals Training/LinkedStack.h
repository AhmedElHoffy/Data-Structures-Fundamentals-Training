#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>
using namespace std;


class LinkedStack {
	struct Node {
		int val;
		Node* next;
	};
	Node* StackTop_ptr, * curr;

public:
	// Initial value for the Top by using default constructor
	LinkedStack();

	void push(int newval);

	bool is_Empty();

	void pop();

	// function pop overloading
	void pop(int& Delval);

	void GetTop();

	// function GetTop overloading
	void GetTop(int& val);

	void PrintStack();

};

#endif // LINKEDSTACK_H
#ifndef STACKARRAYTEMPLATE_H
#define STACKARRAYTEMPLATE_H

#include <iostream>
using namespace std;

const int MAX_SIZE2 = 100;

template<class T>

class StackArrayT {

	int top;
	T item[MAX_SIZE2];  // ADT array

public:

	StackArrayT() {
		top = -1;
	}

	bool is_full() {
		if (top >= MAX_SIZE2 - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool is_empty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(T Addval) {

		if (is_full()) {
			cout << "Stack Array is full!" << endl;
		}
		else {
			top++;
			item[top] = Addval;
		}

	}

	void pop() {
		if (is_empty()) {
			cout << "Stack Array is Empty!" << endl;
		}
		else {
			top--;
		}

	}

	// function pop overloading to save the delerted val before deleting it.
	void pop(int& DelVal) { // call by reference
		if (is_empty()) {
			cout << "Stack Array is Empty!" << endl;
		}
		else {
			DelVal = item[top]; // saving the delted item in case we need it elsewhere
			top--;
		}

	}


	void GetTop() {
		if (is_empty()) {
			cout << "Stack Array is Empty!" << endl;
		}
		else {
			cout << "Top Item in the Stack Now is = " << item[top] << endl;
		}
	}

	// we used call by reference
	int GetTop(int& StackTop) {
		if (is_empty()) {
			cout << "Stack Array is Empty!" << endl;
		}
		else {
			StackTop = item[top];
		}
		return StackTop;
	}

	void printStack() {

		cout << "[ ";
		for (int i = top; i >= 0; i--) {
			cout << item[i] << " ";
		}
		cout << "]" << endl;
	}
};

#endif // STACKARRAYTEMPLATE_H

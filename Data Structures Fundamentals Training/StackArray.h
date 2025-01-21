#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
class StackArray{

	int top;
	int item[MAX_SIZE];  // ADT array

public:
	
	StackArray();

	bool is_full();
	bool is_empty();
	void push(int Addval);

	void pop();

	// function pop overloading to save the delerted val before deleting it.
	void pop(int& DelVal);

	void GetTop();
	// we used call by reference
	int GetTop(int& StackTop);

	void printStack();
	
};

#endif // STACKARRAY_H


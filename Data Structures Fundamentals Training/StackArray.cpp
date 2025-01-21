#include "StackArray.h"

StackArray::StackArray() {
	top = -1;
}

bool StackArray::is_full() {
	if (top >= MAX_SIZE - 1) {
		return true;
	}
	else {
		return false;
	}
}
bool StackArray::is_empty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

void StackArray::push(int Addval) {

	if (is_full()) {
		cout << "Stack Array is full!" << endl;
	}
	else {
		top++;
		item[top] = Addval;
	}

}

void StackArray::pop() {
	if (is_empty()) {
		cout << "Stack Array is Empty!" << endl;
	}
	else {
		top--;
	}

}

// function pop overloading to save the delerted val before deleting it.
void StackArray::pop(int& DelVal) { // call by reference
	if (is_empty()) {
		cout << "Stack Array is Empty!" << endl;
	}
	else {
		DelVal = item[top]; // saving the delted item in case we need it elsewhere
		top--;
	}

}


void StackArray::GetTop() {
	if (is_empty()) {
		cout << "Stack Array is Empty!" << endl;
	}
	else {
		cout << "Top Item in the Stack Now is = "<<item[top] << endl;
	}
}

// we used call by reference
int StackArray::GetTop(int& StackTop) {
	if (is_empty()) {
		cout << "Stack Array is Empty!" << endl;
	}
	else {
		StackTop = item[top];
	}
	return StackTop;
}

void StackArray::printStack() {

	cout << "[ ";
	for (int i = top; i>=0; i--) {
		cout << item[i] << " ";
	}
	cout << "]" << endl;
}



#include "LinkedStack.h"

	// Initial value for the Top by using default constructor
	LinkedStack::LinkedStack() {
		StackTop_ptr = NULL;
	}

	void LinkedStack::push(int newval) {
		// new node is created by using pointer implementation to save the new value and the sequential of the stack continuity
		Node* newitemptr = new Node;

		// New created pointer can't allocate memory correctly for the new node
		if (newitemptr == NULL) {
			cout << "LinkedStack push cannot allocate memory" << endl;
		}
		else {
			newitemptr->val = newval;
			newitemptr->next = StackTop_ptr;
			StackTop_ptr = newitemptr;
		}
	}

	bool LinkedStack::is_Empty() {
		return StackTop_ptr == NULL;
	}
	void LinkedStack::pop() {
		if (is_Empty()) {
			cout << "Linked St ack is Empty!" << endl;
		}
		else {
			Node* temp = new Node;

			temp = StackTop_ptr;
			StackTop_ptr = StackTop_ptr->next;
			temp->next = NULL;
			delete temp;
		}
	}

	// function pop overloading
	void LinkedStack::pop(int& Delval) {

		if (is_Empty()) {
			cout << "Linked St ack is Empty!" << endl;
		}
		else {
			Node* temp = new Node;
			Delval = StackTop_ptr->val;
			temp = StackTop_ptr;
			StackTop_ptr = StackTop_ptr->next;
			temp->next = NULL;
			delete temp;
		}
	}

	void LinkedStack::GetTop() {
		if (is_Empty()) {
			cout << "Linked St ack is Empty!" << endl;
		}
		else {
			cout << "The LinkedStack Top now is= " << StackTop_ptr->val << endl;
		}
	}

	void LinkedStack::GetTop(int& val) {
		if (is_Empty()) {
			cout << "Linked Stack is Empty!" << endl;
		}
		else {
			val = StackTop_ptr->val;
		}
	}

	void LinkedStack::PrintStack() {
		curr = StackTop_ptr;
		cout << "[ ";
		while (curr != NULL) {
			cout << curr->val << " ";
			curr = curr->next;
		}
		cout << "]" << endl;
	}


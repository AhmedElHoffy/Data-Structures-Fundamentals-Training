#ifndef LINKEDSTACKTEMPLATE_H
#define LINKEDSTACKTEMPLATE_H

template <class LT>

class LinkedStackT {
	struct Node {
		LT val;
		Node* next;
	};
	Node* StackTop_ptr, * curr;

public:
	// Initial value for the Top by using default constructor
	LinkedStackT() {
		StackTop_ptr = NULL;
	}

	void push(LT newval) {
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

	bool is_Empty() {
		return StackTop_ptr == NULL;
	}
	void pop() {
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
	void pop(LT& Delval) {

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

	void GetTop() {
		if (is_Empty()) {
			cout << "Linked St ack is Empty!" << endl;
		}
		else {
			cout << "The LinkedStack Top now is= " << StackTop_ptr->val << endl;
		}
	}

	void GetTop(LT& val) {
		if (is_Empty()) {
			cout << "Linked Stack is Empty!" << endl;
		}
		else {
			val = StackTop_ptr->val;
		}
	}

	void PrintStack() {
		curr = StackTop_ptr;
		cout << "[ ";
		while (curr != NULL) {
			cout << curr->val << " ";
			curr = curr->next;
		}
		cout << "]" << endl;
	}

};
#endif // LINKEDSTACKTEMPLATE_H

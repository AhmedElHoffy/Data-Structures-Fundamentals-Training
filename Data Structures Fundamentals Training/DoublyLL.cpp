#include "DoublyLL.h"

#include<iostream>
using namespace std;

DoublyLL::DoublyLL() {
	count = 0;
	Head = Tail = NULL;
}

bool DoublyLL::isEmpty() {
	return count == 0;
}

int DoublyLL::GetHead() {
	return Head->item;
}

int DoublyLL::GetTail() {
	return Tail->item;
}

int DoublyLL::GetSize() {
	return count;
}


void DoublyLL::PrintHeadTraverse() {
	cout << "[ ";
	NodeDLL* curr = Head;
	while (curr != NULL) {
		cout << curr->item << " ";
		curr = curr->next;
	}
	cout << "]" << endl;
}

void DoublyLL::PrintTailTraverse() {
	cout << "[ ";
	NodeDLL* curr = Tail;
	while (curr != NULL) {
		cout << curr->item << " ";
		curr = curr->Prev;
	}
	cout << "]" << endl;
}

void DoublyLL::InsertAtHead(int val) {
	NodeDLL* newNodeDLL = new NodeDLL;
	newNodeDLL->item = val;
	if (isEmpty()) {
		Head = Tail = newNodeDLL;
		newNodeDLL->next = newNodeDLL->Prev = NULL;
	}else{
		newNodeDLL->next = Head;
		Head->Prev = newNodeDLL;
		newNodeDLL->Prev = NULL;
		Head = newNodeDLL;
	}
	count++;
}

void DoublyLL::InsertAtTail(int val) {
	NodeDLL* newNodeDLL = new NodeDLL;
	newNodeDLL->item = val;
	if (isEmpty()) {
		Head = Tail = newNodeDLL;
		newNodeDLL->next = newNodeDLL->Prev = NULL;
	}
	else {
		newNodeDLL->Prev = Tail;
		Tail->next = newNodeDLL;
		newNodeDLL->next = NULL;
		Tail = newNodeDLL;
	}
	count++;
}

void DoublyLL::InsertAtPos(int val, int pos) {
	if (pos < 0) {
		cout << "-ve pos is not accepted. Please re-enter " << endl;
	}
	else if (pos > count - 1) {
		cout << "out of range! can't be inserted" << endl;
	}
	else if (pos == 0) {
		InsertAtHead(val);
	}else if(pos==count-1){
		InsertAtTail(val);
	}
	else {
		NodeDLL* newNodeDLL = new NodeDLL;
		newNodeDLL->item = val;
		NodeDLL* curr = Head->next;
		NodeDLL* prev;
		for (int i = 1; i < count - 1; i++) {
			if (pos == i) {
				prev = curr->Prev; // make the prev pointer points at the address of the node before the one we want to insert the new node instead
				newNodeDLL->Prev = prev;
				newNodeDLL->next = curr;
				curr->Prev = newNodeDLL;
				prev->next = newNodeDLL;
				break;
			}
			curr = curr->next;
		}
		count++;
	}
}

void DoublyLL::RemoveAtHead() {
	if (isEmpty()) {
		cout << "Doubly Linkd List is Empty!" << endl;
	}else if(count==1){
		NodeDLL* temp = Head;
		Head = Tail = NULL;
		delete temp;
		count--;
	}
	else {
		NodeDLL* temp = Head;
		Head = Head->next;
		Head->Prev = NULL;
		delete temp;
		count--;
	}
}

int DoublyLL::RemoveAtHead(int &delval) {
	if (isEmpty()) {
		cout << "Doubly Linkd List is Empty!" << endl;
		return -1;
	}
	else if (count == 1) {
		delval = Head->item;
		NodeDLL* temp = Head;
		Head = Tail = NULL;
		delete temp;
		count--;
	}
	else {
		delval = Head->item;
		NodeDLL* temp = Head;
		Head = Head->next;
		Head->Prev = NULL;
		delete temp;
		count--;
	}
	return delval;
}

void DoublyLL::RemoveAtTail() {
	if (isEmpty()) {
		cout << "Doubly Linkd List is Empty!" << endl;
	}
	else if (count == 1) {
		NodeDLL* temp = Tail;
		Head = Tail = NULL;
		delete temp;
		count--;
	}
	else {
		NodeDLL* temp = Tail;
		Tail = Tail->Prev;
		Tail->next = NULL;
		delete temp;
		count--;
	}
}

int DoublyLL::RemoveAtTail(int& delval) {
	if (isEmpty()) {
		cout << "Doubly Linkd List is Empty!" << endl;
		return -1;
	}
	else if (count == 1) {
		delval = Head->item;
		NodeDLL* temp = Tail;
		Head = Tail = NULL;
		delete temp;
		count--;
	}
	else {
		delval = Head->item;
		NodeDLL* temp = Tail;
		Tail = Tail->Prev;
		Tail->next = NULL;
		delete temp;
		count--;
	}
	return delval;
}


void DoublyLL::RemoveAtPos(int pos) {
	if (pos < 0) {
		cout << "-ve pos is not accepted. Please re-enter " << endl;
	}
	else if (pos > count - 1) {
		cout << "out of range! can't be Deleted" << endl;
	}
	else if (pos == 0) {
		RemoveAtHead();
	}
	else if (pos == count - 1) {
		RemoveAtTail();
	}
	else {
		NodeDLL* curr = Head->next;
		for (int i = 1; i < count - 1; i++) {
			if (pos == i) {
				curr->Prev->next = curr->next;
				curr->next->Prev = curr->Prev;
				curr->next = curr->Prev = NULL;
				delete curr;
				
				break;
			}
			curr = curr->next;
		}
		count--;
	}
}

void DoublyLL::RemoveVal(int val) {
	bool found = false;
	if (isEmpty()) {
		cout << "Doubly Linkd List is Empty!" << endl;
	}else if (Head->item == val) {
		RemoveAtHead();
		cout << val << " was found at Head " << " and deleted successfully" << endl;
	}
	else if (Tail->item == val) {
		RemoveAtTail();
		cout << val << " was found at Tail " << " and deleted successfully" << endl;
	}else{
		NodeDLL* curr = Head;
		int index = 0;
		while (curr != NULL) {
			if (curr->item == val) {
				found = true;
				curr->Prev->next = curr->next;
				curr->next->Prev = curr->Prev;
				curr->next = curr->Prev = NULL;
				delete curr;
				count--;
				break;
			}
			curr = curr->next;
			index++;
		}
		if (found) {
			cout << val << " was found at index " << index << " and deleted successfully" << endl;

		}
		else {
			cout << val << " was not found int the Doubly LinekdList "<< endl;
		}
	}

}

// Destructor to free up the memoy

 DoublyLL::~DoublyLL() {
	NodeDLL* temp;
	while (Head != NULL) {
		temp = Head;
		Head = Head->next;
		delete temp;
	}
	Tail = NULL;
	count = 0;

}





#include "LinkedList.h"

#include<iostream>
using namespace std;


LinkedList::LinkedList() {
	head = tail = NULL;
	count = 0;
}

bool LinkedList::isEmpty() {
	return count == 0;
	// return head==NULL;
}

void LinkedList::InsertAtStart(int val) {
	NodeLL* newNode;
	newNode = new NodeLL;
	newNode->item = val;

	if (count == 0) { //if the LinkedList is empty
		head =tail= newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	count++;
}


//without Tail pointer, using curr ptr and while loop
void LinkedList::InsertAtEndWithCurr(int val) {
	NodeLL* newNode;
	newNode = new NodeLL;
	newNode->item = val;

	if (count == 0) { //If the LinekdList was Empty
		head = tail= newNode;
		newNode->next = NULL;
	}
	else {
		NodeLL* curr = head;
		while (curr->next!=NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
		newNode->next = NULL;
		tail = newNode;
	}
	count++;
}


// with Tail ptr 
void LinkedList::InsertAtEndTailPtr(int val) {
	NodeLL* newNode;
	newNode = new NodeLL;
	newNode->item = val;
	if (count == 0) {
		head = tail = newNode;
		newNode->next;
	}
	else {
		tail->next = newNode;
		newNode->next = NULL;
		tail = newNode;
	}
	count++;
}

void LinkedList::InsertAtPos(int val,int pos) {
	NodeLL* newNode = new NodeLL;
	newNode->item = val;
	if (pos >= count - 1) {
		cout << "last position in the LinkedList for insertion is ";
		cout << count - 1 << " new Value is added at the end of the LinkedList" << endl;
		InsertAtEndTailPtr(val);
	}else if (pos<0){
		cout << "Can't insert at -ve pos, please re-enter the position selected" << endl;

	}else if (pos==0){
		InsertAtStart(val);
		count++;
	}
	else {
		NodeLL* curr = head;
		for (int i = 0; i < pos-1; i++) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
		count++;
	}
	
}

void LinkedList::PrintList() {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
	}
	else {
		cout << "[ ";
		NodeLL* temp = head;
		while (temp != NULL) {
			cout << temp->item << " ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}
}

int LinkedList::GetHead() {
	return head->item;
}

int LinkedList::GetTail() {
	return tail->item;
}

int LinkedList::GetSize() {
	return count;
}

void LinkedList::RemoveHead() {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
	}
	else if (count == 1) {
		NodeLL* curr = head;
		head = tail = NULL;
		curr->next = NULL;
		delete curr;
		count--;
	}
	else {
		NodeLL* curr = head;
		head = head->next;
		curr->next = NULL;
		delete curr;
		count--;
	}
}


// Overriding the RemoveEHad function to get the value of the node removed as a return
int LinkedList::RemoveHead(int delval) {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
		return -1;
	}
	else if (count == 1) {
		NodeLL* curr = head;
		delval = head->item;
		head = tail = NULL;
		curr->next = NULL;
		delete curr;
		count--;
	}
	else {
		NodeLL* curr = head;
		delval = head->item;
		head = head->next;
		curr->next = NULL;
		delete curr;
		count--;
	}

	return delval;
}

void LinkedList::RemoveTail() {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
	}
	else if (count == 1) {
		NodeLL* curr = head;
		head = tail = NULL;
		curr->next = NULL;
		delete curr;
		count--;
	}
	else {
		NodeLL* curr = head->next;
		NodeLL* prev = head;
		while (curr != tail) {
			//curr = curr->next;
			//prev = prev->next;
			//or
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		tail = prev;
		delete curr;
		count--;

	}
}

int LinkedList::RemoveTail(int delval) {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
		return -1;
	}
	else if (count == 1) {
		NodeLL* curr = head;
		delval = head->item;
		head = tail = NULL;
		curr->next = NULL;
		delete curr;
		count--;
	}
	else {
		NodeLL* curr = head->next;
		NodeLL* prev = head;
		while (curr != tail) {
			curr = curr->next;
			prev = prev->next;
		}
		delval = curr->item;
		prev->next = NULL;
		tail = prev;
		delete curr;
		count--;

	}
	return delval;
}

void LinkedList::RemoveSpecificVal(int val) {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
	}
	else if (count == 1) {
		if (head->item == val) {
			cout << val << " was found at pos " << count - 1 << " and deleted successfully" << endl;
			NodeLL* curr = head;
			head = tail = NULL;
			delete curr;
		}
		else {
			cout << val << " was not found in the LinkedList, try a different value " << endl;
		}
	}
	else if (count > 1) {
		if (head->item == val) {
			RemoveHead();
			cout << val << " was found at pos " << 0 << " and deleted successfully" << endl;
		}
		else if (tail->item == val) {
			cout << val << " was found at pos " << count - 1 << " and deleted successfully" << endl;
			RemoveTail();
		}
		else {
			bool found = false;
			NodeLL* curr = head->next;
			NodeLL* prev = head;
			int index = 1;
			while (curr != tail ) {
				if (curr->item == val) {
					found = true;
					break;
				}
				prev = curr;
				curr = curr->next;
				index++;
			}
			if (found) {
				cout << val << " was found at pos " << index << " and deleted successfully" << endl;
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				count--;
			}
			else {
				cout << val << " was not found in the LinkedList, try a different value " << endl;
			}
		}
	}
}

void LinkedList::RemoveAtPos(int pos) {

	if (pos < 0) { // -ve value
		cout << "Can't Delete at -ve pos, please re-enter a suitable index" << endl;
	}
	else if (pos > count - 1) { //out of range
		cout << "Last position to delete at the LinkedList is: " << count - 1 << " .   Please re-enter a suitable index"<< endl;
	}
	else {
		if (pos == 0) {
			RemoveHead();
			cout << "value at pos  " << pos << " is deleted successfully" << endl;
		}
		else if (pos == count - 1) {
			RemoveTail();
			cout << "value at pos  " << pos << " is deleted successfully" << endl;
		}
		else {
			NodeLL* curr = head->next;
			NodeLL* prev = head;
			int index = 1;
			while (curr != tail) {
				if (index == pos) {
					break;
				}
				prev = curr;
				curr = curr->next;
				index++;
			}
				cout << "value at pos  " << pos << " is deleted successfully" << endl;
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				count--;
		}
	}

}

void LinkedList::ReverselinkedList() {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
	}
	else if (count == 1) {
		cout << "LinkedList is of size 1. it is mirrored " << endl;
	}
	else if (count == 2) {
		NodeLL* curr = tail;
		NodeLL* prev = head;
		prev->next = NULL;
		curr->next = prev;
		head = curr;
		tail = prev;
	}
	else {
		NodeLL* curr, *prev, *future;
		prev = NULL;
		curr = head;
		tail = head;
		future = curr->next;
		while (future != NULL) {
			future = curr->next;
			curr->next = prev;
			prev = curr;
			curr = future;			
		}
		head = prev;

	}
}

void LinkedList::SearchVal(int val) {
	if (isEmpty()) {
		cout << "LinkedList is Empty! " << endl;
	}
	else if (count == 1) {
		if (head->item == val) {
			cout << val << " was found at pos " << count - 1 <<  endl;
		}
		else {
			cout << val << " was not found in the LinkedList, try a different value " << endl;
		}
	}
	else if (count > 1) {
		if (head->item == val) {
			cout << val << " was found at pos " << 0 <<  endl;
		}
		else if (tail->item == val) {
			cout << val << " was found at pos " << count - 1 <<  endl;
		}
		else {
			bool found = false;
			NodeLL* curr = head->next;
			int index = 1;
			while (curr != tail) {
				if (curr->item == val) {
					found = true;
					break;
				}
				curr = curr->next;
				index++;
			}
			if (found) {
				cout << val << " was found at pos " << index << endl;
			}
			else {
				cout << val << " was not found in the LinkedList, try a different value " << endl;
			}
		}
	}

}
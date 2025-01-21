#include "LinkedQueue.h"

#include<iostream>
using namespace std;


LinkedQueue::LinkedQueue() {
	front = rear = NULL;
	count = 0;
}

bool LinkedQueue::isEmpty() {
	return count == 0;
	// return front==NULL;
	// return rear==NULL
}

void LinkedQueue::Enqueue(int val) {
	NodeQ *newitemptr = new NodeQ;
	newitemptr->item = val;
	newitemptr->next = NULL;
	if (!isEmpty()) {
		rear->next = newitemptr;
		rear = newitemptr;
	}
	else { //if the Queue is empty
		front = rear = newitemptr;
	}
	count++;
}

void LinkedQueue::Dequeue() {
	if (!isEmpty()) {
		NodeQ* temp = front;
		if (front ==rear) { // only 1 element in the Queue
			front = rear = NULL;
		}
		else { // more than 1 element in the queue
			front = front->next;
			temp->next = NULL;
			delete temp;
		}
		count--;
	}
	else {
		cout << "Queue is Already Empty!" << endl;
	}
}

//Dequeue Function override
void LinkedQueue::Dequeue(int& delval) {

	if (!isEmpty()) {
		NodeQ* temp = front;
		if (front == rear) { // only 1 element in the Queue
			front = rear = NULL;
		}
		else { // more than 1 element in the queue
			front = front->next;
			delval = temp->item;
			temp->next = NULL;
			delete temp;
		}
		count--;
	}
	else {
		cout << "Queue is Already Empty!" << endl;
	}
}

int LinkedQueue::GetFront() {
	if (!isEmpty()) {
		return front->item;
	}
	else {
		cout << "Queue is  Empty!" << endl;
	}
	
}

int LinkedQueue::GetRear() {
	if (!isEmpty()) {
		return rear->item;
	}
	else {
		cout << "Queue is  Empty!" << endl;
	}
}

int LinkedQueue::Getsize() {
	return count;
}

void LinkedQueue::PrintQueue() {
	if (isEmpty()) {
		cout << "Queue is  Empty!" << endl;
	}
	else {
		NodeQ* curr = front;
		cout << "[ ";
		while (curr != NULL) {
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << "]" << endl;
	}
	
}

bool LinkedQueue::Search(int val) {
	if (!isEmpty()) {
		NodeQ* curr = front;
		while (curr != NULL) {
			if (curr->item == val) {
				return true;
			}
			curr = curr->next;
		}
		return false;
	}
	else {
		cout << "Queue is  Empty!" << endl;
		return false;
	}
}

void LinkedQueue::clearQueueList() {
	if (isEmpty()) {
		cout << "Queue is  Empty!" << endl;
	}
	else {
		NodeQ* curr;
		while (front != NULL) {
			curr = front;
			front = front->next;
			curr->next = NULL;
			delete curr;
			count--;
		}
		rear = NULL;

	}
}



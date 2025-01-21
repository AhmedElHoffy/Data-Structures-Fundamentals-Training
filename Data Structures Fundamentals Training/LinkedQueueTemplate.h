#ifndef LINKEDQUEUETEMPLATE_H
#define LINKEDQUEUETEMPLATE_H

#include<iostream>
using namespace std;

template<class QLLT>
class LinkedQueueT {

private:
	struct NodeQ {
		QLLT item;
		NodeQ* next;
	};
	NodeQ* front, * rear;
	int count;

public:

	LinkedQueueT() {
		front = rear = NULL;
		count = 0;
	}

	bool isEmpty() {
		return count == 0;
		// return front==NULL;
		// return rear==NULL
	}

	void Enqueue(QLLT val) {
		NodeQ* newitemptr = new NodeQ;
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

	void Dequeue() {
		if (!isEmpty()) {
			NodeQ* temp = front;
			if (front == rear) { // only 1 element in the Queue
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
	void Dequeue(QLLT& delval) {

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

	QLLT GetFront() {
		if (!isEmpty()) {
			return front->item;
		}
		else {
			cout << "Queue is  Empty!" << endl;
		}

	}

	QLLT GetRear() {
		if (!isEmpty()) {
			return rear->item;
		}
		else {
			cout << "Queue is  Empty!" << endl;
		}
	}

	int Getsize() {
		return count;
	}

	void PrintQueue() {
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

	bool Search(QLLT val) {
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

	void clearQueueList() {
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




};


#endif //LINKEDQUEUETEMPLATE_H
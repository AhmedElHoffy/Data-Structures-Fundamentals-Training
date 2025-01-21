#ifndef QUEUEDYNAMICARRAYTEMPLATE_H
#define QUEUEDYNAMICARRAYTEMPLATE_H

#include <iostream>
using namespace std;

template<class QT>
class QueueDynamicArrayT {

	int front, rear, count, MaxSizeDynamic;
	QT* arrQ;

public:
	//implement the constructor to iniialize the front, rear and count
	QueueDynamicArrayT(int size)
	{
		front = 0;
		rear = size - 1;
		count = 0;
		if (size <= 0) {
			cout << "entered size is not accepted!, Default size of 100 is built" << endl;
			arrQ = new QT[100];
			MaxSizeDynamic = 100;
		}
		else {
			MaxSizeDynamic = size;
			arrQ = new QT[MaxSizeDynamic];

		}

	}

	bool isEmpty() {
		return count == 0;
	}
	bool isFull() {
		return count == MaxSizeDynamic;
	}


	void Enqueue(QT val) {
		if (isFull()) {
			cout << "Queue Array is full!" << endl;
		}
		else {
			rear = (rear + 1) % MaxSizeDynamic; //remainder theory is used for best practise of circular array implementation
			arrQ[rear] = val;
			count++;
		}
	}

	void Dequeue() {
		if (isEmpty()) {
			cout << "Queue Array is Empty!" << endl;
		}
		else {
			front = (front + 1) % MaxSizeDynamic; //remainder theory is used for best practise of circular array implementation
			count--;
		}
	}

	// Function Dequeue override to use the deleted value afterwards
	void Dequeue(QT& DelVal) {
		if (isEmpty()) {
			cout << "Queue Array is Empty!" << endl;

		}
		else {
			DelVal = arrQ[front];
			front = (front + 1) % MaxSizeDynamic; //remainder theory is used for best practise of circular array implementation
			count--;
		}
	}

	QT GetFrontQ() {
		if (isEmpty()) {
			cout << "Queue Array is Empty!" << endl;
			return -1;
		}
		else {
			return arrQ[front];
		}

	}
	QT GetRearQ() {
		if (isEmpty()) {
			cout << "Queue Array is Empty!" << endl;
			return -1;
		}
		else {
			return arrQ[rear];
		}
	}

	int GetSize() {
		return count;
	}
	void PrintQueue() {
		cout << "[ ";
		for (int i = 0; i < count; i++) {  // i != rear + 1   (+1) is used to be able to print the rear element as well, if we don't use it we will need to print
			//  the arrQ[rear] after the for loop
			cout << arrQ[(front + i) % MaxSizeDynamic] << " ";
		}
		cout << " ]" << endl;
	}
	void clearQArray() {
		if (!isEmpty()) {
			for (int i = 0; i < count; i++) {  // i != rear + 1   (+1) is used to be able to print the rear element as well, if we don't use it we will need to print
				//  the arrQ[rear] after the for loop
				arrQ[(front + i) % MaxSizeDynamic] = -1; // -1 to indicate that the element location is deleted
			}
			count = 0;
		}
		else {
			cout << "Queue Array is Empty!" << endl;
		}

	}

	void search(QT val) {
		int pos = -1;
		if (!isEmpty()) {
			for (int i = 0; i < count; i++) {
				if (arrQ[(front + i) % MaxSizeDynamic] == val) {
					pos = i;
					cout << val << " is found at position " << pos << endl;
					return; // Exit after finding the first match
				}
			}
			if (pos == -1) {
				cout << val << " is not found in the Queue Dynamic Array" << endl;
			}
		}
		else {
			cout << "Queue is Empty" << endl;
		}

	}



};

#endif QUEUEDYNAMICARRAYTEMPLATE_H

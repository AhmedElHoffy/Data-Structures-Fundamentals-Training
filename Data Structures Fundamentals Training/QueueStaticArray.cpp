#include "QueueStaticArray.h"

#include <iostream>
using namespace std;

//implement the constructor to iniialize the front, rear and count
QueueStaticArray::QueueStaticArray() {
	front = 0;
	rear = Max_SizeQueueArray - 1;
	count = 0;

}

bool QueueStaticArray::isEmpty() {
	return count == 0;
}
bool QueueStaticArray::isFull() {
	return count == Max_SizeQueueArray;
}


void QueueStaticArray::Enqueue(int val) {
	if (isFull()) {
		cout << "Queue Array is full!" << endl;
	}
	else {
		rear = (rear + 1) % Max_SizeQueueArray; //remainder theory is used for best practise of circular array implementation
		arrQ[rear] = val;
		count++;
	}
}

void QueueStaticArray::Dequeue() {
	if (isEmpty()) {
		cout << "Queue Array is Empty!" << endl;
	}
	else {
		front = (front + 1) % Max_SizeQueueArray; //remainder theory is used for best practise of circular array implementation
		count--;
	}
}

// Function Dequeue override to use the deleted value afterwards
void QueueStaticArray::Dequeue(int& DelVal) {
	if (isEmpty()) {
		cout << "Queue Array is Empty!" << endl;
	}
	else {
		DelVal = arrQ[front];
		front = (front + 1) % Max_SizeQueueArray; //remainder theory is used for best practise of circular array implementation
		count--;
	}
}

int QueueStaticArray::GetFrontQ() {
	if (isEmpty()) {
		cout << "Queue Array is Empty!" << endl;
		return -1;
	}
	else {
		return arrQ[front];
	}

}
int QueueStaticArray::GetRearQ() {
	if (isEmpty()) {
		cout << "Queue Array is Empty!" << endl;
		return -1;
	}
	else {
		return arrQ[rear];
	}
}

int QueueStaticArray::GetSize() {
	return count;
}
void QueueStaticArray::PrintQueue() {
	cout << "[ ";
	for (int i = front; i != rear + 1; i = (i + 1) % Max_SizeQueueArray) {  // i != rear + 1   (+1) is used to be able to print the rear element as well, if we don't use it we will need to print
		//  the arrQ[rear] after the for loop
		cout << arrQ[i] << " ";
	}
	cout << " ]" << endl;
}
void QueueStaticArray::clearQArray() {
	if (!isEmpty()) {
		for (int i = front; i != rear + 1; i = (i + 1) % Max_SizeQueueArray) {  // i != rear + 1   (+1) is used to be able to print the rear element as well, if we don't use it we will need to print
			//  the arrQ[rear] after the for loop
			arrQ[i] = -1; // -1 to indicate that the element location is deleted
		}
		count = 0;
	}
	else {
		cout << "Queue Array is Empty!" << endl;
	}

}

void QueueStaticArray::search(int val) {
	int pos = -1;
	if (!isEmpty()) {
		for (int i = 0; i < count; i++) {
			if (arrQ[(front + i) % Max_SizeQueueArray] == val) {
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
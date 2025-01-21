#ifndef QUEUEDYNAMICARRAY_H
#define QUEUEDYNAMICARRAY_H
#include <iostream>
using namespace std;
class QueueDynamicArray{

	int front, rear, count, MaxSizeDynamic;
    int* arrQ;

public:
	QueueDynamicArray(int size);

	//implement the constructor to iniialize the front, rear and count

	bool isEmpty();
	bool isFull();

	void Enqueue(int val);

	void Dequeue();

	// Function Dequeue override to use the deleted value afterwards
	void Dequeue(int& DelVal);

	int GetFrontQ();
	int GetRearQ();

	int GetSize();
	void PrintQueue();
	void clearQArray();
	void search(int val);

	

};

#endif QUEUEDYNAMICARRAY_H
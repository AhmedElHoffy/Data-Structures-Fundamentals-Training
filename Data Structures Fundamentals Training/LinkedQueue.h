#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include<iostream>
using namespace std;

class LinkedQueue{

private: 
	struct NodeQ {
		int item;
		NodeQ* next;
	};
	NodeQ* front, * rear;
	int count;

public:

	LinkedQueue();

	bool isEmpty();
	void Enqueue(int val);

	void Dequeue();
	void Dequeue(int& Delval);

	int GetFront();
	int GetRear();

	void PrintQueue();
	int Getsize();
	bool Search(int val);
	void clearQueueList();

};


#endif //LINKEDQUEUE_H


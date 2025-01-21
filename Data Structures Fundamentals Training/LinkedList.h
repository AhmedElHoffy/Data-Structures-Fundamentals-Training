#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
using namespace std;

class LinkedList
{
	struct NodeLL {

		int item;
		NodeLL* next;
	};
	NodeLL* head, * tail;
	int count;

public:
	//constructor for initialzation
	LinkedList();
	bool isEmpty();
	void InsertAtStart(int val);
	void InsertAtEndWithCurr(int val);
	void InsertAtEndTailPtr(int val);
	void InsertAtPos(int val,int pos);
	void PrintList();
	int GetHead();
	int GetTail();
	int GetSize();

	void RemoveHead();
	int RemoveHead(int delval);

	void RemoveTail();
	int  RemoveTail(int delval);

	void RemoveSpecificVal(int delval);
	void RemoveAtPos(int index);

	void ReverselinkedList();

	void SearchVal(int val);

};


#endif //LINKEDLIST_H


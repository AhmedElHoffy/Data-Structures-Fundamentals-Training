#ifndef DOUBLYLL_H
#define DOUBLYLL_H
class DoublyLL
{
	struct NodeDLL {
	int item;
	NodeDLL *next, *Prev;
};

	NodeDLL* Head, * Tail;
	int count;
public:
	DoublyLL();
	~DoublyLL();
	bool isEmpty();

	int GetHead();
	int GetTail();
	int GetSize();

	void PrintHeadTraverse();
	void PrintTailTraverse();

	void InsertAtHead(int val);
	void InsertAtTail(int val);

	void InsertAtPos(int val, int pos);

	void RemoveAtHead();
	// Function overload of remove head of the Doubly LinkedList
	int RemoveAtHead(int& delval);

	void RemoveAtTail();
	// Function overload of remove Tail of the Doubly LinkedList
	int RemoveAtTail(int& delval);

	void RemoveAtPos(int pos);

	void RemoveVal(int val);

	void DeleteDoublyLL();
	 
};

#endif //DOUBLYLL_H


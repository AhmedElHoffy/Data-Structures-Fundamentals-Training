#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include<iostream>
using namespace std;


class ArrayList{

	int* arrList;  //pointer for dynamic array
	int Max_size; //max size entered by user
	int count;  //counter of elements entered in the array by the user
public:
	ArrayList(int size);

	bool isEmpty();
	bool isFull();
	int GetSize();
	void printArrayList();
	void insert(int val, int loc);
	void remove( int loc);
	int search(int val);
	void insertNoDuplicate(int val,int loc);
	void UpdateAt(int val, int loc);
	void PrintValAt(int loc);
	int GetElementAt(int loc);
	~ArrayList();
};





#endif //ARRAYLIST_H

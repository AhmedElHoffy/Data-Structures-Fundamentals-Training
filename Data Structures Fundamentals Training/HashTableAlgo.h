#ifndef HASHTABLEALGO_H
#define HASHTABLEALGO_H

#include<iostream>
#include<list>    //Because we will be using linekdlist in the chaining Algorithm
#include<cstring> // For using the key value pair in the linkedlist. the key will be integer type and the value will be a sting type
using namespace std;


// We will use a hashtable to implement a phonebook  Key,value pair example --> 950 , Ahmed 
// Chaining Method
class HashTable {
	
	static const int HashGroups = 10;  //we need to specify how many lists we will be actually using 
	
	list<pair<int, string>> HashTable[HashGroups];  
	// List 1 is at index 0. So technically we created a hashtable of linkedlist type
	//with constant length of the table of 10 LinekdLists. 
	// each linked list is of type pair with integer as a key and string as a value 

public:
	bool isEmpty();
	int  HashFn(int key);
	void InsertVal(int key, string Val);
	void RemoveItem(int key); // we will be only removing 1 item when we call this function
	string SearchHAshTable(int key);
	void PrintTable();


};


#endif  //HASHTABLEALGO_H


#include "HashTableAlgo.h"

#include<iostream>
#include<list>    //Because we will be using linekdlist in the chaining Algorithm
#include<cstring> // For using the key value pair in the linkedlist. the key will be integer type and the value will be a sting type
using namespace std;

bool HashTable::isEmpty() {
	int Listsize = 0;
	for (int i = 0; i < HashGroups; i++) {
		Listsize += HashTable[i].size();
		if (Listsize != 0) {
			return false;
		}
	}
	return true;
}

int HashTable::HashFn(int key) {
	// Since we have 10 Lists, We want to return a value between 0 and 9 
	return key % HashGroups;
}

void  HashTable::InsertVal(int key, string Val){
	int HashValue = HashFn(key); // this will siginify which list the key,val pair will go into it.

	list<pair<int, string>>& Bucket = HashTable[HashValue]; // Access the bucket with the specific Hashfn output
	list<pair<int, string>>::iterator BucketIterator = Bucket.begin(); // defining a list iterator to iterate along the bucket

	// Now we need to know if there is a collision

	bool keyExists = false;
	for (; BucketIterator != Bucket.end(); BucketIterator++) {
		if (BucketIterator->first == key) {
			keyExists = true;
			BucketIterator->second = Val;
			cout << "[Warning] Key Exists. Value has been Replaced!" << endl;
			break; // Exit loop since the key is found
		}
	}
	if (!keyExists) {
		Bucket.push_back(std::make_pair(key, Val));
	}
	return;
}

void HashTable::RemoveItem(int key) {
	int HashValue = HashFn(key); // this will siginify which list the key,val pair will go into it.

	list<pair<int, string>>& Bucket = HashTable[HashValue]; // Access the bucket with the specific Hashfn output
	list<pair<int, string>>::iterator BucketIterator = Bucket.begin(); // defining a list iterator to iterate along the bucket

	// Now we need to know if there is a collision

	bool keyExists = false;
	for (; BucketIterator != Bucket.end(); BucketIterator++) {
		if (BucketIterator->first == key) {
			keyExists = true;
			BucketIterator = Bucket.erase(BucketIterator);
			cout << "[Info] Item Removed!" << endl;
			break; // Exit loop since the key is found
		}
	}
	if (!keyExists) {
		cout << "[Warning] (Key not found, Pair not removed). Item Not Found!" << endl;
	}
	return;
}

void HashTable::PrintTable() {
	for (int i = 0; i < HashGroups; i++) {
		if (HashTable[i].size() == 0) continue;
		list<pair<int, string>>::iterator BucketPrintIterator = HashTable[i].begin(); // defining a list iterator to iterate along the bucket
		for (; BucketPrintIterator != HashTable[i].end(); BucketPrintIterator++) {
			cout << "[INFO] Key: " << BucketPrintIterator->first << " , Val: " << BucketPrintIterator->second << endl;
		}
	}
	return;
}
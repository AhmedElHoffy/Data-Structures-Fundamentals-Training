#include "ArrayList.h"
#include<iostream>
using namespace std;

ArrayList::ArrayList(int size) {
	if (size <= 0) {
		Max_size = 10;
	}
	else {
		Max_size = size;
		arrList = new int[Max_size]; //reserving space in the memory for the dynamic array with the pointer created to save the array address and the size entered by the user
	}
	count = 0;
}

bool ArrayList::isEmpty() {
	return count == 0;
}

bool ArrayList::isFull() {
	return count == Max_size;
}

int ArrayList::GetSize() { // get the number of entered elemnets 
	return count;
}

void ArrayList::printArrayList() {
	cout << "[ ";
	for (int i = 0; i < count; i++) {
		cout << arrList[i] << " ";
	}
	cout << "]" << endl;
}

void ArrayList::insert(int val, int loc) {  // Shift Right  (SHR)
	if (isFull()) {
		cout << "ArrayList is full!, can't insert new elements" << endl;
	}
	else if ( loc <0 || loc>count){
		cout << "location is out of range!" << endl;
	} 
	else{
		for (int i = count; i > loc;i--) {
			arrList[i] = arrList[i-1];
		}
		arrList[loc] = val;
		count++;
	}
}

void ArrayList::remove(int loc) { // Shift Left (SHL)
	if (isEmpty()) {
		cout << "ArrayList is Empty!, can't delete " << endl;
	}
	else if (loc <0 || loc>count) {
		cout << "location is out of range!" << endl;
	}
	else {
		for (int i = loc; i < count; i++) {
			arrList[i] = arrList[i+1];
		}
		count--;
	}
}

int  ArrayList::search(int val) {
	for (int i = 0; i < count; i++) {
		if (arrList[i] == val) {
			return i;
			break;
		}
	}
	return -1;
}

void ArrayList::insertNoDuplicate(int val,int loc) {
	if (isFull()) {
		cout << "ArrayList is full!, can't insert new elements" << endl;
	}
	else if (loc <0 || loc>count) {
		cout << "location is out of range!" << endl;
	}
	else {
		int flag = search(val);
		if (flag == -1) {
			for (int i = loc; i < count; i++) {
				arrList[i + 1] = arrList[i];
			}
			arrList[loc] = val;
			count++;
		}
		else {
				cout << "There is a duplicate of this eleemnt in the arraylist at index: " << flag << endl;
		}

	}

}

void ArrayList::UpdateAt(int val, int loc) {
	if (isEmpty()) {
		cout << "ArrayList is Empty!, can't update loc " << endl;
	}
	else if (loc <0 || loc>count) {
		cout << "location is out of range!" << endl;
	}
	else {
		arrList[loc] = val;
	}
}

void ArrayList::PrintValAt(int loc) {
	if (isEmpty()) {
		cout << "ArrayList is Empty!, can't update loc " << endl;
	}
	else if (loc <0 || loc>count) {
		cout << "location is out of range!" << endl;
	}
	else {
		cout << "Eleement at location " << loc << " is : " << arrList[loc] << endl;
	}
}

int ArrayList::GetElementAt(int loc) {
	if (isEmpty()) {
		cout << "ArrayList is Empty!, can't update loc " << endl;
	}
	else if (loc <0 || loc>count) {
		cout << "location is out of range!" << endl;
	}
	else {
		return arrList[loc];
	}
}

//Destructor
ArrayList::~ArrayList() {
	delete[]arrList;
}

//
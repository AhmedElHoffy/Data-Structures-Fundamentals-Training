#include "LinearSearchAlgo.h"

#include<iostream>
using namespace std;

int LinearSearch(int Arr[], int size, int key) {

	for (int i = 0; i < size; i++) {
		if (Arr[i] == key) {
			return i;
		}
	}
	return -1;
}

void PrintArrayLinearSearch(int Arr[], int size) {
	cout << " The Array size now is: [ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << " ]" << endl;
}

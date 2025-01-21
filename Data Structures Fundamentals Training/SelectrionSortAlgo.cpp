#include "SelectrionSortAlgo.h"
#include<iostream>
using namespace std;

void swapVal(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void PrintArr(int Arr[], int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << "}" << endl;
}
void SelectionSort(int Arr[], int n) {

	int MinIndex; // Assume the first element is the minimum

	// Ascending Order
	for (int i = 0; i < n - 1; i++) {
		MinIndex = i;

		// Find the index of the smallest element in the unsorted part
		for (int j = i + 1; j < n; j++) {
			if (Arr[j] <  Arr[MinIndex]) {
				MinIndex = j;
			}
		}
		// Swap the found minimum element with the first element of the unsorted part
		swapVal(Arr[MinIndex], Arr[i]);
	}

}
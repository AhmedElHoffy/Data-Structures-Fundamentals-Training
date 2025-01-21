#include "InsertionSortAlgo.h"

#include<iostream>
using namespace std;

void ShiftRight(int Arr[], int currIdx, int prevIdx) {
	int temp = Arr[currIdx];
	for (int i = currIdx; i > prevIdx; i--) {
		Arr[i] = Arr[i - 1];
	}
	Arr[prevIdx] = temp;;
}

// Insertion Sort Algorithm with nested For Loops (it doesn't quite break if the array is sorted)
void InsertionSortForLOOP(int Arr[], int size) {
	bool Sorted = true;
	// By default we assume thatArr[0] is sorted; therefore we start our for loop from Arr[1]
	for (int currIdx = 1; currIdx < size; currIdx++) {
		for (int prevIdx = 0; prevIdx < currIdx; prevIdx++) {
			if (Arr[prevIdx] > Arr[currIdx]) {
				ShiftRight(Arr, currIdx, prevIdx);
				PrintArrayInsertion(Arr,size);
				Sorted = false;
			}
		}
		// If no swaps occurred in this pass, the array is sorted
		if (Sorted) {
			break;
		}
	}
}

// Insertion sort Algorithm with For, While loops (key Method)

void InsertionSortForWhileLOOP(int Arr[], int size) {
	// By default we assume thatArr[0] is sorted; therefore we start our for loop from Arr[1]
	int Key;
	int ComparePtr;
	for (int i = 1; i < size; i++) {
		// We need a key index to hold the value of the current index before we perform shifhting right 
		Key = Arr[i]; 
		ComparePtr = i - 1; // to be able to Perform SHR
		// Performing shifting right Algorithm
		while (ComparePtr >= 0 && Key < Arr[ComparePtr]) {
			Arr[ComparePtr + 1] = Arr[ComparePtr];
			ComparePtr = ComparePtr - 1;
		}
		Arr[ComparePtr + 1] = Key;
	}
}

void PrintArrayInsertion(int Arr[], int size) {
	\
		cout << " The Array size now is: [ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << " ]" << endl;
}
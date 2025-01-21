#include "MergeSortAlgo.h"

#include<iostream>
using namespace std;

void Merge(int Arr[], int leftIdx, int RightIdx, int MiddleIdx) { //MiddleIdx = LeftIdx +(Rightidx-LeftIdx)/2
	
	int i, j, k;

	int LeftsubArraySize = MiddleIdx - leftIdx + 1;
	int RightSubArraySize = RightIdx - MiddleIdx;

	//Dynamic Array; we can use static but the sizes needs to be passed as constants
	int* LeftNewArray = new int[LeftsubArraySize], * RightNewArray = new int[RightSubArraySize];

	for (i = 0; i < LeftsubArraySize; i++) {
		LeftNewArray[i] = Arr[leftIdx + i];
	}
	for (j = 0; j < RightSubArraySize; j++) {
		RightNewArray[j] = Arr[MiddleIdx + 1 + j];
	}

	i=j = 0;
	k = leftIdx; // we start from left index because it will be changed to right side in the recursion and doesn't start from zero

	// comparison section to merge divided arrays
	while (i < LeftsubArraySize && j < RightSubArraySize) {
		if (LeftNewArray[i] <= RightNewArray[j]) {
			Arr[k] = LeftNewArray[i];
			i++;
		}
		else {
			Arr[k] = RightNewArray[j];
			j++;
		}
		k++;
	}

	// adding rest elements if one array is completed
	while (i < LeftsubArraySize) {
		Arr[k] = LeftNewArray[i];
		i++;
		k++;
	}
	while (j < RightSubArraySize) {
		Arr[k] = RightNewArray[j];
		j++;
		k++;
	}
}

// Merge sort recursion Algorithm
void MergeSort(int Arr[], int LeftIdx, int RightIdx) {
	
	if (LeftIdx < RightIdx) {
		
		int MiddleIdx = LeftIdx + (RightIdx - LeftIdx) / 2;

		//Left SubArray Creation
		MergeSort(Arr, LeftIdx, MiddleIdx);
		//Right SubArray Creation
		MergeSort(Arr, MiddleIdx + 1, RightIdx);

		//Merging Left and Right Subarrays
		Merge(Arr, LeftIdx, RightIdx,MiddleIdx);
	}

}

void PrintArrayMerge(int Arr[], int size) {
	cout << " The Array size now is: [ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << " ]" << endl;
}




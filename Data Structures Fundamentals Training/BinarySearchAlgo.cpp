#include "BinarySearchAlgo.h"

#include<iostream>
using namespace std;


int BinarySearchIterative(int Arr[], int Left, int Right, int Key) {

	int Middle;
	while (Left <= Right) {
		Middle = (Left + Right) / 2;
		//or it could be -->  Middle = Left + (Right - Left)/2;
		if (Key == Arr[Middle]) {
			return Middle;
		}
		// Key is greter than middle --> Go to Right sub-Array of the key and Neglect the Left Sub-Array
		else if (Key > Arr[Middle]) {
			Left = Middle + 1;
		}
		else {
			Right = Middle - 1;
		}
	}
	return-1;
}

int BinarySearchRecursive(int Arr[], int Left, int Right, int Key) {
	int Middle2  = (Left + Right) / 2;
	if (Left <= Right) {
		if (Key = Arr[Middle2]) {
			return Key;
		}
		else if (Key > Arr[Middle2]) {
			return BinarySearchRecursive(Arr, Middle2 + 1, Right, Key);
		}
		else if (Key < Arr[Middle2]) {
			return BinarySearchRecursive(Arr, Left, Middle2 - 1, Key);
		}
	}

	return -1;
}

void PrintArrayBinarySearch(int Arr[], int size) {
	cout << " The Array size now is: [ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << " ]" << endl;
}
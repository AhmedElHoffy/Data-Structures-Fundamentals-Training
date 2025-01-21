#include "BubbleSortAlgo.h"
#include<iostream>
using namespace std;

void SwapVal(int& x, int& y) {
	int temp = x;
	 x = y;
	y = temp;
}
//100, 60, 20  50 , 30 , 90 
int BubbleSort(int Arr[], int size) {
	bool sorted = true;
	int c = 0; // counting how many  swaps check are performed
	for (int i = 0; i < size-i; i++) { // calculate how many passes/iterations
		for (int j = 0; j < size-i-1; j++) { // works on the swap
			if (Arr[j] > Arr[j + 1]) {
				cout << "Swap performed on " << Arr[j] << " And " << Arr[j + 1] << " At Indeces" << j << " and " << j + 1 << endl;
				SwapVal(Arr[j], Arr[j + 1]);
				c++;
				sorted = false;
			}
		}
		cout << endl;
			if (sorted == true) {
				cout << "Array is already sorted!" << endl;
				break;
			}
		}
	return c;
	}


void PrintArrayBubble(int Arr[], int size) {
	\
		cout << " The Array size now is: [ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << " ]" << endl;
}

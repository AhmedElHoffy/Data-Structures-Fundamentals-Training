#include "QuickSortAlgo.h"
#include<iostream>

using namespace std;

void SwapValQuick(int &x, int&y) {
	int temp = x;
	x = y;
	y = temp;
}
int Partition_Ahmed(int Arr[], int LeftIdx, int RightIdx) {
	int i = LeftIdx;
	int j = RightIdx;
	int PivLoc = i; //Intitialize the pivot location to be at the start of (Sub) - Array

	/*cout << "Initial Array: ";
	for (int k = LeftIdx; k <= RightIdx; k++) {
		cout << Arr[k] << " ";
	}
	cout << "\nPivot initialized at index: " << PivLoc << ", Value: " << Arr[PivLoc] << endl;
	*/

	while (i < j) {

		//cout << "Before iteration: i = " << i << ", j = " << j << ", PivLoc = " << PivLoc << endl;

		if (PivLoc == i && Arr[i] > Arr[j]) {
			//cout << "Swapping Arr[i] (" << Arr[i] << ") and Arr[j] (" << Arr[j] << ") because PivLoc == i and Arr[i] > Arr[j]" << endl;
			SwapValQuick(Arr[i], Arr[j]);
			PivLoc = j;
			i++;
		}
		else if (PivLoc == i  && Arr[i] < Arr[j]) {
			//cout << "Decrementing j because PivLoc == i and Arr[i] < Arr[j]" << endl;
			j--;

		}
		else if (PivLoc == j && Arr[i] < Arr[j]) {
			//cout << "Incrementing i because PivLoc == j and Arr[i] < Arr[j]" << endl;
			i++;
		}
		else if (PivLoc == j && Arr[i] > Arr[j]) {
			//cout << "Swapping Arr[i] (" << Arr[i] << ") and Arr[j] (" << Arr[j] << ") because PivLoc == j and Arr[i] > Arr[j]" << endl;
			SwapValQuick(Arr[i], Arr[j]);
			PivLoc = i;
			j--;
		}
		//cout << "After iteration: i = " << i << ", j = " << j << ", PivLoc = " << PivLoc << endl;
		//cout << "Current Array: ";
		/*for (int k = LeftIdx; k <= RightIdx; k++) {
			cout << Arr[k] << " ";
		}
		cout << endl << endl;*/
	}

	cout << "Final Pivot Location: " << PivLoc << ", Pivot Value: " << Arr[PivLoc] << endl;
	return PivLoc;
	}


void  QuickSort_Ahmed(int Arr[], int LeftIdx, int RightIdx) {
	if (LeftIdx < RightIdx) {
		int PivLoc = Partition_Ahmed(Arr, LeftIdx, RightIdx);
		QuickSort_Ahmed(Arr, LeftIdx, PivLoc - 1);
		QuickSort_Ahmed(Arr, PivLoc + 1, RightIdx);
	}
}



int Partition_AdelNasim1(int Arr[], int LeftIdx, int RightIdx) {
	int i = LeftIdx;
	int j = RightIdx;
	int PivLoc = i;
	while (true) {
		while (PivLoc != j && Arr[PivLoc] <= Arr[j]) {
			j--;
		}
		if (PivLoc == j) {
			break; // break from while (true)
		}
		else if (Arr[PivLoc] > Arr[j]) {
			SwapValQuick(Arr[PivLoc], Arr[j]);
			PivLoc = j;
		}

		while (PivLoc != i && Arr[PivLoc] >= Arr[i]) {
			i++;
		}
		if (PivLoc == i) {
			break;
		}
		else if (Arr[PivLoc] < Arr[i]) {
			SwapValQuick(Arr[PivLoc], Arr[i]);
			PivLoc = i;
		}
	}
	return PivLoc;
}



void  QuickSort_AdelNasim1(int Arr[], int LeftIdx, int RightIdx) {
	if (LeftIdx < RightIdx) {
		int PivLoc = Partition_AdelNasim1(Arr, LeftIdx, RightIdx);
		QuickSort_AdelNasim1(Arr, LeftIdx, PivLoc - 1);
		QuickSort_AdelNasim1(Arr, PivLoc + 1, RightIdx);
	}
}

int Partition_AdelNasim2(int Arr[], int LeftIdx, int RightIdx) {
	int Pivot = Arr[LeftIdx];
	int i = LeftIdx;
	int j= RightIdx;

	do {
		i++;
	} while (Arr[i] <= Pivot); //We search for a value with I Index that is greater than the Pivot

	do {
		j--;
	} while (Arr[j] > Pivot); // We search for a value using the j Index that is smaller than the pivot
	if (i < j) {
		SwapValQuick(Arr[i], Arr[j]);
   }
	SwapValQuick(Arr[LeftIdx], Arr[j]);
	return j;
}

void  QuickSort_AdelNasim2(int Arr[], int LeftIdx, int RightIdx) {
	if (LeftIdx < RightIdx) {
		int PivLoc = Partition_AdelNasim2(Arr, LeftIdx, RightIdx);
		QuickSort_AdelNasim2(Arr, LeftIdx, PivLoc - 1);
		QuickSort_AdelNasim2(Arr, PivLoc + 1, RightIdx);
	}
}


void PrintArrayQuick(int Arr[], int size) {

	cout << " The Array size now is: [ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << " ]" << endl;
}

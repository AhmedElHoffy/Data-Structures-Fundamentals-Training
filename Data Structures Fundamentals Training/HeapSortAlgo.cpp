#include "HeapSortAlgo.h"

#include<iostream>
using namespace std;

void SwapValHeap(int& x, int& y) {
	int temp = x;
	 x = y;
	 y = temp;

}

void HeapifyMax(int Arr[], int size, int ParentPos) {
	int LeftChildIdx = ParentPos * 2 + 1;
	int LeftChild = Arr[LeftChildIdx];
	int RightChildIdx = ParentPos * 2 + 2;
	int RightChild = Arr[RightChildIdx];


	int Max = ParentPos; //Assume the Parent is greater than the children at the begining
	if (LeftChildIdx<size && Arr[Max] < LeftChild) {
		Max = LeftChildIdx;
	}
	if (RightChildIdx < size && Arr[Max] < RightChild) {
		Max = RightChildIdx;
	}
	if (Max != ParentPos) {
		SwapValHeap(Arr[ParentPos], Arr[Max]); //swapping the parent with the max Child 
		//Recursivley call Heapify to fix children values till we reach the leaves (in case the ParentPos was in mid of the tree of at root.
		// We need to apply Max heap cncept to all parent nodes in the tree
		HeapifyMax(Arr, size, Max);
	}
}

// to Apply Heapify on each level of Parent
void BuildHeapMax(int Arr[], int size) {
	for (int i = size / 2 - 1; i >= 0;i--) {
		HeapifyMax(Arr, size, i);
	}
}

// After we apply Build Heap --> we have the Array sorted Descedingly
// We need HeapSort Function tore-arrange the heap ascendingly
//if we need descending order only , we don't need heapSort

void HeapSortMax(int Arr[], int size) {


	BuildHeapMax(Arr, size);//Max heapify in Descending order


	//Now we need to swap first with last and apply heapify again to make sure max heap concept is followed
	for (int i = size - 1; i >= 0; i--) {
		SwapValHeap(Arr[0], Arr[i]);
		HeapifyMax(Arr, i, 0);
	}
}

void HeapifyMin(int Arr[], int size, int ParentPos) {
	int LeftChildIdx = ParentPos * 2 + 1;
	int LeftChild = Arr[LeftChildIdx];
	int RightChildIdx = ParentPos * 2 + 2;
	int RightChild = Arr[RightChildIdx];


	int Min = ParentPos; //Assume the Parent is greater than the children at the begining
	if (LeftChildIdx < size && Arr[Min] > LeftChild) {
		Min = LeftChildIdx;
	}
	if (RightChildIdx < size && Arr[Min] > RightChild) {
		Min = RightChildIdx;
	}
	if (Min != ParentPos) {
		SwapValHeap(Arr[ParentPos], Arr[Min]); //swapping the parent with the max Child 
		//Recursivley call Heapify to fix children values till we reach the leaves (in case the ParentPos was in mid of the tree of at root.
		// We need to apply Max heap cncept to all parent nodes in the tree
		HeapifyMin(Arr, size, Min);
	}
}

// to Apply Heapify on each level of Parent
void BuildHeapMin(int Arr[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		HeapifyMin(Arr, size, i);
	}
}

void PrintArrayHeap(int Arr[], int size) {

	cout << " The Array size now is: [ ";
	for (int i = 0; i < size; i++) {
		cout << Arr[i] << " ";
	}
	cout << " ]" << endl;
}

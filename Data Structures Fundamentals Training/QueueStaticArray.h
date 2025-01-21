#pragma once

#include <iostream>
using namespace std;
const int Max_SizeQueueArray = 100;
// Circular Queue Array Implementations
class QueueStaticArray
{
	int front, rear, count;
	int arrQ[Max_SizeQueueArray]; //since it is an array queue we need to idelntify the array list (static array) , later we can see how to use dynamic array instead and generic template idea

public:
	//implement the constructor to iniialize the front, rear and count
	QueueStaticArray();


	bool isEmpty();
	bool isFull();

   void Enqueue(int val);

   void Dequeue();

	// Function Dequeue override to use the deleted value afterwards
   void Dequeue(int& DelVal);

   int GetFrontQ();
   int GetRearQ();

   int GetSize();
   void PrintQueue();
   void clearQArray();
   void search(int val);
};


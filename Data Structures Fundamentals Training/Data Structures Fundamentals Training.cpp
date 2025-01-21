// Data Structures Fundamentals Training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<stack>
#include <map>
#include<queue>
#include <chrono> // For measuring time
using namespace std;


#include"StackArray.h"
#include"StackArrayTemplate.h"

#include "LinkedStack.h"
#include"LinkedStackTemplate.h"

#include "AreBalancedParantheses.h"

#include "ExpressionEval_PostFix.h"

#include "InfixPostfixConvert.h"

#include "QueueStaticArray.h"
#include "QueueDynamicArray.h"
#include"QueueDynamicArrayTemplate.h"
#include "LinkedQueue.h"
#include"LinkedQueueTemplate.h"

#include "ArrayList.h"
#include "LinkedList.h"
#include "DoublyLL.h"

#include "BinaryTree.h"

#include "SelectrionSortAlgo.h"
#include "BubbleSortAlgo.h"
#include "InsertionSortAlgo.h"
#include "MergeSortAlgo.h"
#include "QuickSortAlgo.h"
#include "HeapSortAlgo.h"



#include "LinearSearchAlgo.h"
#include "BinarySearchAlgo.h"

#include "HashTableAlgo.h"

#include "BFSAlgo.h"
#include "DFSAlgo.h"












int main()
{ 

	// Stack array Test

	cout << "Press 1  for StackArray" << endl;
	cout << "Press 2  for Stack Stack LinkedList" << endl;
	cout << "Press 3  for Balanced Parentheses Testing" << endl;
	cout << "Press 4  for Expression Evaluation Testing"<< endl;
	cout << "Press 5  for infix to postfix conversion " << endl;
	cout << "Press 6  for Static QueueArray" << endl;
	cout << "Press 7  for Dynamic QueueArray" << endl;
	cout << "Press 8  for Dynamic QueueArrayCharacter" << endl;
	cout << "Press 9  for  Linked Queue" << endl;
	cout << "Press 10 for  Linked Queue Characters" << endl;
	cout << "Press 11 for  Aray Based List (using Dynamic Array {Pointer}" << endl;
	cout << "Press 12 for  Singular LinkedList Testintg {with Pointers} " << endl;
	cout << "Press 13 for  Doubly LinkedList Testintg {with Pointers}" << endl;
	cout << "Press 14 for  Binary Search Tree Testing " << endl;
	cout << "Press 15 For Tesing Huffman Code Tree " << endl;
	cout << "Press 16 For Tesing Selection Sort Algorithm " << endl;
	cout << "Press 17 For Tesing Bubble Sort Algorithm " << endl;
	cout << "Press 18 For Tesing Insertion Sort Algorithm " << endl;
	cout << "Press 19 For Tesing Merge Sort Algorithm " << endl;	
	cout << "Press 20 For Tesing Quick Sort Algorithm " << endl;
	cout << "Press 21 For Tesing Heap Sort (MAx Heap) Algorithm " << endl;
	cout << "Press 22 For Tesing Linear Search Algorithm " << endl;
	cout << "Press 23 For Tesing Binary Search Algorithm " << endl;
	cout << "Press 24 For Testing Hash Table Algorithm " << endl;
	cout << "Press 25 For Testing Breadth First Search Algorithm" << endl;
	cout << "Press 26 For Testing Depth First Search Algorithm" << endl;
	cout << "Press 27 For Testing Djjkstra's Shortest path Algorithm \n" << endl;


	// to be coded for huffman coding algo and Greedy Algorithm (Graphs for Djjkstra's Shortest path Algorithm)

	int option;
	cout << "Please Enter Here: ";
	cin >> option;
	cout << endl<< endl;

	switch (option) {

	case 1:{
		StackArray S;

		S.GetTop();

		S.push(5);
		S.push(10);
		S.push(15);
		S.push(20);
		S.push(25);
		S.printStack();
		S.GetTop();

		S.pop();
		S.printStack();
		S.GetTop();

		S.pop();
		S.pop();
		S.pop();
		S.printStack();
		S.GetTop();


		S.push(99);
		S.push(77);
		S.printStack();
		S.GetTop();

		cout << endl << endl;

		StackArrayT<char> C;
		cout << "StackArray for Charaters" << endl;
		C.push('A');
		C.push('B');
		C.push('C');
		C.push('D');
		C.printStack();
		C.GetTop();

		C.pop();
		C.pop();
		C.printStack();
		C.GetTop();

		cout << endl << endl;

		StackArrayT<string> Names;
		cout << "StackArray for Strings" << endl;
		Names.push("Ahmed");
		Names.push("Bassel");
		Names.push("Seham");
		Names.push("Ismail");
		Names.printStack();
		Names.GetTop();

		Names.pop();
		Names.pop();
		Names.printStack();
		Names.GetTop();
		break;
	}

	case 2: {

		LinkedStack LS;

		LS.push(100);
		LS.push(200);
		LS.push(300);
		LS.push(400);
		LS.PrintStack();
		LS.GetTop();

		LS.pop();
		LS.pop();
		LS.PrintStack();
		LS.GetTop();

	
		cout << endl << endl;

		LinkedStackT<char> CharLL;
		cout << "LinkedStack for Charaters" << endl;
		CharLL.push('A');
		CharLL.push('B');
		CharLL.push('C');
		CharLL.push('D');
		CharLL.PrintStack();
		CharLL.GetTop();


		CharLL.pop();
		CharLL.pop();
		CharLL.PrintStack();
		CharLL.GetTop();

		cout << endl << endl;

		LinkedStackT<string> NamesLL;
		cout << "LinkedStack for Strings" << endl;
		NamesLL.push("Ahmed");
		NamesLL.push("Bassel");
		NamesLL.push("Seham");
		NamesLL.push("Ismail");
		NamesLL.PrintStack();
		NamesLL.GetTop();

		NamesLL.pop();
		NamesLL.pop();
		NamesLL.PrintStack();
		NamesLL.GetTop();

		cout << endl << endl;
		
	}

	case 3: {
		string Expression;

		cout << "Enter an Expression: ";
		cin >> Expression;

		if (areBalancedParantheses(Expression)) {
			cout << "Expression is balanced in parantheses, Great!" << endl;
		}
		else {
			cout << "Expression is not balanced in Parantheses, Please re-enter" << endl;
		}

	}

	case 4: {
		char exp[1000], buffer[15];
		int op1, op2, len, j, x;
		stack<int> s;

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer (because we have previously used cin so the cin string has input already)
		cout << "Enter a postfix Expression (e.g., 4 5 *): ";
		cin.getline(exp, 1000);
		len = strlen(exp);
		j = 0;

		for (int i = 0; i < len; i++) {
			if (exp[i] >= '0' && exp[i] <= '9') {
				buffer[j++] = exp[i];
			}
			else if (exp[i] == ' ') {
				if (j > 0) {
					buffer[j] = '\0';  // Null-terminate the buffer string
					x = atoi(buffer);  // Convert the buffer string to an integer
					s.push(x);         // Push the integer onto the stack
					j = 0;             // Reset buffer index for the next number
				}
			}
			else if (isOperator(exp[i])) {

				op2 = s.top(); s.pop();
				op1 = s.top(); s.pop();
				s.push(PerformOperation(op1, op2, exp[i]));
			}
		}

		if (s.size() != 1) {
			cout << "Error: Malformed expression. Final stack size is not 1." << endl;
		}
		else {
			cout << "Answer: " << s.top() << endl;
		}
		break; // Prevent fall-through

	}

	case 5: {
		string expConvert;
		cout << "Enter the Infix Expression: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer (because we have previously used cin so the cin string has input already)
		getline(cin, expConvert);

		string postfix = InfixPostfixConvert(expConvert);
		cout << "Output = " << postfix << endl;
		break;
	}
	
	case 6:{

		QueueStaticArray Qarray1;
		Qarray1.Enqueue(10);
		Qarray1.Enqueue(20);
		Qarray1.Enqueue(30);
		Qarray1.Enqueue(40);

		cout << "Queue array now: ";
		Qarray1.PrintQueue();
		int frontQ = Qarray1.GetFrontQ();
		int RearQ = Qarray1.GetRearQ();
		cout << "Front of the Queue now is: " << frontQ << endl;
		cout << "Rear of the Queue now is: " << RearQ << endl;

		cout << "Search for  10  test:  " << endl;
		Qarray1.search(10);


		Qarray1.Dequeue();
		Qarray1.Dequeue();

		cout << "Queue array now: ";
		Qarray1.PrintQueue();

		 frontQ = Qarray1.GetFrontQ();
		 RearQ = Qarray1.GetRearQ();
		cout << "Front of the Queue now is: " << frontQ << endl;
		cout << "Rear of the Queue now is: " << RearQ << endl;

		int sizeQ= Qarray1.GetSize();
		cout << "Array size now: " << sizeQ << endl;

		Qarray1.clearQArray();

		cout << "Queue array now: ";
		Qarray1.PrintQueue();

		break;
	}
	
	case 7: {
		QueueDynamicArray QarrayD1(4);
		QarrayD1.Enqueue(10);
		QarrayD1.Enqueue(20);
		QarrayD1.Enqueue(30);
		QarrayD1.Enqueue(40);

		cout << "Queue array now: ";
		QarrayD1.PrintQueue();
		int frontQD = QarrayD1.GetFrontQ();
		int RearQD = QarrayD1.GetRearQ();
		cout << "Front of the Queue now is: " << frontQD << endl;
		cout << "Rear of the Queue now is: " << RearQD << endl;

		cout << "Search for  80  test:  " << endl;
		QarrayD1.search(80);

		QarrayD1.Dequeue();
		QarrayD1.Dequeue();

		cout << "Queue array now: ";
		QarrayD1.PrintQueue();

		frontQD = QarrayD1.GetFrontQ();
		RearQD = QarrayD1.GetRearQ();
		cout << "Front of the Queue now is: " << frontQD << endl;
		cout << "Rear of the Queue now is: " << RearQD << endl;

		int sizeQD = QarrayD1.GetSize();
		cout << "Array size now: " << sizeQD << endl;

		QarrayD1.clearQArray();

		cout << "Queue array now: ";
		QarrayD1.PrintQueue();

		 sizeQD = QarrayD1.GetSize();
		cout << "Array size now: " << sizeQD << endl;

		break;

	}
	
	case 8: {
		QueueDynamicArrayT <char> QarrayDC1(4);
		QarrayDC1.Enqueue('A');
		QarrayDC1.Enqueue('B');
		QarrayDC1.Enqueue('C');
		QarrayDC1.Enqueue('D');

		cout << "Queue array now: ";
		QarrayDC1.PrintQueue();
		char frontQDC = QarrayDC1.GetFrontQ();
		char RearQDC = QarrayDC1.GetRearQ();
		cout << "Front of the Queue now is: " << frontQDC << endl;
		cout << "Rear of the Queue now is: " << RearQDC << endl;

		cout << "Search for  A  test:  " << endl;
		QarrayDC1.search('A');

		QarrayDC1.Dequeue();
		QarrayDC1.Dequeue();

		cout << "Queue array now: ";
		QarrayDC1.PrintQueue();

		frontQDC = QarrayDC1.GetFrontQ();
		RearQDC = QarrayDC1.GetRearQ();
		cout << "Front of the Queue now is: " << frontQDC << endl;
		cout << "Rear of the Queue now is: " << RearQDC << endl;

		int sizeQD = QarrayDC1.GetSize();
		cout << "Array size now: " << sizeQD << endl;

		QarrayDC1.clearQArray();

		cout << "Queue array now: ";
		QarrayDC1.PrintQueue();

		sizeQD = QarrayDC1.GetSize();
		cout << "Array size now: " << sizeQD << endl;

		break;

	}
	
	case 9: {
		LinkedQueue LinkedQueue1;
		LinkedQueue1.Enqueue(10);
		LinkedQueue1.Enqueue(20);
		LinkedQueue1.Enqueue(30);
		LinkedQueue1.Enqueue(40);

		cout << "Queue array now: ";
		LinkedQueue1.PrintQueue();
		int frontQL = LinkedQueue1.GetFront();
		int RearQL = LinkedQueue1.GetRear();
		cout << "Front of the Queue now is: " << frontQL << endl;
		cout << "Rear of the Queue now is: " << RearQL << endl;

		int valsearch;
		cout << "please enter the value you want to search in the Linekd Queue: ";
		cin >> valsearch;
		cout << endl;
		cout << "Search for "<<valsearch << " : " << endl;
		if (LinkedQueue1.Search(valsearch)) {
			cout << valsearch << " was found in the LinkedQueue" << endl;
		}
		else {
			cout<< valsearch << " is not in the LinkedQueue" << endl;
		}

		LinkedQueue1.Dequeue();
		LinkedQueue1.Dequeue();

		cout << "Queue array now: ";
		LinkedQueue1.PrintQueue();

		frontQL = LinkedQueue1.GetFront();
		RearQL = LinkedQueue1.GetRear();
		cout << "Front of the Queue now is: " << frontQL << endl;
		cout << "Rear of the Queue now is: " << RearQL << endl;

		int sizeQL = LinkedQueue1.Getsize();
		cout << "Array size now: " << sizeQL << endl;

		LinkedQueue1.clearQueueList();

		cout << "Queue array now: ";
		LinkedQueue1.PrintQueue();

		sizeQL = LinkedQueue1.Getsize();
		cout << "Array size now: " << sizeQL << endl;
		break;
	}
	
	case 10: {
		LinkedQueueT<char> LinkedQueueC;
		LinkedQueueC.Enqueue('A');
		LinkedQueueC.Enqueue('B');
		LinkedQueueC.Enqueue('C');
		LinkedQueueC.Enqueue('D');

		cout << "Queue array now: ";
		LinkedQueueC.PrintQueue();
		char frontQLLC = LinkedQueueC.GetFront();
		char RearQLLC = LinkedQueueC.GetRear();
		cout << "Front of the Queue now is: " << frontQLLC << endl;
		cout << "Rear of the Queue now is: " << RearQLLC << endl;

		char valsearch;
		cout << "please enter the value you want to search in the Linekd Queue: ";
		cin >> valsearch;
		cout << endl;
		cout << "Search for " << valsearch << " : " << endl;
		if (LinkedQueueC.Search(valsearch)) {
			cout << valsearch << " was found in the LinkedQueue" << endl;
		}
		else {
			cout << valsearch << " is not in the LinkedQueue" << endl;
		}

		LinkedQueueC.Dequeue();
		LinkedQueueC.Dequeue();

		cout << "Queue array now: ";
		LinkedQueueC.PrintQueue();

		frontQLLC = LinkedQueueC.GetFront();
		RearQLLC = LinkedQueueC.GetRear();
		cout << "Front of the Queue now is: " << frontQLLC << endl;
		cout << "Rear of the Queue now is: " << RearQLLC << endl;

		int sizeQLLC = LinkedQueueC.Getsize();
		cout << "Array size now: " << sizeQLLC << endl;

		LinkedQueueC.clearQueueList();

		cout << "Queue array now: ";
		LinkedQueueC.PrintQueue();

		sizeQLLC = LinkedQueueC.Getsize();
		cout << "Array size now: " << sizeQLLC << endl;

		break;
	}
	
	case 11: {
		cout << "Please insert the size of the arraylist you will use: ";
		int Arrsize;
		cin >> Arrsize;
		cout << endl;

		ArrayList ArrayList1(Arrsize);

		ArrayList1.insert(10, 0);
		ArrayList1.insert(20, 1);
		ArrayList1.insert(30, 2);
		ArrayList1.insert(40, 3);
		ArrayList1.insert(50, 4);

		cout << "The Size of the ArrayList now is: " << ArrayList1.GetSize() << endl;
		cout << "The arraylist now is: ";
		ArrayList1.printArrayList();

		ArrayList1.insertNoDuplicate(20, 3);


		ArrayList1.insert(15, 2);
		cout << "The Size of the ArrayList now is: " << ArrayList1.GetSize() << endl;
		cout << "The arraylist now is: ";
		ArrayList1.printArrayList();

		int get1 = ArrayList1.GetElementAt(5);
		int get2 = ArrayList1.GetElementAt(2);
		cout << "Element at loc 5 is: " << get1 << endl;
		cout << "Element at loc 2 is: " << get2 << endl;


		ArrayList1.remove(2);
		ArrayList1.remove(4);
		cout << "The Size of the ArrayList now is: " << ArrayList1.GetSize() << endl;
		cout << "The arraylist now is: ";
		ArrayList1.printArrayList();


		ArrayList1.UpdateAt(25, 0);
		cout << "The arraylist now is: ";
		ArrayList1.printArrayList();

		int search1;
		cout << "Please enter the element you want to search for in the ArrayList: ";
		cin >> search1;
		cout << endl;
		if (ArrayList1.search(search1) != -1) {
			cout << search1 << " was found at location " << ArrayList1.search(search1) << endl;
		}
		else {
			cout << search1 << " was not found at the arraylist" << endl;
		}

		break;
	}
	
	case 12: {
		LinkedList L1;
		L1.InsertAtStart(10);
		L1.InsertAtEndWithCurr(20);
		L1.InsertAtEndTailPtr(30);

		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();

		int xfirst, xlast;
		xfirst = L1.GetHead();
		xlast = L1.GetTail();
		cout << "The head of the Linked List now is: " << xfirst << endl;
		cout << "The Tail of the Linked List now is: " << xlast << endl;

		L1.InsertAtPos(40, -5);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();

		L1.RemoveHead();
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();

		L1.RemoveTail();
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();

		L1.RemoveTail();
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;


		L1.InsertAtStart(10);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		L1.InsertAtEndWithCurr(20);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		L1.InsertAtEndTailPtr(30);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		L1.InsertAtEndTailPtr(40);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		L1.InsertAtEndTailPtr(50);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();

		L1.RemoveSpecificVal(10);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;

		L1.RemoveSpecificVal(580);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;

		L1.RemoveSpecificVal(30);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;

		L1.RemoveAtPos(2);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;

		L1.RemoveAtPos(5);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;

		L1.InsertAtEndTailPtr(50);
		L1.InsertAtEndTailPtr(60);
		L1.InsertAtEndTailPtr(70);
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;

		L1.ReverselinkedList();
		cout << "The size Linked List now is: " << L1.GetSize() << endl;
		cout << "The Linked List now is: ";
		L1.PrintList();
		cout << endl;

		L1.SearchVal(40);

		break;
	}

	case 13: {
		DoublyLL DoubleLL1;
		DoubleLL1.InsertAtHead(10);  //0
		DoubleLL1.InsertAtTail(20);  //1
		DoubleLL1.InsertAtTail(30);  //2
		DoubleLL1.InsertAtTail(50);  //3
		DoubleLL1.InsertAtTail(60);  //4
		DoubleLL1.InsertAtPos(40,3);  
		cout << "The size Linked List now is: " << DoubleLL1.GetSize() << endl;
		cout << "The Linked List from the HEAD now is: ";
		DoubleLL1.PrintHeadTraverse();
		cout << "The Linked List from the Tail now is: ";
		DoubleLL1.PrintTailTraverse();
		cout << endl; 

		DoubleLL1.RemoveAtHead();
		cout << "The size Linked List now is: " << DoubleLL1.GetSize() << endl;
		cout << "The Linked List from the HEAD now is: ";
		DoubleLL1.PrintHeadTraverse();
		cout << "The Linked List from the Tail now is: ";
		DoubleLL1.PrintTailTraverse();
		cout << endl; 

		DoubleLL1.RemoveAtTail();
		cout << "The size Linked List now is: " << DoubleLL1.GetSize() << endl;
		cout << "The Linked List from the HEAD now is: ";
		DoubleLL1.PrintHeadTraverse();
		cout << "The Linked List from the Tail now is: ";
		DoubleLL1.PrintTailTraverse();
		cout << endl;

		DoubleLL1.RemoveAtPos(19);
		cout << "The size Linked List now is: " << DoubleLL1.GetSize() << endl;
		cout << "The Linked List from the HEAD now is: ";
		DoubleLL1.PrintHeadTraverse();
		cout << "The Linked List from the Tail now is: ";
		DoubleLL1.PrintTailTraverse();
		cout << endl;

		DoubleLL1.RemoveVal(20);
		cout << "The size Linked List now is: " << DoubleLL1.GetSize() << endl;
		cout << "The Linked List from the HEAD now is: ";
		DoubleLL1.PrintHeadTraverse();
		cout << "The Linked List from the Tail now is: ";
		DoubleLL1.PrintTailTraverse();

		DoubleLL1.~DoublyLL();
		break;
	}

	case 14: {
		BinaryTree Tree1;

		// Test 1: Insert values into the tree
		cout << "Inserting values into the tree...\n";
		Tree1.InsertValRec(50);
		Tree1.InsertValRec(30);
		Tree1.InsertValRec(70);
		Tree1.InsertValRec(20);
		Tree1.InsertValRec(40);
		Tree1.InsertValRec(60);
		Tree1.InsertValRec(80);

		// Test 2: Print tree traversals
		cout << "\nTree Traversals:\n";
		Tree1.Pre_OrderPrint();  // Expected: 50 30 20 40 70 60 80
		Tree1.In_OrderPrint();   // Expected: 20 30 40 50 60 70 80
		Tree1.Post_OrderPrint(); // Expected: 20 40 30 60 80 70 50
		Tree1.Level_OrderPrint(); // Expected: 50 30 70 20 40 60 80

		// Test 3: Search for values
		cout << "\nSearch for values:\n";
		cout << "Searching for 40 (Recursive): " << (Tree1.searchValRec(40) ? "Found" : "Not Found") << endl; // Expected: Found
		cout << "Searching for 90 (Recursive): " << (Tree1.searchValRec(90) ? "Found" : "Not Found") << endl; // Expected: Not Found
		cout << "Searching for 20 (Iterative): " << (Tree1.SearchValIter(20) ? "Found" : "Not Found") << endl; // Expected: Found
		cout << "Searching for 100 (Iterative): " << (Tree1.SearchValIter(100) ? "Found" : "Not Found") << endl; // Expected: Not Found

		// Test 4: Insert duplicate value
		cout << "\nInserting duplicate value 40...\n";
		Tree1.InsertValRec(40); // Expected: "40 Already exists in the BST!"

		// Test 5: Insert additional values iteratively
		cout << "\nInserting values iteratively...\n";
		Tree1.InsertValIter(90);
		Tree1.InsertValIter(10);
		Tree1.Level_OrderPrint(); // Expected: 50 30 70 20 40 60 80 10 90 

		cout << "The Max and min search...\n" << endl;
		Tree1.Find_MaxNode();
		Tree1.Find_MinNode();

		Tree1.LeavesCount();
		Tree1.TreeNodesCount();
		Tree1.TreeHeight();

		Tree1.DeleteNode(50);
		Tree1.Level_OrderPrint(); 


		// Clear the tree
		cout << "Clearing the   tree..." << endl;
		Tree1.ClearTree();

		// Check if the tree is empty
		if (Tree1.isEmpty()) {
			cout << "The tree is now  empty!" << endl;
		}

		break;
	}

	case 15: {

		// to be coded
		break;
	}
	case 16: {

		int Arr[] = { -60,40,50,30,10,20 };

		int n = sizeof(Arr) / sizeof(Arr[0]); // size of actual array / size  of an element in the array = array length/size
		cout << "Array now Before Selection Sort is: ";
		PrintArr(Arr, n);

		SelectionSort(Arr, n);
		cout << " Array now After Selection Sort is:  ";
		PrintArr(Arr, n);

	}
	case 17: {

		int ArrayBubble[] = { 100, 60, 20 , 50 , 30 , 90 };

		int nBubble = sizeof(ArrayBubble) / sizeof(ArrayBubble[0]); // size of actual array / size  of an element in the array = array length/size
		cout << "Array now Before Bubble Sort is: ";
		PrintArrayBubble(ArrayBubble, nBubble);
		int counter = 0;
		counter = BubbleSort(ArrayBubble, nBubble);
		cout << "Array now After Bubble Sort is: ";
		PrintArrayBubble(ArrayBubble, nBubble);
		cout << "Swaps Checks are = " << counter << endl;
		break;
	}
	case 18: {
		int ArrayInsertion[] = { 100, 60, 20 , 50 , 30 , 90 };
		int nInsertion = sizeof(ArrayInsertion) / sizeof(ArrayInsertion[0]); // size of actual array / size  of an element in the array = array length/size
		cout << "size of array is: " << nInsertion << endl;
		cout << "Array now Before Insertion Sort is: ";
		PrintArrayInsertion(ArrayInsertion, nInsertion);

		// Start the timer
		auto start1 = chrono::high_resolution_clock::now();

		InsertionSortForLOOP(ArrayInsertion, nInsertion);
		
		// Stop the timer
		auto end1 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
		// Print the time taken
		cout << "Time taken by InsertionSort: " << duration1.count() << " microseconds" << endl;


		cout << "Array now After Insertion Sort is: ";
		PrintArrayInsertion(ArrayInsertion, nInsertion);

		cout << "\n Now we will use For While Loop algorithm... \n" << endl;

		cout << "Array now Before Insertion Sort is: ";
		PrintArrayInsertion(ArrayInsertion, nInsertion);
		
		// Start the timer
		auto start2 = chrono::high_resolution_clock::now();
		InsertionSortForWhileLOOP(ArrayInsertion, nInsertion);

		// Stop the timer
		auto end2 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
		cout << "Time taken by InsertionSort: " << duration2.count() << " microseconds" << endl;


		cout << "Array now After Insertion Sort is: ";
		PrintArrayInsertion(ArrayInsertion, nInsertion);
	
	}
	case 19: {
		int ArrayMerge[] = { 60,10,20,5,60,70};
		int nMerge = sizeof(ArrayMerge) / sizeof(ArrayMerge[0]); // size of actual array / size  of an element in the array = array length/size
		cout << "size of array is: " << nMerge << endl;
		cout << "Array now Before Merge Sort is: ";
		PrintArrayMerge(ArrayMerge, nMerge);


		// Start the timer
		auto start3 = chrono::high_resolution_clock::now();

		MergeSort(ArrayMerge, 0, nMerge - 1);

		// Stop the timer
		auto end3 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);
		cout << "Time taken by Merge Sort: " << duration3.count() << " microseconds" << endl;

		cout << "Array now After Merge Sort is: ";
		PrintArrayMerge(ArrayMerge, nMerge);


		break;
	}
	case 20: {

		int ArrayQuick[] = {50,20,60,10,30,40};
		int nQuick = sizeof(ArrayQuick) / sizeof(ArrayQuick[0]); // size of actual array / size  of an element in the array = array length/size
		cout << "Size of array now is: " << nQuick << endl;
		cout << "Array now Before Quick Sort is: ";
		PrintArrayQuick(ArrayQuick, nQuick);

		/*int loc = Partition_AdelNasim(ArrayQuick, 0, nQuick - 1);

		cout << "Location of pivot " << ArrayQuick[loc] << " After Partitioning is: " << loc << endl;
		*/

		// Start the timer
		auto startQuick1 = chrono::high_resolution_clock::now();

		QuickSort_Ahmed(ArrayQuick, 0, nQuick - 1);

		// Stop the timer
		auto endQuick1 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto durationQuick1 = chrono::duration_cast<chrono::microseconds>(endQuick1 - startQuick1);
		cout << "Time taken by Quick Sort (Ahmed's Code): " << durationQuick1.count() << " microseconds" << endl;

		cout << "Array now After Quick Sort (Ahmed's Code) is: ";
		PrintArrayQuick(ArrayQuick, nQuick);


		// Start the timer
		auto startQuick2 = chrono::high_resolution_clock::now();

		QuickSort_AdelNasim1(ArrayQuick, 0, nQuick - 1);

		// Stop the timer
		auto endQuick2 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto durationQuick2 = chrono::duration_cast<chrono::microseconds>(endQuick2 - startQuick2);
		cout << "Time taken by Quick Sort (Adel Nasim's Code) with partition 1 method: " << durationQuick2.count() << " microseconds" << endl;

		// Start the timer
		auto startQuick3 = chrono::high_resolution_clock::now();

		QuickSort_AdelNasim2(ArrayQuick, 0, nQuick - 1);

		// Stop the timer
		auto endQuick3 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto durationQuick3 = chrono::duration_cast<chrono::microseconds>(endQuick3 - startQuick3);
		cout << "Time taken by Quick Sort (Adel Nasim's Code) with Partition 2 method: " << durationQuick3.count() << " microseconds" << endl;


		cout << "Array now After Quick Sort (AdelNasim's Code) is: ";
		PrintArrayQuick(ArrayQuick, nQuick);

		break;
	}
	case 21: {

		int ArrayHeap[] = {90,10,40,70,5};
		int nHeap = sizeof(ArrayHeap) / sizeof(ArrayHeap[0]); // size of actual array / size  of an element in the array = array length/size
		cout << "Size of array now is: " << nHeap << endl;
		cout << "Array now Before Max Heap Sort is: ";
		PrintArrayHeap(ArrayHeap, nHeap);

		// Start the timer
		auto startHeap1 = chrono::high_resolution_clock::now();

		HeapSortMax(ArrayHeap, nHeap);

		// Stop the timer
		auto endheap1 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto durationHeap1 = chrono::duration_cast<chrono::microseconds>(endheap1 - startHeap1);
		cout << "Time taken by Max Heap Sort is: " << durationHeap1.count() << " microseconds" << endl;
		
		cout << "Array now After Max Heap Sort is: ";
		PrintArrayHeap(ArrayHeap, nHeap);


		cout << "\n\n" << "Now we try Min Heap to get the ascending order directly withou the need of HeapSort..." << endl;
		int ArrayHeap2[] = { 90,10,40,70,5 };
		int nHeap2 = sizeof(ArrayHeap2) / sizeof(ArrayHeap2[0]); // size of actual array / size  of an element in the array = array length/size
		cout << "Size of array2 now is: " << nHeap << endl;
		cout << "Array2 now Before Min Heap Sort is: ";
		PrintArrayHeap(ArrayHeap2, nHeap2);


		// Start the timer
		auto startHeap2 = chrono::high_resolution_clock::now();

		BuildHeapMin(ArrayHeap2, nHeap2);
		
		// Stop the timer
		auto endheap2 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto durationHeap2 = chrono::duration_cast<chrono::microseconds>(endheap2 - startHeap2);
		cout << "Time taken by Max Heap Sort is: " << durationHeap2.count() << " microseconds" << endl;

		cout << "Array2 now After Min Heap Sort is: ";
		PrintArrayHeap(ArrayHeap2, nHeap2);

		break;
	}
	case 22: {

		int ArrayLinearSearch[] = { 90,10,40,70,5 };
		int nLinearSearch = sizeof(ArrayLinearSearch) / sizeof(ArrayLinearSearch[0]); // size of actual array / size  of an element in the array = array length/size
		int key;
		cout << "Please Enter the Key you are looking for: ";
		cin >> key;
		cout << endl;

		int ResultIdx = LinearSearch(ArrayLinearSearch, nLinearSearch, key);
		if (ResultIdx != -1) {
			cout<< "The Key " << ArrayLinearSearch[ResultIdx] << " was Found at Index " << ResultIdx << endl;
		}
		else {
			cout << "The Key " << key << " was not found in the array!" << endl;
		}
		break; 
	}
	case 23: {

		int ArrayBinarySearch[] = { 90,10,40,70,5 };
		int nBinarySearch = sizeof(ArrayBinarySearch) / sizeof(ArrayBinarySearch[0]); // size of actual array / size  of an element in the array = array length/size
		int keyBinary;
		int RightIdx = nBinarySearch - 1;

		cout << "Please Enter the Key you are looking for: ";
		cin >> keyBinary;
		cout << endl;

		// Start the timer
		auto startBinary1 = chrono::high_resolution_clock::now();


		cout << "Using Binary Search iterative Method...." << endl;
		int ResultBinaryIdx = BinarySearchIterative(ArrayBinarySearch, 0, RightIdx, keyBinary);

		// Stop the timer
		auto endBinary1 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto durationBinary1 = chrono::duration_cast<chrono::microseconds>(endBinary1 - startBinary1);
		cout << "Time taken by Binary Searh Iteratively is: " << durationBinary1.count() << " microseconds\n" << endl;
		
		
		if (ResultBinaryIdx != -1) {
			cout << "The Key " << ArrayBinarySearch[ResultBinaryIdx] << " was Found at Index " << ResultBinaryIdx << endl;
		}
		else {
			cout << "The Key " << keyBinary << " was not found in the array!\n \n" << endl;
		}


		// Start the timer
		auto startBinary2 = chrono::high_resolution_clock::now();

		cout << "Using Binary Search Recursive Method...." << endl;
		int ResultBinaryIdx2 = BinarySearchIterative(ArrayBinarySearch, 0, RightIdx, keyBinary);

		// Stop the timer
		auto endBinary2 = chrono::high_resolution_clock::now();
		// Calculate the duration
		auto durationBinary2 = chrono::duration_cast<chrono::microseconds>(endBinary2 - endBinary2);
		cout << "Time taken by Binary Searh Recursively is: " << durationBinary2.count() << " microseconds\n" << endl;
		if (ResultBinaryIdx2 != -1) {
			cout << "The Key " << ArrayBinarySearch[ResultBinaryIdx2] << " was Found at Index " << ResultBinaryIdx2 << endl;
		}
		else {
			cout << "The Key " << keyBinary << " was not found in the array!" << endl;
		}
		break;
	}
	case 24: {
		HashTable HT1;
		if (HT1.isEmpty()) {
			cout << " Hash Table is Empty" << endl;
		}
		else {
			cout << "need to cehck your code again!" << endl;
		}

		HT1.InsertVal(950, "Ahmed");
		HT1.InsertVal(352, "Bssel");
		HT1.InsertVal(357, "Yusuf");
		HT1.InsertVal(952, "Malik");
		HT1.InsertVal(550, "Kamal");
		HT1.InsertVal(950, "Ismail");

		HT1.PrintTable();

		HT1.RemoveItem(357);
		HT1.RemoveItem(950);
		HT1.RemoveItem(997);

		HT1.PrintTable();

		if (HT1.isEmpty()) {
			cout << " need to check your code" << endl;
		}
		else {
			cout << "correct!" << endl;
		}


		break;


	}
	case 25: {
		// Test BFS with integers
		cout << "BFS Traversal for Integer Graph:\n";
		int V_int = 5; // Number of vertices
		vector<vector<int>> AdjInt(V_int);

		AddEdge_Vector(AdjInt, 0, 1);
		AddEdge_Vector(AdjInt, 0, 2);
		AddEdge_Vector(AdjInt, 1, 3);
		AddEdge_Vector(AdjInt, 1, 4);
		AddEdge_Vector(AdjInt, 2, 4);

		BFS_Vector(AdjInt, 0);


		// Test BFS with characters
		cout << "\nBFS Traversal for Character Graph starting from 'A':\n";
		int V_char = 5; // Number of vertices
		vector<vector<int>> AdjChar(V_char);

		// Create a map to associate characters with indices
		map<char, int> charToIndex;
		map<int, char> indexToChar;
		char vertices[] = { 'A', 'B', 'C', 'D', 'E' };

		// Map characters to indices and indices back to characters
		for (int i = 0; i < V_char; i++) {
			charToIndex[vertices[i]] = i;
			indexToChar[i] = vertices[i];
		}

		// Add edges to the character graph using mapped indices
		AddEdge_Vector(AdjChar, charToIndex['A'], charToIndex['B']);
		AddEdge_Vector(AdjChar, charToIndex['A'], charToIndex['C']);
		AddEdge_Vector(AdjChar, charToIndex['B'], charToIndex['D']);
		AddEdge_Vector(AdjChar, charToIndex['B'], charToIndex['E']);
		AddEdge_Vector(AdjChar, charToIndex['C'], charToIndex['E']);

		// Pass the mapped indices and index-to-char map to BFS function
		BFS_Vector(AdjChar, charToIndex['A'], indexToChar);

		break;
	}
	case 26: {

		// Test DFS with integers
		cout << "DFS Traversal for Integer Graph:\n";
		int V_int = 5; // Number of vertices
		vector<vector<int>> AdjInt(V_int);

		// Add edges to the graph
		AddEdge_VectorDFS(AdjInt, 0, 1);
		AddEdge_VectorDFS(AdjInt, 0, 2);
		AddEdge_VectorDFS(AdjInt, 1, 3);
		AddEdge_VectorDFS(AdjInt, 1, 4);
		AddEdge_VectorDFS(AdjInt, 2, 4);

		// Perform DFS starting from vertex 0
		DFS_Vector(AdjInt, 0);

		cout << endl;

		break;
	}
	default:
		cout << "Thank you!" << endl;
		break;
	}

   


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

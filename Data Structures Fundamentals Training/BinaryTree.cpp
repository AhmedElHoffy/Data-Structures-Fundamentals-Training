#include "BinaryTree.h"

#include<iostream>
#include"queue"
using namespace std;


BinaryTree::BinaryTree() {
	root = NULL;
}

bool BinaryTree::isEmpty() {
	return root == NULL;
}


void BinaryTree::Pre_OrderTraverse(BinaryNode* p) { //VLR
	if (p != NULL) {
		cout << p->item << " ";
		Pre_OrderTraverse(p->left);
		Pre_OrderTraverse(p->right);
	}

}

void BinaryTree::Pre_OrderPrint() {

	if (isEmpty()) {
		cout << "Tree is Empty" << endl;
		return;
	}
	cout << "Pre-order Tree Print now is: [ ";
	Pre_OrderTraverse(root);
	cout << "]" << endl;
}

void BinaryTree::In_OrderTraverse(BinaryNode* p) {  //LVR
	if (p != NULL) {
		In_OrderTraverse(p->left);
		cout << p->item << " ";
		In_OrderTraverse(p->right);
	}
}

void BinaryTree::In_OrderPrint() {
	if (isEmpty()) {
		cout << "Tree is Empty" << endl;
		return;
	}
	cout << "In-order Tree Print now is: [ ";
	In_OrderTraverse(root);
	cout << "]" << endl;
}

void BinaryTree::Post_OrderTraverse(BinaryNode* p) {  //LRV
	if (p != NULL) {
		Post_OrderTraverse(p->left);
		Post_OrderTraverse(p->right);
		cout << p->item << " ";
	}
}

void BinaryTree::Post_OrderPrint() {
	if (isEmpty()) {
		cout << "Tree is Empty" << endl;
		return;
	}
	cout << "Post-order Tree Print now is: [ ";
	Post_OrderTraverse(root);
	cout << "]" << endl;
}

void BinaryTree::Level_OrderTraverse(BinaryNode* p) {
	if (p == NULL) {
		cout << "Tree is Empty" << endl;
	}else{
		queue<BinaryNode*> DiscoveredQ;
		DiscoveredQ.push(p);
		while (!DiscoveredQ.empty()) {
			BinaryNode* curr = DiscoveredQ.front();
			cout << curr->item << " ";
			if (curr->left != NULL) DiscoveredQ.push(curr->left);
			if (curr->right != NULL)DiscoveredQ.push(curr->right);
			DiscoveredQ.pop();
		}
	}
}

void BinaryTree::Level_OrderPrint() {
	cout << "Level-order Tree Print now is: [ ";
	Level_OrderTraverse(root);
	cout << "]" << endl;
}




//f you do not use the & (reference) in the parameters of your AddNewNodeRec function, 
// you will run into several issues because the function will only modify a local copy of the pointer, 
// not the actual tree structure. Let’s explore why the & is necessary and what could go wrong without it.
void BinaryTree::AddNewNodeRec(BinaryNode*& newNode, BinaryNode*& currNode) {
	if (currNode == NULL) {
		currNode = newNode;
		return; //to prevent further execution  after the if condition is satisfied
	}

	// Recursive calls
	if (newNode->item > currNode->item) {
		AddNewNodeRec(newNode, currNode->right);
	}
	else {
		AddNewNodeRec(newNode, currNode->left);
	}
}

void BinaryTree::InsertValRec(int val) {

	if (searchValRecHelper(root, val)) {
		cout << val << " Already exists in the BST!" << endl;
		return; // to stop further execution
	}
	BinaryNode* newNodeTreeptr = new BinaryNode;
	newNodeTreeptr->item = val;
	newNodeTreeptr->left = newNodeTreeptr->right = NULL;

	//Calling the helper private function to recursively insert the new node
	AddNewNodeRec(newNodeTreeptr, root);
}

bool BinaryTree::searchValRecHelper(BinaryNode* currNode, int val) {
	if (currNode == NULL) {
		return false;
	 }
	if (currNode->item == val) {
		return true;
	}

	if (currNode->item > val) {
		searchValRecHelper(currNode->left, val);
	}
	else {
		searchValRecHelper(currNode->right, val);
	}
}

bool BinaryTree::searchValRec(int val) {
	return searchValRecHelper(root, val);
}

bool BinaryTree::SearchValIter(int val) {
	if (isEmpty()) {
		cout << "Tree is Empty" << endl;
	}
	BinaryNode* currNode = root;
	bool found = false;

	while (currNode != NULL) {
		if (currNode->item == val) {
			found = true;
			break; // leave the while loop
		 }
		if (currNode->item > val) {
			currNode = currNode->left;
		}
		else {
			currNode = currNode->right;
		}
	}

	return found;
}

void BinaryTree::InsertValIter(int val) {
	
	if (searchValRecHelper(root, val)) {
		cout << val << " Already exists in the BST!" << endl;
		return; // to stop further execution
	}

	BinaryNode* NewNodePtr = new BinaryNode;
	NewNodePtr->item = val;
	NewNodePtr->left = NewNodePtr->right = NULL;
	
	BinaryNode* curr = root; 
	BinaryNode* trailCurr = NULL;

	if (root == NULL) {
		root = NewNodePtr;
	}
	else {
		curr = root;
		while (curr != NULL)
		{
			trailCurr = curr;
			// root < val ; traverse right  L <= V < R 
			if (curr->item < NewNodePtr->item) {
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		if (trailCurr->item > NewNodePtr->item) {
			trailCurr->left = NewNodePtr;
		}
		else {
			trailCurr->right = NewNodePtr;
		}
	}
}


void BinaryTree::Find_MaxNode() { //Furtherest Right
	BinaryNode* curr = root;

	if (curr == NULL) {
		cout << "Tree is Empty!" << endl;
		return;
	}
	while (curr->right != NULL) {
		curr = curr->right;
	}
	cout << "Max Node value is: " << curr->item << endl;
}

void BinaryTree::Find_MinNode() { //Furhtest Left
	BinaryNode* curr = root;
	if (curr == NULL) {
		cout << "Tree is Empty!" << endl;
		return;
	}
	while (curr->left != NULL) {
		curr = curr->left;
	}
	cout << "Min Node value is: " << curr->item << endl;
}



// Max Height of a Tree Helper Functions

//Max Function to get max height between the subtrees for the Tree Height
int BinaryTree::MaxHeight(int x, int y) {
	if (x >= y) {
		return x;
	}
	else {
		return y;
	}
}

int BinaryTree::TreeHeightHelper(BinaryNode* CurrNode) {
	if (CurrNode == NULL) {
		return -1; //Base Case , Empty Tree Height is -1
	}

	int LeftHeight = TreeHeightHelper(CurrNode->left);
	int RightHeight = TreeHeightHelper(CurrNode->right);

	return  1 + MaxHeight(LeftHeight, RightHeight);
}

void BinaryTree::TreeHeight() {
	cout << "The Tree Height is " << TreeHeightHelper(root) << endl;
}

int BinaryTree::LeavesCountHelper(BinaryNode* CurrNode) {
	if (CurrNode == NULL) {
		return 0;
	}
	else if ((CurrNode->left == NULL) && (CurrNode->right == NULL)) { // Reaching a leave
		return 1;
	}
	else { //Recursion to the depth nodes to reach a leave recursively and keep counting up
		return LeavesCountHelper(CurrNode->left) + LeavesCountHelper(CurrNode->right);
	}
}
void BinaryTree::LeavesCount() {
	cout << "Number of Leaves Nodes : " << LeavesCountHelper(root) << endl;
}

int BinaryTree::TreeNodesCountHelper(BinaryNode* CurrNode) {
	if (CurrNode == 0) {
		return 0;
	}
	else {
		return 1 + TreeNodesCountHelper(CurrNode->left) + TreeNodesCountHelper(CurrNode->right);
	}
}

void BinaryTree::TreeNodesCount() {
	cout << "Number of  Nodes in the Tree : " << TreeNodesCountHelper(root) << endl;
}

BinaryTree::BinaryNode* BinaryTree::FindMin_Successor(BinaryNode* CurrNode) {
	while (CurrNode->left != NULL) {
		CurrNode = CurrNode->left;
	}
	return CurrNode;
}

BinaryTree::BinaryNode* BinaryTree::DeleteNodeHelper(BinaryNode* CurrNode, int val) {
	if (CurrNode == NULL) {
		cout << "Not Found in the Tree!" << endl;
		return CurrNode;  // to stop further execution
	}

	if (val < CurrNode->item) {
		CurrNode->left = DeleteNodeHelper(CurrNode->left, val);
	}
	else if(val >CurrNode->item){
		CurrNode->right = DeleteNodeHelper(CurrNode->right, val);
	}
	else {
		//Node to be deleted is found

		cout << "Deleteing Node with Value " << val << endl;
		//Case 1: Node is a leaf (no children)
		if (CurrNode->left == NULL && CurrNode->right == NULL) {
			delete CurrNode;
			return NULL;
		}
		// Case 2: Node has 1 child (Left or Right)
		else if (CurrNode->left == NULL) {
			BinaryNode* temp = CurrNode->right;
			delete CurrNode;
			return temp;
		}
		else if (CurrNode->right == NULL) {
			BinaryNode* temp = CurrNode->left;
			delete CurrNode;
			return temp;
		}
		 //Case 3: Node Has 2 Children (Left and Right) --> Finding the Successor (min value of the right sub-tree)
		else {

			// Finding the In-Order Successsor (smallest vale in the right subtree)
			BinaryNode* Successor = FindMin_Successor(CurrNode->right);

			// Repalce the Current Node's value with the Successor's value
			CurrNode->item = Successor->item;

			//Recurslively delete the In-Order Successor
			CurrNode->right = DeleteNodeHelper(CurrNode->right, Successor->item);

		}
	}
	return CurrNode;
}

void BinaryTree::DeleteNode(int val) {
	root = DeleteNodeHelper(root, val);
}

void BinaryTree::ClearTreeHelper(BinaryNode* CurrNode) {
	
	if (CurrNode == NULL) {
		return; // Base Case; if the CurrNode is Null, do nothing
	}

	ClearTreeHelper(CurrNode->left);
	ClearTreeHelper(CurrNode->right);

	//Deleteing the Current Node
	cout << "Deleteing Node with Value " << CurrNode->item << endl;
	delete CurrNode;

}

void BinaryTree::ClearTree() {
	ClearTreeHelper(root); // Clear the tree starting from the root
	root = NULL;           // Set root to NULL to indicate an empty tree
}

BinaryTree::~BinaryTree() {
	cout << "Destructor called. Clearing the tree..." << endl;
	ClearTree();
}
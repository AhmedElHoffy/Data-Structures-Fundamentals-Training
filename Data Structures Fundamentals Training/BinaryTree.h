#ifndef BINARYTREE_H
#define BINARYTREE_H
class BinaryTree
{
	struct BinaryNode {
		int item;
		BinaryNode* left, * right;
	};
	BinaryNode* root;

	// Helper function to ahndle the recursion of the insertion of new value in the tree
	void AddNewNodeRec(BinaryNode*& newNode, BinaryNode*& root);

	// Depth First Traversal Helper Functions
	void Pre_OrderTraverse(BinaryNode* p);
	void In_OrderTraverse(BinaryNode* p);
	void Post_OrderTraverse(BinaryNode* p);

	//Breadth First Traversal Helper Function
	void Level_OrderTraverse(BinaryNode* p);

	//Search for a value recursively Helper function
	bool searchValRecHelper(BinaryNode* root, int val);

	// Counting the number of leaves Nodes helper function
	int LeavesCountHelper(BinaryNode* currNode);

	//Counting Number of Nodes in th Tree helper function
	int TreeNodesCountHelper(BinaryNode* CurrNode);


	// Max height between left and right subtree to help in determining the height of the tree
	int MaxHeight(int x, int y);
	// Function to traverse in Tree Nodes to determine the height
	int TreeHeightHelper(BinaryNode* CurrNode);

	//Delete Node Functions helper
	BinaryNode* DeleteNodeHelper(BinaryNode* CurrNode, int val);
	BinaryNode* FindMin_Successor(BinaryNode* CurrNode);


	void ClearTreeHelper(BinaryNode* CurrNode);


public:
	
	BinaryTree();
	~BinaryTree();
	bool isEmpty();

	// Insert value recursively
	void InsertValRec(int val);
	//Insert Value Interatively
	void InsertValIter(int val);


	//Search for a value recursively
	bool searchValRec(int val);
	//Search for a value Iteratively
	bool SearchValIter(int val);

	//Print Tree Orders
	void Pre_OrderPrint();
	void In_OrderPrint();
	void Post_OrderPrint();
	void Level_OrderPrint();

	// Mas/Min Node, Leaves count, Tree height, Tree Nodes Count
	void Find_MaxNode();
	void Find_MinNode();
	void LeavesCount();
	void TreeHeight();
	void TreeNodesCount();

	//Delete a specific Node from the Tree and Replace it with a sucessor if applicable
	void DeleteNode(int val);

	void ClearTree();



};

#endif //BINARYTREE_H

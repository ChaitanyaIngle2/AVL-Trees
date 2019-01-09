// Chaitanya Ingle
// Section 1002
// Ast. 05
//
// FILE: avlTree.h
// DESCRIPTION: Header file for avlTree template class with implementations. Also includes
// 		nodeType template struct used in avlTree class. 
//
//
//
// ----- STRUCT USED -----
// 
// 
// template <class myType>
// struct nodeType 
// 		{
//		myType keyValue;
//		nodeType<myType> *left;
//		nodeType<myType> *right;
//		};
//
// 	- Node for use in avlTree class. keyValue holds data item, left contains pointer to
//	nodeType with lesser data item, right contains pointer to pointer to nodeType with 
//	keyValue of higher value.
//
//
//
// ---------------CLASS OVERVIEW---------------
//
//
//
// ----- PRIVATE DATA MEMBERS -----
//
//
//
// nodeType<myType> *root
//	- Pointer of nodeType to root of avl Tree.
//
//
// ----- CONSTRUCTOR AND DESTRUCTOR
//
//
// avlTree()
//	- Initializes empty avl Tree.
//	
// ~avlTree()
//	- Releases used memory by calling public destroyTree().
//
//
//
// ----- PUBLIC FUNCTIONS -----
//
//
//
// void destroyTree()
//	- Releases used memory by calling private destroyTree().
//
// int countNodes() const
//	- Returns number of nodes in avlTree by calling private countNodes().
// 
// int height() const
//	- Returns maxiumum height of of tree by calling private height().
//
// bool search(myType target) const
//	- Searches tree for target value by calling private search() function. 
//	  Returns true if found and false if not.
//
// void printTree() const
//	- Prints tree by calling private printTree().
//
// void insert(myType newItem)
// 	- Inserts newItem by calling private insert().
//
//
//
// ----- PRIVATE FUNCTIONS -----
//
//
//
// void destroyTree(nodeType<myType>* rNode)
// 	- Destroys tree starting at rNode recursively. Destroys tree by destroying
//	  all trees on left and right and then node for each sub tree.
//
// int countNodes(nodeType<myType>* rNode) const
// 	- Counts total number of nodes for tree starting at rNode via recursion.
//
// int height(nodeType<myType>* rNode) const
//	- Finds height of tree starting at rNode via recursion. Returns highest height
//	  for each subtree all the way until root.
//
// nodeType<myType>* search(myType tData, nodeType<myType>* rNode) const
//	- Searches the tree starting at rNode for tData. Returns NULL to public search()
//	  if tData is not found, indicating a miss. Returns some address if tData is
//	  found, indicating a hit.
//
// void printTree(nodeType<myType>* rNode) const
//	- Prints the tree starting at rNode recursively and in pre-order format.
//
// nodeType<myType>* insert(myType nData, nodeType<myType>* rNode)
// 	- inserts nData into tree starting at rNode via recursion. If nData already exists
//	  in tree, nothing happens. After nData is inserted, as the tree is recursed 
//	  through, balance is checked at each level. If tree is ever found to be
//	  unbalanced, it is rebalanced through the calling of rightRotate() and
//	  leftRotate() appropriately.
//
// nodeType<myType>* rightRotate(nodeType<myType>* x)
// 	- Performs a right tree rotate operation. Is only called during insert().
//
// nodeType<myType>* leftRotate(nodeType<myType>* x)
//	- Performs a left tree rotate operation. Is only called during insert().
//
// int getBalance(nodeType<myType>* rNode) const
// 	- Returns the balance factor (left subtree height – right subtree height) 
//	  of tree starting at rNode.




#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>

using namespace std;


template <class myType>
struct nodeType 
{
	myType keyValue;
	nodeType<myType> *left;
	nodeType<myType> *right;
};

template <class myType>
class avlTree
{
	public:

	// CONSTRUCTOR AND DESTRUCTOR

	avlTree();
	~avlTree();

	// PUBLIC FUNCTIONS

	void destroyTree();
	int countNodes() const;
	int height() const;
	bool search(myType target) const;
	void printTree() const;
	void insert(myType newItem);

	private:

	// PRIVATE DATA MEMBERS

	nodeType<myType> *root;

	// PRIVATE FUNCTIONS

	void destroyTree(nodeType<myType>* rNode);
	int countNodes(nodeType<myType>* rNode) const;
	int height(nodeType<myType>* rNode) const;
	nodeType<myType>* search(myType tData, nodeType<myType>* rNode) const;
	void printTree(nodeType<myType>* rNode) const;
	nodeType<myType>* insert(myType nData, nodeType<myType>* rNode);
	nodeType<myType>* rightRotate(nodeType<myType>* x);
	nodeType<myType>* leftRotate(nodeType<myType>* x);
	int getBalance(nodeType<myType>* rNode) const;

};


// --------------- Implementations for template class avlTree --------------- 



// ---------- Constructor and Destructor ----------



// ********************
// avlTree()
//	- Initializes empty avl Tree.

template <class myType>
avlTree<myType>::avlTree()
{

	root = NULL;

}

// ********************
// ~avlTree()
//	- Releases used memory by calling public destroyTree().

template <class myType>
avlTree<myType>::~avlTree()
{

	destroyTree();

}



// ---------- Public Functions ----------



// ********************
// void destroyTree()
//	- Releases used memory by calling private destroyTree().

template <class myType>
void avlTree<myType>::destroyTree()
{

	destroyTree(root);
	root = NULL;

}

// ********************
// int countNodes() const
//	- Returns number of nodes in avlTree by calling private countNodes().

template <class myType>
int avlTree<myType>::countNodes() const
{

	return countNodes(root);

}

// ********************
// int height() const
//	- Returns maxiumum height of of tree by calling private height().

template <class myType>
int avlTree<myType>::height() const
{

	return height(root);

}

// ********************
// bool search(myType target) const
//	- Searches tree for target value by calling private search() function. 
//	  Returns true if found and false if not.

template <class myType>
bool avlTree<myType>::search(myType target) const
{

	if (search(target, root) == NULL)
		return false;
	else
		return true;

}

// ********************
// void printTree() const
//	- Prints tree by calling private printTree().

template <class myType>
void avlTree<myType>::printTree() const
{
	cout<< "  ";
	printTree(root);
	cout<< endl;

}

// ********************
// void insert(myType newItem)
// 	- Inserts newItem by calling private insert().

template <class myType>
void avlTree<myType>::insert(myType newItem)
{

	root = insert(newItem, root);

}



// ---------- Private Functions ----------



// ********************
// void destroyTree(nodeType<myType>* rNode)
// 	- Destroys tree starting at rNode recursively. Destroys tree by destroying
//	  all trees on left and right and then node for each sub tree.

template <class myType>
void avlTree<myType>::destroyTree(nodeType<myType>* rNode)
{

	if (rNode == NULL)
		return;
	else {
		destroyTree(rNode->left);
		destroyTree(rNode->right);
		delete rNode;
		return;
	}

}

// ********************
// int countNodes(nodeType<myType>* rNode) const
// 	- Counts total number of nodes for tree starting at rNode via recursion.

template <class myType>
int avlTree<myType>::countNodes(nodeType<myType>* rNode) const
{
	if (rNode == NULL)
		return 0;
	else 
		return countNodes(rNode->left) + countNodes(rNode->right) + 1;

}

// ********************
// int height(nodeType<myType>* rNode) const
//	- Finds height of tree starting at rNode via recursion. Returns highest height
//	  for each subtree all the way until root.

template <class myType>
int avlTree<myType>::height(nodeType<myType>* rNode) const
{

	int leftHeight, rightHeight;
	if (rNode == NULL)
		return 0;
	else {
		leftHeight = height(rNode->left);
		rightHeight = height(rNode->right);
		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else 
			return rightHeight + 1;
	}

}

// ********************
// nodeType<myType>* search(myType tData, nodeType<myType>* rNode) const
//	- Searches the tree starting at rNode for tData. Returns NULL to public search()
//	  if tData is not found, indicating a miss. Returns some address if tData is
//	  found, indicating a hit.

template <class myType>
nodeType<myType>* avlTree<myType>::search(myType tData, nodeType<myType>* rNode) const
{

	nodeType<myType>* result = NULL;
	if (rNode == NULL)
		return result;
	while (rNode != NULL) {
		if (tData == rNode->keyValue) {
			result = rNode;
			break;
		}
		else {
			if (tData > rNode->keyValue)
				rNode = rNode->right;
			else
				rNode = rNode->left;
		} 
	}
	
	return result;
			
}

// ********************
// void printTree(nodeType<myType>* rNode) const
//	- Prints the tree starting at rNode recursively and in pre-order format.

template <class myType>
void avlTree<myType>::printTree(nodeType<myType>* rNode) const
{

	if (rNode == NULL)
		return;
	else {
		cout<< rNode->keyValue<< "  ";
		printTree(rNode->left);
		printTree(rNode->right);
	}

}

// ********************
// nodeType<myType>* insert(myType nData, nodeType<myType>* rNode)
// 	- inserts nData into tree starting at rNode via recursion. If nData already exists
//	  in tree, nothing happens. After nData is inserted, as the tree is recursed 
//	  through, balance is checked at each level. If tree is ever found to be
//	  unbalanced, it is rebalanced through the calling of rightRotate() and
//	  leftRotate() appropriately.

template <class myType>
nodeType<myType>* avlTree<myType>::insert(myType nData,nodeType<myType>* rNode)
{

	nodeType<myType>* newNode;
	if (rNode == NULL) {                // creates new node with nData if NULL is reached
		newNode = new nodeType<myType>;
		newNode->keyValue = nData;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	// Decides which way to go in tree based on value
	
	if (nData < rNode->keyValue)        
		rNode->left = insert(nData, rNode->left);
	else 
		rNode->right = insert(nData, rNode->right);

	// Balance tree if needed.

	int bFact = getBalance(rNode);
	if (bFact > 1 && nData < rNode->left->keyValue)
		return rightRotate(rNode);

	if (bFact < -1 && nData > rNode->right->keyValue)
		return leftRotate(rNode);

	if (bFact > 1 && nData > rNode->left->keyValue) {
		rNode->left = leftRotate(rNode->left);
		return rightRotate(rNode);
	}

	if (bFact < -1 && nData < rNode->right->keyValue) {
		rNode->right = rightRotate(rNode->right);
		return leftRotate(rNode);
	}

	return rNode;

}

// ********************
// int getBalance(nodeType<myType>* rNode) const
// 	- Returns the balance factor (left subtree height – right subtree height) 
//	  of tree starting at rNode.

template <class myType>
int avlTree<myType>::getBalance(nodeType<myType>* rNode) const
{

	return height(rNode->left) - height(rNode->right);

}

// ********************
// nodeType<myType>* leftRotate(nodeType<myType>* x)
//	- Performs a left tree rotate operation. Is only called during insert().

template <class myType>
nodeType<myType>* avlTree<myType>::leftRotate(nodeType<myType>* x)
{

	nodeType<myType>* y = x->right;
	nodeType<myType>* tmp = y->left;

	y->left = x;
	x->right = tmp;
	return y;

} 

// ********************
// nodeType<myType>* rightRotate(nodeType<myType>* x)
// 	- Performs a right tree rotate operation. Is only called during insert().

template <class myType>
nodeType<myType>* avlTree<myType>::rightRotate(nodeType<myType>* x)
{

	nodeType<myType>* y = x->left;
	nodeType<myType>* tmp = y->right;

	y->right = x;
	x->left = tmp;
	return y;

} 





#endif

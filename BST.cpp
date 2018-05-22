/*
Joshua Anaya
CST 370
Final
02.21.18
BST functions outlined below
*/

#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
	: myRoot(0)
{}

bool BST::empty() const
{
	return myRoot == 0;
}

void BST::NewSearch(const int &item)
{
	BinNode * locptr = myRoot;
	int num = 50;//initialize num for compare
	bool found = false;
	while (!found && locptr != 0)//search BST for item
	{
		if (item < locptr->data && num > locptr->data)//num updated if closer number to item found
			num = locptr->data;

		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
		{
			num = locptr->data;//num updated if item found
			found = true;

		}
	}

	//output for results
	if (found)
		cout << "Chosen number found in array." << endl;
	else if (num != 50 && !found)
		cout << "Chosen number not found but " << num << " was the closest in the array." << endl;
	else
		cout << "Chosen number not found and larger than any number in array." << endl;
}
bool BST::search(const int & item) const
{
	BinNode * locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	return found;
}

int BST::LeafHeights()
{
	return LeafHeight(myRoot);//call LeafHeight
}

int BST::LeafHeight(BinNode *root)
{
	//check for root
	if (root == NULL)
	{
		return 0;
	}

	if (!root->left && !root->right)//if no children, print 
	{
		cout << "Height of Leaf " << root->data << ": " << LeafHeight(root->left)	
			+ LeafHeight(root->right) +1 << endl;
	}
	if (root->left)//if child continue
	{
		LeafHeight(root->left);
	}
	if (root->right)
	{
		LeafHeight(root->right);
	}
	

}

void BST::insert(const int & item)
{
	BinNode * locptr = myRoot;   // search pointer
	BinNode * parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new BinNode(item);
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else
		cout << "Item already in the tree\n";
}

void BST::inOrder()//public function to call private
{
	return inOrders(myRoot);
}

void BST::inOrders(BinNode *root) //print left, root, then right
{

	if (root == NULL)
		return;
	inOrders(root->left);
	printf("%d ", root->data);
	inOrders(root->right);
}


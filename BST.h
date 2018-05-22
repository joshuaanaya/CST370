/*
Joshua Anaya
CST 370
Final
02.21.18
Header file declaring functions
*/
#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
public:
	/***** Function Members *****/
	BST();
	bool empty() const;
	void NewSearch(const int & item);
	bool search(const int & item) const;
	int LeafHeights();
	
	void insert(const int & item);

	void inOrder();

	

private:
	/***** Node class *****/
	class BinNode
	{
	public:
		int data;
		BinNode * left;
		BinNode * right;

		// BinNode constructors
		// Default -- data part is default int value; both links are null.
		BinNode()
			: left(0), right(0)
		{}

		// Explicit Value -- data part contains item; both links are null.
		BinNode(int item)
			: data(item), left(0), right(0)
		{}

	};// end of class BinNode declaration

	  /***** Data Members *****/
	BinNode * myRoot;
	void inOrders(BinNode * root);
	int LeafHeight(BinNode * root);
	
}; // end of class declaration

#endif
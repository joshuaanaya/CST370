/*----- treetester.cpp -----------------------------------------------------
Joshua Anaya
CST 370
02.21.18
Final Parts #1-4
Balanced BST - Achieved by sorting array and using median as root
inOrder - dispaly BST left, root, right
LeafHeight - find leaf(no children) and display height
NewSearch - input number compared to BST and either returned found, the closest number 
			larger in the array, or chosen number larger than any number in array. 
------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"


void SelectionSort(int A[], int n)
{
	//iterate through elements to n-1
	for (int i = 0; i < n - 1; i++)
	{
		//min is the minimum position
		int min = i;
		//iterate through A to compare min(first element) 
		// to each element after to find the minimum
		for (int j = i + 1; j < n; j++)
		{
			//compare 
			if (A[j] < A[min])
				//update min if j is smaller
				min = j;
		}
		//swap min and i position
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
	int mid = (0 + n) / 2;
	int temp = A[0];
	A[0] = A[mid];
	A[mid] = temp;
	//Print sorted array
	cout << "Sorted Array Function:";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}



int main()
{
	// Testing Constructor and empty()
	int c; 
	BST intBST;            // test the class constructor
	int A[] = { 4, 6, 8, 15, 20, 22, 10, 3, 9, 2 };
	int count = sizeof(A) / sizeof(A[0]);
	SelectionSort(A, count); //sort array for balanced tree
	for (int i = 0; i < count; i++)
	{
		intBST.insert(A[i]);//insert into BST
	}
	c = intBST.LeafHeights();
	
	cout << "inOrder:";//display BST inOrder
	intBST.inOrder();
	cout << endl;
	cout << "Choose a number: ";//choose number for NewSearch()
	cin >> c;
	intBST.NewSearch(c);
	
}
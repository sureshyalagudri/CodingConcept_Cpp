#include <iostream>
#include<string.h>
#include<iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	cout << "Start Main" << endl;
	
	/*
	Let us create following BST
				50
			 /      \
			30	    70
	      /  \     /  \
	     20   40  60   80 
	*/

	BinaryTree *myTree = new BinaryTree();
	Tree * node = myTree->InsertData(NULL, 50);
	myTree->InsertData(node, 30);
	myTree->InsertData(node, 20);
	myTree->InsertData(node, 40);
	myTree->InsertData(node, 70);
	myTree->InsertData(node, 60);
	myTree->InsertData(node, 80);
	
	myTree->PrintData(node);
	myTree->DeleteData(node);

	cout << "End Main" << endl;
	return 0;
}
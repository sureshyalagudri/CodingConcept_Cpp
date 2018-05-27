#pragma once
#include <stdio.h>
#include<iostream>
using namespace std;

struct Tree
{
	int data=0;
	Tree * Left=NULL;
	Tree * Right=NULL;
};
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	Tree * GetNewNode(int val);
	Tree * InsertData(Tree * node, int val);
	void PrintData(Tree * node);
	void DeleteData(Tree * node);
};


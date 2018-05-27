#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}

Tree * BinaryTree::GetNewNode(int val)
{
	Tree * newNode = new Tree();
	newNode->data = val;
	newNode->Left = NULL;
	newNode->Right = NULL;

	return newNode;
}

Tree * BinaryTree::InsertData(Tree * node, int val)
{
	if (node == NULL)
	{
		node = GetNewNode(val);
		return node;
	}
	else if (val < node->data)
	{
		node->Left = InsertData(node->Left, val);
	}
	else
	{
		node->Right = InsertData(node->Right, val);
	}

	return node;
}

void BinaryTree::PrintData(Tree * node)
{
	if (node != NULL)
	{
		PrintData(node->Left);
		cout << node->data << endl;
		PrintData(node->Right);
	}
}

void BinaryTree::DeleteData(Tree * node)
{
	if (node != NULL)
	{
		PrintData(node->Left);
		PrintData(node->Right);
	}
	delete node;
}

#include<iostream>

using namespace std;
#ifndef BITREE_H
#define BITREE_H

typedef int DataType;
struct BinaryTreeNode
{
	DataType data;
	BinaryTreeNode *m_leftChild;
	BinaryTreeNode *m_rightChild;
	BinaryTreeNode()
	{
		data = -1;
		m_leftChild = NULL;
		m_rightChild = NULL;
	}
};

class BinaryTree
{
public:
	BinaryTree() { m_root = NULL; }
	void Initial(DataType value = -1);
	void Pre_Order_TravelRecursive(BinaryTreeNode * root);
	void Pre_Order_TravelCycle(BinaryTreeNode * root);
	void Mid_Order_TravelRecursive(BinaryTreeNode * root);
	void Mid_Order_TravelCycle(BinaryTreeNode *root);
	void Post_Order_TravelRecursive(BinaryTreeNode * root);
	BinaryTreeNode *Insert2LeftNode(BinaryTreeNode *root, DataType value);
	BinaryTreeNode *Insert2RightNode(BinaryTreeNode *root, DataType value);
	bool Destroy(BinaryTreeNode *root);
private:
	BinaryTreeNode *m_root;
};
























#endif // !BITREE_H

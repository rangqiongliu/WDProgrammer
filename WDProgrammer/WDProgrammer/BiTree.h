/*
文件说明：BiTree.h和BiTree.cpp主要是声明和实现一些有关二叉树的函数。

*/
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
	/*
	函数1：
	函数功能：初始化一个二叉树的根节点
	函数入口：由对象调用，如果形参为空，则默认将根节点看做二叉树的头结点，如果不为空，则跟节点不为空
	*/
	void Initial(DataType value = -1);

	/*
	函数2：
	函数功能：利用递归的方法先序遍历以root为节点的二叉树
	函数入口：需要遍历的二叉树的根节点
	函数出口：直接将数据打印在屏幕上
	*/
	void Pre_Order_TravelRecursive(BinaryTreeNode * root);

	/*
	函数3：
	函数功能：利用循环的方法先序遍历以root为节点的二叉树
	函数入口：需要遍历的二叉树的根节点
	函数出口：直接将数据打印在屏幕上
	*/
	void Pre_Order_TravelCycle(BinaryTreeNode * root);


	/*
	函数4：
	函数功能：利用递归的方法中序遍历以root为节点的二叉树
	函数入口：需要遍历的二叉树的根节点
	函数出口：直接将数据打印在屏幕上
	*/
	void Mid_Order_TravelRecursive(BinaryTreeNode * root);

	/*
	函数5：
	函数功能：利用循环的方法中序遍历以root为节点的二叉树
	函数入口：需要遍历的二叉树的根节点
	函数出口：直接将数据打印在屏幕上
	*/
	void Mid_Order_TravelCycle(BinaryTreeNode *root);
	/*
	
	*/
	void Post_Order_TravelRecursive(BinaryTreeNode * root);
	/*
	
	*/
	BinaryTreeNode *Insert2LeftNode(BinaryTreeNode *root, DataType value);
	/*
	
	*/
	BinaryTreeNode *Insert2RightNode(BinaryTreeNode *root, DataType value);
	/*
	
	*/
	bool Destroy(BinaryTreeNode *root);
private:
	BinaryTreeNode *m_root;
};
























#endif // !BITREE_H

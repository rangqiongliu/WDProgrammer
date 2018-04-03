/*
文件说明：BiTree.h和BiTree.cpp主要是声明和实现一些有关二叉树的函数。

*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
#ifndef BITREE_H
#define BITREE_H

typedef string DataType;
struct BinaryTreeNode
{
	DataType data;
	BinaryTreeNode *m_leftChild;
	BinaryTreeNode *m_rightChild;
	BinaryTreeNode()
	{
		data = '\0';
		m_leftChild = NULL;
		m_rightChild = NULL;
	}
};

class BinaryTree
{
public:
	BinaryTree() { m_root = NULL; }
	BinaryTreeNode * getRoot()
	{
		return m_root;
	}
	/*
	函数1：
	函数功能：初始化一个二叉树的根节点
	函数入口：由对象调用，如果形参为空，则默认将根节点看做二叉树的头结点，如果不为空，则跟节点不为空
	*/
	void Initial(DataType value = '\0');

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
	函数6：
	函数功能：利用递归的方法后序遍历以root为节点的二叉树
	函数入口：需要遍历的二叉树的根节点
	函数出口：直接将数据打印在屏幕上
	*/
	void Post_Order_TravelRecursive(BinaryTreeNode * root);

	/*
	函数7：/////TO DO
	函数功能：利用循环的方法后序遍历以root为节点的二叉树
	函数入口：需要遍历的二叉树的根节点
	函数出口：直接将数据打印在屏幕上
	*/
	void Post_Order_TravelCycle(BinaryTreeNode * root);

	/*
	函数8：
	函数功能：将value插入root的左子节点
	函数入口：root：需要插入的父节点，value：需要插入的数据
	函数出口：将最终插入成功的左子节点地址返回
	*/
	BinaryTreeNode *Insert2LeftNode(BinaryTreeNode *root, DataType value);

	/*
	函数9：
	函数功能：将value插入root的右子节点
	函数入口：root：需要插入的父节点，value：需要插入的数据
	函数出口：将最终插入成功的右子节点地址返回
	*/
	BinaryTreeNode *Insert2RightNode(BinaryTreeNode *root, DataType value);

	/*
	函数10：
	函数功能：将root及其子树都销毁掉
	函数入口：需要销毁树的根节点
	函数出口：如果成功销毁则返回true，否则false
	*/
	bool Destroy(BinaryTreeNode *root);

	/*
	函数11：
	函数功能：在root二叉树中通过先序遍历搜索value值，如果有value值，则输出所在节点的地址，如果无，则返回空
	函数入口：root为需要搜寻的树，value需要查找的值,
	函数出口：res为结果带回的出口，把所有拥有value的节点地址都返回
	*/
	void Search(BinaryTreeNode* root, DataType value, vector<BinaryTreeNode*> &res);

	/*
	函数12：
	函数功能：在root二叉树中，寻找节点p、节点q的最小公共祖先
	函数入口：需要寻找树的根节点，需要寻找的两个节点
	函数出口：将最小公共祖先的地址返回
	*/
	BinaryTreeNode * lowestCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* p, BinaryTreeNode * q);

	void Route(BinaryTreeNode* sour, BinaryTreeNode* des, vector<BinaryTreeNode *> &resList);

	/*
	函数13：
	函数功能：计算一颗二叉树的深度（只有一个节点的深度为1）
	函数入口：要计算的二叉树高度的根节点：root
	函数出口：将root的二叉树深度返回
	*/
	int getTreeDepth(BinaryTreeNode *root);

	/*
	函数14：
	函数功能：计算一个颗二叉树中两个节点最远距离
	函数入口：需要计算的二叉树根节点：root
	函数出口：函数返回root中两个节点的最远距离
	说明：计算一颗二叉树中两个节点的最远距离，其实就是求root左子树的深度和右子树深度之和。
	*/
	int getMaxDis(BinaryTreeNode * root);
private:

	BinaryTreeNode *m_root;

};
























#endif // !BITREE_H

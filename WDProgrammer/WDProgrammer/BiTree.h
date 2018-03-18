/*
�ļ�˵����BiTree.h��BiTree.cpp��Ҫ��������ʵ��һЩ�йض������ĺ�����

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
	����1��
	�������ܣ���ʼ��һ���������ĸ��ڵ�
	������ڣ��ɶ�����ã�����β�Ϊ�գ���Ĭ�Ͻ����ڵ㿴����������ͷ��㣬�����Ϊ�գ�����ڵ㲻Ϊ��
	*/
	void Initial(DataType value = -1);

	/*
	����2��
	�������ܣ����õݹ�ķ������������rootΪ�ڵ�Ķ�����
	������ڣ���Ҫ�����Ķ������ĸ��ڵ�
	�������ڣ�ֱ�ӽ����ݴ�ӡ����Ļ��
	*/
	void Pre_Order_TravelRecursive(BinaryTreeNode * root);

	/*
	����3��
	�������ܣ�����ѭ���ķ������������rootΪ�ڵ�Ķ�����
	������ڣ���Ҫ�����Ķ������ĸ��ڵ�
	�������ڣ�ֱ�ӽ����ݴ�ӡ����Ļ��
	*/
	void Pre_Order_TravelCycle(BinaryTreeNode * root);


	/*
	����4��
	�������ܣ����õݹ�ķ������������rootΪ�ڵ�Ķ�����
	������ڣ���Ҫ�����Ķ������ĸ��ڵ�
	�������ڣ�ֱ�ӽ����ݴ�ӡ����Ļ��
	*/
	void Mid_Order_TravelRecursive(BinaryTreeNode * root);

	/*
	����5��
	�������ܣ�����ѭ���ķ������������rootΪ�ڵ�Ķ�����
	������ڣ���Ҫ�����Ķ������ĸ��ڵ�
	�������ڣ�ֱ�ӽ����ݴ�ӡ����Ļ��
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

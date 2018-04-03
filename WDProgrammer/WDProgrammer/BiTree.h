/*
�ļ�˵����BiTree.h��BiTree.cpp��Ҫ��������ʵ��һЩ�йض������ĺ�����

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
	����1��
	�������ܣ���ʼ��һ���������ĸ��ڵ�
	������ڣ��ɶ�����ã�����β�Ϊ�գ���Ĭ�Ͻ����ڵ㿴����������ͷ��㣬�����Ϊ�գ�����ڵ㲻Ϊ��
	*/
	void Initial(DataType value = '\0');

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
	����6��
	�������ܣ����õݹ�ķ������������rootΪ�ڵ�Ķ�����
	������ڣ���Ҫ�����Ķ������ĸ��ڵ�
	�������ڣ�ֱ�ӽ����ݴ�ӡ����Ļ��
	*/
	void Post_Order_TravelRecursive(BinaryTreeNode * root);

	/*
	����7��/////TO DO
	�������ܣ�����ѭ���ķ������������rootΪ�ڵ�Ķ�����
	������ڣ���Ҫ�����Ķ������ĸ��ڵ�
	�������ڣ�ֱ�ӽ����ݴ�ӡ����Ļ��
	*/
	void Post_Order_TravelCycle(BinaryTreeNode * root);

	/*
	����8��
	�������ܣ���value����root�����ӽڵ�
	������ڣ�root����Ҫ����ĸ��ڵ㣬value����Ҫ���������
	�������ڣ������ղ���ɹ������ӽڵ��ַ����
	*/
	BinaryTreeNode *Insert2LeftNode(BinaryTreeNode *root, DataType value);

	/*
	����9��
	�������ܣ���value����root�����ӽڵ�
	������ڣ�root����Ҫ����ĸ��ڵ㣬value����Ҫ���������
	�������ڣ������ղ���ɹ������ӽڵ��ַ����
	*/
	BinaryTreeNode *Insert2RightNode(BinaryTreeNode *root, DataType value);

	/*
	����10��
	�������ܣ���root�������������ٵ�
	������ڣ���Ҫ�������ĸ��ڵ�
	�������ڣ�����ɹ������򷵻�true������false
	*/
	bool Destroy(BinaryTreeNode *root);

	/*
	����11��
	�������ܣ���root��������ͨ�������������valueֵ�������valueֵ����������ڽڵ�ĵ�ַ������ޣ��򷵻ؿ�
	������ڣ�rootΪ��Ҫ��Ѱ������value��Ҫ���ҵ�ֵ,
	�������ڣ�resΪ������صĳ��ڣ�������ӵ��value�Ľڵ��ַ������
	*/
	void Search(BinaryTreeNode* root, DataType value, vector<BinaryTreeNode*> &res);

	/*
	����12��
	�������ܣ���root�������У�Ѱ�ҽڵ�p���ڵ�q����С��������
	������ڣ���ҪѰ�����ĸ��ڵ㣬��ҪѰ�ҵ������ڵ�
	�������ڣ�����С�������ȵĵ�ַ����
	*/
	BinaryTreeNode * lowestCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* p, BinaryTreeNode * q);

	void Route(BinaryTreeNode* sour, BinaryTreeNode* des, vector<BinaryTreeNode *> &resList);

	/*
	����13��
	�������ܣ�����һ�Ŷ���������ȣ�ֻ��һ���ڵ�����Ϊ1��
	������ڣ�Ҫ����Ķ������߶ȵĸ��ڵ㣺root
	�������ڣ���root�Ķ�������ȷ���
	*/
	int getTreeDepth(BinaryTreeNode *root);

	/*
	����14��
	�������ܣ�����һ���Ŷ������������ڵ���Զ����
	������ڣ���Ҫ����Ķ��������ڵ㣺root
	�������ڣ���������root�������ڵ����Զ����
	˵��������һ�Ŷ������������ڵ����Զ���룬��ʵ������root����������Ⱥ����������֮�͡�
	*/
	int getMaxDis(BinaryTreeNode * root);
private:

	BinaryTreeNode *m_root;

};
























#endif // !BITREE_H

#include"BiTree.h"

void BinaryTree::Initial(DataType value)
{
	m_root = new BinaryTreeNode;
	m_root->data = value;
}

BinaryTreeNode* BinaryTree::Insert2LeftNode(BinaryTreeNode *root, DataType value)
{
	if (NULL == root)
	{
		return NULL;
	}
	BinaryTreeNode *temp = new BinaryTreeNode;
	temp->data = value;
	temp->m_leftChild = root->m_leftChild;
	root->m_leftChild = temp;
	return temp;

}

BinaryTreeNode* BinaryTree::Insert2RightNode(BinaryTreeNode *root, DataType value)
{
	if (NULL == root)
	{
		return NULL;
	}
	BinaryTreeNode* temp = new BinaryTreeNode;
	temp->data = value;
	temp->m_rightChild = root->m_rightChild;
	root->m_rightChild = temp;
	return temp;
}

bool BinaryTree::Destroy(BinaryTreeNode *root)
{
	if (NULL == root) return true;
	Destroy(root->m_leftChild);
	Destroy(root->m_rightChild);
	delete root;//deleteһ��ָ��ʱ��ֻ���ͷŵ���ָ����ָ����ڴ棬����δ���ͷŵ�����˱�����ʹ��ָ��ָ��NULL,�Է���ΪҰָ��
	root = NULL;
	return true;
}

void BinaryTree::Pre_Order_TravelRecursive(BinaryTreeNode * root)
{
	if (NULL == root) return;
	cout << root->data << "  ";
	Pre_Order_TravelRecursive(root->m_leftChild);
	Pre_Order_TravelRecursive(root->m_rightChild);
}

void BinaryTree::Pre_Order_TravelCycle(BinaryTreeNode * root)
{
	if (NULL == root) return;
	BinaryTreeNode *cur = root;
	BinaryTreeNode *pre = NULL;
	while (cur != NULL)
	{
		
		//������������У��������ҽڵ������һ�������Ľڵ㣬�����ͨ���ƶ�pre��Ѱ��cur�����������������е�һ��Ҷ���ҽڵ㡣
		//ͨ�������ĵ�һ��Ҷ���ҽڵ�ָ����ڵ㣬���ܱ���������֮�����ܻص�����ýڵ㣬�Ӷ�ȥ��������һ�ߵĽڵ�
		if (cur->m_leftChild == NULL)//���û����ڵ�
		{
			cout << cur->data << "  ";
			cur = cur->m_rightChild;
		}
		else
		{
			pre = cur->m_leftChild;
			while (pre->m_rightChild != NULL && pre->m_rightChild != cur)
			{
				pre = pre->m_rightChild;//Ѱ��cur�����ĵ�һ��Ҷ���ҽڵ�
			}
			if (pre->m_rightChild == NULL)
			{
				pre->m_rightChild = cur;//ͨ��Ҷ�ӽڵ�ת�����������ĸ��ڵ�
				cout << cur->data << "  ";
				cur = cur->m_leftChild;
			}
			else
			{
				pre->m_rightChild = NULL;
				cur = cur->m_rightChild;
			}

		}
		
	}
}

void BinaryTree::Mid_Order_TravelRecursive(BinaryTreeNode * root)
{
	if (NULL == root) return;
	Mid_Order_TravelRecursive(root->m_leftChild);
	cout << root->data << "  ";
	Mid_Order_TravelRecursive(root->m_rightChild);
}

void BinaryTree::Mid_Order_TravelCycle(BinaryTreeNode *root)
{
	BinaryTreeNode* cur = root;
	BinaryTreeNode* pre = NULL;

	while (cur != NULL)
	{
		if (cur->m_leftChild == NULL)
		{
			cout << cur->data << "  ";
			cur = cur->m_rightChild;
		}
		else
		{
			pre = cur->m_leftChild;
			while (pre->m_rightChild!=NULL && pre->m_rightChild!=cur)
			{
				pre = pre->m_rightChild;
			}
			if (pre->m_rightChild == NULL)
			{
				pre->m_rightChild = cur;
				cur = cur->m_leftChild;
			}
			else
			{
				pre->m_rightChild = NULL;
				cout << cur->data << "  ";
				cur = cur->m_rightChild;
			}
		}
	}
}

void BinaryTree::Post_Order_TravelRecursive(BinaryTreeNode * root)
{
	if (root == NULL) return;
	Post_Order_TravelRecursive(root->m_leftChild);
	Post_Order_TravelRecursive(root->m_rightChild);
	cout << root->data << "  ";
}

void BinaryTree::Post_Order_TravelCycle(BinaryTreeNode * root)
{
	//��������ջ��ʵ�ֶԶ������ĺ������
	//��һ��ջ��myStack�ȴ�Ÿ��ڵ㡢�ҽڵ㡢�ӽڵ�
	//�ڶ���ջ��pareStacֻ��ŷ�Ҷ�ӽڵ�
	//�����һ��ջ��ջ��Ԫ�غ͵ڶ���ջ��ջ��Ԫ����ͬ����֤����Ԫ�ص��ӽڵ���������Ѿ������꣬��������ø��ڵ��ֵ
	stack<BinaryTreeNode*> myStack;
	stack<BinaryTreeNode*> pareStac;
	BinaryTreeNode *cur = root;
	myStack.push(cur);
	while(myStack.size()!=0)
	{
		cur = myStack.top();
		if (!pareStac.empty() && cur == pareStac.top())
		{
			cout << cur->data << "  ";
			myStack.pop();
			pareStac.pop();
			continue;
		}
		if (cur->m_leftChild != NULL || cur->m_rightChild != NULL)
		{
			pareStac.push(cur);
			if (cur->m_rightChild != NULL)
				myStack.push(cur->m_rightChild);
			if (cur->m_leftChild != NULL)
				myStack.push(cur->m_leftChild);
		}
		else
		{
			cout << cur->data << "  ";
			myStack.pop();
		}
	}
	
}

void  BinaryTree::Search(BinaryTreeNode* root, DataType value, vector<BinaryTreeNode*> &res)
{

	if (NULL == root) return ;
	BinaryTreeNode *cur = root;
	BinaryTreeNode *pre = NULL;
	while (cur != NULL)
	{
		
		//������������У��������ҽڵ������һ�������Ľڵ㣬�����ͨ���ƶ�pre��Ѱ��cur�����������������е�һ��Ҷ���ҽڵ㡣
		//ͨ�������ĵ�һ��Ҷ���ҽڵ�ָ����ڵ㣬���ܱ���������֮�����ܻص�����ýڵ㣬�Ӷ�ȥ��������һ�ߵĽڵ�
		if (cur->m_leftChild == NULL)//���û����ڵ�
		{
			//cout << cur->data << "  ";
			if (cur->data == value)
				res.push_back(cur);
			cur = cur->m_rightChild;
		}
		else
		{
			pre = cur->m_leftChild;
			while (pre->m_rightChild != NULL && pre->m_rightChild != cur)
			{
				pre = pre->m_rightChild;//Ѱ��cur�����ĵ�һ��Ҷ���ҽڵ�
			}
			if (pre->m_rightChild == NULL)
			{
				pre->m_rightChild = cur;//ͨ��Ҷ�ӽڵ�ת�����������ĸ��ڵ�
				//cout << cur->data << "  ";
				if (cur->data == value)
					res.push_back(cur);
				cur = cur->m_leftChild;
			}
			else
			{
				pre->m_rightChild = NULL;
				cur = cur->m_rightChild;
			}

		}

	}
}

void BinaryTree::Route(BinaryTreeNode* sour, BinaryTreeNode* des, BinaryTreeNode * &resList)
{
	    
}

BinaryTreeNode * BinaryTree::lowestCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* p, BinaryTreeNode * q)
{
	if (root == NULL || root == p || root == q) return root;

	BinaryTreeNode * left = lowestCommonAncestor(root->m_leftChild, p, q);

	BinaryTreeNode * right = lowestCommonAncestor(root->m_rightChild, p, q);

	if (left != NULL && right != NULL) return root;

	return left == NULL ? right : left;
}


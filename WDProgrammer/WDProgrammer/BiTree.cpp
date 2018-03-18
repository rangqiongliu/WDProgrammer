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
	delete root;//delete一个指针时，只会释放掉该指针所指向的内存，本身并未被释放掉。因此必须再使该指针指向NULL,以防成为野指针
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
		
		//由于先序遍历中：子树的右节点是最后一个遍历的节点，因此先通过移动pre来寻找cur左子树或者右子树中第一个叶子右节点。
		//通过子树的第一个叶子右节点指向本身节点，就能遍历完子树之后又能回到本身该节点，从而去遍历另外一边的节点
		if (cur->m_leftChild == NULL)//如果没有左节点
		{
			cout << cur->data << "  ";
			cur = cur->m_rightChild;
		}
		else
		{
			pre = cur->m_leftChild;
			while (pre->m_rightChild != NULL && pre->m_rightChild != cur)
			{
				pre = pre->m_rightChild;//寻找cur子树的第一个叶子右节点
			}
			if (pre->m_rightChild == NULL)
			{
				pre->m_rightChild = cur;//通过叶子节点转回所在子树的父节点
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
	if (NULL == NULL)return;
	Post_Order_TravelRecursive(root->m_leftChild);
	Post_Order_TravelRecursive(root->m_rightChild);
	cout << root->data << "  ";
}
#include"List.h"

ListNode *List::InsertNode(ListNode * root, string data)
{
	ListNode *temp = new ListNode;
	temp->m_data = data;
	temp->next;
	if (root == NULL)
	{
		root->next = temp;
	}
	else
	{
		temp->next = root->next;
		root->next = temp;
	}
	return temp;
}

bool List::setDirect(ListNode *sour, ListNode * des)
{
	if (sour == NULL || des == NULL)
	{
		return false;
	}
	sour->next = des;
	return true;
}

ListNode *List::hasCircle()
{
	if (root->next == NULL) return NULL;

	ListNode *pt1 = root;
	ListNode *pt2 = root;
	while (pt2 != NULL && pt1 != NULL)
	{
		pt1 = pt1->next;
		pt2 = pt2->next;
		if (pt2 != NULL)
		{
			pt2 = pt2->next;
		}

		if (pt1 == pt2)//如果有环，则退出循环，开始寻找环的入口节点
		{
			break;
		}
	}

	if (pt2 == NULL || pt1 == NULL) return NULL;//如果无环返回NULL

	//找环的入口节点，方法是：首先求出环的长度n，然后两个指针都回到头结点，然后其中一个指针先前进n个节点，然后两个指针以相同的速度前进，直到相遇，则为入口的节点
	pt1 = pt1->next;
	int count = 1;
	while (pt1 != pt2)
	{
		pt1=pt1->next;
		count++;
	}
	pt1 = root;
	pt2 = root;
	while (count > 0)
	{
		pt2 = pt2->next;
		count--;
	}
	while (pt1 != pt2)
	{
		pt1=pt1->next;
		pt2 = pt2->next;
	}
	return pt2;
}
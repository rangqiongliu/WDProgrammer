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

		if (pt1 == pt2)//����л������˳�ѭ������ʼѰ�һ�����ڽڵ�
		{
			break;
		}
	}

	if (pt2 == NULL || pt1 == NULL) return NULL;//����޻�����NULL

	//�һ�����ڽڵ㣬�����ǣ�����������ĳ���n��Ȼ������ָ�붼�ص�ͷ��㣬Ȼ������һ��ָ����ǰ��n���ڵ㣬Ȼ������ָ������ͬ���ٶ�ǰ����ֱ����������Ϊ��ڵĽڵ�
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
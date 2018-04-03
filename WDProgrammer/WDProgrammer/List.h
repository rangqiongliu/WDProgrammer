#pragma once
#include<iostream>
#include<string>
using namespace std;
struct ListNode
{
	string  m_data;
	ListNode *next;
};

class List
{
public:
	List()
	{
		root = new ListNode;
		root->next = NULL;
	}
	ListNode *getRoot()
	{
		return root;
	}

	ListNode *InsertNode(ListNode * root, string data);
	bool setDirect(ListNode *sour, ListNode * des);
	ListNode *hasCircle();
private:
	ListNode * root;
};

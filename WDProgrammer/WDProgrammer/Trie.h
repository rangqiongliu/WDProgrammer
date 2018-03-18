/*
�ļ�˵����Trie.h��Trie.cpp��Ϊ��������ʵ�ֺ�׺����ص�һЩ�㷨
*/
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 
#pragma once
#define INF 99999999
#include<iostream>
#include<typeinfo>
#include<bitset>
#include<vector>
#include<algorithm>
#include<time.h>
#include<fstream>
#include<Windows.h>
#include<hash_map>
using namespace std;


//���´���Ϊ����Trie����ֻʵ�ֶ��ַ���(a-z)�Ĳ���Ͳ��ҡ�
//Trie�������ڴ������ݵ�ͳ�ƺͲ�ѯ�����в�ѯĳ���ַ����Ƿ�����һ���ַ�����ǰ׺��
//�ŵ㣺��������ν���ַ����Ƚ�
//ȱ�㣺���ַ��������й���ǰ׺����ʱ������������ڴ�ռ�
struct Trie_Node
{
	bool isStr;
	Trie_Node * Child[26];//ÿ���ڵ���26���ӽڵ�
	string sth;//�������Ҳ���Լ�¼ͳ��ÿ�����ʳ��ֵ�Ƶ��
	Trie_Node() : isStr(false) { memset(Child, NULL, sizeof(Child)); }
};


class Trie
{
public:

	Trie() { root = new Trie_Node(); }
	~Trie() { delete root; }
	//����ǰ׺��
	void Insert(const char *word);

	//����������ַ������򷵻�0����������򷵻�1�����ֻ��ĳ���ַ�����ǰ׺�򷵻�2
	int Check(const char *word);

	//ɾ����ĳ�ڵ�Ϊ���ڵ�ĺ�׺��
	void delete_Trie(Trie_Node *Tree);

	//������׺��
	void InsertSufixTrie(const char *word);

	//�ж�sour�Ƿ�Ϊdes���Ӵ���sourΪ����ѯ���ַ�����desΪĿ���ַ��������des������Trie�У���Ĭ�ϻ���ӽ�Trie�С�
	bool isSubstr(const char *sour, const char *des);

	//ͳ��sour��des���ظ��Ĵ�����sourΪ�Ӵ���desΪĿ���ַ��������des������Trie�У���Ĭ�ϻ���ӽ�Trie�С�
	int  repeatNum(const char *sour, const char *des);

	/*ͳ�ƴ�ĳ���ڵ㿪ʼ�������У�����ֹ���ĸ���*/
	int getStrNum(Trie_Node * root);
private:
	Trie_Node * root;
};////���ϴ���Ϊ����Trie��(ǰ׺���ߺ�׺)��ʵ�ֶ��ַ�����a-z���Ĳ���Ͳ���
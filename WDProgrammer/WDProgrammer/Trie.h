/*
文件说明：Trie.h与Trie.cpp是为了声明和实现后缀树相关的一些算法
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


//以下代码为构建Trie树，只实现对字符串(a-z)的插入和查找。
//Trie数多用于大量数据的统计和查询，还有查询某个字符串是否是另一个字符串的前缀。
//优点：最大减少无谓的字符串比较
//缺点：当字符串集合中公共前缀较少时，会大量消耗内存空间
struct Trie_Node
{
	bool isStr;
	Trie_Node * Child[26];//每个节点有26个子节点
	string sth;//这个变量也可以记录统计每个单词出现的频率
	Trie_Node() : isStr(false) { memset(Child, NULL, sizeof(Child)); }
};


class Trie
{
public:

	Trie() { root = new Trie_Node(); }
	~Trie() { delete root; }
	//构建前缀树
	void Insert(const char *word);

	//如果不存在字符串，则返回0，如果存在则返回1，如果只是某个字符串的前缀则返回2
	int Check(const char *word);

	//删除以某节点为父节点的后缀树
	void delete_Trie(Trie_Node *Tree);

	//构建后缀树
	void InsertSufixTrie(const char *word);

	//判断sour是否为des的子串，sour为待查询的字符串，des为目标字符串；如果des不存在Trie中，则默认会添加进Trie中。
	bool isSubstr(const char *sour, const char *des);

	//统计sour在des中重复的次数。sour为子串，des为目标字符串。如果des不存在Trie中，则默认会添加进Trie中。
	int  repeatNum(const char *sour, const char *des);

	/*统计从某个节点开始的子树中，含终止符的个数*/
	int getStrNum(Trie_Node * root);
private:
	Trie_Node * root;
};////以上代码为构建Trie树(前缀或者后缀)，实现对字符串（a-z）的插入和查找

#include"Trie.h"

void Trie::Insert(const char *word)
{
	if (word == NULL) return;
	const char *pt = word;
	Trie_Node *Location = root;
	while (*pt)
	{
		if (Location->Child[*pt - 'a'] == NULL)//如果子节点为空，则新增一个节点
		{
			Trie_Node * temp = new Trie_Node();
			Location->Child[*pt - 'a'] = temp;
			Location = Location->Child[*pt - 'a'];
			pt++;
		}
		else
		{
			Location = Location->Child[*pt - 'a'];
			pt++;
		}
	}
	Location->isStr = true;
	Location->sth = word;
}

int Trie::Check(const char *word)
{
	Trie_Node *Location = root;
	while (*word)
	{
		if (Location->Child[*word - 'a'] == NULL)
		{
			cout << "Trie树中，没有该字符串" << endl;
			return 0;
		}
		else
		{
			Location = Location->Child[*word - 'a'];
			word++;
		}
	}
	if (Location->isStr) return 1;
	else
	{
		//如果运行到了这，证明要查找的字符串是某一个字符串的前缀
		cout << "Trie树中，该字符串是某一字符串的前缀，但磁盘中并未存储该字符串" << endl;
		return 2;
	}

}

void Trie::delete_Trie(Trie_Node *Tree)
{
	for (int i = 0; i < 26; i++)
	{
		if (Tree->Child[i] != NULL)
		{
			delete_Trie(Tree->Child[i]);
		}
	}
	delete Tree;
}

void Trie::InsertSufixTrie(const char *word)
{
	if (word == NULL) return;
	const char *pt = NULL;
	while (*word)
	{
		pt = word;
		Insert(pt);
		word++;
	}
}

bool Trie::isSubstr(const char *sour, const char *des)
{
	if (NULL == sour || NULL == des) return false;
	if (Check(des))
	{
		if (Check(sour))
		{
			cout << sour << "是" << des << "的子串" << endl;
			return true;
		}
		else
		{
			cout << sour << "不是" << des << "的子串" << endl;
			return false;
		}
	}
	else
	{
		InsertSufixTrie(des);
		return isSubstr(sour, des);
	}
}

int Trie::getStrNum(Trie_Node * root)
{
	int count = 0;
	if (root != NULL)
	{
		if (root->isStr) count++;
		for (int i = 0; i < 26; i++)
		{
			count += getStrNum(root->Child[i]);
		}
	}
	return count;
}

int  Trie::repeatNum(const char *sour, const char *des)
{
	if (NULL == sour || NULL == des) return 0;
	int count = 0;
	if (Check(des))
	{
		Trie_Node *Location = root;
		while (*sour)
		{
			if (Location->Child[*sour - 'a'] == NULL) return 0;
			else
			{
				Location = Location->Child[*sour - 'a'];
				sour++;
			}
		}
		return getStrNum(Location);
	}
	else
	{
		InsertSufixTrie(des);
		return repeatNum(sour, des);
	}
}
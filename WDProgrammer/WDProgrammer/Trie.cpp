
#include"Trie.h"

void Trie::Insert(const char *word)
{
	if (word == NULL) return;
	const char *pt = word;
	Trie_Node *Location = root;
	while (*pt)
	{
		if (Location->Child[*pt - 'a'] == NULL)//����ӽڵ�Ϊ�գ�������һ���ڵ�
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
			cout << "Trie���У�û�и��ַ���" << endl;
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
		//������е����⣬֤��Ҫ���ҵ��ַ�����ĳһ���ַ�����ǰ׺
		cout << "Trie���У����ַ�����ĳһ�ַ�����ǰ׺���������в�δ�洢���ַ���" << endl;
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
			cout << sour << "��" << des << "���Ӵ�" << endl;
			return true;
		}
		else
		{
			cout << sour << "����" << des << "���Ӵ�" << endl;
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
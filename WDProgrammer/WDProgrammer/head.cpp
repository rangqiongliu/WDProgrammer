#include"head.h"
#include<algorithm>
#include<stack>
#include<string>
int LCS_LENTH(const char *ptr1, const char *ptr2)
{
	if (NULL == ptr1 || NULL == ptr2) return 0;
	int m_ptr1 = strlen(ptr1);
	int n_ptr2 = strlen(ptr2);

	int **C = new int*[m_ptr1+1];
	for (int i = 0; i <= m_ptr1; i++)
		C[i] = new int[n_ptr2+1];

	for (int i = 0; i <= m_ptr1; i++)
		C[i][0] = 0;
	for (int i = 1; i <= n_ptr2; i++)
		C[0][i] = 0;

	for(int i=1;i<=m_ptr1;i++)
		for (int j = 1; j <= n_ptr2; j++)
		{
			if (ptr1[i-1] == ptr2[j-1])
			{
				C[i][j] = C[i - 1][j - 1] + 1;
			}
			else
			{
				C[i][j] = max(C[i - 1][j], C[i][j - 1]);
			}
		}
	return C[m_ptr1][n_ptr2];
}

void getSuffixExp(const char *ptr)
{
	string sufixExp;//�����Ҫ���غ�׺���ʽ������΢�޸��º��������ظñ������
	if (!judgeInfixExp(ptr))
	{
		cout << "Pls enter the right infix expression!" << endl;
		return;
	}
	stack<char> *top = new stack<char>;
	if(ptr[0]!='#')
		top->push('#');
	while ('\0' != *ptr)
	{
		if (*ptr == '(')//�����������������ֱ����ջ
		{
			top->push(*ptr);
			ptr++;
			continue;
		}
		if (*ptr == ')')//��������������������ջ������Լ�������Ԫ��ȫ����ջ
		{
			while (top->top() != '(')
			{
				sufixExp+=top->top();
				top->pop();
			}
			top->pop();//�������������Ҳ���ӡ
			ptr++;
			continue;
		}
		int stack_in = getPrioroty(top->top());
		int stack_out = getPrioroty(*ptr);
		if (stack_out == -2)//���Ϊ������ֱ�����
		{
			sufixExp += *ptr;
		}
		else if (stack_in >= stack_out)//���ջ��ȼ����ڵ���ջ�⣬��ջ�ڵķ��ų�ջ��ջ��ķ�����ջ
		{
			while(stack_in >= stack_out)//����ջ������������ŵȼ�����ջ��ķ���
			{ 
				if (top->top() != '#')
				{
					sufixExp += top->top();
					top->pop();
				}
				stack_in = getPrioroty(top->top());
			}
			top->push(*ptr);
		}
		else//���ջ��ĵȼ�С��ջ�⣬��ջ��ķ���ֱ����ջ
		{
			top->push(*ptr);
		}
		ptr++;
	}
	while (!top->empty())
	{
		if (top->top() != '#')
		{
			sufixExp += top->top();
			top->pop();
		}
		else
		{
			top->pop();
		}
	}
	delete top;
	cout << sufixExp << endl;
}

bool judgeInfixExp(const char *ptr)
{
	if (NULL == ptr)
	{
		cout << "The infix expression is empty!" << endl;
		return false;
	}
	int num_elem = strlen(ptr);
	for (int i = 0; i < num_elem; i++)
	{
		int p = getPrioroty(ptr[i]);
		if (p>=100)
			return false;
		if (p == -1 && i != 0 && i !=( num_elem - 1))//��ֹ��׺���ʽ�м�γ��֡�#���ַ���
			return false;
	}
	return true;
}

int getPrioroty(const char c)
{
	if (NULL == c) return 100;
	switch (c)
	{
		case '#': return -1;
		case '=': return 0;
		case '(': return 1;
		case '+': return 2;
		case '-': return 2;
		case '*': return 3;
		case '/': return 3;
		case ')': return 4;
	}
	if (c >= 'a'&& c <= 'z' || c>='A'&& c<='Z') return -2;
	if (c >= '0'&&c <= '9' || c == '.') return -2;
	else return 100;
}

void str2int(const char *ptr)
{
	if (NULL == ptr) return;
	int num = strlen(ptr);//�ַ����ܵĸ���
	double sum = 0;//�洢����ת����ֵ��
	bool flag = true;//�Ƿ���С����
	int num_after_point = 0;//��¼С������λ��
	for (int i = 0; i < num; i++)
	{
		if (ptr[i] >= '0'&& ptr[i] <= '9' || ptr[i] == '.')
		{
			if (ptr[i] == '.')
			{
				flag = false;
				continue;
			}
			if (flag)
			{
				sum = 10 * sum + (ptr[i] - 48);
			}
			else
			{
				num_after_point++;
				sum += double(ptr[i] - 48) / (pow(10, num_after_point));
			}

		}
		else
		{
			cout << "Please enter right str" << endl;
			return;
		}
	}
	cout << sum << endl;
}

void combineCoin(const int * Coin, const int num_elem/*Ӳ�ҵ�������*/, const int *num_Coin)
{
	cout << "Hello" << endl;
}

void BubbleSort(int * RawData, const int num_elem)
{
	if (NULL == RawData || 0 >= num_elem)
	{
		cout << "No parameters passed! " << endl;
		return;
	}
	for (int i = 0; i < num_elem - 1; i++)
	{
		for (int j = i + 1; j < num_elem; j++)
		{
			if (RawData[j] < RawData[i])
			{
				int temp = RawData[j];
				RawData[j] = RawData[i];
				RawData[i] = temp;
			}
		}
	}
}

void QuickSort(int *RawData, const int start, const int end)
{
	if (end <= start || NULL == RawData || start < 0 || end < 0 )
		return;
	int key = RawData[start];
	int former = start;
	int latter = end;
	while (former<latter)//���ٺ���ÿ�ε��ñ��뾭��end-start�αȽ�
	{
		for (; latter > former; latter--)//�Ӻ���ǰ�ұ�keyֵС�������ҵ���һ��С��keyֵ��Ԫ�ؾ���RawData[former]�Ե�
		{
			if (RawData[latter] < key)
			{
				int temp = RawData[former];
				RawData[former] = RawData[latter];
				RawData[latter] = temp;
				break;
			}
		}

		for (; former < latter; former++)//��ǰ����ұ�keyֵҪ��������ҵ���һ������keyֵ��Ԫ�ؾ���RawData[latter]�Ե�
		{
			if (RawData[former] > key)
			{
				int temp = RawData[former];
				RawData[former] = RawData[latter];
				RawData[latter] = temp;
				break;
			}
		}
	}
	RawData[former] = key;
	QuickSort(RawData, start, former - 1);
	QuickSort(RawData, former + 1, end);
}
void QuickSort(vector<int> &myVector, const int start, const int end)
{
	if (myVector.size() == 0 || start<0 || start>=end) return;
	int key = myVector[start];
	int former = start;
	int latter = end;
	while (former<latter)
	{
		for (; former < latter ; latter--)
		{
			if (myVector[latter] < key)
			{
				int temp = myVector[latter];
				myVector[latter] = myVector[former];
				myVector[former] = temp;
				break;
			}
		}

		for (; former < latter; former++)
		{
			if (myVector[former] > key)
			{
				int temp = myVector[latter];
				myVector[latter] = myVector[former];
				myVector[former] = temp;
				break;
			}
			
		}
	}
	myVector[former] = key;
	QuickSort(myVector, start, former - 1);
	QuickSort(myVector, former + 1, end);
}

void InsertSort(int *RawData, const int ele_num)
{
	if (NULL == RawData || ele_num<=0)
		return;
	for (int sort_i = 1; sort_i < ele_num; sort_i++)
	{
		int temp = RawData[sort_i];
		int move_i = sort_i - 1;
		for ( ; move_i >= 0 && temp< RawData[move_i]; move_i--)
		{
			RawData[move_i + 1] = RawData[move_i];
		}
		RawData[move_i + 1] = temp;
	}
}

void ShellSort(int *RawData, const int ele_num)
{
	if (NULL == RawData || 0 >= ele_num)
		return;
	int Incre = ele_num / 2;//��ʼ����
	for (; Incre > 0; Incre /= 2)//�𲽸ı�������ϣ��������ÿ����ԭ����������һ��
	{
		for (int i = 0; i < Incre; i++)//���������ֳ��˼���
		{
			for (int sort_i = i+Incre; sort_i < ele_num; sort_i += Incre)//��ÿ�����ֱ�Ӳ�������
			{
				int temp = RawData[sort_i];
				int move_i = sort_i - Incre;
				for (; move_i >= 0 && temp < RawData[move_i]; move_i -= Incre)
				{
					RawData[move_i + Incre] = RawData[move_i];
				}
				RawData[move_i + Incre] = temp;
			}
		}
	}

}

void ModifyHeap(int *RawData, int No_leaf,const int ele_num)
{
	if (NULL == RawData || No_leaf < 0 || ele_num <= 0)
		return;
	int lChild = 2 * No_leaf + 1;//���ӽڵ㣬�����Ŵ�0��ʼ��
	int Child = -1;//��Ҫ�븸�ڵ��뽻�����ӽڵ�������
	for (; lChild < ele_num; No_leaf = Child,lChild=2*No_leaf+1)//��Child��ֵ��No_leaf��ԭ������ֻ�иı��Ԫ�ص���������Ҫ���µ����ı�Ҫ
	{
		
		if (lChild + 1 < ele_num && RawData[lChild] < RawData[lChild + 1])//ȷ�������ӽڵ㻹�����ӽڵ��븸�ڵ���бȽϲ�����Ԫ��
		{
			Child = lChild + 1;
		}
		else
		{
			Child = lChild;
		}

		if (RawData[Child] > RawData[No_leaf])//����ӽڵ�ȸ��ڵ���򽻻�Ԫ��
		{
			int temp = RawData[No_leaf];
 			RawData[No_leaf] = RawData[Child];
			RawData[Child] = temp;
			
		}
		else
			break;//���û�з�����ֵ�Ľ�����ֱ������ѭ����֤���������Ѿ����ϴ�ѵ�����
	}
}

void HeapSort(int *RawData, const int ele_num)
{
	if ( NULL == RawData || 0 >= ele_num)
		return  ;
	for (int i = ele_num / 2 - 1; i >= 0; i--)//������ʼ�󶥶�
	{
		ModifyHeap(RawData, i, ele_num);
	}

	for (int i = ele_num - 1; i >= 0; i--)
	{
		int temp = RawData[i];
		RawData[i] = RawData[0];
		RawData[0] = temp;
		ModifyHeap(RawData, 0, i );
	}
}

void BitmapSort(int *RawData,  const int ele_num)
{
	bitset<100> sort;
	for (int i = 0; i < ele_num; i++)
	{
		sort[RawData[i]] = 1;
	}
	int record = 0;
	for (int i = 0;i < 100; i++)
	{
		if (record >= ele_num) return;
		if (sort[i] == 1)
		{
			RawData[record] = i;
			record++;
		}
	}
}

void MergeSort(int *RawData, int low, int high)
{
	
	if (RawData != NULL  && low < high)
	{
		int mid = (high+low) / 2;
		MergeSort(RawData, low, mid);
		MergeSort(RawData, mid + 1, high);
		Merge(RawData, low, mid, high);

	}//if end

}

void Merge(int *RawData, int low, int mid, int high)
{
	if (NULL == RawData || low < 0 || mid<0 || low>high) return;
	int * tempData = new int[high - low +1];
	for (int i = low; i <= high; i++)
	{
		tempData[i - low] = RawData[i];
	}
	int i=-1, j=-1, k=-1;
	for ( i = 0, j = mid + 1 -low, k = i+low; i+low <= mid && j +low<= high; k++)
	{
		if (tempData[i] <= tempData[j])
		{
			RawData[k] = tempData[i++];
		}
		else
			RawData[k] = tempData[j++];
		
	}//��ѭ��֮�󣬿��ܻ����ĳһ�������û�и��Ƶ�RawData�����С���˻���Ҫ��������ѭ�������жϣ�����ʣ�µ�����Ԫ�طŽ�RawData�У�����ѭ��ÿ��ֻ���������е�һ����

	while (i <= mid-low) RawData[k++] = tempData[i++];
	while (j <= high-low)	RawData[k++] = tempData[j++];
	delete[] tempData;
}

void StraightSort(int *RawData, int ele_num)
{
	if (NULL == RawData || ele_num <= 0) return;
	int minmum = -1;
	for (int i = 0; i < ele_num - 1; i++)
	{
		minmum = i;
		for (int j = i+1; j < ele_num; j++)
		{
			if (RawData[j] < RawData[minmum])
			{
				minmum = j;
			}
		}
		int temp = RawData[minmum];
		RawData[minmum] = RawData[i];
		RawData[i] = temp;
	}
}

void BucketSort(vector<int> &myVector)
{
	if (myVector.size() == 0) return;
	auto max_iter = max_element(myVector.begin(), myVector.end());
	int max_value = *max_iter;
	int ele_num = myVector.size();
	int group = max_value / 10 + 1;//��ҪͰ�ĸ���
	vector<int> *SortVector = new vector<int>[group];
	int index = -1;
	for (int i = 0; i < ele_num; i++)
	{
		index = myVector[i] / 10;//������������ݰ�10Ϊ����������䣬����0-9��Ԫ��ȫ�ŵ���0��Ͱ��10-19��Ԫ��ȫ�ŵ���1��Ͱ
		SortVector[index].push_back(myVector[i]);
	}

	//��ÿ��Ͱ�е����ݽ�������
	for (int i = 0; i < group; i++)
	{
		if (SortVector[i].size() > 1)
		{
			QuickSort(SortVector[i], 0, SortVector[i].size() - 1);
		}
	}

	//���ź����Ͱ�е�Ԫ������--���Ƶ�myVector�У��������
	int record = 0;
	for (int i = 0; i < group; i++)
	{
		for (int j = 0; j < SortVector[i].size(); j++)
		{
			myVector[record++] = SortVector[i][j];
		}
	}
	delete[] SortVector;
}

int getNum(int value, int order)//��ȡvalue�ĵ�order�������Ӹ�λ���λ��
{
	value /= pow(10, order - 1);
	return value % 10;
}

void RadixSort(vector<int> &RawData)
{
	if (RawData.size() <= 1) return;
	auto max_iter = max_element(RawData.begin(), RawData.end());
	int max_value = *max_iter;
	int temp = max_value;
	int count = 0;
	vector<int> myVector[10];
	while (temp != 0)//��ȡ���ֵ��λ��
	{
		count++;
		temp /= 10;
	}
	for (int i = 1; i <= count; i++)
	{
		for (int j = 0; j < RawData.size(); j++)
		{
			myVector[getNum(RawData[j], i)].push_back(RawData[j]);
		}

		for (int temp_i = 0 ,k=0; temp_i < 10; temp_i++)
		{
			for (int temp_j = 0; temp_j < myVector[temp_i].size(); temp_j++)
			{
				RawData[k++] = myVector[temp_i][temp_j];
			}
			myVector[temp_i].clear();
		}

	}

}

int Binary_Search(int *RawData, const int ele_num, const int value)
{
	if (NULL == RawData || ele_num <= 0) return -1;
	int start = 0;
	int end = ele_num-1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (RawData[mid] == value) return mid;
		if (RawData[mid] > value)
		{
			end = mid - 1;
			continue;
		}
		else
		{
			start = mid + 1;
			continue;
		}
	}
	return -1;
}

void Trie :: Insert(const char *word)
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
			Location=Location->Child[*word - 'a'];
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

void compressSpace(char *myChar)
{
	if (NULL == myChar)	return;
	int ele_num = strlen(myChar);
	bool *flag = new bool[ele_num] {false};//����Ŀո��Ϊtrue
	if ( myChar[0] == ' ')//����ַ�����һ��Ϊ�ո�ҲҪȥ��
	{
		flag[0] = true;
	}

	for (int i = 1; i < ele_num; i++)
	{
		if (myChar[i - 1]==' ' && myChar[i] == ' ')
			flag[i] = true;
	}

	if (myChar[ele_num - 1] == ' ') flag[ele_num - 1] = true;//����ַ��������һ���ַ�Ϊ�ո���ҲҪȥ��

	for (int i = 0; i < ele_num; i++)
	{
		if (!flag[i])
		{
			cout << myChar[i];
		}
	}

	cout << endl;
	delete[] flag;
}



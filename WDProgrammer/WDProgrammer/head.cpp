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
	string sufixExp;//如果需要返回后缀表达式，则稍微修改下函数，返回该变量便可
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
		if (*ptr == '(')//如果遇到‘（’，则直接入栈
		{
			top->push(*ptr);
			ptr++;
			continue;
		}
		if (*ptr == ')')//如果会遇到‘）’，则把栈里‘（’以及到顶的元素全部出栈
		{
			while (top->top() != '(')
			{
				sufixExp+=top->top();
				top->pop();
			}
			top->pop();//弹出‘（’并且不打印
			ptr++;
			continue;
		}
		int stack_in = getPrioroty(top->top());
		int stack_out = getPrioroty(*ptr);
		if (stack_out == -2)//如果为变量则直接输出
		{
			sufixExp += *ptr;
		}
		else if (stack_in >= stack_out)//如果栈里等级大于等于栈外，则栈内的符号出栈，栈外的符号入栈
		{
			while(stack_in >= stack_out)//可能栈内连续多个符号等级大于栈外的符号
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
		else//如果栈里的等级小与栈外，则栈外的符号直接入栈
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
		if (p == -1 && i != 0 && i !=( num_elem - 1))//防止中缀表达式中间段出现‘#’字符。
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
	int num = strlen(ptr);//字符串总的个数
	double sum = 0;//存储最后的转换数值。
	bool flag = true;//是否含有小数点
	int num_after_point = 0;//记录小数点后的位数
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

void combineCoin(const int * Coin, const int num_elem/*硬币的种类数*/, const int *num_Coin)
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
	while (former<latter)//快速函数每次调用必须经过end-start次比较
	{
		for (; latter > former; latter--)//从后向前找比key值小的数，找到第一个小于key值得元素就与RawData[former]对调
		{
			if (RawData[latter] < key)
			{
				int temp = RawData[former];
				RawData[former] = RawData[latter];
				RawData[latter] = temp;
				break;
			}
		}

		for (; former < latter; former++)//从前向后找比key值要大的数，找到第一个大于key值得元素就与RawData[latter]对调
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
	int Incre = ele_num / 2;//初始增量
	for (; Incre > 0; Incre /= 2)//逐步改变增量，希尔增量是每次是原来的增量的一半
	{
		for (int i = 0; i < Incre; i++)//根据增量分成了几组
		{
			for (int sort_i = i+Incre; sort_i < ele_num; sort_i += Incre)//对每组进行直接插入排序
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
	int lChild = 2 * No_leaf + 1;//左子节点，索引号从0开始。
	int Child = -1;//需要与父节点想交换的子节点索引号
	for (; lChild < ele_num; No_leaf = Child,lChild=2*No_leaf+1)//将Child赋值给No_leaf的原因在于只有改变过元素的子树才需要重新调整的必要
	{
		
		if (lChild + 1 < ele_num && RawData[lChild] < RawData[lChild + 1])//确定是左子节点还是右子节点与父节点进行比较并交换元素
		{
			Child = lChild + 1;
		}
		else
		{
			Child = lChild;
		}

		if (RawData[Child] > RawData[No_leaf])//如果子节点比父节点大，则交换元素
		{
			int temp = RawData[No_leaf];
 			RawData[No_leaf] = RawData[Child];
			RawData[Child] = temp;
			
		}
		else
			break;//如果没有发生数值的交换则直接跳出循环，证明该子树已经符合大堆的性质
	}
}

void HeapSort(int *RawData, const int ele_num)
{
	if ( NULL == RawData || 0 >= ele_num)
		return  ;
	for (int i = ele_num / 2 - 1; i >= 0; i--)//创建初始大顶堆
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
		
	}//此循环之后，可能会存在某一侧的数据没有复制到RawData数组中。因此还需要下面两个循环进行判断，来把剩下的有序元素放进RawData中，两个循环每次只会运行其中的一个。

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
	int group = max_value / 10 + 1;//需要桶的个数
	vector<int> *SortVector = new vector<int>[group];
	int index = -1;
	for (int i = 0; i < ele_num; i++)
	{
		index = myVector[i] / 10;//将待排序的数据按10为间隔划分区间，比如0-9的元素全放到第0个桶，10-19的元素全放到第1个桶
		SortVector[index].push_back(myVector[i]);
	}

	//对每个桶中的数据进行排序
	for (int i = 0; i < group; i++)
	{
		if (SortVector[i].size() > 1)
		{
			QuickSort(SortVector[i], 0, SortVector[i].size() - 1);
		}
	}

	//将排好序的桶中的元素重新--复制到myVector中，由其带回
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

int getNum(int value, int order)//获取value的第order个数，从个位向高位数
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
	while (temp != 0)//获取最大值得位数
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
			Location=Location->Child[*word - 'a'];
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

void compressSpace(char *myChar)
{
	if (NULL == myChar)	return;
	int ele_num = strlen(myChar);
	bool *flag = new bool[ele_num] {false};//多余的空格记为true
	if ( myChar[0] == ' ')//如果字符串的一个为空格，也要去掉
	{
		flag[0] = true;
	}

	for (int i = 1; i < ele_num; i++)
	{
		if (myChar[i - 1]==' ' && myChar[i] == ' ')
			flag[i] = true;
	}

	if (myChar[ele_num - 1] == ' ') flag[ele_num - 1] = true;//如果字符串的最后一个字符为空格，则也要去掉

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



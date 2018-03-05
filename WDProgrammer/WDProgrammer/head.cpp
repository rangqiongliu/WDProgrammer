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
	if (NULL == RawData || 0 == num_elem)
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

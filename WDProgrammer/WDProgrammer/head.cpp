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

//Ϊ�˸���RotaryCube��������Data�����У�����value���ڵ��к���
void getIndex(int *Data, int &hang, int &lie, const int value)
{
	if (Data == NULL) return;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Data[i * 3 + j] == value)
			{
				hang = i;
				lie = j;
				return;
			}
		}
	}
}

//Ϊ�˸���RotaryCube�������ж�data�����Ƿ�С�ڵ���0
bool allempty(int *data)
{
	if (data == NULL) return true;
	for (int i = 0; i < 9; i++)
	{
		if (data[i] > 0) return false;
	}
	return true;
}

//Ϊ�˸���RotaryCube������data���飬ÿ��Ҫʹ�ĸ�Ԫ�أ�>0����1������������û���ĸ�Ԫ�ؿ��Լ��ˣ�����ֻ��ȥ��Ӧ���������ܹ��ܼ����ٴΣ�ʹ��data����Ԫ��ȫ��С�ڵ���0
int getCount(int* data)
{
	if (data == NULL) return 0;
	int count = 0;
	int temp_count = 0;
	while (!allempty(data))
	{
		temp_count = 0;
		for (int i = 0; i < 9; i++)
		{
			if (temp_count >= 4)
				break;
			if (data[i] > 0)
			{
				data[i]--;
				temp_count++;
			}
		}
		count++;
	}

	return count;
}

/*
�������ܣ����״���ʵϰ�����⣬�����⡣����Ҫ�����£�
����һ��3*3����A��1-9��������ÿһ���Ӿ���2*2����Ϊһ��������Խ���90 180 270����ת���ٸ���һ��3*3��Ŀ�����B��
��A->B������Ҫ��ת���ٴ�
*/
int RotaryCube()
{

			int *RawData = new int[9];
			int *Target = new int[9];
			for (int i = 0; i < 3; i++)//����ԭʼ����
			{
				for (int j = 0; j < 3; j++)
				{
					cin >> RawData[i * 3 + j];
				}
			}

			for (int i = 0; i < 3; i++)//����Ŀ�����
			{
				for (int j = 0; j < 3; j++)
				{
					cin >> Target[i * 3 + j];
				}
			}

			int *dis = new int[9];
			int r_i = -1;
			int r_j = -1;
			int t_i = -1;
			int t_j = -1;
			for (int i = 0; i < 9; i++)
			{
				r_i = i / 3;
				r_j = i % 3;
				getIndex(Target, t_i, t_j, RawData[i]);
				dis[i] = abs(r_i - t_i) + abs(r_j - t_j);//��Target��ĳ��Ԫ�ص�RawData��ӦԪ�ص������پ���
			}
			delete[] RawData;
			delete[] Target;
			return getCount(dis);

}

int calWeek(string str)
{
	int a = 0;
	time_t timep = time(NULL);
	struct tm *p;
	p = localtime(&timep);
	if (str.size() == 8)
	{
		p->tm_year =atoi( (str.substr(0, 4)).c_str())-1990;
		p->tm_mon = atoi(str.substr(4, 2).c_str()) - 1;
		p->tm_mday = atoi(str.substr(6, 2).c_str()) ;
	}
	//˵�����˴����ò��չ�ʽ
	//strum tm�ṹ���У�year�Ǵ�1900�꿪ʼ�ģ�����2018���ʱ��,p->tm_year��118
	//mon�Ǵ�0��ʼ�ģ����4�µ�ʱ��p->tm_mon��3
	int week = ((p->tm_year+1900) % 100 + int(((p->tm_year+1900) % 100) / 4) + int(((p->tm_year + 1900) / 100) / 4) - 2 * ((p->tm_year+1900) / 100) + int(26 * ((p->tm_mon+1) + 1) / 10) + p->tm_mday - 1)%7;
	switch (week)
	{
	case 0:cout << "Sunday" << endl; break;
	case 1:cout << "Monday" << endl; break;
	case 2:cout << "Tuesday" << endl; break;
	case 3:cout << "Wednesday" << endl; break;
	case 4:cout << "Thursday" << endl; break;
	case 5:cout << "Friday" << endl; break;
	case 6:cout << "Saturday" << endl; break;
	}
	return week;
}

void  RotateMatrix()
{
	
		int ok;
		vector<int> temp;
		vector<vector<int>>data;
		char a;
		while (true)
		{
			cin >> ok;
			temp.push_back(ok);
			a=cin.get();
			if (a == '\n')
				break;
		}
		int num = temp.size();
		int **res = new int*[num];
		for (int i = 0; i < num; i++)
		{
			res[i] = new int[num];
		}
		data.push_back(temp);
		temp.clear();
		for (int i = 1; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				cin >> ok;
				temp.push_back(ok);
			}
			data.push_back(temp);
			temp.clear();
		}
		int start = 0;
		int end = num - 1;
		/*while (start < end)
		{
			swap(data[start++], data[end--]);
		}*/
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				res[j][num-1-i]=data[i][j];
			}
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				cout << res[i][j];
				if (j != num - 1)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		temp.clear();
		data.clear();
	
}

int countPointNumOnLine(vector<Point2D>myVector)
{
	if (myVector.size() <= 2) return myVector.size();
	map<double, vector<Point2D>> myMap;
	map<double, vector<Point2D>>::iterator iter;
	int num = myVector.size();
	for (int i = 0; i < num - 1; i++)
	{
		
		for (int j = i + 1; j < num; j++)
		{
			double rotate = 0;
			if (myVector[i].x == myVector[j].x)
			{
				rotate = INT_MAX;
			}
			else
			{
				rotate = (myVector[j].y - myVector[i].y) / (myVector[j].x - myVector[i].x);
			}
			myMap[rotate].push_back(myVector[i]);
			myMap[rotate].push_back(myVector[j]);
		}
	}
	iter = myMap.begin();
	int  max_count = 0;
	while (iter != myMap.end())
	{
		int temp_count = 0;
		int i = 0;
		while (i<iter->second.size()-1)
		{
			temp_count = 1;
			int j = i + 1;
			for (; j < iter->second.size(); j+=2)
			{
				
				double rotate = 0;
				if (iter->second[j].x == iter->second[i].x)
					rotate == INT_MAX;
				else
					rotate=(iter->second[j].y - iter->second[i].y) / (iter->second[j].x - iter->second[i].x);
				if (abs(rotate - iter->first) < 1e-6)
				{
					temp_count++;//�˴�û�п����ظ��ĵ㣬�������ơ�
					max_count = max_count < temp_count ? temp_count : max_count;

				}
				else
				{
					max_count = max_count < temp_count ? temp_count : max_count;
					temp_count = 0;
					i = j ;
					break;
				}
			}
			if (j >= iter->second.size())
			{
				break;
			}
			else
			{
				i++;
			}
			
		}
		iter++;
	}
	return max_count;
}

long  Factorial(const int n)
{
	long sum = 1;
	for (int i = 1; i <= n; i++)
		sum*= i;
	return sum;
}

long  Choose(const int n, const int m)
{
	return Factorial(n) / (Factorial(m)*Factorial(n - m));
}

void sing()
{
	int K, A, B, X, Y;
	while (cin >> K >> A >> B >> X >> Y)
	{
		long sum = 0;
		map<int, int> myMap;
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (i*A + j*B == K)
				{
					myMap.insert(make_pair (i, j));
				}
			}
		}
		map<int, int >::iterator iter = myMap.begin();
		for (; iter != myMap.end(); iter++)
		{
			sum += Choose(X, iter->first)*Choose(Y, iter->second);
			if (sum >= 1000000007)
				sum %= 1000000007;
		}
		cout << sum << endl;

	}
}

int findIndex(vector<vector<int>> data, int mission_num, bool *flag)
{
	int index = -1;
	int sum = 0;
	for (int i = 0; i < mission_num; i++)
	{
		if (!flag[i])
		{
			int tempSum = 200 * data[i][0] + 3 * data[i][1];
			if (sum < tempSum)
			{
				index = i;
				sum = tempSum;
			}
				
		}
	}
	return index;
}

bool isEmpty(bool *flag, int mission_num)
{
	for (int i = 0; i < mission_num; i++)
	{
		if (!flag[i])
			return false;
	}

	return true;
}

void mission()
{
	int machine_num = 0;
	int mission_num = 0;
	while(cin>>machine_num>>mission_num)
	{
		vector<vector<int>> machine;
		vector<vector<int>> mission;
		vector<int> temp = {0,0};
		bool *flag = new bool[mission_num] {false};
		bool *machineFlag = new bool[machine_num] {false};
		for (int i = 0; i < machine_num; i++)
		{
			cin >> temp[0] >> temp[1];
			machine.push_back(temp);
		}
		for (int i = 0; i < mission_num; i++)
		{
			cin >> temp[0] >> temp[1];
			mission.push_back(temp);
		}
		int index = -1;
		long sum = 0;
		int count = 0;
		while (!isEmpty(machineFlag, machine_num))
		{
			index = findIndex(mission, mission_num, flag);
			
			if (index == -1 && isEmpty(flag, mission_num))
				break;
			flag[index] = true;
			for (int j = 0; j < machine_num; j++)
			{
				if (!machineFlag[j])
				{
					if (machine[j][0] >= mission[index][0] && machine[j][1] >= mission[index][1])
					{
						machineFlag[j] = true;
						sum += 200 * mission[index][0] + 3 * mission[index][1];
						count++;
						break;
					}
				}
			}
		}
		cout << count << " " << sum << endl;
	}
}
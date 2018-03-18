#include"Search.h"
#include"Sort.h"
int Binary_Search(int *RawData, const int ele_num, const int value)
{
	if (NULL == RawData || ele_num <= 0) return -1;
	int start = 0;
	int end = ele_num - 1;
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

void generateBigData(const int kind, const int num, float percent, string file_name)
{
	srand(time(0));
	unsigned long long  Avai_memory = 0;
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	Avai_memory = statex.ullAvailPhys;
	int Threhold = 0;
	int total_count = 0;
	int temp_count = 0;
	ofstream ot(file_name);

	switch (kind)
	{
	case 1:
		Threhold = (Avai_memory*percent) / sizeof(int);
		break;
	default:
		Threhold = (Avai_memory*percent) / sizeof(string);
		break;
	}

	Threhold = min(Threhold, num);

	switch (kind)
	{
	case 1://������������
	{
		int *data = new int[Threhold];
		for (total_count = 0, temp_count = 0; total_count <= num; total_count++)
		{
			if (temp_count >= Threhold || total_count == num)
			{
				for (int i = 0; i < temp_count; i++)
				{
					ot << data[i] << endl;
				}
				temp_count = 0;
			}
			data[temp_count++] = rand() % 1000000001;//����0-100000000��Χ�ڵ�����
			if (total_count % 10000 == 0)
			{
				cout << "�Ѿ�����" << total_count << "������" << endl;
			}
		}
		ot.close();
		delete[] data;
	}
	break;

	case 2: //����16���ֽڵ��ַ���
	{
		string  * data = new string[Threhold];
		for (total_count = 0, temp_count = 0; total_count <= num; total_count++)
		{
			if (temp_count >= Threhold || total_count == num)
			{
				for (int i = 0; i < temp_count; i++)
				{
					ot << data[i] << endl;
				}
				temp_count = 0;
			}
			data[temp_count].clear();
			for (int i = 0; i < 16; i++)
			{
				data[temp_count] += char('a' + rand() % ('z' + 1 - 'a'));
			}
			temp_count++;
		}
		ot.clear();
		delete[] data;
	}
	break;

	case 3: //����IP��ַ
	{
		string  * data = new string[Threhold];
		for (total_count = 0, temp_count = 0; total_count <= num; total_count++)
		{
			if (temp_count >= Threhold || total_count == num)
			{
				for (int i = 0; i < temp_count; i++)
				{
					ot << data[i] << endl;
				}
				temp_count = 0;
			}
			data[temp_count].clear();
			for (int i = 0; i < 4; i++)
			{
				data[temp_count] += to_string(rand() % 256);
				if (i < 3)
				{
					data[temp_count] += '.';
				}
			}
			temp_count++;
		}
		ot.close();
		delete[] data;
	}
	break;

	default:
		break;
	}
	std::cout << "�����������" << endl;
}

int getLastTrue(bool *flag, const int ele_num)
{
	for (int i = ele_num - 1; i >= 0; i--)
		if (flag[i]) return i;

	return -1;
}

void creatSmallHeap(int *RawData, int No_leaf, const int k)
{
	if (NULL == RawData || No_leaf<0 || No_leaf > k / 2 - 1)
	{
		cout << "��ʼ����������󣬽���ʧ��" << endl;
		return;
	}
	bool *flag = new bool[k] {false};
	int lChild = No_leaf * 2 + 1;//���ӽڵ�
	int Child = -1;
	for (; lChild < k && No_leaf >= 0; lChild = 2 * No_leaf + 1)
	{
		if (lChild + 1 >= k || RawData[lChild] <= RawData[lChild + 1])
		{
			Child = lChild;
		}
		else
		{
			Child = lChild + 1;
		}

		if (RawData[Child] < RawData[No_leaf])
		{
			int temp = RawData[No_leaf];
			RawData[No_leaf] = RawData[Child];
			RawData[Child] = temp;
			flag[No_leaf] = true;
			if (2 * Child + 1 > k)//�����ָ����Ҷ�ӽڵ��³����˺���λ�ã�����й��䶯�������µ���ΪС����
			{
				int index = getLastTrue(flag, k);
				No_leaf = (index + 1) / 2 - 1;
				flag[index] = false;
			}
			else
			{
				No_leaf = Child;
			}
		}
		else
		{
			int index = getLastTrue(flag, k);//�鿴���н�����Ԫ�صĸ��ڵ��Ƿ񶼷���С���ѵ�����
			if (index>0)
			{
				No_leaf = (index + 1) / 2 - 1;
				flag[index] = false;
			}
			else
				break;
		}


	}
}

void creatSmallHeap(vector<hash_map<const string, int>> &myVector, int No_leaf)
{
	if (myVector.size() <= 0 || No_leaf < 0) return;
	bool *flag = new bool[myVector.size()]{ false };

	int lChild = 2 * No_leaf + 1;
	int Child = -1;

	for (; lChild < myVector.size() && No_leaf >= 0; lChild = 2 * No_leaf + 1)
	{
		if (lChild + 1 >= myVector.size() || myVector[lChild].begin()->second <= myVector[lChild + 1].begin()->second)
		{
			Child = lChild;
		}
		else
		{
			Child = lChild + 1;
		}

		if (myVector[Child].begin()->second < myVector[No_leaf].begin()->second)
		{
			hash_map<const string, int > temp(myVector[No_leaf]);
			myVector[No_leaf].clear();
			myVector[No_leaf].insert(make_pair(myVector[Child].begin()->first, myVector[Child].begin()->second));
			myVector[Child].clear();
			myVector[Child].insert(make_pair(temp.begin()->first, temp.begin()->second));
			flag[No_leaf] = true;
			if (2 * Child + 1 > myVector.size())//�����ָ����Ҷ�ӽڵ��³����˺���λ�ã�����й��䶯�������µ���ΪС����
			{
				int index = getLastTrue(flag, myVector.size());
				No_leaf = (index + 1) / 2 - 1;
				flag[index] = false;
			}
			else
			{
				No_leaf = Child;
			}

		}
		else
		{
			int index = getLastTrue(flag, myVector.size());//�鿴���н�����Ԫ�صĸ��ڵ��Ƿ񶼷���С���ѵ�����
			if (index>0)
			{
				No_leaf = (index + 1) / 2 - 1;
				flag[index] = false;
			}
			else
				break;
		}
	}
}

void TopK_Heap(string file_name, const int k)
{

	ifstream in(file_name);
	if (!in.is_open() || k <= 0)
	{
		cout << "��ȡ�����ļ�ʧ��" << endl;
		return;
	}
	int *result = new int[k];
	for (int i = 0; i < k; i++)
	{
		result[i] = -INF;
	}
	for (int i = 0; i <= k / 2 - 1; i++)//������ʼ��С��
	{
		creatSmallHeap(result, i, k);
	}
	//���㱾������ռ�õ��ڴ�ռ��С
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	unsigned long long Avai_Memory = statex.ullAvailPhys;
	int Threhold = Avai_Memory*0.1 / sizeof(int);
	//
	int count = 0;
	int *temp_data = new int[Threhold];
	while (!in.eof())
	{
		for (int i = 0; i < Threhold && !in.eof(); i++)//ÿ�ζ�ȡ�ռ��ڴ�10%��С�����ݽ�������ȡ��������̵�IO�������Ӷ���ʡ�������е�ʱ�䡣
		{
			in >> temp_data[count++];
		}

		if (in.eof() && count <= Threhold)//ȥ���ļ����һ�����з��ļ���
		{
			count = count - 1;
		}
		for (int i = 0; i < count; i++)
		{
			if (result[0] < temp_data[i])
			{
				result[0] = temp_data[i];
				creatSmallHeap(result, 0, k);
			}
		}
		count = 0;
	}
	delete[] temp_data;
	in.close();
	QuickSort(result, 0, k - 1);//��Ϊ���ջ�õ���С��������ģ����Կ������ÿ��Ż��߶������������򣬾��ܻ������K������
	for (int i = 0; i < k; i++)
	{
		if (result[i] != -INF)
			cout << result[i] << "  ";
	}
	cout << endl;
}

void StringTopK_map(string file_name, const int k)
{
	ifstream in(file_name);
	if (!in.is_open() || k <= 0)
	{
		cout << "��ȡ�����ļ�ʧ��" << endl;
		return;
	}
	vector<hash_map<const string, int>> myVector;
	hash_map<string, int>temp_map;

	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	unsigned long long Avai_Memory = statex.ullAvailPhys;
	int Threhold = Avai_Memory*0.1 / sizeof(string);
	//
	int count = 0;
	string  *temp_data = new string[Threhold];

	while (!in.eof())
	{
		for (int i = 0; i < Threhold && !in.eof(); i++)//ÿ�ζ�ȡ�ռ��ڴ�10%��С�����ݽ�������ȡ��������̵�IO�������Ӷ���ʡ�������е�ʱ�䡣
		{
			temp_data[count].clear();
			getline(in, temp_data[count++]);
		}

		if (in.eof() && count <= Threhold)//ȥ���ļ����һ�����з��ļ���
		{
			count = count - 1;
		}

		for (int i = 0; i < count; i++)//ͳ���ļ��е��ַ���
		{
			hash_map<const string, int>::iterator iter;
			iter = temp_map.find(temp_data[i]);
			if (iter == temp_map.end())
			{
				temp_map.insert(pair<const string, int>(temp_data[i], 1));
			}
			else
			{
				iter->second++;
			}
		}
		count = 0;
	}
	delete[] temp_data;
	in.close();

	hash_map<const string, int>::iterator iter = temp_map.begin();
	for (int i = 0; i < k; i++, iter++)
	{
		hash_map<const string, int> m;
		m.insert(pair<const string, int>(iter->first, iter->second));
		myVector.push_back(m);
	}

	for (int i = 0; i < k / 2 - 1; i++)
	{
		creatSmallHeap(myVector, i);
	}

	for (; iter != temp_map.end(); iter++)
	{
		if (iter->second > myVector[0].begin()->second)
		{
			myVector[0].clear();
			myVector[0].insert(pair<const string, int>(iter->first, iter->second));
			creatSmallHeap(myVector, 0);
		}

	}

	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i].begin()->first << ":" << myVector[i].begin()->second << endl;
	}

}
#include"Sort.h"

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
	if (end <= start || NULL == RawData || start < 0 || end < 0)
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

	thread t1(QuickSort,RawData,start,former-1);
	t1.detach();
	thread t2( QuickSort, RawData, former + 1, end);
	t2.detach();
}
void QuickSortVec(vector<int> &myVector, const int start, const int end)
{
	if (myVector.size() == 0 || start<0 || start >= end) return;
	int key = myVector[start];
	int former = start;
	int latter = end;
	while (former<latter)
	{
		for (; former < latter; latter--)
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
	
	thread t1(QuickSortVec,myVector, start, former - 1);
	t1.detach();
	thread t2(QuickSortVec,myVector, former + 1, end);
	t2.detach();
}

void InsertSort(int *RawData, const int ele_num)
{
	if (NULL == RawData || ele_num <= 0)
		return;
	for (int sort_i = 1; sort_i < ele_num; sort_i++)
	{
		int temp = RawData[sort_i];
		int move_i = sort_i - 1;
		for (; move_i >= 0 && temp< RawData[move_i]; move_i--)
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
			for (int sort_i = i + Incre; sort_i < ele_num; sort_i += Incre)//对每组进行直接插入排序
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

void ModifyHeap(int *RawData, int No_leaf, const int ele_num)
{
	if (NULL == RawData || No_leaf < 0 || ele_num <= 0)
		return;
	int lChild = 2 * No_leaf + 1;//左子节点，索引号从0开始。
	int Child = -1;//需要与父节点想交换的子节点索引号
	for (; lChild < ele_num; No_leaf = Child, lChild = 2 * No_leaf + 1)//将Child赋值给No_leaf的原因在于只有改变过元素的子树才需要重新调整的必要
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
	if (NULL == RawData || 0 >= ele_num)
		return;
	for (int i = ele_num / 2 - 1; i >= 0; i--)//创建初始大顶堆
	{
		ModifyHeap(RawData, i, ele_num);
	}

	for (int i = ele_num - 1; i >= 0; i--)
	{
		int temp = RawData[i];
		RawData[i] = RawData[0];
		RawData[0] = temp;
		ModifyHeap(RawData, 0, i);
	}
}

void BitmapSort(int *RawData, const int ele_num)
{
	bitset<100> sort;
	for (int i = 0; i < ele_num; i++)
	{
		sort[RawData[i]] = 1;
	}
	int record = 0;
	for (int i = 0; i < 100; i++)
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
		int mid = (high + low) / 2;
		MergeSort(RawData, low, mid);
		MergeSort(RawData, mid + 1, high);
		Merge(RawData, low, mid, high);

	}//if end

}

void Merge(int *RawData, int low, int mid, int high)
{
	if (NULL == RawData || low < 0 || mid<0 || low>high) return;
	int * tempData = new int[high - low + 1];
	for (int i = low; i <= high; i++)
	{
		tempData[i - low] = RawData[i];
	}
	int i = -1, j = -1, k = -1;
	for (i = 0, j = mid + 1 - low, k = i + low; i + low <= mid && j + low <= high; k++)
	{
		if (tempData[i] <= tempData[j])
		{
			RawData[k] = tempData[i++];
		}
		else
			RawData[k] = tempData[j++];

	}//此循环之后，可能会存在某一侧的数据没有复制到RawData数组中。因此还需要下面两个循环进行判断，来把剩下的有序元素放进RawData中，两个循环每次只会运行其中的一个。

	while (i <= mid - low) RawData[k++] = tempData[i++];
	while (j <= high - low)	RawData[k++] = tempData[j++];
	delete[] tempData;
}

void StraightSort(int *RawData, int ele_num)
{
	if (NULL == RawData || ele_num <= 0) return;
	int minmum = -1;
	for (int i = 0; i < ele_num - 1; i++)
	{
		minmum = i;
		for (int j = i + 1; j < ele_num; j++)
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
			QuickSortVec(SortVector[i], 0, SortVector[i].size() - 1);
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

		for (int temp_i = 0, k = 0; temp_i < 10; temp_i++)
		{
			for (int temp_j = 0; temp_j < myVector[temp_i].size(); temp_j++)
			{
				RawData[k++] = myVector[temp_i][temp_j];
			}
			myVector[temp_i].clear();
		}

	}

}
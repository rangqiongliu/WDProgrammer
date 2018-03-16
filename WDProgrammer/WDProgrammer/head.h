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
/*
函数功能说明：计算两个字符串的公共子序列的长度
函数入口：ptr1为字符串1，ptr2为字符串2
函数出口：返回ptr1和ptr2两个字符串公共子序列的长度
作者：刘让琼
时间：2018-2-12
参考：《王道程序员》第10.2.1节
*/
int LCS_LENTH(const char *ptr1, const char *ptr2) ;

/*
函数功能说明：获取一维数组的最大和最小值
函数入口：ptr为数组，num_elem为数组元素的个数
函数出口：返回最大和最小值得地址，其中max_min_pt[0]为最大值，max_min_pt[1]为最小值。
作者：刘让琼
时间：2018-2-13
注：模板函数的定义和说明必须在同一个文件中，否则在链接的过程中，调用函数处会出错
*/
template<typename T>
T* getMaxAndMin(const T *ptr, const int num_elem)
{
	if (NULL == ptr || num_elem == 0) return 0;
	if (typeid(*ptr) != typeid(int) && typeid(*ptr) != typeid(float) && typeid(*ptr) != typeid(double))
	{
		cout << "This function is usd for type involved in only int , float ,double" << endl;
	}
	T *max_min_pt = new T[2];
	max_min_pt[0] = -999999999;
	max_min_pt[1] = 999999999;
	for (int i = 0; i < num_elem; i++)
	{
		if (ptr[i] > max_min_pt[0])
			max_min_pt[0] = ptr[i];
		if (ptr[i] < max_min_pt[1])
			max_min_pt[1] = ptr[i];
	}
	return max_min_pt;
}

/*
函数功能说明：计算一维数组中子数组之和的最大值
函数入口：ptr为数组，num_elem为数组元素的个数
函数出口：返回子数组的最大和
作者：刘让琼
时间：2018-2-13
参考：《王道程序员》196页
*/
template<typename T> 
T getMaxSum(const T *ptr, const int num_elem)
{
	if (NULL == ptr || num_elem == 0) return 0;
	if (typeid(*ptr) != typeid( int) && typeid(*ptr) != typeid( float) && typeid(*ptr) != typeid( double))
	{
		cout << "This function is usd for type involved in only int , float ,double" << endl;
	}
	T * max_min_pt = getMaxAndMin(ptr, num_elem);
	if (max_min_pt[0] <= 0) return max_min_pt[0];
	delete[] max_min_pt;
	T maxSum = 0;
	T sum = 0;
	for (int i = 0; i < num_elem; i++)
	{
		sum += ptr[i];
		if (maxSum <= sum)
			maxSum = sum;
		else if(sum<0)
			sum = 0;
	}
	return maxSum;
}

/*
函数功能说明：输出一个中缀表达式的后缀表达式
函数入口：ptr为中缀表达式的字符串
函数出口：不返回数据，直接将后缀表达式打印出来
作者：刘让琼
时间：2018-2-14
*/
void getSuffixExp(const char *ptr);

/*
函数功能说明：判断中缀表达式是否合法，评判的标准为：表达式中只能包含字母，阿拉伯数字，和‘加减乘除’符号。只是简单的做一次评判，并不能判断是否是标准的中缀表达式
函数入口：ptr需要判断的中缀表达式字符串
函数出口：返回true或false
作者：刘让琼
时间：2018-2-14
*/
bool judgeInfixExp(const char *ptr);

/*
函数功能说明：计算中缀表达式中各个字符的优先级，需要根据字符的优先级进行入栈和出栈
函数入口：c 为需要评定的优先级
函数出口：返回c字符的优先级
作者：刘让琼
时间：2018-2-14
*/
int getPrioroty(const char c);


void str2int(const char *ptr);
/*
函数功能说明：给定多个面值不同的硬币，各面值的硬币数给出，求能组成Target钱的组合情况
函数入口：Coin为面值种类，比如{1,2,5,10}，num_elem为面值种类数，num_Coin为每种面值的数量，默认为NULL（即每种面值的数量为无穷大）
函数出口：无返回值，详细组合情况会在函数当中打印出来
作者：刘让琼
时间：2018-2-16
*/
struct C_coin
{
	int m_value;//面值
	C_coin * ptr;
};
void combineCoin(const int * Coin, const int num_elem/*硬币的种类数*/,  const int *num_Coin = NULL);

/*
函数功能说明：打印一维数组
函数入口：需要打印的一维数组首地址，需要打印的元素个数
函数出口：无返回值，详细情况会在函数当中打印出来
作者：刘让琼
时间：2018-3-4
注：传入的元素个数不能超过数组本身的个数，不然会出现错误
*/
template<typename T>
void PrintArray(T * RawData, const int num_elem)
{
	if (NULL == RawData || 0 == num_elem)
	{
		cout << "PrintArray function no parameters passed!"<<endl;
		return;
	}
	if (typeid(RawData) !=  typeid(int *) && typeid(RawData) !=  typeid(double *) && typeid(RawData) != typeid(float *)) 
	{
		cout << "PrintArray function passed wrong parameters!" << endl;
		return;
	}
	for (int i = 0; i < num_elem; i++)
		cout << RawData[i] << "  ";
	cout << endl;
}

/*
函数功能说明：打印二维数组
函数入口：需要打印的二维数组首地址，二维数组的行和列
函数出口：无返回值，详细情况会在函数当中打印出来
作者：刘让琼
时间：2018-3-4
注：传入的行和列必须和二维数组本身的行数和列数一致，不然会出现错误。
调用方式如下：
int a[][10] = { {9,8,4,6,5,8,3,2,6,8},{4,2,5,6,9,7,1,5,6,3 } };
PrintArray(&a[0][0], 2,10);
*/
template<typename T>
void PrintArray(T *RawData, const int row, const int col)
{
	if (NULL == RawData || 0 == row || 0 == col)
	{
		cout << "PrintArray function no parameters passed!" << endl;
		return;
	}
	if (typeid(RawData) !=  typeid(int *) && typeid(RawData) !=  typeid(double *) && typeid(RawData) !=  typeid(float *))
	{
		cout << "PrintArray function passed wrong parameters!" << endl;
		return;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << RawData[i*col+j] << "  ";
		}
		cout << endl;
	}
}

/*
函数功能说明：冒泡排序
函数入口：需要排序的一维数组，以及一维数组的元素个数
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-4
时间复杂度与空间复杂度分析如下：
【时间复杂度】
   最差情况下：
     对于n个元素的一维数组，冒泡排序总共需要进行[(n-1)+(n-2)+(n-3)+...+1]=(n^2-n)/2次比较，即时间复杂度为O(n^2)
     需要移动元素的次数为3*（n^2-n）/2次。
   最好情况下：
     需要进行比较的次数为n-1次。
	 需要移动的系数为0次。
   平均时间复杂度：
     O(n)
【空间复杂度】
    因为就在传入的数组当中进行顺序调换，只需要一个临时的存储变量，所以空间复杂度为O(1)。
【稳定性】
    冒泡排序是一种稳定的排序算法，即排完序后相同的两个元素之间的相对位置是不会发生变化的。
*/
void BubbleSort(int *RawData, const int num_elem);

/*
函数功能说明：快速排序
函数入口：需要排序的一维数组，需要排序的数组开始下标和数组的结束下标。也就是说start的索引是从0开始的
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-5
时间复杂度与空间复杂度分析如下：
【时间复杂度】
    设利用快速排序对n个元素进行排序是的时间复杂度为T(n).
  最差情况下：
    对于n个元素的一维数组，最差的情况便是每次二分时，n个元素分成n-1个和1个；因每次调用快速排序会进行end-start次比较；
	所以，在第一次调用时：T(n)=T(n-1)+n+T(1)--------->说明T(n-1),T(1)为对二分后的两部分数据进行排序的时间复杂度，n为该次排序已经进行了n次比较。可结合具体的程序分析
	      在第二次调用时：T(n)=[T(n-2)+(n-1)+T(1)]+n+T(1)
		  依此类推：T(n)=(n^2+n)/2+n，即时间复杂度为O(n^2)
  最好情况下：
    对于n个一维数组，最好的情况便是每次而分时，n个元素恰好被分成n/2、n/2;
	所以，第一次调用时：T(n)=2*T(n/2)+n;
	      第二次调用时：T(n)=2*(2*T(n/4)+n/2)+n;

		  当第x调用时已经排完，则T(n)=2^x+n*x;而2^x=n,x=logn;
		  因此，T(n)=n+nlogn,时间复杂度为O(nlogn)
  平均情况下：
    每次被二分是不确定左右两边的个数，其最后的时间复杂度也是O(nlogn)

【空间复杂度】
  因为就在传入的数组当中进行顺序调换，每次递归都需要一个临时变量存储比对值，在快排为逆序的时候，需要递归n次，因此空间复杂度为O(n)。
【稳定性】
  快速排序是一种不稳定的排序算法，即排完序后相同的两个元素之间的相对位置会发生变化。
*/
void QuickSort(int *RawData, const int start, const int end);
void QuickSort(vector<int> &myVector, const int start, const int end);
/*
函数功能说明：插入排序
函数入口：需要排序的一维数组，以及数组的元素个数
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-6
时间复杂度与空间复杂度分析如下：
【时间复杂度】
   最差情况下：
	 即数组的元素恰好全部是逆序；
	 第一次：比较1次
	 第二次：比较2次
	 第n-1次：比较n-1次
	 所以时间复杂度为1+2+3+...+(n-1)=(n^2-n)/2==>O(n^2)
   最好情况下：
     即数组的元素全部为正序，就恰好从头到尾判断一遍，即O(n)
   平均情况下：
     O(n^2)
【空间复杂度】
    因为就在传入的数组当中进行顺序调换，只需要一个临时的存储变量，所以空间复杂度为O(1)。
【稳定性】
    快速排序是一种稳定的排序算法，即排完序后相同的两个元素之间的相对位置不会发生变化。
*/
void InsertSort(int *RawData, const int ele_num);


/*
函数功能说明：希尔排序
函数入口：需要排序的一维数组，以及数组的元素个数
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-7
时间复杂度与空间复杂度分析如下：
【时间复杂度】
最差情况下：
	即每次分组后，分组的情况恰好都是逆序的
	第一次：每组2个元素，比较1*n/2次
	第二次：每组4个元素，比较（1+2+3）*n/4
	第x次：每组2^x个元素,比较(1+2+3+2^x-1)*n/2^x
	累加求极限，可得最坏情况下复杂度为O(n^2)
最好情况下：
	O(nlogn)
平均情况下：
	O(n^2),但比O(n^2)小，取决于增量；所以比冒泡排序要快，比快排要慢很多
【空间复杂度】
	因为就在传入的数组当中进行顺序调换，只需要一个临时的存储变量，所以空间复杂度为O(1)。
【稳定性】
	希尔排序是一种不稳定的排序算法，即排完序后相同的两个元素之间的相对位置会发生变化。
*/
void ShellSort(int *RawData, const int ele_num);


/*
函数功能说明：从下至上将数组调整为最大堆
函数入口：RawData需要调整的数组，从第No_leaf（索引从0开始）个开始自顶向下调整子树为最大堆，ele_num数组总的元素个数
函数出口：无返回值，调整好的结果又形参数组直接带回
作者：刘让琼
时间：2018-03-08
*/
void ModifyHeap(int *RawData, int No_leaf, const int ele_num);

/*
函数功能说明：堆排序
函数入口：需要排序的一维数组，以及数组的元素个数
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-8
时间复杂度与空间复杂度分析如下：
【时间复杂度】
最差情况下：
	首先要对无序数组创建初始最大堆（HeapSort的第一个循环），会从最后一个非叶子节点开始调整其子树为最大堆。
	假设该完全二叉树的高度为H（从0开始计数），总的元素个数为n所以最后一排非叶子节点总共需要向下调整2^(H-1)*1
	倒数第二排需要向下调整：2^(H-2)*2
	倒数第三排需要向下调整：2^(H-3)*3
	最顶一排需要向下调整  ：2^(0)*H
	所以总共需要调整次数为：S=2^(H-1)*1+2^(H-2)*2+2^(H-3)*3+...+2^(0)*H
	其中H=logn;
	所以S=2*n--2-logn;所以创建初始大顶堆的时间复杂度为O(n)

	HeapSort的第二个循环：
	每次顶端元素与尾部元素调换后，需要从顶元素到未排好尾部元素重新调整为最大堆
	第一次交换后，需要调整log(n-1)次
	第二次交换后，需要调整log(n-2)次

	第n-1次交换后，需要调整为log(1)次
	所以S=log(n-1)+log(n-2)+...+log(1)
	====>S=logn!
	又因为：(n/2)^(n/2)<=n!<=n^n
	所以S取极限时为：S=nlogn，所以最终堆排序的时间复杂度为O(nlogn)
最好情况下：
	O(nlogn)
平均情况下：
	O(nlogn)
【空间复杂度】
	因为就在传入的数组当中进行顺序调换，只需要一个临时的存储变量，所以空间复杂度为O(1)。
【稳定性】
	堆排序是一种不稳定的排序算法，即排完序后相同的两个元素之间的相对位置会发生变化。
*/
void HeapSort(int *RawData, const int ele_num);

/*
函数功能：位图排序
日期：2018-03-08
说明：这个函数值简单的实现了位图排序的基本原理，最大输入100以内，不能有重复的数据。
*/
void BitmapSort(int *RawData, const int ele_num);


/*
函数功能说明：归并排序
函数入口：需要排序的一维数组，数组的最低索引（从0开始），数组的最高索引
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-9
时间复杂度与空间复杂度分析如下：
【时间复杂度】
最差情况下：
	最初始分组，即每组一个元素，总共对比次数为1*n/2次
	第二次：即每组两个元素，总共组多需要对比2*n/4次
	第三次，即每组四个元素，总共最多需要对比4*n/8次
	第x次全部合并完，即每组有2^x个元素，总共做多需要对比2^（x-1）*n/(2^x)次
	所以总共需要的时间复杂度为O(nlogn)
最好情况下：
	O(nlogn)
平均情况下：
	O(nlogn)
【空间复杂度】
	因为每次在Merge的时候需要用到一个大小为high-low+1的数组来存储临时值，其high-low+1的最大值就是最后一次大的合并，大小为n，所以空间复杂度为O(n)。
【稳定性】
	归并排序是一种不稳定的排序算法，即排完序后相同的两个元素之间的相对位置不会发生变化。
*/
void MergeSort(int *RawData, int low, int high);
void Merge(int *RawData, int low, int mid, int high);

/*
函数功能说明：直接排序
函数入口：需要排序的一维数组，数组元素的个数
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-9
时间复杂度与空间复杂度分析如下：
【时间复杂度】
最差的情况下：
	第一次比较n-1次，
	第二次比较n-2次，
	第三次比较n-3次，
	第n-1次比较1次，
	所以：S=（n-1）+（n-2）+（n-3）+...+1=(n^2-n)/2
	时间复杂度为O(n^2)
最好情况下：
	O(n^2)
平均情况下：
	O(n^2)
【空间复杂度】
	两个元素需要交换的时候需要一个临时变量，所以空间复杂度为O(1)
【稳定性】
	直接排序是一种不稳定的排序算法，即排完序后相同的两个元素之间的相对位置不会发生变化。
*/
void StraightSort(int *RawData, int ele_num);

/*
函数功能说明：桶排序
函数入口：需要排序的vector，这里选用vector，纯粹为是了调用方便使用库函数max_element，懒得去写查找数组里的最大值函数了。
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-9
时间复杂度与空间复杂度分析如下：
【时间复杂度】
最差的情况下：
	将所有待排序的N元素分别配到M个桶中，时间复杂度为O(N)

	对每个桶中的数列（假如每个桶中的元素为N/M个）进行排序（最快的时间复杂度为O(NlogN)），

	所以桶排序总的复杂度为：O(N)+O(M*N/Mlog(N/M))==>O(N+NlogN/M)

最好情况下：
	当M=N时，时间复杂度为O(N)
平均情况下：
	O(N+NlogN/M)
【空间复杂度】
	空间主要与桶的个数有关，所以空间复杂度为O(M)
【稳定性】
	桶排序的稳定性依赖于桶内元素排序时所使用的排序算法

备注：该算法只是简单的实现了桶排序的一个基本原理，其中对待排序元素分桶时使用的是x/10,x为待排序元素。x/10得到的数就是分配到桶的索引号。
*/
void BucketSort(vector<int> &myVector);

/*
函数功能：获取一个整型数据指定位置的数值，方向是从个位向高位递增，比如getNum(1234,2)，返回的是3
作者：刘让琼
日期：2018-03-11
*/
int getNum(int value, int order);

/*
函数功能说明：基数排序
函数入口：需要排序的vector，这里选用vector，纯粹为是了调用方便使用库函数max_element，懒得去写查找数组里的最大值函数了。
函数出口：无返回值，排好序的数组由形参直接带回
作者：刘让琼
时间：2018-3-11
时间复杂度与空间复杂度分析如下：
【时间复杂度】
最差的情况下：
	假设待排序中的最大数有d位关键码，关键码的取值范围为radix，待排序的元素有n个
	则需要d次循环，每次循环中，首先要对n个u元素分配到radix个桶中，分完之后有得把radix个桶中的元素回收到原来的数组中。
	所以最后的时间复杂度为O(d*(n=r+radix))

最好情况下：
	O(d*(n=r+radix))
平均情况下：
	O(d*(n=r+radix))
【空间复杂度】
	O(n+radix) radix为桶的个数
【稳定性】
	稳定排序

备注：该算法只是简单的实现了基数排序的一个基本原理。可以说基数排序是桶排序的一种特殊情况。
*/
void RadixSort(vector<int> &RawData);

/*
函数功能：在一个已经按升序排序的整型数组中查找某一个数
函数入口：RawData：需要查找的数组源，ele_num：数组包含的元素个数，value：需要被查找的值
函数出口：如果value存在于RawData中，则返回value在RawData中的索引号，如果不存在则返回-1
日期：2018-03-12
作者：刘让琼
时间复杂度：O(logn）

*/
int Binary_Search(int *RawData, const int ele_num, const int value);


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

/*
函数功能：将一个字符串中多余的空格删除掉，即字符串的第一个字符和最后一个字符为空格的话，会被删掉，中间如果连续出现两个及两个以上的空格只会保留一个
函数入口：一个指向字符串的指针
函数出口：最后的处理结果直接打印在屏幕上
日期：2018-03-12
作者：刘让琼
时间复杂度：O(n)
*/
void compressSpace(char *myChar);

/*
函数功能：生成大量的整型、16字节字符串、IP地址
函数入口：kind为1时，生成整型数据（范围0-100000000），为2时：生成16字节字符串（a-z），为3时：生成IP地址；num：需要生成的个数；percent：允许本函数使用当前可用内存的百分比；file_name：保存的文件名。
函数出口：无返回值，生成的数据全部存入txt文件中。
日期：2018-03-13
作者：刘让琼
备注：函数内部会根据当前系统可用内存来进行分批将数据写入内存，本函数最多占用系统当前可用内存的10%。

*/
void generateBigData(const int kind, const int num, float percent,string file_name);

/*
函数功能：将堆中的No_leaf父节点下沉到合适位置，符合最小堆的原则
函数入口：RawData为数组，No_leaf为父节点索引，k为数组的元素个数；其重载函数中myVector是一个装有hash_map<const string,int>元素的容器，利用hash_map容易统计字符串出现的个数
函数出口：由RawData数组带回
日期：2018-03-13
作者：刘让琼
备注：该函数只能辅助完成建立小顶堆，如果要建立小顶堆，则从第一个父节点到最后一个父节点循环调用该函数就行。
*/
void creatSmallHeap(int *RawData, int No_leaf,const int k);
void creatSmallHeap(vector<hash_map<const string,int>> &myVector, int No_leaf);
/*
函数功能：从海量数据中，找出最大的K个数
函数入口：file_name:数据存放文件;k:需要找出最大数的个数
函数出口：最终的K个数直接打印在屏幕上
日期：2018-03-13
作者：刘让琼
备注：为防止本函数过度占用内存，每次只会从海量数据中读取可用内存空间的10%进入到程序。
*/
void TopK_Heap(string file_name, const int k);

/*
函数功能：从海量数据中，找出K个出现频率最大的字符串
函数入口：file_name：字符串存放文件；k：需要找出最大数的个数
函数出口：最终的字符串以及出现的次数会直接打印在屏幕上
日期：2018-03-14
作者：刘让琼
备注：为防止本函数过度占用内存，每次只会从海量数据中读取可用内存空间的10%进入到程序。
其次，本函数只是为了实践对海量字符串寻找top_k问题。如果海量字符串中，不同的字符串也是海量的，那本函数暂时处理不了。
目前本函数只能求解不同字符串数量较少（<1w）情况下的topK问题。如果不同字符串的数量较多时，可将原数据通过hash映射到多个文件，然后再调用该函数逐步处理即可

由于读取文件的时候是读入到string类型的对象中，每个字符串放入hash_map时也会占用较大时间。因此在读取字符串和将字符串放入hash_map占用该函数95%的运行时间。
*/
void StringTopK_map(string file_name, const int k);


class Graph
{
public:
	
	Graph(const int n);
	virtual ~Graph();
public:
	void setEdge(int * weight);
	void dijstra(int start, int *distance, int *path);
	void Prim() ;// TO DO
	void Floyd();//TO DO
	void Kruskal();//TO DO
private:
	vector<int> *m_edge;
	int num_vertex;
};

class C {
public:
	C()
	{
		cout << "C" << endl;
	}
};
class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};


class B :public C, public A
{

public:
	B()
	{
		cout << "B" << endl;
	}

	~B()
	{
		cout << "B" << endl;
	}
};


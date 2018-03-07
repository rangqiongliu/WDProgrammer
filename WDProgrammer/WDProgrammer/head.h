#pragma once
#define INF 9999999
#include<iostream>
#include<typeinfo>
using namespace std;
/*
函数功能说明：计算两个字符串的公共子序列的长度
函数入口：ptr1为字符串1，ptr2为字符串2
函数出口：返回ptr1和ptr2两个字符串公共子序列的长度
作者：刘让琼
时间：2018-2-12
参考：《王道程序员》第10.2.1节
*/
int LCS_LENTH(const char *ptr1, const char *ptr2);

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
  因为就在传入的数组当中进行顺序调换，只需要一个临时的存储变量，所以空间复杂度为O(1)。
【稳定性】
  快速排序是一种不稳定的排序算法，即排完序后相同的两个元素之间的相对位置会发生变化。
*/
void QuickSort(int *RawData, const int start, const int end);

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
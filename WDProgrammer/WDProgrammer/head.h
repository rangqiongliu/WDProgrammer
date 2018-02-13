#pragma once
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
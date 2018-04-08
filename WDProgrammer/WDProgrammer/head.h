/*
文件说明：head.h和head.cpp是声明和实现一些常见的笔试题，和一些辅助性功能函数。
	函数1：寻找两个字符串之间的公共子串，返回子串的长度
	函数2：从一维数组中，寻找最大值和最小值
	函数3：计算一个数组中子串的最大和
	函数4：计算一个方程的后缀表达式
	函数5：将字符转换成整型或者浮点型
	函数6：打印一维或者二维（重载）数组
*/
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define INF 99999999
#include<iostream>
#include<typeinfo>
#include"Sort.h"
#include<memory>
#include<math.h>
#include<map>
#include<ctime>
using namespace std;
/*
函数1：
函数功能说明：计算两个字符串的公共子序列的长度
函数入口：ptr1为字符串1，ptr2为字符串2
函数出口：返回ptr1和ptr2两个字符串公共子序列的长度
作者：刘让琼
时间：2018-2-12
参考：《王道程序员》第10.2.1节
*/
int LCS_LENTH(const char *ptr1, const char *ptr2) ;

/*
函数2：
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
函数3：
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
函数4：
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

/*
函数5：
函数功能说明：将字符转换成int或者double
*/
void str2int(const char *ptr);


/*
函数6：
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
函数功能：将一个字符串中多余的空格删除掉，即字符串的第一个字符和最后一个字符为空格的话，会被删掉，中间如果连续出现两个及两个以上的空格只会保留一个
函数入口：一个指向字符串的指针
函数出口：最后的处理结果直接打印在屏幕上
日期：2018-03-12
作者：刘让琼
时间复杂度：O(n)
*/
void compressSpace(char *myChar);

/*
函数功能：网易春招实习笔试题，第三题。大致要求如下：
	 给定一个3*3矩阵A（1-9）；其中每一个子矩阵（2*2）作为一个整体可以进行90 180 270度旋转，再给定一个3*3的目标矩阵B；
	 求A->B至少需要旋转多少次
函数出口：最后的处理结果直接打印在屏幕上
日期：2018-03-12
作者：刘让琼
*/
int RotaryCube();

/*
函数功能：携程笔试题，第二题，大致要求如下：
		输入一个N*N的矩阵，对输入的矩阵顺时针旋转90度。
函数出口：旋转后的结果直接打印在屏幕上
日期：2018-03-29
作者：刘让琼
*/
void  RotateMatrix();

/*
函数功能呢：计算一个日期是星期几
函数入口：一个string型字符串，格式为20180408
函数出口：0~6中的一个数，其中0代表星期天，1代表星期一，以此类推
日期：2018-04-08
作者：刘让琼
*/
int calWeek(string str="123");

struct Point2D
{
	double x;
	double y;
	Point2D():x(0),y(0){}
	Point2D(double a,double b):x(a),y(b){}
};

int countPointNumOnLine(vector<Point2D>myVector);

void sing();

void mission();
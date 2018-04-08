/*
�ļ�˵����head.h��head.cpp��������ʵ��һЩ�����ı����⣬��һЩ�����Թ��ܺ�����
	����1��Ѱ�������ַ���֮��Ĺ����Ӵ��������Ӵ��ĳ���
	����2����һά�����У�Ѱ�����ֵ����Сֵ
	����3������һ���������Ӵ�������
	����4������һ�����̵ĺ�׺���ʽ
	����5�����ַ�ת�������ͻ��߸�����
	����6����ӡһά���߶�ά�����أ�����
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
����1��
��������˵�������������ַ����Ĺ��������еĳ���
������ڣ�ptr1Ϊ�ַ���1��ptr2Ϊ�ַ���2
�������ڣ�����ptr1��ptr2�����ַ������������еĳ���
���ߣ�������
ʱ�䣺2018-2-12
�ο�������������Ա����10.2.1��
*/
int LCS_LENTH(const char *ptr1, const char *ptr2) ;

/*
����2��
��������˵������ȡһά�����������Сֵ
������ڣ�ptrΪ���飬num_elemΪ����Ԫ�صĸ���
�������ڣ�����������Сֵ�õ�ַ������max_min_pt[0]Ϊ���ֵ��max_min_pt[1]Ϊ��Сֵ��
���ߣ�������
ʱ�䣺2018-2-13
ע��ģ�庯���Ķ����˵��������ͬһ���ļ��У����������ӵĹ����У����ú����������
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
����3��
��������˵��������һά������������֮�͵����ֵ
������ڣ�ptrΪ���飬num_elemΪ����Ԫ�صĸ���
�������ڣ����������������
���ߣ�������
ʱ�䣺2018-2-13
�ο�������������Ա��196ҳ
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
����4��
��������˵�������һ����׺���ʽ�ĺ�׺���ʽ
������ڣ�ptrΪ��׺���ʽ���ַ���
�������ڣ����������ݣ�ֱ�ӽ���׺���ʽ��ӡ����
���ߣ�������
ʱ�䣺2018-2-14
*/
void getSuffixExp(const char *ptr);

/*
��������˵�����ж���׺���ʽ�Ƿ�Ϸ������еı�׼Ϊ�����ʽ��ֻ�ܰ�����ĸ�����������֣��͡��Ӽ��˳������š�ֻ�Ǽ򵥵���һ�����У��������ж��Ƿ��Ǳ�׼����׺���ʽ
������ڣ�ptr��Ҫ�жϵ���׺���ʽ�ַ���
�������ڣ�����true��false
���ߣ�������
ʱ�䣺2018-2-14
*/
bool judgeInfixExp(const char *ptr);

/*
��������˵����������׺���ʽ�и����ַ������ȼ�����Ҫ�����ַ������ȼ�������ջ�ͳ�ջ
������ڣ�c Ϊ��Ҫ���������ȼ�
�������ڣ�����c�ַ������ȼ�
���ߣ�������
ʱ�䣺2018-2-14
*/
int getPrioroty(const char c);

/*
����5��
��������˵�������ַ�ת����int����double
*/
void str2int(const char *ptr);


/*
����6��
��������˵������ӡһά����
������ڣ���Ҫ��ӡ��һά�����׵�ַ����Ҫ��ӡ��Ԫ�ظ���
�������ڣ��޷���ֵ����ϸ������ں������д�ӡ����
���ߣ�������
ʱ�䣺2018-3-4
ע�������Ԫ�ظ������ܳ������鱾��ĸ�������Ȼ����ִ���
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
��������˵������ӡ��ά����
������ڣ���Ҫ��ӡ�Ķ�ά�����׵�ַ����ά������к���
�������ڣ��޷���ֵ����ϸ������ں������д�ӡ����
���ߣ�������
ʱ�䣺2018-3-4
ע��������к��б���Ͷ�ά���鱾�������������һ�£���Ȼ����ִ���
���÷�ʽ���£�
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
�������ܣ���һ���ַ����ж���Ŀո�ɾ���������ַ����ĵ�һ���ַ������һ���ַ�Ϊ�ո�Ļ����ᱻɾ�����м�������������������������ϵĿո�ֻ�ᱣ��һ��
������ڣ�һ��ָ���ַ�����ָ��
�������ڣ����Ĵ�����ֱ�Ӵ�ӡ����Ļ��
���ڣ�2018-03-12
���ߣ�������
ʱ�临�Ӷȣ�O(n)
*/
void compressSpace(char *myChar);

/*
�������ܣ����״���ʵϰ�����⣬�����⡣����Ҫ�����£�
	 ����һ��3*3����A��1-9��������ÿһ���Ӿ���2*2����Ϊһ��������Խ���90 180 270����ת���ٸ���һ��3*3��Ŀ�����B��
	 ��A->B������Ҫ��ת���ٴ�
�������ڣ����Ĵ�����ֱ�Ӵ�ӡ����Ļ��
���ڣ�2018-03-12
���ߣ�������
*/
int RotaryCube();

/*
�������ܣ�Я�̱����⣬�ڶ��⣬����Ҫ�����£�
		����һ��N*N�ľ��󣬶�����ľ���˳ʱ����ת90�ȡ�
�������ڣ���ת��Ľ��ֱ�Ӵ�ӡ����Ļ��
���ڣ�2018-03-29
���ߣ�������
*/
void  RotateMatrix();

/*
���������أ�����һ�����������ڼ�
������ڣ�һ��string���ַ�������ʽΪ20180408
�������ڣ�0~6�е�һ����������0���������죬1��������һ���Դ�����
���ڣ�2018-04-08
���ߣ�������
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
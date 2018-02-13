#pragma once
#include<iostream>
#include<typeinfo>
using namespace std;
/*
��������˵�������������ַ����Ĺ��������еĳ���
������ڣ�ptr1Ϊ�ַ���1��ptr2Ϊ�ַ���2
�������ڣ�����ptr1��ptr2�����ַ������������еĳ���
���ߣ�������
ʱ�䣺2018-2-12
�ο�������������Ա����10.2.1��
*/
int LCS_LENTH(const char *ptr1, const char *ptr2);

/*
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
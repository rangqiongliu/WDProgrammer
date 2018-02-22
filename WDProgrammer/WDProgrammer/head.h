#pragma once
#define INF 9999999
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

/*
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



void str2int(const char *ptr);
/*
��������˵�������������ֵ��ͬ��Ӳ�ң�����ֵ��Ӳ�����������������TargetǮ��������
������ڣ�CoinΪ��ֵ���࣬����{1,2,5,10}��num_elemΪ��ֵ��������num_CoinΪÿ����ֵ��������Ĭ��ΪNULL����ÿ����ֵ������Ϊ�����
�������ڣ��޷���ֵ����ϸ���������ں������д�ӡ����
���ߣ�������
ʱ�䣺2018-2-16
*/
struct C_coin
{
	int m_value;//��ֵ
	C_coin * ptr;
};
void combineCoin(const int * Coin, const int num_elem/*Ӳ�ҵ�������*/,  int *num_Coin = NULL);
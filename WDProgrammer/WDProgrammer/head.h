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
void combineCoin(const int * Coin, const int num_elem/*Ӳ�ҵ�������*/,  const int *num_Coin = NULL);

/*
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
��������˵����ð������
������ڣ���Ҫ�����һά���飬�Լ�һά�����Ԫ�ظ���
�������ڣ��޷���ֵ���ź�����������β�ֱ�Ӵ���
���ߣ�������
ʱ�䣺2018-3-4
ʱ�临�Ӷ���ռ临�Ӷȷ������£�
��ʱ�临�Ӷȡ�
   �������£�
     ����n��Ԫ�ص�һά���飬ð�������ܹ���Ҫ����[(n-1)+(n-2)+(n-3)+...+1]=(n^2-n)/2�αȽϣ���ʱ�临�Ӷ�ΪO(n^2)
     ��Ҫ�ƶ�Ԫ�صĴ���Ϊ3*��n^2-n��/2�Ρ�
   �������£�
     ��Ҫ���бȽϵĴ���Ϊn-1�Ρ�
	 ��Ҫ�ƶ���ϵ��Ϊ0�Ρ�
   ƽ��ʱ�临�Ӷȣ�
     O(n)
���ռ临�Ӷȡ�
    ��Ϊ���ڴ�������鵱�н���˳�������ֻ��Ҫһ����ʱ�Ĵ洢���������Կռ临�Ӷ�ΪO(1)��
���ȶ��ԡ�
    ð��������һ���ȶ��������㷨�������������ͬ������Ԫ��֮������λ���ǲ��ᷢ���仯�ġ�
*/
void BubbleSort(int *RawData, const int num_elem);

/*
��������˵������������
������ڣ���Ҫ�����һά���飬��Ҫ��������鿪ʼ�±������Ľ����±ꡣҲ����˵start�������Ǵ�0��ʼ��
�������ڣ��޷���ֵ���ź�����������β�ֱ�Ӵ���
���ߣ�������
ʱ�䣺2018-3-5
ʱ�临�Ӷ���ռ临�Ӷȷ������£�
��ʱ�临�Ӷȡ�
    �����ÿ��������n��Ԫ�ؽ��������ǵ�ʱ�临�Ӷ�ΪT(n).
  �������£�
    ����n��Ԫ�ص�һά���飬�����������ÿ�ζ���ʱ��n��Ԫ�طֳ�n-1����1������ÿ�ε��ÿ�����������end-start�αȽϣ�
	���ԣ��ڵ�һ�ε���ʱ��T(n)=T(n-1)+n+T(1)--------->˵��T(n-1),T(1)Ϊ�Զ��ֺ�����������ݽ��������ʱ�临�Ӷȣ�nΪ�ô������Ѿ�������n�αȽϡ��ɽ�Ͼ���ĳ������
	      �ڵڶ��ε���ʱ��T(n)=[T(n-2)+(n-1)+T(1)]+n+T(1)
		  �������ƣ�T(n)=(n^2+n)/2+n����ʱ�临�Ӷ�ΪO(n^2)
  �������£�
    ����n��һά���飬��õ��������ÿ�ζ���ʱ��n��Ԫ��ǡ�ñ��ֳ�n/2��n/2;
	���ԣ���һ�ε���ʱ��T(n)=2*T(n/2)+n;
	      �ڶ��ε���ʱ��T(n)=2*(2*T(n/4)+n/2)+n;

		  ����x����ʱ�Ѿ����꣬��T(n)=2^x+n*x;��2^x=n,x=logn;
		  ��ˣ�T(n)=n+nlogn,ʱ�临�Ӷ�ΪO(nlogn)
  ƽ������£�
    ÿ�α������ǲ�ȷ���������ߵĸ�����������ʱ�临�Ӷ�Ҳ��O(nlogn)

���ռ临�Ӷȡ�
  ��Ϊ���ڴ�������鵱�н���˳�������ֻ��Ҫһ����ʱ�Ĵ洢���������Կռ临�Ӷ�ΪO(1)��
���ȶ��ԡ�
  ����������һ�ֲ��ȶ��������㷨�������������ͬ������Ԫ��֮������λ�ûᷢ���仯��
*/
void QuickSort(int *RawData, const int start, const int end);

/*
��������˵������������
������ڣ���Ҫ�����һά���飬�Լ������Ԫ�ظ���
�������ڣ��޷���ֵ���ź�����������β�ֱ�Ӵ���
���ߣ�������
ʱ�䣺2018-3-6
ʱ�临�Ӷ���ռ临�Ӷȷ������£�
��ʱ�临�Ӷȡ�
   �������£�
	 �������Ԫ��ǡ��ȫ��������
	 ��һ�Σ��Ƚ�1��
	 �ڶ��Σ��Ƚ�2��
	 ��n-1�Σ��Ƚ�n-1��
	 ����ʱ�临�Ӷ�Ϊ1+2+3+...+(n-1)=(n^2-n)/2==>O(n^2)
   �������£�
     �������Ԫ��ȫ��Ϊ���򣬾�ǡ�ô�ͷ��β�ж�һ�飬��O(n)
   ƽ������£�
     O(n^2)
���ռ临�Ӷȡ�
    ��Ϊ���ڴ�������鵱�н���˳�������ֻ��Ҫһ����ʱ�Ĵ洢���������Կռ临�Ӷ�ΪO(1)��
���ȶ��ԡ�
    ����������һ���ȶ��������㷨�������������ͬ������Ԫ��֮������λ�ò��ᷢ���仯��
*/
void InsertSort(int *RawData, const int ele_num);


/*
��������˵����ϣ������
������ڣ���Ҫ�����һά���飬�Լ������Ԫ�ظ���
�������ڣ��޷���ֵ���ź�����������β�ֱ�Ӵ���
���ߣ�������
ʱ�䣺2018-3-7
ʱ�临�Ӷ���ռ临�Ӷȷ������£�
��ʱ�临�Ӷȡ�
�������£�
	��ÿ�η���󣬷�������ǡ�ö��������
	��һ�Σ�ÿ��2��Ԫ�أ��Ƚ�1*n/2��
	�ڶ��Σ�ÿ��4��Ԫ�أ��Ƚϣ�1+2+3��*n/4
	��x�Σ�ÿ��2^x��Ԫ��,�Ƚ�(1+2+3+2^x-1)*n/2^x
	�ۼ����ޣ��ɵ������¸��Ӷ�ΪO(n^2)
�������£�
	O(nlogn)
ƽ������£�
	O(n^2),����O(n^2)С��ȡ�������������Ա�ð������Ҫ�죬�ȿ���Ҫ���ܶ�
���ռ临�Ӷȡ�
	��Ϊ���ڴ�������鵱�н���˳�������ֻ��Ҫһ����ʱ�Ĵ洢���������Կռ临�Ӷ�ΪO(1)��
���ȶ��ԡ�
	ϣ��������һ�ֲ��ȶ��������㷨�������������ͬ������Ԫ��֮������λ�ûᷢ���仯��
*/
void ShellSort(int *RawData, const int ele_num);
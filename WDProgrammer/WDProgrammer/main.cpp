#include"head.h"
#include<iostream>
#include<typeinfo>
using namespace std;

void main()
{
	/*���������ַ����У�������������еĳ���
	char Seq1[100];
	char Seq2[100];
	cout << "Please Enter the 1st Sequence:";
	cin >> Seq1;
	cout << "Please Enter the 2nd Sequence:";
	cin >> Seq2;
	cout << "The longest common subsequence's lenth is:" << LCS_LENTH(Seq1, Seq2) << endl;
	*/

	/*���Լ���һ��������������֮�͵����ֵ��
	double ptr[] = {-2,-5,-3,-6,-4,-8,-6};
	cout << getMaxSum(ptr, sizeof(ptr) / sizeof(double)) << endl;
	*/
	//char * a = "a+b*(c-d)/e-f";
	//getSuffixExp(a);
	//�����ַ�ת���ֵĺ���
	//char a[] = "123.4576";
	//str2int(a);
	//��������
	int a[] = { 9,8,4,6,5,8,3,2,6,8,4,2,5,6,9,7,1,5,6,3 };
	QuickSort(a,  0,sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
	
}
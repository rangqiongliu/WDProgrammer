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
	//int a[] = {9,8,7,6,5,4,3,2,12,23,34,45,56,67,78,89,93,100,110,120,150,197,200,160,179,189};
	//�����ǶԻ�������Ĳ���
	//vector<int> myVector= { 9,8,7,6,5,4,3,2,12,23,34,45,56,67,78,89,93,100,110,120,150,197,200,160,179,189 };
	//RadixSort(myVector);
	//for (int i = 0; i < myVector.size(); i++)
	//	cout << myVector[i] << " ";
	//cout << endl;
	//�����ǶԶ��ֲ��ҵĲ���
	//int a[] = {1,2,3,4,5,6,7,8,9,10,15,16};
	//cout << Binary_Search(a, sizeof(a) / sizeof(int), 8) << endl;

	Trie a;
	char *str_pt[] = {"liuzhenfang","liurangqiong","hanwangxin"};
	for (int i = 0; i < 3; i++)
	{
		a.Insert(str_pt[i]);
	}
	cout << a.Check("hanwangxi") << endl;
}
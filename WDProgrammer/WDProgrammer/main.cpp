#include"head.h"
#include<iostream>
#include<typeinfo>
using namespace std;

void main()
{
	/*计算两个字符串中，其最长公共子序列的长度
	char Seq1[100];
	char Seq2[100];
	cout << "Please Enter the 1st Sequence:";
	cin >> Seq1;
	cout << "Please Enter the 2nd Sequence:";
	cin >> Seq2;
	cout << "The longest common subsequence's lenth is:" << LCS_LENTH(Seq1, Seq2) << endl;
	*/

	/*测试计算一个数组中子数组之和的最大值。
	double ptr[] = {-2,-5,-3,-6,-4,-8,-6};
	cout << getMaxSum(ptr, sizeof(ptr) / sizeof(double)) << endl;
	*/
	//char * a = "a+b*(c-d)/e-f";
	//getSuffixExp(a);
	//测试字符转数字的函数
	//char a[] = "123.4576";
	//str2int(a);
	//测试排序
	int a[] = { 1,2,38,8,8,4,4,4,4,5,6,9,7,2,6,8,10 };
	HeapSort(a,  sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	
}
#include"head.h"
#include"BiTree.h"
#include"Graph.h"
#include"Search.h"
#include"Sort.h"
#include"Trie.h"
#include<iostream>
#include<typeinfo>
#include<map>
#include<string>
#include <iomanip>
//#include<hash_map>
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
	//int a[] = {9,8,7,6,5,4,3,2,12,23,34,45,56,67,78,89,93,100,110,120,150,197,200,160,179,189};
	//以下是对基数排序的测试
	//vector<int> myVector= { 9,8,7,6,5,4,3,2,12,23,34,45,56,67,78,89,93,100,110,120,150,197,200,160,179,189 };
	//RadixSort(myVector);
	//for (int i = 0; i < myVector.size(); i++)
	//	cout << myVector[i] << " ";
	//cout << endl;
	//以下是对二分查找的测试
	//int a[] = {1,2,3,4,5,6,7,8,9,10,15,16};
	//cout << Binary_Search(a, sizeof(a) / sizeof(int), 8) << endl;
	//
	//Trie a;
	//cout<<a.repeatNum("ana", "anananananana")<<endl;
	//测试压缩多余空格函数
	//char *p = " liuzhenfang    liurangqiong hanwangxin            dengyang ";
	//compressSpace(p);
	
	//generateBigData(2, 10000, 0.1,"string.txt");

	//以下是对海量数据中寻找topK函数的测试。为了有对比，只设置了10000个数据，验证了利用小顶堆寻找topK的正确性
	
	/*ifstream in("data.txt");
	int *data = new int[10000];
	for (int i = 0; !in.eof(); i++)
		in >> data[i];
	QuickSort(data, 0, 9999);
	for (int i = 19; i >=0; i--)
	{
		cout << data[9999-i] << "  ";
	}
	cout << endl;
	TopK_Heap("data.txt", 20);*/
	//测试：寻找字符串中出现频率最高的K个字符串。
	//StringTopK_map("string.txt", 10);
	//Graph a(5);
	// cout << a.hadis << endl;
	string a = "liurangqiong";
	cout << a.substr(0,5) << endl;
}
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
	//
	//Trie a;
	//cout<<a.repeatNum("ana", "anananananana")<<endl;
	//����ѹ������ո���
	//char *p = " liuzhenfang    liurangqiong hanwangxin            dengyang ";
	//compressSpace(p);
	
	//generateBigData(2, 10000, 0.1,"string.txt");

	//�����ǶԺ���������Ѱ��topK�����Ĳ��ԡ�Ϊ���жԱȣ�ֻ������10000�����ݣ���֤������С����Ѱ��topK����ȷ��
	
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
	//���ԣ�Ѱ���ַ����г���Ƶ����ߵ�K���ַ�����
	//StringTopK_map("string.txt", 10);
	//Graph a(5);
	// cout << a.hadis << endl;
	string a = "liurangqiong";
	cout << a.substr(0,5) << endl;
}
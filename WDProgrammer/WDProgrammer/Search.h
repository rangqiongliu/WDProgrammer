/*
�ļ�˵����Search.h��Search.cpp��Ϊ��������ʵ��һЩ���ҵ��㷨
*/
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 
#pragma once
#define INF 99999999
#include<iostream>
#include<typeinfo>
#include<bitset>
#include<vector>
#include<algorithm>
#include<time.h>
#include<fstream>
#include<Windows.h>
#include<hash_map>
using namespace std;


/*
�������ܣ���һ���Ѿ���������������������в���ĳһ����
������ڣ�RawData����Ҫ���ҵ�����Դ��ele_num�����������Ԫ�ظ�����value����Ҫ�����ҵ�ֵ
�������ڣ����value������RawData�У��򷵻�value��RawData�е������ţ�����������򷵻�-1
���ڣ�2018-03-12
���ߣ�������
ʱ�临�Ӷȣ�O(logn��

*/
int Binary_Search(int *RawData, const int ele_num, const int value);


/*
�������ܣ����ɴ��������͡�16�ֽ��ַ�����IP��ַ
������ڣ�kindΪ1ʱ�������������ݣ���Χ0-100000000����Ϊ2ʱ������16�ֽ��ַ�����a-z����Ϊ3ʱ������IP��ַ��num����Ҫ���ɵĸ�����percent����������ʹ�õ�ǰ�����ڴ�İٷֱȣ�file_name��������ļ�����
�������ڣ��޷���ֵ�����ɵ�����ȫ������txt�ļ��С�
���ڣ�2018-03-13
���ߣ�������
��ע�������ڲ�����ݵ�ǰϵͳ�����ڴ������з���������д���ڴ棬���������ռ��ϵͳ��ǰ�����ڴ��10%��

*/
void generateBigData(const int kind, const int num, float percent, string file_name);

/*
�������ܣ������е�No_leaf���ڵ��³�������λ�ã�������С�ѵ�ԭ��
������ڣ�RawDataΪ���飬No_leafΪ���ڵ�������kΪ�����Ԫ�ظ����������غ�����myVector��һ��װ��hash_map<const string,int>Ԫ�ص�����������hash_map����ͳ���ַ������ֵĸ���
�������ڣ���RawData�������
���ڣ�2018-03-13
���ߣ�������
��ע���ú���ֻ�ܸ�����ɽ���С���ѣ����Ҫ����С���ѣ���ӵ�һ�����ڵ㵽���һ�����ڵ�ѭ�����øú������С�
*/
void creatSmallHeap(int *RawData, int No_leaf, const int k);
void creatSmallHeap(vector<hash_map<const string, int>> &myVector, int No_leaf);
/*
�������ܣ��Ӻ��������У��ҳ�����K����
������ڣ�file_name:���ݴ���ļ�;k:��Ҫ�ҳ�������ĸ���
�������ڣ����յ�K����ֱ�Ӵ�ӡ����Ļ��
���ڣ�2018-03-13
���ߣ�������
��ע��Ϊ��ֹ����������ռ���ڴ棬ÿ��ֻ��Ӻ��������ж�ȡ�����ڴ�ռ��10%���뵽����
*/
void TopK_Heap(string file_name, const int k);

/*
�������ܣ��Ӻ��������У��ҳ�K������Ƶ�������ַ���
������ڣ�file_name���ַ�������ļ���k����Ҫ�ҳ�������ĸ���
�������ڣ����յ��ַ����Լ����ֵĴ�����ֱ�Ӵ�ӡ����Ļ��
���ڣ�2018-03-14
���ߣ�������
��ע��Ϊ��ֹ����������ռ���ڴ棬ÿ��ֻ��Ӻ��������ж�ȡ�����ڴ�ռ��10%���뵽����
��Σ�������ֻ��Ϊ��ʵ���Ժ����ַ���Ѱ��top_k���⡣��������ַ����У���ͬ���ַ���Ҳ�Ǻ����ģ��Ǳ�������ʱ�����ˡ�
Ŀǰ������ֻ����ⲻͬ�ַ����������٣�<1w������µ�topK���⡣�����ͬ�ַ����������϶�ʱ���ɽ�ԭ����ͨ��hashӳ�䵽����ļ���Ȼ���ٵ��øú����𲽴�����

���ڶ�ȡ�ļ���ʱ���Ƕ��뵽string���͵Ķ����У�ÿ���ַ�������hash_mapʱҲ��ռ�ýϴ�ʱ�䡣����ڶ�ȡ�ַ����ͽ��ַ�������hash_mapռ�øú���95%������ʱ�䡣
*/
void StringTopK_map(string file_name, const int k);
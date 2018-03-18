/*
文件说明：Search.h与Search.cpp是为了声明和实现一些查找的算法
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
函数功能：在一个已经按升序排序的整型数组中查找某一个数
函数入口：RawData：需要查找的数组源，ele_num：数组包含的元素个数，value：需要被查找的值
函数出口：如果value存在于RawData中，则返回value在RawData中的索引号，如果不存在则返回-1
日期：2018-03-12
作者：刘让琼
时间复杂度：O(logn）

*/
int Binary_Search(int *RawData, const int ele_num, const int value);


/*
函数功能：生成大量的整型、16字节字符串、IP地址
函数入口：kind为1时，生成整型数据（范围0-100000000），为2时：生成16字节字符串（a-z），为3时：生成IP地址；num：需要生成的个数；percent：允许本函数使用当前可用内存的百分比；file_name：保存的文件名。
函数出口：无返回值，生成的数据全部存入txt文件中。
日期：2018-03-13
作者：刘让琼
备注：函数内部会根据当前系统可用内存来进行分批将数据写入内存，本函数最多占用系统当前可用内存的10%。

*/
void generateBigData(const int kind, const int num, float percent, string file_name);

/*
函数功能：将堆中的No_leaf父节点下沉到合适位置，符合最小堆的原则
函数入口：RawData为数组，No_leaf为父节点索引，k为数组的元素个数；其重载函数中myVector是一个装有hash_map<const string,int>元素的容器，利用hash_map容易统计字符串出现的个数
函数出口：由RawData数组带回
日期：2018-03-13
作者：刘让琼
备注：该函数只能辅助完成建立小顶堆，如果要建立小顶堆，则从第一个父节点到最后一个父节点循环调用该函数就行。
*/
void creatSmallHeap(int *RawData, int No_leaf, const int k);
void creatSmallHeap(vector<hash_map<const string, int>> &myVector, int No_leaf);
/*
函数功能：从海量数据中，找出最大的K个数
函数入口：file_name:数据存放文件;k:需要找出最大数的个数
函数出口：最终的K个数直接打印在屏幕上
日期：2018-03-13
作者：刘让琼
备注：为防止本函数过度占用内存，每次只会从海量数据中读取可用内存空间的10%进入到程序。
*/
void TopK_Heap(string file_name, const int k);

/*
函数功能：从海量数据中，找出K个出现频率最大的字符串
函数入口：file_name：字符串存放文件；k：需要找出最大数的个数
函数出口：最终的字符串以及出现的次数会直接打印在屏幕上
日期：2018-03-14
作者：刘让琼
备注：为防止本函数过度占用内存，每次只会从海量数据中读取可用内存空间的10%进入到程序。
其次，本函数只是为了实践对海量字符串寻找top_k问题。如果海量字符串中，不同的字符串也是海量的，那本函数暂时处理不了。
目前本函数只能求解不同字符串数量较少（<1w）情况下的topK问题。如果不同字符串的数量较多时，可将原数据通过hash映射到多个文件，然后再调用该函数逐步处理即可

由于读取文件的时候是读入到string类型的对象中，每个字符串放入hash_map时也会占用较大时间。因此在读取字符串和将字符串放入hash_map占用该函数95%的运行时间。
*/
void StringTopK_map(string file_name, const int k);
/*
文件说明：该Graph.h与Graph.cpp是声明和实现有关图的一些函数
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


class Graph
{
public:

	Graph(const int n);
	virtual ~Graph();
public:
	void setEdge(int * weight);
	void dijstra(int start, int *distance, int *path);
	void Prim();// TO DO
	void Floyd();//TO DO
	void Kruskal();//TO DO
private:
	vector<int> *m_edge;
	int num_vertex;
};

#include"Graph.h"

Graph::Graph(const int n)
{
	num_vertex = n;
	m_edge = new vector<int>[num_vertex];
}

Graph::~Graph()
{
	delete[] m_edge;
}

void Graph::setEdge(int * weight)
{
	if (NULL == weight || num_vertex <= 0) return;
	for (int i = 0; i < num_vertex; i++)
	{
		for (int j = 0; j < num_vertex; j++)
		{
			m_edge[i].push_back(weight[i*num_vertex + j]);
		}
	}
}


void Graph::dijstra(int start, int *distance, int *path)
{
	if (NULL == distance)
	{
		distance = new int[num_vertex];
	}
	if (NULL == path)
	{
		path = new int[num_vertex];
	}
	bool *flag = new bool[num_vertex] {false};
	int minDis = -1;
	int u = -1;
	for (int i = 0; i < num_vertex; i++)
	{
		distance[i] = m_edge[start][i];
		if (i != start && distance[i] < INF)
		{
			path[i] = start;
		}
		else
		{
			path[i] = -1;
		}
	}

	flag[start] = true;

	for (int i = 1; i < num_vertex; i++)
	{
		minDis = INF;
		for (int j = 0; j < num_vertex; j++)//在未找到最短路径的顶点中寻找与start点最近的顶点。
		{
			if (!flag[j] && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
		}

		if (minDis == INF) return;//该语句是用来判断start点是否与剩下未定的点是非连通图。如果是非连通图则直接返回

		flag[u] = true;

		for (int j = 0; j < num_vertex; j++)//重新确认从start到其他未确定顶点的最短路径
		{
			if (!flag[j] && distance[u] + m_edge[u][j] < distance[j])
			{
				distance[j] = distance[u] + m_edge[u][j];
				path[j] = u;
			}
		}
	}
}


void Graph::Prim()
{

}
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
		for (int j = 0; j < num_vertex; j++)//��δ�ҵ����·���Ķ�����Ѱ����start������Ķ��㡣
		{
			if (!flag[j] && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
		}

		if (minDis == INF) return;//������������ж�start���Ƿ���ʣ��δ���ĵ��Ƿ���ͨͼ������Ƿ���ͨͼ��ֱ�ӷ���

		flag[u] = true;

		for (int j = 0; j < num_vertex; j++)//����ȷ�ϴ�start������δȷ����������·��
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
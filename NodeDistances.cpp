// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.cpp

#include "NodeDistances.h"

int* Dijkstra(const AdjMatrix& A, const int u)
{
	const int SIZE = A.getdensity();
    bool visited[SIZE];
	int minD;
	int minV;
	int k          = 0;
	int *distance  = new int[SIZE];
	distance[u]    = 0;
	visited[u]     = 1;
	
	for (int i = 0; i < SIZE; i++)
		if (i != u)
		{
			distance[i] = -1;
		}
	for (int i = 0; i < SIZE; i++)
		if (A(u,i))
		{
			distance[i] = 1;
		}
	while (k < SIZE)
	{
		minD = -1;
		minV = NULL;
		for (int i = 0; i < SIZE; i++)
			if (distance[i] < minD && !visited[i])
			{
				minD = distance[i];
				minV = i;
			}
		visited[minV] = 1;
		k++;
		for (int i = 0; i < SIZE; i++)
			if (A(u,i))
			{
				if (!visited[i] && distance[i] > distance[minV] + 1)
				{
					distance[i] = distance[minV] + 1;
				}
			}
	}
	return distance;
}

int** shortestPaths(const AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	int** paths = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
		paths[i] = Dijkstra (A, i);
	return paths;
}

const float avgDistance(int** p, AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	float sum      = 0;
	float avg      = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			sum = sum + p[i][j];
		}
	}
	avg = sum / (SIZE * SIZE);
	return avg;
}

const float longDistance(int** p, AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	float max      = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (p[i][j] > max)
				max = p[i][j];
		}
	}
	return max;
}

void deleteDij(int** p, AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	
	for (int i = 0; i < SIZE; i++ )
	{
		delete[] p[i];
	}
	delete[] p;                            //Might not work/ cause memory leak?
}
// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.cpp

#include "NodeDistances.h"

int* Dijkstra(const AdjMatrix& A, const GeoNode u)
{
	int visited[SIZE];
	int minD;
	int minV;
	int k          = 0;
	const int SIZE = A.getDensity();
	int *distance  = new int[SIZE];
	distance[u]    = 0;
	visited[u]     = TRUE;
	
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
			if (distance[i] < minD && visited[i] == FALSE)
			{
				minD = distance[i];
				minV = i;
			}
		visited[minV] = TRUE;
		k++;
		for (int i = 0; i < SIZE; i++)
			if (A(u,i))
			{
				if (visited[i] == FALSE && distance[i] > distance[minV] +1)
				{
					distance[i] = distance[minV] + 1;
				}
			}
	}
	return distance;
}

int** shortestPaths(const int* p, const AdjMatrix& A, const geoNode u)
{
	const int SIZE = A.getDensity();
	int paths      = new int** [SIZE];
	for (int i = 0; i < SIZE; i++)
		paths[i] = dijkstra (A, u);
	return paths;
}

const float avgDistance(const int** p, AdjMatrix& A)
{
	const int SIZE = A.getDensity();
	float sum      = 0;
	float avg      = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; i++)
		{
			sum = sum + p[i][j];
		}
	}
	avg = sum / (SIZE * SIZE);
	return avg;
}

const float longDistance(const int** p, AdjMatrix& A)
{
	const int SIZE = A.getDensity();
	float max      = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; i++)
		{
			if (p[i][j] > max)
				max = p[i][j];
		}
	}
	return max;
}

void deletePaths(int** p)
{
	const int SIZE = A.getDensity();
	
	for (int i = 0; i < SIZE; i++ )
	{
		delete[] p[i];
	}
	delete[] p;                            //Might not work/ cause memory leak?
}
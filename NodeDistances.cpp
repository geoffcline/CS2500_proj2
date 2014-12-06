// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.cpp

#include "NodeDistances.h"

int* Dijkstra(const AdjMatrix& A, const GeoNode u)
{
	int visited[SIZE];
	int minD;
	int minV;
	int k          = 1;
	const int SIZE = A.getDensity();
	int *distance  = new int[SIZE];
	distance[u]    = 0;
	visited[u]     = TRUE;
	


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
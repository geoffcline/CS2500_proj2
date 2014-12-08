// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.cpp

#include "NodeDistances.h"
#include <fstream>

int minDistance(int* distance, bool sptSet[], const int V)
{
    // Initialize min value
    int min = INT_MAX, min_index(0);
    
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;
    
    return min_index;
}

int* Dijkstra(const AdjMatrix& A, const int src)
{
	int V = A.getdensity();
    int* distance = new int[V];     //distance[i] will hold the shortest distance from src to i
    bool sptSet[V];                    // Will be true if the vertex is visited
    for (int i = 0; i < V; i++)        // Initialize all distances as INFINITE and stpSet[] as false
    	distance[i] = INT_MAX, sptSet[i] = false;
    
    distance[src] = 0;       // Distance from the source to the source is always 0
    
    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Picks the minimum distance vertex from the set of vertices not yet visited.
        int u = minDistance(distance, sptSet,V);
        // Mark the picked vertex as visited
        sptSet[u] = true;
            
        // Update the value of distance for the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
                
        // Update distance[v] only if it is not in sptSet, there is an edge from u to v, and total weight 
        // of path from src to v through u is smaller than the current value
        if (!sptSet[v] && A(u,v) && distance[u] != INT_MAX && distance[u]+A(u,v) < distance[v])
              distance[v] = distance[u] + A(u,v);
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
    int count = 0;

    //Averages all distances
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if(p[i][j] != INT_MAX && p[i][j] != 0)
            {
                sum = sum + p[i][j];
                count++;
            }
            
		}
	}
    avg = sum / count;
	return avg;
}

const float longDistance(int** p, AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	float maxr      = 0;

	// Searches for the largest distance from any source
	// this distance is the longest diameter
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (p[i][j] > maxr && p[i][j] != INT_MAX && p[i][j] != 0)
				maxr = p[i][j];
		}
	}
	return maxr;
}

void deleteDij(int** p, AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	
	for (int i = 0; i < SIZE; i++ )
	{
		//delete[] p[i];
	}
	//delete[] p;                            //Might not work/ cause memory leak?
}
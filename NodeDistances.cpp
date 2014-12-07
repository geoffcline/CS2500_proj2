// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.cpp

#include "NodeDistances.h"
#include <fstream>

int minDistance(int* dist, bool sptSet[], const int V)
{
    // Initialize min value
    int min = INT_MAX, min_index(0);
    
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

int* Dijkstra(const AdjMatrix& A, const int src)
{
    int V = A.getdensity();
    int* dist = new int[V];     // The output array.  dist[i] will hold the shortest
                     // distance from src to i
        
    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                    // path tree or shortest distance from src to i is finalized
        
        // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;
        
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
        
    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet,V);
            
        // Mark the picked vertex as processed
        sptSet[u] = true;
            
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
                
        // Update dist[v] only if is not in sptSet, there is an edge from
        // u to v, and total weight of path from src to  v through u is
        // smaller than current value of dist[v]
        if (!sptSet[v] && A(u,v) && dist[u] != INT_MAX && dist[u]+A(u,v) < dist[v])
              dist[v] = dist[u] + A(u,v);
        }
        
        // print the constructed distance array

 return dist;
}

int** shortestPaths(const AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	int** paths = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
		paths[i] = Dijkstra (A, i);
    
    fstream fout;
    fout.open("matrix.txt");
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            fout << paths[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl << endl << endl;
    
    fout.close();
    
	return paths;
}

const float avgDistance(int** p, AdjMatrix& A)
{
	const int SIZE = A.getdensity();
	float sum      = 0;
	float avg      = 0;
    int count = 0;

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
		delete[] p[i];
	}
	delete[] p;                            //Might not work/ cause memory leak?
}
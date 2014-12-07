// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.h

#ifndef NODEDISTANCES_H
#define NODEDISTANCES_H

#include "AdjMatrix.h"
using namespace std;


//Finds the largest distance from a single source
int* Dijkstra(const AdjMatrix& A, const int u);  

//Creates a 2D array of distance arrays generated from Dijkstra
int** shortestPaths(const AdjMatrix& A);

//Function that add's up all distances in the 2D array and divides by the number of nodes^2
const float avgDistance(int** p, AdjMatrix& A);

//Searches the entire 2D array for the largest distance
const float longDistance(int** p, AdjMatrix& A);

//Deletes all the pointers
void deleteDij(int** p, AdjMatrix& A);

#endif
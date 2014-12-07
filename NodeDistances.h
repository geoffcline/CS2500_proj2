// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.h

#ifndef NODEDISTANCES_H
#define NODEDISTANCES_H

#include "AdjMatrix.h"
using namespace std;



int* Dijkstra(const AdjMatrix& A, const int u);  

int** shortestPaths(const AdjMatrix& A);

const float avgDistance(int** p, AdjMatrix& A);

const float longDistance(int** p, AdjMatrix& A);

void deleteDij(int** p, AdjMatrix& A);

#endif
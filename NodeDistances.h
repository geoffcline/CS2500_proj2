// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.h

#ifndef NODEDISTANCES_H
#define NODEDISTANCES_H

#include <iostream>
#include "AdjMatrix.h"
using namespace std;



int* Dijkstra(const AdjMatrix& A, const int u);  

int** shortestPaths(const AdjMatrix& A);

const float avgDistance(const int** p, AdjMatrix& A);

const float longDistance(const int** p, AdjMatrix& A);

void deleteDij(int** p);

#endif
// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// NodeDistances.h

#ifndef NODEDISTANCES_H
#define NODEDISTANCES_H

#include <iostream>
#include "AdjMatrix.h"
using namespace std;



int* Dijkstra(const AdjMatrix& A, const GeoNode u);  

int** shortestPaths(const int* p);

const float avgDistance(const int* p);

const float longDistance(const int* p);

void deleteDij(int* p);

#endif
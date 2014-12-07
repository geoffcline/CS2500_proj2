#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "AdjMatrix.h"

int* ConnectedComponents(const AdjMatrix& A);

void DFSAssign(const AdjMatrix& A, int* id_arr, const int parent, const int newid);

int  MostOccur(const int* A, const int sz);



#endif 
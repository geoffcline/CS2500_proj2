#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "AdjMatrix.h"

int* ConnectedComponents(const AdjMatrix& A);

void DFSAssign(const AdjMatrix& A, int* id_arr, const int parent, const int newid);

int  MostOccur(const int* A, const int sz);

int  Maxi(const int* A, const int sz);

int  Max(const int* A, const int sz) {return A[Maxi(A,sz)];}

int  Maxi(const int* A, const int sz);

int  Mini(const int* A, const int sz);

int  Min(const int* A, const int sz) {return A[Mini(A,sz)];}



#endif 
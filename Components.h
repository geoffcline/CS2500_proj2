#ifndef GREEDY_H
#define GREEDY_H

#include "KnapSack.h"

int* ConnectedComponents(const AdjMatrix& A);

int  MostOccur(const int* A, const int sz);

int  Max(const int* A, const int sz) {return A[maxi(A,sz)];}

int  Maxi(const int* A, const int sz);

int  Min(const int* A, const int sz) {return A[mini(A,sz)];}

int  Mini(const int* A, const int sz);

#endif 
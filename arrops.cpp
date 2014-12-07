//
//  arrops.cpp
//  cs2500_proj2
//
//  Created by Geoffrey on 12/7/14.
//  Copyright (c) 2014 Geoffrey. All rights reserved.
//

#include "arrops.h"

int  Maxi(const int* A, const int sz)
{
    int r = 0;
    for (int i = 1; i < sz; ++i)
        if (A[i] > A[r])
            r = i;
    
    return r;
}

int  Mini(const int* A, const int sz)
{
    int r = 0;
    for (int i = 1; i < sz; ++i)
        if (A[i] < A[r])
            r = i;
    
    return r;
}

int  Max(const int* A, const int sz)
{
    return A[Maxi(A,sz)];
}

int  Min(const int* A, const int sz) {return A[Mini(A,sz)];}
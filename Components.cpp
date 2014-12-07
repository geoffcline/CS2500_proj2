// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// Components.cpp
#include "Components.h"

int* ConnectedComponents(const AdjMatrix& A)
{
  const int SIZE = A.getdensity();
  int curr_id = 0;

  int* id_arr = new int [SIZE];
  for (int i = 0; i < SIZE; ++i)
    id_arr[i] = 0;
  
  for (int i = 0; i < SIZE; ++i)
    if(id_arr[i] == 0)
    {
      DFSAssign(A, id_arr, i,++curr_id);
    }
    
    return id_arr;
}

void DFSAssign(const AdjMatrix& A, int* id_arr, const int parent, const int newid)
{
  id_arr[parent] = newid;
  for (int i = 0; i < A.getdensity(); ++i)
    if(id_arr[i] == 0 && A(i,parent))
    {
      DFSAssign(A,id_arr,i,newid);
    }
}

int MostOccur(const int* A, const int sz)
{
  int max = Max(A,sz);
  int* const freq = new int[max+1];
  for (int i = 0; i < max; ++i)
    freq[i] = 0;

  for (int i = 0; i < sz; ++i)
    freq[A[i]]++;
    
  int result = Maxi(freq, max);
    
  delete [] freq;

  return result;
}

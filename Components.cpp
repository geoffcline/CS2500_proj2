#include "Components.h"
#include "AdjMatrix.h"

int* ConnectedComponents(const AdjMatrix& A)
{
  const int SIZE = A.getdensity();
  int curr_id = 0;

  new int* id_arr = new int [SIZE];
  for (int i = 0; i < SIZE; ++i)
    id_arr[i] = 0;
  
  for (int i = 0; i < SIZE; ++i)
    if(id_arr[i] == 0)
    {
      DFSAssign(A, id_arr, i,++curr_id);
    }

}

void DFSAssign(const AdjMatrix& A, const int* id_arr, const int parent, const int newid)
{
  id_arr[n] = newid;
  for (int i = 0; i < A.getdensity(); ++i)
    if(id_arr[i] == 0 && A(i,parent))
    {
      DFSAssign(A,id_arr,i,newid);
    }
}

int MostOccur(const int* A, const int sz)
{
  int min   = min(A);
  int range = max(A) - min;
  int result;
  new int* freq = new int[range];
  for (int i = 0; i < range; ++i)
    freq[i] = 0;

  for (int i = 0; i < sz; ++i)
    freq[A[i] - min]++;

  return maxi(freq, range) + min;
}

int Maxi(const int* A, const int sz)
{
  int r = 0;
  for (int i = 1; i < sz; ++i)
    if (A[i] > A[r])
      r = i;

  return r;
}

int Mini(const int* A, const int sz)
{
  int r = 0;
  for (int i = 1; i < sz; ++i)
    if (A[i] < A[r])
      r = i;

  return r;
}
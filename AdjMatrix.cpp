#include "AdjMatrix.h"

void AdjMatrix::generate(const int newsz, const int newr)
{
  clear();
  
  density = newsz;
  radius  = newr;
  
  data = new GeoNode[getdensity()];
  connect = new bool*[getdensity()];
  for (int i = 0; i < getdensity(); ++i)
    connect[i] = new bool[getdensity()];

  calculate();
  
  return;
}

GeoNode::GeoNode()
{
    const int X_MAX = 500;
    const int Y_MAX = 500; //decide where we want these variables
    
  x = rand() % (X_MAX + 1);
  y = rand() % (Y_MAX + 1);
}

float NodeDistance(const GeoNode& l, const GeoNode& r)
{
  int sx = (l.x - r.x);
    sx *= sx;
  int sy = (l.y - r.y);
    sy *= sy;

  return sqrt(sx + sy);
}

void  AdjMatrix::clear()
{

  if(getdensity() != 0)
  {
    delete [] data;

    for (int i = 0; i < getdensity(); ++i)
      delete [] connect[i];
    
    delete [] connect;
    
    
  }
  
  data = NULL;
  connect = NULL;
  density = 0;
    radius=0;

  return;
}

void AdjMatrix::calculate()
{
  for (int i = 0; i < getdensity(); ++i)
  {
    for (int j = 0; j < getdensity(); ++j)
    {
      connect[i][j] = NodeDistance(data[i],data[j]) <= getradius();
    }
  }
}



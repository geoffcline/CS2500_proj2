#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

const int X_MAX = 500;
const int Y_MAX = 500; //decide where we want these variables

struct GeoNode
{
private:
  int x, y;
public:
  GeoNode();
  friend float NodeDistance(const GeoNode& l, const GeoNode& r);
};

class AdjMatrix
{
private:
  GeoNode* data;       //holds actual nodes, size density
  bool**   connect;    //literal adjacency matrix, size density^2
  int   density;       
  int   radius;
  void  setdensity (const int newd) {generate(newd);}
                       //changing the desnsity requires a whole new graph
  void  calculate();   //uses the radius to determine if the nodes are connected
public:
  int   getdensity () const {return density;}
  void  setradius  (const float newr) {radius = newr; calculate();} //radius can be updated, applied to same graph
  int   getradius   () const {return radius;}
  void  generate(const int newd, const int newr);
  void  generate(const int newd) {generate(newd, getradius());}
  void  generate() {generate(getdensity(),getradius());}
  void  clear();

  bool operator () (const int i, const int j) const {return connect[i][j];}
  GeoNode operator [] (const int i) const {return data[i];}

  AdjMatrix(const AdjMatrix &rhs) {*this = rhs;};
  AdjMatrix(const int newd = 0, const int newr = 0): radius(newr), density(0) {generate(newd);}
  ~AdjMatrix() {clear();}

};


#endif 
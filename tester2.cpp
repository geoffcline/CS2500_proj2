
#include "AdjMatrix.h"
#include "Components.h"
#include <fstream>
#include <iostream>

using namespace std;

const int X_SIZE = 500;
const int Y_SIZE = 500; //decide where we want these variables

int main ()
{

  const int DATAPOINTS = 10;
  const int NUMPERPOINT = 5;  
  const int RADIUS = 20;
  const int NUMOFSENSORS = 200;
  const int INITIALRADIUS = 5;
  const int RADIUSINCREMENT = 5;
  const int INITIALNUMOFSENSORS = 50;
  const int NUMOFSENSORSINCREMENT = 50;

  ofstream fout;

  AdjMatrix M_working;

  int* cc_result = null;

  float currentresult=0;
  float totalresultNumCC=0;
  float totalresultMaxCC=0;
  float totalresultAvgDist=0;
  float totalresultDiameter=0;


  //increasing number of sensors

  //set num of sensors to INITIALNUMOFSENSORS
  //set radius to RADIUS
  for(int i=0; i < DATAPOINTS*NUMPERPOINT;i++) 
  {
    M_working.generate(INITIALNUMOFSENSORS + NUMOFSENSORSINCREMENT * (i / NUMPERPOINT), RADIUS);
    
    cc_result = ConnectedComponents(const AdjMatrix& M_working)
    
    //Num of CC
    cout << "Num of CCs (increasing sensors): \t" << i << endl;
    currentresult = Max(const int* cc_result, const int A.getdensity());
    fout << "\"Num of CCs\",\"" << i << "\",\"" << currentresult << "\"" << endl;
    
    totalresultNumCC+=currentresult;
 
    
    //Size of Largest CC
    cout << "Size Of Largest CC (increasing sensors): \t" << i << endl;
    currentresult = MostOccur(const int* cc_result, const int A.getdensity());
    fout << "\"Size Of Largest CC\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultMaxCC+=currentresult;

    delete [] cc_result;
    cc_result = NULL;

    //Avg Node Distance
    cout << "Avg Node Dist (increasing sensors): \t" << i << endl;
    currentresult = GreedyKS(M_working, MAXW);
    fout << "\"Avg Node Dist\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultAvgDist+=currentresult;

    //Diameter of network
    cout << "Diameter (increasing sensors): \t" << i << endl;
    currentresult = GreedyKS(M_working, MAXW);
    fout << "\"Diameter\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultDiameter+=currentresult;

    if(i%NUMPERPOINT==0 && i!=0)
    {
      
      totalresultNumCC = totalresultNumCC/NUMPERPOINT;
      totalresultMaxCC= totalresultMaxCC/NUMPERPOINT;
      totalresultAvgDist = totalresultAvgDist/NUMPERPOINT;
      totalresultDiameter= totalresultDiameter/NUMPERPOINT;

      fout << "\"NUM CC DATA POINT 3\",\"" << i << "\",\"" << totalresultNumCC << "\"" << endl;
      fout << "\"MAX CC DATA POINT 3\",\"" << i << "\",\"" << totalresultMaxCC << "\"" << endl;
      fout << "\"AVG DIST DATA POINT 3\",\"" << i << "\",\"" << totalresultAvgDist << "\"" << endl;
      fout << "\"DIAMETER DATA POINT 3\",\"" << i  << "\",\"" << totalresultDiameter << "\"" << endl;
      

      totalresultNumCC = 0;
      totalresultMaxCC= 0;
      totalresultAvgDist = 0;
      totalresultDiameter= 0;
    }
  }


   //increasing transmission range

  //set num of sensors to NUMOFSENSORS
  //set radius to INITIALRADIUS
  for(int i=0; i < DATAPOINTS*NUMPERPOINT;i++) 
  {

    M_working.generate(NUMOFSENSORS, INITIALRADIUS + RADIUSINCREMENT * (i / NUMPERPOINT)); //generate graph

    cc_result = ConnectedComponents(const AdjMatrix& A)
    
    //Num of CC
    cout << "Num of CCs (increasing sensors): \t" << i << endl;
    currentresult = Max(const int* cc_result, const int A.getdensity());
    fout << "\"Num of CCs\",\"" << i << "\",\"" << currentresult << "\"" << endl;
    
    totalresultNumCC+=currentresult;
 
    
    //Size of Largest CC
    cout << "Size Of Largest CC (increasing sensors): \t" << i << endl;
   currentresult = MostOccur(const int* cc_result, const int A.getdensity());
    fout << "\"Size Of Largest CC\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultMaxCC+=currentresult;

    delete [] cc_result;
    cc_result = NULL;

    //Avg Node Distance
    cout << "Avg Node Dist (increasing sensors): \t" << i << endl;
    currentresult = GreedyKS(M_working, MAXW);
    fout << "\"Avg Node Dist\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultAvgDist+=currentresult;

    //Diameter of network
    cout << "Diameter (increasing sensors): \t" << i << endl;
    currentresult = GreedyKS(M_working, MAXW);
    fout << "\"Diameter\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultDiameter+=currentresult;

    if(i%NUMPERPOINT==0 && i!=0)
    {
      
      totalresultNumCC = totalresultNumCC/NUMPERPOINT;
      totalresultMaxCC= totalresultMaxCC/NUMPERPOINT;
      totalresultAvgDist = totalresultAvgDist/NUMPERPOINT;
      totalresultDiameter= totalresultDiameter/NUMPERPOINT;

      fout << "\"NUM CC DATA POINT 3\",\"" << i << "\",\"" << totalresultNumCC << "\"" << endl;
      fout << "\"MAX CC DATA POINT 3\",\"" << i << "\",\"" << totalresultMaxCC << "\"" << endl;
      fout << "\"AVG DIST DATA POINT 3\",\"" << i << "\",\"" << totalresultAvgDist << "\"" << endl;
      fout << "\"DIAMETER DATA POINT 3\",\"" << i  << "\",\"" << totalresultDiameter << "\"" << endl;
      

      totalresultNumCC = 0;
      totalresultMaxCC= 0;
      totalresultAvgDist = 0;
      totalresultDiameter= 0;
    }
  
    fout.close();

    return 0;
  
  }
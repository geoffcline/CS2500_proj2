// Alex Marey, Tyler Percy, Geoffrey Cline
// Project 2
// main.cpp
#include "NodeDistances.h"
#include "Components.h"
#include <fstream>

using namespace std;

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
    
    fout.open("stuff.csv");

  AdjMatrix M_working;

  int* cc_result = NULL;
  int** dist;

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
    
    cc_result = ConnectedComponents(M_working);
    //Num of CC
    cout << "Num of CCs (increasing sensors): \t" << i << endl;
    currentresult = Max(cc_result, M_working.getdensity());
    //fout << "\"Num of CCs\",\"" << i << "\",\"" << currentresult << "\"" << endl;
    
    totalresultNumCC+=currentresult;
 
    
    //Size of Largest CC
    cout << "Size Of Largest CC (increasing sensors): \t" << i << endl;
    currentresult = MostOccur(cc_result, M_working.getdensity());
    //fout << "\"Size Of Largest CC\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultMaxCC+=currentresult;

    //delete [] cc_result;
    cc_result = NULL;

    dist = shortestPaths(M_working);
      
    //Avg Node Distance
    cout << "Avg Node Dist (increasing sensors): \t" << i << endl;
    currentresult = avgDistance(dist, M_working);
    //fout << "\"Avg Node Dist\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultAvgDist+=currentresult;

    //Diameter of network
    cout << "Diameter (increasing sensors): \t" << i << endl;
    currentresult = longDistance(dist, M_working);
    //fout << "\"Diameter\",\"" << i << "\",\""  << currentresult << "\"" << endl;

    totalresultDiameter+=currentresult;

    deleteDij(dist, M_working);

    if((i+1)%NUMPERPOINT==0 && i!=0)
    {
      
      totalresultNumCC = totalresultNumCC/NUMPERPOINT;
      totalresultMaxCC= totalresultMaxCC/NUMPERPOINT;
      totalresultAvgDist = totalresultAvgDist/NUMPERPOINT;
      totalresultDiameter= totalresultDiameter/NUMPERPOINT;

      fout << "\"Number Of Nodes\",\"" << M_working.getdensity() << "\"" << endl; 
      fout << "\"NUM CC DATA POINT\",\"" << i << "\",\"" << totalresultNumCC << "\"" << endl;
      fout << "\"MAX CC DATA POINT\",\"" << i << "\",\"" << totalresultMaxCC << "\"" << endl;
      fout << "\"AVG DIST DATA POINT\",\"" << i << "\",\"" << totalresultAvgDist << "\"" << endl;
      fout << "\"DIAMETER DATA POINT\",\"" << i  << "\",\"" << totalresultDiameter << "\"" << endl;
      

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

    cc_result = ConnectedComponents(M_working);
    
    //Num of CC
    cout << "Num of CCs (increasing radius): \t" << i << endl;
    currentresult = Max(cc_result, M_working.getdensity());
    //fout << "\"Num of CCs\",\"" << i << "\",\"" << currentresult << "\"" << endl;
    
    totalresultNumCC+=currentresult;
 
    
    //Size of Largest CC
    cout << "Size Of Largest CC (increasing radius): \t" << i << endl;
    currentresult = MostOccur(cc_result, M_working.getdensity());
    //fout << "\"Size Of Largest CC\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultMaxCC+=currentresult;

    //delete [] cc_result;
    cc_result = NULL;

    dist = shortestPaths(M_working);

    //Avg Node Distance
    cout << "Avg Node Dist (increasing radius): \t" << i << endl;
    currentresult = avgDistance(dist, M_working);
    //fout << "\"Avg Node Dist\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultAvgDist+=currentresult;

    //Diameter of network
    cout << "Diameter (increasing radius): \t" << i << endl;
    currentresult = longDistance(dist, M_working);
    //fout << "\"Diameter\",\"" << i << "\",\""  << currentresult << "\"" << endl;
    
    totalresultDiameter+=currentresult;

    deleteDij(dist, M_working);

    if((i+1)%NUMPERPOINT==0 && i!=0)
    {
      
      totalresultNumCC = totalresultNumCC/NUMPERPOINT;
      totalresultMaxCC= totalresultMaxCC/NUMPERPOINT;
      totalresultAvgDist = totalresultAvgDist/NUMPERPOINT;
      totalresultDiameter= totalresultDiameter/NUMPERPOINT;


      fout << "\"Size Of Radius\",\"" << M_working.getradius() << "\"" << endl; 
      fout << "\"NUM CC DATA POINT\",\"" << i << "\",\"" << totalresultNumCC << "\"" << endl;
      fout << "\"MAX CC DATA POINT\",\"" << i << "\",\"" << totalresultMaxCC << "\"" << endl;
      fout << "\"AVG DIST DATA POINT\",\"" << i << "\",\"" << totalresultAvgDist << "\"" << endl;
      fout << "\"DIAMETER DATA POINT\",\"" << i  << "\",\"" << totalresultDiameter << "\"" << endl;
      

      totalresultNumCC = 0;
      totalresultMaxCC= 0;
      totalresultAvgDist = 0;
      totalresultDiameter= 0;
    }
  
    
  
  }
    
    fout.close();
    
    return 0;
}

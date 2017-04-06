//Connor Kunstek
//CS315
//Lab - Practicum 4
//4-6-2017
//Sider Header

//include guards////////////////////////////////////////////////////////////////
#ifndef Spider_h
#define Spider_h
//includes//////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
using namespace std;
class Spider
{
    public:
        //constructors//////////////////////////////////////////////////////////
        Spider();
        Spider(row, column);
        //to access private data////////////////////////////////////////////////
        vector<int> newLocation();
        vector<int> getstartLocation();
        vector<int> getcurrentLocation();
        double getRow();
        double getCol();


    private:
        vector<int> startLocation;
        vector<int> currentLocation;
};
//closing include guard/////////////////////////////////////////////////////////
#endif

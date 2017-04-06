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
#include <vector>
using namespace std;
class Spider
{
    public:
        //constructors//////////////////////////////////////////////////////////
        Spider();
        Spider(int row, int column);
        //to access private data////////////////////////////////////////////////
        void newLocation(int tempRow, int tempCol);
        vector<int> getstartLocation();
        vector<int> getcurrentLocation();
        void startSpider(vector<string> temp);
        void checkSurround();
        int getRow();
        int getCol();


    private:
        vector<int> startLocation;
        vector<int> currentLocation;
        int row;
        int column;
};
//closing include guard/////////////////////////////////////////////////////////
#endif

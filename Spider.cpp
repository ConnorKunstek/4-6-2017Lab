//Connor Kunstek
//CS315
//4-6-2017
//Lab - Practicum 4
//spider class

#include "City.h"
#include<vector>
using namespace std;

Spider::Spider()
{
    row = 1;
    column = 1;
    location.push_back(row);
    location.push_back(column);
}

Spider::Spider(int row, int column)
{
    startLocation.push_back(row);
    startLocation.push_back(column);
    currentLocation.push_back(row);
    currentLocation.push_back(column);
}

Spider::startSpider(vector<int> temp)
{
    startLocation.clear();
    startLocation = temp;
}

Spider::newLocation(int row, int column)
{
    currentLocation.clear();
    currentLocation.push_back(row);
    currentLocation.push_back(column);
}

Spider::getRow()
{
    return currentLocation[0];
}

Spider::getColumn()
{
    return currentLocation[1];
}

Spider::checkSurround()
{
    int row = getRow();
    int col = getColumn();

}

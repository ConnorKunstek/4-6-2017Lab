  //Connor Kunstek
//CS315
//4-6-2017
//Lab - Practicum 4
//spider class

#include "Spider.h"
#include<vector>
using namespace std;

Spider::Spider()
{
    row = 1;
    column = 1;
    startLocation.push_back(row);
    startLocation.push_back(column);
}

Spider::Spider(int row, int column)
{
    startLocation.push_back(row);
    startLocation.push_back(column);
    currentLocation.push_back(row);
    currentLocation.push_back(column);
}

void Spider::startSpider(vector<string> temp)
{
    startLocation.clear();
    startLocation.push_back(stoi(temp[0]));
    startLocation.push_back(stoi(temp[1]));
}

void Spider::newLocation(int tempRow, int tempColumn)
{
    currentLocation.clear();
    currentLocation.push_back(row);
    currentLocation.push_back(column);
}

int Spider::getRow()
{
    return currentLocation[0];
}

int Spider::getCol()
{
    return currentLocation[1];
}

void Spider::checkSurround()
{
    int row = getRow();
    int col = getCol();

}

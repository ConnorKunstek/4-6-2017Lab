//Connor Kunstek
//4-6-2017
//Lab - Practicum 4
//main file

//Includes//////////////////////////////////////////////////////////////////////
#include "string.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
//to keep track of locations visited
int visited[100][100];

//Split/////////////////////////////////////////////////////////////////////////
vector<string> split( string line, string delimiters ) {
  vector<string> result;

  int start_loc = 0;
  bool is_delim = true;
  int curr_loc = 0;
  for( char curr_char : line ){
    // Check if delimiter
    bool found_del = false;
    for( char delim : delimiters ){
      if( curr_char == delim ){
        found_del = true;
        // If wasn't a delimeter then start_loc -> curr_loc is a word
        if( !is_delim ){
          result.push_back( line.substr(start_loc, curr_loc-start_loc) );
        }
        break;
      }
    }
    // If no delimeter matched
    if( !found_del && is_delim ){
      is_delim = false;
      start_loc = curr_loc;
    }
    is_delim = found_del;
    curr_loc++;
  }
  // Check if the last word ended at the end of the string, start_loc -> end
  if(!is_delim)
  {
    result.push_back(line.substr(start_loc, curr_loc-start_loc));
  }
  return result;
}

//DEPTH FIRST SEARCH////////////////////////////////////////////////////////////
int dfs(int r, int c, int rows, int columns, vector<vector<char>>grid)
{
    //return variable
    int count = 0;
    //to give the grid the 3 dimmensional torus shape
    if(r > rows)
    {
        r = 0;
    }
    if(c > columns)
    {
        c = 0;
    }
    if(r < 0)
    {
        r = rows;
    }
    if(c < 0)
    {
        c = columns;
    }
    //to check for places the spider can't/shouldn't go - BASE CASE/////////////
    if(grid[r][c] == 'S' || visited[r][c] == 1)
    {
        return 0;
    }
    if(grid[r][c] == 'F')
    {
        visited[r][c] = 1;
        return 1;
    }
    //To Mark visited locations//////////////////
    visited[r][c] = 1;
    //recursive calls///////////////////////////
    count += dfs(r, c + 1, rows, columns, grid);
    count += dfs(r, c - 1, rows, columns, grid);
    count += dfs(r + 1 , c, rows, columns, grid);
    count += dfs(r + 1 , c + 1, rows, columns, grid);
    count += dfs(r + 1 , c - 1, rows, columns, grid);
    count += dfs(r - 1 , c, rows, columns, grid);
    count += dfs(r - 1 , c + 1, rows, columns, grid);
    count += dfs(r - 1 , c - 1, rows, columns, grid);
    return count;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main()
{
    //timing info
    chrono::time_point<chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    //timer started

    //variable declaration
    string line;
    bool check = false;
    int rows = -1;
    int columns = 0;
    string answer;
    vector<vector<char>> grid;
    int count = 0;
    int counter = 0;

    //get input from file
    while(getline(cin, line))
    {
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ' ')
            {
                check = true;
            }
        }
        //if location of spider given
        if(check)
        {
            vector<string> temp = split(line, " , \t");
            int r = stoi(temp[0])-1;
            int c = stoi(temp[1])-1;
            //call initial recursive function
            count = dfs(r, c, rows, columns, grid);
            //if a fly was found
            if(count > 0)
            {
                answer = "Yes";
            }
            else
            {
                answer = "No";
            }
            //give answer
            cout << answer << endl;
            count = 0;
            memset(visited, 0, sizeof(visited));
        }
        //if grid given
        else
        {
            vector<char> temp(line.begin(), line.end());
            grid.push_back(temp);
            rows++;
            columns = line.length() - 1;
        }
    }
    //more timing info
    end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "Time: " << elapsed_seconds.count() << " seconds" << endl << endl;

    return 0;
}

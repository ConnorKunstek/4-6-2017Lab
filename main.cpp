//Connor Kunstek
//4-6-2017
//Lab - Practicum 4
//main file

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <math.h>
#include <sstream>
#include <chrono>
#include "Spider.h"

using namespace std;

vector<vector<char>> sugar;
vector<vector<char>> visited;
vector<vector<char>> grid;
vector<vector<int>> fly;

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

vector<int> dfs(int r, int c, int rows, int columns)
{
    //out of bounds? not a good cell? visited?
    cout << "in new dfs " << endl;
    cout << "r: "<<r<<" c: "<<c<<" rows: "<< rows<<" columns: "<< columns<<endl;
    vector<int> returnVec;
    cout << "after returnVec creation " << endl;
    if (r > rows || r < 1 || c > columns || c < 1 || grid[r][c] == 'S' || visited[r][c] == 'V')
    {
        cout << "in base case" << endl;
        returnVec.push_back(r);
        returnVec.push_back(c);
        returnVec.push_back(0);
        cout<<"before base case return"<<endl;
        return returnVec;
    }
    cout << "after base case " << endl;
    if(grid[r][c] == 'F')
    {
        cout << "found a fly" << endl;
        returnVec.push_back(r);
        returnVec.push_back(c);
        returnVec.push_back(1);
        visited[r][c] = 'V';
        return returnVec;
    }
    else
    {
        cout << "in else case" << endl;
        returnVec.push_back(r);
        returnVec.push_back(c);
        returnVec.push_back(0);
        visited[r][c] = 'V';
    }
    //int count = 1;
    // number of water cells (including this one) that are connected
    //visited[r][c] = 'V'; //dfs called for 8 neighbors of the current cell
    cout << "recursive calls" << endl;
    fly.push_back(dfs(r, c + 1, rows, columns));
    fly.push_back(dfs(r, c - 1, rows, columns));
    fly.push_back(dfs(r + 1 , c, rows, columns));
    fly.push_back(dfs(r + 1 , c + 1, rows, columns));
    fly.push_back(dfs(r + 1 , c - 1, rows, columns));
    fly.push_back(dfs(r - 1 , c, rows, columns));
    fly.push_back(dfs(r - 1 , c + 1, rows, columns));
    fly.push_back(dfs(r - 1 , c - 1, rows, columns));
    return returnVec;
}


int main()
{
    chrono::time_point<chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    Spider spider = Spider();
    string line;
    bool check = false;
    int rows = 0;
    int columns = 0;
    string answer = "Did not work";

    while(getline(cin, line))
    {
        cout << line << endl;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ' ')
            {
                check = true;
            }
        }
        if(check)
        {
            for(int i = 0; i<grid.size(); i++)
            {
                vector<char> temp;
                for(int j = 0; j < columns; j++)
                {
                    temp.push_back('N');
                }
                visited.push_back(temp);
            }
            vector<string> temp = split(line, " , \t");
            vector<int>output;
            cout << "r: "<<stoi(temp[0])<<" c: "<<stoi(temp[1])<<" rows: "<< rows<<" columns: "<< columns<<endl;
            output = dfs(stoi(temp[0]), stoi(temp[1]), rows, columns);
            cout << "right after dfs"<<endl;
            for(int i = 0; i < fly.size(); i++)
            {
                if(fly[i][2] == 1)
                {
                    answer = "Yes";
                }
                else
                {
                    answer = "No";
                }
            }
            cout<<answer<<endl;
        }
        else
        {
            vector<char> temp(line.begin(), line.end());
            grid.push_back(temp);
            rows++;
            columns = line.length();
        }
    }

    end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "Time: " << elapsed_seconds.count() << " seconds" << endl << endl;

    return 0;
}

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

using namespace std;

int *TOTOALROW;
int *TOTALCOL;

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

  int dfs(int r, int c)
  {
      //out of bounds? not a good cell? visited?
      if (r == TOTALROW || r < 0 || c == TOTALCOL ||
          c < 0 || matrix[r][c] == 'L' || visited[r][c])
      {
          return 0;
      }
      int count = 1;
      // number of water cells (including this one) that are connected
      visited[r][c] = true; //dfs called for 8 neighbors of the current cell
      count += dfs (r, c + 1);
      count += dfs (r, c - 1  );
      count += dfs (r + 1 , c  );
      count += dfs (r + 1 , c + 1 );
      count += dfs (r + 1 , c - 1 );
      count += dfs (r - 1 , c );
      count += dfs (r - 1 , c + 1 );
      count += dfs (r - 1 , c - 1 );
      return count;
  }


int main()
{
    chrono::time_point<chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    Spider spider = new Spider();

    string line;
    vector<vector> column;
    bool check = false;

    while(getline(cin, line))
    {
        count++;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == " ")
            {
                return true;
            }
        }
        if(check)
        {
            TOTALROW = line.length();
            TOTALCOL = count;
            vector<int> temp = split(line, " , \t");
            spider.startSpider(temp);
            for(int i = 1; i < 8; i++)
            {
                int row = spider.getRow();
                int col = spider.getColumn();
                if
                spider.checkSurround();
            }


        }
        else
        {
            vector<char> temp(line.begin(), line.end());
            column.push_back(temp);
        }
    }

    return 0;
}

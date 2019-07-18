// Runtime: 8 ms, faster than 99.45% of C++ online submissions for Number of Islands.
// Memory Usage: 10.7 MB, less than 76.96% of C++ online submissions for Number of Islands.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
  int turn1to0(vector<vector<char>> &grid, int i, int j)
  {
    grid[i][j] = '0';
    if (i - 1 >=0 && grid[i - 1][j] == '1')
    {
      turn1to0(grid, i - 1, j);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == '1')
    {
      turn1to0(grid, i, j - 1);
    }
    if (i + 1 < grid.size() && grid[i + 1][j] == '1')
    {
      turn1to0(grid, i + 1, j);
    }
    if (j + 1 < grid[i].size() && grid[i][j + 1] == '1')
    {
      return turn1to0(grid, i, j + 1);
    }
    return j;
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int gridRows = grid.size(),
        ret = 0;
    for (int i = 0; i < gridRows; i++)
    {
      auto &row = grid[i];
      auto columns = row.size();
      for (int j = 0; j < columns; j++)
      {
        if(row[j] == '1') {
          ++ret;
          j = turn1to0(grid, i, j);
        }
      }
    }
    return ret;
  }
};

int main()
{
  vector<vector<char>> grid{{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
  cout << Solution().numIslands(grid)
       << endl;
  return 0;
}

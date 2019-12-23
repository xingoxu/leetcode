#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int ret = 0;
    int rowSize = grid.size();
    for (int i = rowSize; i >= -1; --i)
    {
      int columnSize = grid[0].size();
      for (int j = columnSize; j >= -1; --j)
      {
        if (i == rowSize || i == -1 || j == columnSize || j == -1 || grid[i][j] == 0)
        {
          if (j >= 0 && j < columnSize)
          {
            if (i < rowSize - 1 && grid[i + 1][j] == 1)
              ++ret;
            if (i >= 1 && grid[i - 1][j] == 1)
              ++ret;
          }
          if (i >= 0 && i < rowSize)
          {
            if (j >= 1 && grid[i][j - 1] == 1)
              ++ret;

            if (j < columnSize - 1 && grid[i][j + 1] == 1)
              ++ret;
          }
        }
      }
    }
    return ret;
  }
};
int main()
{
  vector<vector<int>> grid{
      {0, 1, 0, 0},
      {1, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0}

  };
  cout << Solution().islandPerimeter(grid) << endl;
  return 0;
}
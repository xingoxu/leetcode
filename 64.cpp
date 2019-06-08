#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    if (grid.size() <= 0 || grid[0].size() <= 0)
      return 0;
    int lastResult = grid[0][0];
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        if (i == 0 && j == 0)
          continue;
        int up = INT_MAX;
        int left = INT_MAX;
        if (i - 1 >= 0)
        {
          up = grid[i - 1][j];
        }
        if (j - 1 >= 0)
        {
          left = grid[i][j - 1];
        }
        int min = up > left ? left : up;
        lastResult = min + grid[i][j];
        grid[i][j] = lastResult;
      }
    }
    return lastResult;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<vector<int>> x{
  {1,3,1},
  {1,5,1},
  {4,2,1}
};

  cout << s->minPathSum(x) << endl;

  return 0;
}

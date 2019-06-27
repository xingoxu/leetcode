#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {
    int rows = dungeon.size() - 1;
    for (int i = rows; i >= 0; i--)
    {
      int columns = dungeon[i].size() - 1;
      for (int j = columns; j >= 0; j--)
      {
        auto &now = dungeon[i][j];
        int ret = INT_MAX;
        if (i + 1 <= rows)
        {
          int diff = dungeon[i + 1][j] - now;
          if (diff <= 0)
            diff = 1;
          ret = min(ret, diff);
        }
        if (j + 1 <= columns)
        {
          int diff = dungeon[i][j + 1] - now;
          if (diff <= 0)
            diff = 1;
          ret = min(ret, diff);
        }
        if (ret == INT_MAX){
          ret = (1 - now <= 0) ? 1 : (1 - now);
        }
        dungeon[i][j] = ret;
      }
    }
    return dungeon[0][0];
  }
};

int main()
{
  vector<vector<int>> x{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};

  cout << Solution().calculateMinimumHP(x) << endl;

  return 0;
}

// Runtime: 48 ms, faster than 81.05% of C++ online submissions for Pacific Atlantic Water Flow.
// Memory Usage: 15.7 MB, less than 78.57% of C++ online submissions for Pacific Atlantic Water Flow.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  void findHigher(vector<vector<int>> &matrix, vector<vector<int>> &record, int x, int y)
  {
    if (record[x][y] != 0)
      return;
    auto current = matrix[x][y];
    // 1 accessing, 2 canAccess
    record[x][y] = 1;
    if (x - 1 >= 0 && matrix[x - 1][y] >= current)
      findHigher(matrix, record, x - 1, y);
    if (y - 1 >= 0 && matrix[x][y - 1] >= current)
      findHigher(matrix, record, x, y - 1);
    if (x + 1 < matrix.size() && matrix[x + 1][y] >= current)
      findHigher(matrix, record, x + 1, y);
    if (y + 1 < matrix[x].size() && matrix[x][y + 1] >= current)
      findHigher(matrix, record, x, y + 1);
    record[x][y] = 2;
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
  {
    int rows = matrix.size();
    if(rows == 0)
      return {};
    vector<vector<int>> pacificAccess(rows, vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < rows; ++i)
    {
      if (i == 0)
      {
        for (int j = 0; j < matrix[0].size(); ++j)
          findHigher(matrix, pacificAccess, 0, j);
        continue;
      }
      findHigher(matrix, pacificAccess, i, 0);
    }

    vector<vector<int>> atlanticAccess(rows, vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < rows; ++i)
    {
      if (i == rows - 1)
      {
        for (int j = 0; j < matrix[rows - 1].size(); ++j)
          findHigher(matrix, atlanticAccess, rows - 1, j);
        continue;
      }
      findHigher(matrix, atlanticAccess, i, matrix[i].size() - 1);
    }

    vector<vector<int>> ret;
    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < matrix[i].size(); ++j)
        if (pacificAccess[i][j] == 2 && atlanticAccess[i][j] == 2)
          ret.push_back({i, j});
    return ret;
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {8, 9, 4},
      {7, 6, 5},

  };
  auto result = Solution().pacificAtlantic(matrix);
  for (auto &r : result)
  {
    cout << r[0] << ' ' << r[1] << endl;
  }
  return 0;
}
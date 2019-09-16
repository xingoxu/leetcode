// Runtime: 56 ms, faster than 41.30% of C++ online submissions for Longest Increasing Path in a Matrix.
// Memory Usage: 12.9 MB, less than 54.55% of C++ online submissions for Longest Increasing Path in a Matrix.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  int rowSize;
  int colSize;

public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    rowSize = matrix.size();
    if (rowSize == 0)
      return 0;
    colSize = matrix[0].size();
    if (colSize == 0)
      return 0;
    vector<vector<int>> memory(rowSize, vector<int>(colSize, 1));

    int biggest = 1;
    for (auto i = 0; i < rowSize; ++i)
    {
      for (auto j = 0; j < colSize; ++j)
      {
        biggest = max(dfs(memory, matrix, i, j, INT_MIN), biggest);
      }
    }
    return biggest;
  }
  int dfs(vector<vector<int>> &memory, vector<vector<int>> &matrix, int i, int j, int previous)
  {
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize)
      return 0;
    if (matrix[i][j] <= previous)
      return 0;
    if (memory[i][j] != 1)
      return memory[i][j];
    int up = dfs(memory, matrix, i - 1, j, matrix[i][j]);
    int down = dfs(memory, matrix, i + 1, j, matrix[i][j]);
    int left = dfs(memory, matrix, i, j - 1, matrix[i][j]);
    int right = dfs(memory, matrix, i, j + 1, matrix[i][j]);

    memory[i][j] = max(up + 1, max(down + 1, max(left + 1, max(memory[i][j], right + 1))));
    return memory[i][j];
  }
};

int main()
{
  vector<vector<int>> nums = {
      {3, 4, 5},
      {3, 2, 6},
      {2, 2, 1}

  };
  cout << Solution().longestIncreasingPath(nums) << endl;
  return 0;
}
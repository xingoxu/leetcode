
// Runtime: 32 ms, faster than 14.27% of C++ online submissions for Maximal Square.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Maximal Square.
// TODO ? 

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int rows = matrix.size();
    int maxArea = 0;
    for (int i = 0; i < rows; ++i)
    {
      int columns = matrix[i].size();
      for (int j = 0; j < columns; ++j)
      {
        if (matrix[i][j] == '0')
        {
          matrix[i][j] = 0;
          continue;
        }
        int up = 0, left = 0, upLeft = 0;
        if (i - 1 >= 0)
        {
          up = matrix[i - 1][j];
        }
        if (j - 1 >= 0)
        {
          left = matrix[i][j - 1];
        }
        if (i - 1 >= 0 && j - 1 >= 0)
        {
          upLeft = matrix[i - 1][j - 1];
        }
        int neighbourArea = min(min(up, left), upLeft);
        matrix[i][j] = neighbourArea == 0 ? 1 : pow(sqrt(neighbourArea) + 1, 2);
        maxArea = max(maxArea, (int)matrix[i][j]);
      }
    }
    return maxArea;
  }
};

int main()
{
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
  cout << Solution().maximalSquare(matrix) << endl;
  return 0;
}
// Runtime: 72 ms, faster than 82.67% of C++ online submissions for Diagonal Traverse.
// Memory Usage: 14.8 MB, less than 71.43% of C++ online submissions for Diagonal Traverse.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
  {
    bool isUp = true;
    int row = matrix.size();
    if (row <= 0)
      return {};
    int column = matrix[0].size();
    int itRow = 0, itColumn = 0;
    vector<int> ret;
    while (itRow != row - 1 || itColumn != column - 1)
    {
      ret.push_back(matrix[itRow][itColumn]);
      // cout << itRow << ' ' << itColumn << endl;
      if (isUp)
      {
        if (itRow == 0 || itColumn == column - 1)
          isUp = !isUp;

        if (itColumn == column - 1)
          ++itRow;
        else if (itRow == 0)
          ++itColumn;
        else
        {
          ++itColumn, --itRow;
        }
      }
      else
      {
        if (itColumn == 0 || itRow == row - 1)
          isUp = !isUp;

        if (itRow == row - 1)
          ++itColumn;
        else if (itColumn == 0)
          ++itRow;
        else
        {
          --itColumn, ++itRow;
        }
      }
    }
    ret.push_back(matrix[itRow][itColumn]);
    return ret;
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  auto result = Solution().findDiagonalOrder(matrix);
  for (auto &num : result)
    cout << num << ' ';
  cout << endl;
}
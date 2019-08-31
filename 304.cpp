// Runtime: 32 ms, faster than 15.56% of C++ online submissions for Range Sum Query 2D - Immutable.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Range Sum Query 2D - Immutable.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

class NumMatrix
{
  vector<vector<int>> BIT;
  int lowbit(int x)
  {
    return x & (-x);
  }
  int sum(int x, int y)
  {
    int result = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
      for (int j = y; j > 0; j -= lowbit(j))
      {
        result += BIT[i][j];
      }
    }
    return result;
  }
  void add(int x, int y, int value)
  {
    for (int i = x; i < BIT.size(); i += lowbit(i))
    {
      for (int j = y; j < BIT[i].size(); j += lowbit(j))
      {
        BIT[i][j] += value;
      }
    }
  }

public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    if(matrix.size() <= 0 || matrix[0].size() <= 0)
      return;
    BIT = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
    for (int i = matrix.size(); i > 0; --i)
    {
      for (int j = matrix[i - 1].size(); j > 0; --j)
      {
        add(i, j, matrix[i - 1][j - 1]);
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return sum(row2 + 1, col2 + 1) - sum(row1, col2 + 1) - sum(row2 + 1, col1) + sum(row1, col1);
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {3, 0, 1, 4, 2},
      {5, 6, 3, 2, 1},
      {1, 2, 0, 1, 5},
      {4, 1, 0, 1, 7},
      {1, 0, 3, 0, 5}};

  NumMatrix *obj = new NumMatrix(matrix);
  cout << obj->sumRegion(2, 1, 4, 3) << endl; // 8
  cout << obj->sumRegion(1, 1, 2, 2) << endl; // 11
  cout << obj->sumRegion(1, 2, 2, 4) << endl; // 12
  return 0;
}
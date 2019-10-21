#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int target)
  {
    int rowNum = matrix.size();
    if (rowNum <= 0)
      return 0;
    int columnNum = matrix[0].size();
    if (columnNum <= 0)
      return 0;
    int result = INT_MIN;
    for (int i = 0; i < columnNum; ++i)
    {
      vector<int> column(rowNum, 0);
      for (int j = i; j < columnNum; ++j)
      {
        int sum = 0, localMax = INT_MIN;
        set<int> bound;
        bound.insert(0);
        for (int k = 0; k < rowNum; ++k)
        {
          int &now = matrix[k][j];
          column[k] += now;
          sum += column[k];

          auto it = bound.lower_bound(sum - target);
          if (it != bound.end())
            localMax = max(localMax, sum - *it);
          bound.insert(sum);
        }
        result = max(result, localMax);
      }
    }
    return result;
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {1, 0, 1},
      {0, -2, 3}};
  int k = 2;
  cout << Solution().maxSumSubmatrix(matrix, k) << endl;
  return 0;
}

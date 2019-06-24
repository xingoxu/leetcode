// Runtime: 8 ms, faster than 80.46% of C++ online submissions for Triangle.
// Memory Usage: 9.6 MB, less than 98.29% of C++ online submissions for Triangle.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    vector<int> dp(triangle[row - 1].begin(), triangle[row - 1].end());
    for (int i = row - 1; i >= 0;i--) {
      for (int j = 0; j <= i - 1; j++)
      {
        dp[j] = min(dp[j + 1], dp[j]) + triangle[i - 1][j];
      }
    }
    return dp[0];
  }
};

int main()
{
  vector<vector<int>> triangle{
      {2},
      {3, 4},
      {6, 5, 7},
      {4, 1, 8, 3}};
  cout << Solution().minimumTotal(triangle) << endl;

  return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int numberOfArithmeticSlices(vector<int> &A)
  {
    int size = A.size(), ret = 0;
    vector<unordered_map<int, int>> dp(size);
    for (int i = 0; i < size; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        if (((long)A[j] - A[i]) < INT_MIN || ((long)A[j] - A[i]) > INT_MAX)
          continue;

        int diff = A[j] - A[i];
        ++dp[i][diff];
        if (dp[j].count(diff) > 0)
        {
          ret += dp[j][diff];
          dp[i][diff] += dp[j][diff];
        }
      }
    }
    return ret;
  }
};

int main()
{
  vector<int> nums = {1, 3, 5, 7, 9};
  cout << Solution().numberOfArithmeticSlices(nums) << endl;
  return 0;
}
// Runtime: 160 ms, faster than 50.40% of C++ online submissions for Target Sum.
// Memory Usage: 50.5 MB, less than 15.38% of C++ online submissions for Target Sum.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{

public:
  int findTargetSumWays(vector<int> &nums, int S)
  {
    if (nums.size() <= 0)
      return 0;
    unordered_map<int, int> dp;
    dp[nums[nums.size() - 1]] = 1;
    dp[-nums[nums.size() - 1]] += 1;

    for (int i = nums.size() - 2; i >= 0; --i)
    {
      unordered_map<int, int> replace;
      for (auto &pair : dp)
      {
        replace[pair.first + nums[i]] += pair.second;
        replace[pair.first - nums[i]] += pair.second;
      }
      dp = replace;
    }
    return dp[S];
  }
};

int main()
{
  vector<int> nums{1, 1, 1, 1, 1};
  cout << Solution().findTargetSumWays(nums, 3) << endl;
  return 0;
}
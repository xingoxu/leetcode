// Runtime: 12 ms, faster than 20.36% of C++ online submissions for Predict the Winner.
// Memory Usage: 11.3 MB, less than 11.11% of C++ online submissions for Predict the Winner.
// TODO find a faster solution

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, unordered_map<int, int>> dp;
  int getScore(vector<int> &nums, int start, int end, bool isFirst)
  {
    if (start == end)
      return isFirst ? nums[start] : -nums[start];
    if (dp.count(start) > 0 && dp[start].count(end) > 0)
      return dp[start][end];

    int useFirst = getScore(nums, start + 1, end, !isFirst);
    int useEnd = getScore(nums, start, end - 1, !isFirst);
    if (isFirst)
      return dp[start][end] = max(useFirst + nums[start], useEnd + nums[end]);
    else
      return dp[start][end] = min(useFirst - nums[start], useEnd - nums[end]);
  }

public:
  bool PredictTheWinner(vector<int> &nums)
  {
    return getScore(nums, 0, nums.size() - 1, true) >= 0;
  }
};

int main()
{
  vector<int> nums{3606449, 6, 5, 9, 452429, 7, 9580316, 9857582, 8514433, 9, 6, 6614512, 753594, 5474165, 4, 2697293, 8, 7, 1};
  cout << Solution().PredictTheWinner(nums) << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  bool dfs(vector<int> &sums, vector<int> &nums, int index, long sum)
  {
    if(index == nums.size())
      return sums[0] == sum && sums[1] == sum && sums[2] == sum && sums[3] == sum;
    for (int i = 0; i < 4; ++i)
    {
      if (sums[i] + nums[index] > sum)
        continue;
      sums[i] += nums[index];
      if (dfs(sums, nums, index + 1, sum))
        return true;
      sums[i] -= nums[index];
    }
    return false;
  }

public:
  bool makesquare(vector<int> &nums)
  {
    if(nums.empty())
      return false;
    long sum = 0;
    for (auto &num : nums)
      sum += num;
    if (sum % 4 > 0)
      return false;
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> sums(4);
    return dfs(sums, nums, 0, sum / 4);
  }
};

int main()
{
  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3, 2, 1};
  cout << Solution().makesquare(nums) << endl;
  return 0;
}
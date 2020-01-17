// Runtime: 88 ms, faster than 15.13% of C++ online submissions for Partition to K Equal Sum Subsets.
// Memory Usage: 8.4 MB, less than 75.00% of C++ online submissions for Partition to K Equal Sum Subsets.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  bool dfs(vector<int> &sums, vector<int> &nums, int index, long sum)
  {
    if (index == nums.size())
    {
      for (auto s : sums)
        if (s != sum)
          return false;
      return true;
    }

    for (int i = 0; i < sums.size(); ++i)
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
  bool canPartitionKSubsets(vector<int> &nums, int k)
  {
    if (nums.empty())
      return false;
    long sum = 0;
    for (auto &num : nums)
      sum += num;
    if (sum % k > 0)
      return false;
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> sums(k);
    return dfs(sums, nums, 0, sum / k);
  }
};

int main()
{
  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3, 2, 1};
  cout << Solution().canPartitionKSubsets(nums, 4) << endl;
  return 0;
}
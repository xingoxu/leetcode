// TODO find a faster solution

// Runtime: 1336 ms, faster than 5.01% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 204.6 MB, less than 5.88% of C++ online submissions for Partition Equal Subset Sum.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, unordered_map<int, bool>> cache;
  bool canPartition(vector<int> &nums, int index, int remain)
  {
    if (index >= nums.size())
      return false;
    auto it = cache.find(index);
    if (it != cache.end())
    {
      auto _it = it->second.find(remain);
      if (_it != it->second.end())
        return _it->second;
    }
    if (remain - nums[index] == 0)
      return true;
    if (remain - nums[index] < 0)
      return cache[index][remain] = false;
    return cache[index][remain] = canPartition(nums, index + 1, remain) || canPartition(nums, index + 1, remain - nums[index]);
  }

public:
  bool canPartition(vector<int> &nums)
  {
    if (nums.size() == 1)
      return false;
    if (nums.size() == 0)
      return true;
    int sum = 0;
    for (auto &x : nums)
      sum += x;
    if (sum % 2 == 1)
      return false;
    return canPartition(nums, 0, sum / 2);
  }
};

int main()
{
  vector<int> nums{39, 68, 6, 73, 8, 81, 90, 12, 60, 87, 20, 84, 83, 8, 55, 62, 97, 8, 77, 51, 71, 96, 3, 29, 90, 63, 2, 14, 38, 60, 33, 34, 79, 41, 83, 32, 17, 67, 63, 97, 23, 16, 19, 8, 95, 57, 56, 96, 31, 85, 47, 19, 86, 60, 68, 11, 84, 5, 70, 87, 70, 49, 30, 86, 63, 90, 73, 70, 86, 49, 98, 91, 57, 48, 98, 35, 22, 23, 78, 40, 96, 82, 94, 14, 78, 49, 43, 12, 53, 23, 22, 90, 87, 92, 1, 39, 24, 7, 54, 84};
  cout << Solution().canPartition(nums) << endl;
  return 0;
}
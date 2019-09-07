// Runtime: 888 ms, faster than 5.10% of C++ online submissions for Burst Balloons.
// Memory Usage: 15.6 MB, less than 5.00% of C++ online submissions for Burst Balloons.

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<string, int> cache;

public:
  int maxCoins(vector<int> &nums)
  {
    int N = nums.size();
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    return maxCoins(nums, 1, N);
  }
  int maxCoins(vector<int> &nums, int start, int end)
  {
    if (start > end)
      return 0;
    string key = to_string(start) + '-' + to_string(end);
    auto it = cache.find(key);
    if (it != cache.end())
      return it->second;
    int best = 0;
    for (int i = start; i <= end; ++i)
    {
      int left = maxCoins(nums, start, i - 1);
      int right = maxCoins(nums, i + 1, end);
      int middle = nums[start - 1] * nums[i] * nums[end + 1];
      int s = left + right + middle;
      if (s > best)
        best = s;
    }
    cache[key] = best;
    return best;
  }
};

int main()
{
  vector<int> nums = {3, 9, 6, 2, 4};
  cout << Solution().maxCoins(nums) << endl;
  return 0;
}
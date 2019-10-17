
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, int> cache;
  int dfs(vector<int> &nums, int remain)
  {
    if (remain == 0)
      return 1;
    auto p = cache.find(remain);
    if (p != cache.end())
    {
      return p->second;
    }

    int ret = 0;
    for (auto &x : nums)
    {
      if (remain - x >= 0)
        ret += dfs(nums, remain - x);
    }
    return cache[remain] = ret;
  }

public:
  int combinationSum4(vector<int> &nums, int target)
  {
    return dfs(nums, target);
  }
};

int main()
{
  vector<int> nums{1, 2, 3};
  cout << Solution().combinationSum4(nums, 4) << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  void dfs(vector<vector<int>> &ret, vector<int> &sub, vector<int> &nums, int index)
  {
    if (sub.size() > 1)
      ret.push_back(sub);
    unordered_map<int, bool> cache;
    for (int i = index; i < nums.size(); ++i)
    {
      if (sub.size() > 0 && nums[i] < sub.back())
        continue;
      if (cache.count(nums[i]) > 0)
        continue;
      cache[nums[i]] = true;
      sub.push_back(nums[i]);
      dfs(ret, sub, nums, i + 1);
      sub.pop_back();
    }
  }

public:
  vector<vector<int>> findSubsequences(vector<int> &nums)
  {

    vector<vector<int>> ret;
    vector<int> sub;
    dfs(ret, sub, nums, 0);
    return ret;
  }
};

int main()
{
  vector<int> nums{4, 3, 2, 1};
  auto result = Solution().findSubsequences(nums);
  for (auto &pair : result)
  {
    for (auto &num : pair)
    {
      cout << num << ' ';
    }
    cout << endl;
  }
  return 0;
}
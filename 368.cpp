// Runtime: 52 ms, faster than 8.75% of C++ online submissions for Largest Divisible Subset.
// Memory Usage: 14.8 MB, less than 6.67% of C++ online submissions for Largest Divisible Subset.

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, list<int>> memory;

public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    if(nums.size() == 0)
      return {};
    sort(nums.begin(), nums.end());
    auto last = nums[nums.size() - 1];
    memory[last] = {last};
    dfs(nums, nums.size() - 2);
    int longest, longest_count = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
      int size = memory[nums[i]].size();
      if (size > longest_count)
      {
        longest_count = size;
        longest = nums[i];
      }
    }
    return vector<int>(memory[longest].begin(), memory[longest].end());
  }
  // 从后向前
  // 记忆index
  void dfs(vector<int> &nums, int index)
  {
    if (index < 0)
    {
      return;
    }
    int longest, longest_count = INT_MIN, current = nums[index];
    for (int i = nums.size() - 1; i > index; --i)
    {
      int traversing = nums[i];
      // cout << memory[traversing].size() << ' ' << longest_count << endl;
      if (traversing % current == 0)
      {
        int size = memory[traversing].size();
        if (size > longest_count)
        {
          longest_count = memory[traversing].size();
          longest = traversing;
        }
      }
    }
    list<int> m;
    if (longest_count == INT_MIN)
    {
      m = {current};
    }
    else
    {
      m = memory[longest];
      m.push_front(current);
    }
    memory[current] = m;
    dfs(nums, index - 1);
  }
};

int main()
{
  vector<int> nums{1, 2, 4, 8};
  auto result = Solution().largestDivisibleSubset(nums);
  for (auto x : result)
  {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}

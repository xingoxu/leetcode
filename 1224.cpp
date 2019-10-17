
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, int> count_count;
  unordered_map<int, int> exist_count;
  bool check()
  {
    if (exist_count.size() == 1)
      return true;
    if (count_count.size() == 1 && count_count.begin()->first == 1)
      return true;
    if (count_count.size() != 2)
      return false;

    auto first = count_count.begin();
    auto second = first;
    ++second;
    if (first->first == 1 && first->second == 1)
      return true;
    if (second->first == 1 && second->second == 1)
      return true;
    if (first->second == 1 && first->first - second->first == 1)
      return true;
    if (second->second == 1 && second->first - first->first == 1)
      return true;
    return false;
  }

public:
  int maxEqualFreq(vector<int> &nums)
  {
    int maxLength = 0, prefix_count = 0;
    for (auto &x : nums)
    {
      int oldCount = exist_count[x];

      if (count_count.find(oldCount) != count_count.end())
        if (--count_count[oldCount] <= 0)
          count_count.erase(oldCount);

      ++count_count[++exist_count[x]];

      ++prefix_count;
      if (check())
        maxLength = max(maxLength, prefix_count);
    }
    return maxLength;
  }
};

int main()
{
  vector<int> rollMax{1, 2};
  cout << Solution().maxEqualFreq(rollMax) << endl;
  return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    unordered_map<int, int> dict;
    for (auto &num : nums)
      ++dict[num];
    int count = 0;
    for (auto &pair : dict)
    {
      if (k > 0)
      {
        if (dict.count(pair.first + k) > 0)
          ++count;
      }
      else if (k == 0)
      {
        if (pair.second > 1)
          ++count;
      }
    }
    return count;
  }
};

int main()
{
  vector<int> nums{3, 1, 4, 1, 5};
  cout << Solution().findPairs(nums, 2) << endl;
  return 0;
}
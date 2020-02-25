// Runtime: 128 ms, faster than 52.63% of C++ online submissions for Contiguous Array.
// Memory Usage: 19.8 MB, less than 83.33% of C++ online submissions for Contiguous Array.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  unordered_map<int, int> index;

public:
  int findMaxLength(vector<int> &nums)
  {
    index[0] = nums.size();
    int sum = 0, result = 0;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
      if (nums[i] == 0)
        --sum;
      else
        ++sum;
      if (index.count(sum) > 0)
        result = max(result, index[sum] - i);
      else
        index[sum] = i;
    }
    return result;
  }
};

int main()
{
  vector<int> nums{1, 0, 0, 1, 0, 0, 1};
  cout << Solution().findMaxLength(nums);
  return 0;
}
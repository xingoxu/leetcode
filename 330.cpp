// Runtime: 8 ms, faster than 70.83% of C++ online submissions for Patching Array.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Patching Array.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minPatches(vector<int> &nums, int n)
  {
    int iterator = 0, patches = 0;
    long maxN = 0;
    for (long i = 1; i <= n; ++i)
    {
      if (iterator < nums.size() && (maxN >= nums[iterator] || nums[iterator] == i))
        maxN += nums[iterator++];
      else
      {
        maxN += i;
        ++patches;
      }
      i = max(i, maxN);
    }
    return patches;
  }
};

int main()
{
  vector<int> nums =
      {};
  cout << Solution().minPatches(nums, 7) << endl;
  return 0;
}
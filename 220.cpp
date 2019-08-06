#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  bool isAlmostDuplicate(int a, int b, int t)
  {
    return abs(a - b) <= t;
  }

public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
  {
    int numLength = nums.size();
    for (int i = numLength - 1; i >= 0; i--)
    {
      if (i + k <= numLength - 1 && isAlmostDuplicate(nums[i], nums[i + k], t))
      {
        return true;
      }
      if (i - k >= 0 && isAlmostDuplicate(nums[i], nums[i - k], t))
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  vector<int> nums = {1, 5, 9, 1, 5, 9};
  cout << Solution().containsNearbyAlmostDuplicate(nums, 2, 3) << endl;
  return 0;
}
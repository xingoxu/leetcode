
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.size() <= 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
  }
  int rob(vector<int> &nums, int start, int end)
  {
    int noRob = 0;
    int robbed = nums[end];
    for (int i = end - 1; i >= start; i--)
    {
      int noRobT = noRob;
      noRob = max(robbed, noRob);
      robbed = noRobT + nums[i];
    }
    return max(noRob, robbed);
  }
};

int main()
{
  vector<int> grid{2, 3, 2};
  cout << Solution().rob(grid)
       << endl;
  return 0;
}


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
    int noRob = 0;
    int robbed = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
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
  vector<int> grid{1, 2, 3, 1};
  cout << Solution().rob(grid)
       << endl;
  return 0;
}

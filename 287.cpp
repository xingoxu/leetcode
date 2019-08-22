#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int slow = nums[0], fast = nums[nums[0]];
    int slowIndex = 0, fastIndex = nums[0];
    while (fast != slow || fastIndex != slowIndex)
    {
      fastIndex = nums[fast];
      fast = nums[fastIndex];
      slowIndex = slow;
      slow = nums[slowIndex];
    }
    slow = 0;
    slowIndex = 0;
    while (fast != slow || fastIndex != slowIndex)
    {
      fastIndex = fast;
      fast = nums[fastIndex];
      slowIndex = slow;
      slow = nums[slow];
    }

    return slowIndex;
  }
};

int main()
{
  vector<int> nums{1, 3, 4, 2, 2};
  cout << Solution().findDuplicate(nums);
  return 0;
}
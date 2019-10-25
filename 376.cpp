// Runtime: 4 ms, faster than 68.92% of C++ online submissions for Wiggle Subsequence.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Wiggle Subsequence.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    if (nums.size() < 2)
      return nums.size();
    int upCount = 1, before = nums[0], isUp = true;
    for (int i = 1; i < nums.size(); ++i)
    {
      if(isUp){
        if (nums[i] - before > 0)
        {
          ++upCount;
          isUp = !isUp;
        }
      } else {
        if (nums[i] - before < 0)
        {
          ++upCount;
          isUp = !isUp;
        }
      }
      before = nums[i];
    }
    int downCount = 1;
    before = nums[0], isUp = false;
    for (int i = 1; i < nums.size(); ++i)
    {
      if(isUp){
        if (nums[i] - before > 0)
        {
          ++downCount;
          isUp = !isUp;
        }
        before = nums[i];
      } else {
        if (nums[i] - before < 0)
        {
          ++downCount;
          isUp = !isUp;
        }
        before = nums[i];
      }
    }
    return max(upCount, downCount);
  }
};

int main()
{
  vector<int> nums{0, 0};

  cout << Solution().wiggleMaxLength(nums) << endl;
  return 0;
}

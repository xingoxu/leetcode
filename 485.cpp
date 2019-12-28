#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    int count = 0, ret = 0;
    for (auto &num : nums)
    {
      if (num != 1)
      {
        ret = max(count, ret);
        count = 0;
      }
      else
        ++count;
    }
    return max(count, ret);
  }
};

int main()
{
  vector<int> nums{1, 1, 0, 1, 1, 1};
  cout << Solution().findMaxConsecutiveOnes(nums) << endl;
  return 0;
}
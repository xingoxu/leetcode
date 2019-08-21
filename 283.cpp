
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums)
  {
    int pZero = 0;
    for (int pNonZero = 0; pNonZero < nums.size(); ++pNonZero)
    {
      if (nums[pNonZero] != 0)
        nums[pZero++] = nums[pNonZero];
    }
    for (; pZero < nums.size(); ++pZero)
    {
      nums[pZero] = 0;
    }
  }
};

int main()
{
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution().moveZeroes(nums);
  for (int i = 0; i < nums.size(); ++i)
  {
    cout << nums[i] << ' ';
  }
  cout << endl;

  return 0;
}

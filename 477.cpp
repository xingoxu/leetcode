#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int totalHammingDistance(vector<int> &nums)
  {
    int ret = 0;
    while (true)
    {
      int zeroCount = 0;
      int zero = 0, one = 0;
      for (auto &num : nums)
      {
        if(num == 0)
          ++zeroCount;
        if((num & 1) == 1)
          ++one;
        else
          ++zero;
        num = num >> 1;
      }
      ret += one * zero;

      if(zeroCount == nums.size())
        break;
    }
    return ret;
  }
};

int main()
{
  vector<int> nums{4, 14, 2};
  cout << Solution().totalHammingDistance(nums) << endl;
  return 0;
}

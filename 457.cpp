// Runtime: 12 ms, faster than 38.05% of C++ online submissions for Circular Array Loop.
// Memory Usage: 8.4 MB, less than 90.00% of C++ online submissions for Circular Array Loop.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  int numSize;
  int getNext(int iNow, int num)
  {
    int result = iNow + num;
    while (result >= numSize)
    {
      result -= numSize;
    }
    while (result < 0)
    {
      result += numSize;
    }
    return result;
  }

public:
  bool circularArrayLoop(vector<int> &nums)
  {
    numSize = nums.size();
    for (int i = numSize - 1; i >= 0; --i)
    {
      int fp = i;
      int sp = i;
      do
      {
        fp = getNext(fp, nums[fp]);
        sp = getNext(sp, nums[sp]);
        sp = getNext(sp, nums[sp]);
      } while (fp != sp);

      int circleP = fp;
      int distance = 0;
      do
      {
        int before = nums[circleP];
        circleP = getNext(circleP, nums[circleP]);
        int after = nums[circleP];
        if (before * after < 0)
        {
          distance = 0;
          break;
        }
        ++distance;
      } while (circleP != fp);
      if (distance > 1)
        return true;
    }
    return false;
  }
};

int main()
{
  vector<int> nums{-2, -3, -9};
  cout << Solution().circularArrayLoop(nums) << endl;
  return 0;
}
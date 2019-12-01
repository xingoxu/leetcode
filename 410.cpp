#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  bool canSplit(vector<int> &nums, int m, int max)
  {
    long sum = 0;
    for (auto &num : nums)
    {
      if (sum + num > max)
      {
        sum = num;
        // cout << num << ' ' << m - 1 << endl;
        if (--m < 0)
          return false;
      }
      else
        sum += num;
    }
    return true;
  }

public:
  int splitArray(vector<int> &nums, int m)
  {
    int minStart = INT_MIN;
    long maxEnd = 0;
    for (auto &num : nums)
    {
      minStart = max(num, minStart);
      maxEnd += num;
    }

    while (minStart < maxEnd)
    {
      int mid = ((long)minStart + (long)maxEnd) / 2;
      // cout << "mid: " << mid << endl;
      if (canSplit(nums, m - 1, mid))
        maxEnd = mid;
      else
        minStart = mid + 1;
    }
    return minStart;
  }
};

int main()
{
  vector<int> nums = {7, 2, 5, 10, 8};
  cout << Solution().splitArray(nums, 2) << endl;
  return 0;
}
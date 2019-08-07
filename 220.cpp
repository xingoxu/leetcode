// Runtime: 36 ms, faster than 7.78% of C++ online submissions for Contains Duplicate III.
// Memory Usage: 12.5 MB, less than 11.43% of C++ online submissions for Contains Duplicate III.
// TODO

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
  map<long, int> timesMap;

public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
  {
    if (k == 0)
      return false;
    int numLength = nums.size();
    for (int i = numLength - 1; i > numLength - 1 - k && i >= 0; i--)
    {
      ++timesMap[nums[i]];
    }

    for (int i = numLength - 1; i >= 0; i--)
    {
      if (i + k <= numLength - 1)
      {
        if (timesMap[nums[i + k]]-- == 1)
        {
          timesMap.extract(nums[i + k]);
        }
      }
      if (i - k >= 0)
      {
        timesMap[nums[i - k]]++;
      }
      if (timesMap[nums[i]]-- == 1)
      {
        timesMap.extract(nums[i]);
      }

      int lower = INT_MAX;
      auto iterator = timesMap.lower_bound((long)nums[i] - t);
      if (iterator != timesMap.end())
        lower = iterator->first;
      int higher = INT_MIN;
      iterator = timesMap.upper_bound((long)nums[i] + t);
      if (iterator != timesMap.begin())
        higher = (--iterator)->first;

      if (lower <= higher)
        return true;

      timesMap[nums[i]]++;
    }
    return false;
  }
};

int main()
{
  vector<int> nums = {0};
  cout << Solution().containsNearbyAlmostDuplicate(nums, 0, 0) << endl;
  return 0;
}
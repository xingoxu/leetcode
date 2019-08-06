#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, vector<int>> m;

public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    int numLength = nums.size();
    for (int i = numLength - 1; i >= 0; i--)
    {
      auto &beforeAppearance = m[nums[i]];
      beforeAppearance.push_back(i);
      if (beforeAppearance.size() > 1 && find(beforeAppearance, i, k))
      {
        return true;
      }
    }
    return false;
  }
  // logn
  bool find(vector<int> &appearance, int i, int k)
  {
    int big = i + k;
    int small = i - k;

    int end = appearance.size() - 1;
    if (small > appearance[0] || big < appearance[end])
      return false;
    int bigIndex = findBig(appearance, big, 0, end);
    int smallIndex = findSmall(appearance, small, 0, end);
    return bigIndex < smallIndex;
  }
  int findBig(vector<int> &appearance, int target, int start, int end)
  {
    if (start > end)
    {
      if (end < 0)
        return 0;
      else
        return target >= appearance[end] ? end : end + 1;
    }
    if (start == end)
      return target >= appearance[start] ? start : start + 1;
    int middle = (end - start) / 2 + start;
    if (target < appearance[middle])
      return findBig(appearance, target, middle + 1, end);
    else if (target > appearance[middle])
      return findBig(appearance, target, start, middle - 1);
    else
      return middle;
  }
  int findSmall(vector<int> &appearance, int target, int start, int end)
  {
    if (start >= end)
      return target <= appearance[start] ? start : start - 1;
    int middle = (end - start) / 2 + start;
    if (target < appearance[middle])
    {
      return findSmall(appearance, target, middle + 1, end);
    }
    else if (target > appearance[middle])
    {
      return findSmall(appearance, target, start, middle - 1);
    }
    else
    {
      return middle;
    }
  }
};

int main()
{
  vector<int> nums = {99, 99};
  cout << Solution().containsNearbyDuplicate(nums, 2) << endl;
  return 0;
}
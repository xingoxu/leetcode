#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  int findMiddle(vector<int> &nums, int target, int left, int right)
  {
    int start = left, end = right, pivot = nums[(left + right) / 2];
    while (start <= end)
    {
      while (nums[start] < pivot)
        ++start;
      while (nums[end] > pivot)
        --end;
      if (start >= end)
        break;
      swap(nums[start++], nums[end--]);
    }
    if (start - left + 1 > target)
      return findMiddle(nums, target, left, start - 1);
    if (start - left + 1 == target && start == end)
      return nums[start];
    return findMiddle(nums, target - end + left - 1, end + 1, right);
  }

public:
  int minMoves2(vector<int> &nums)
  {
    int middle = findMiddle(nums, nums.size() / 2 + 1, 0, nums.size() - 1);
    int ret = 0;
    for (auto &num : nums)
      ret += abs(middle - num);
    return ret;
  }
};

int main()
{
  vector<int> nums{1, 2, 3};
  cout << Solution().minMoves2(nums) << endl;
  return 0;
}
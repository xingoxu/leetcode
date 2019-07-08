
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    return findLocalMaximum(nums, 0, nums.size() - 1);
  }
  int findLocalMaximum(vector<int> &nums, int left, int right)
  {
    if (left == right)
      return left;
    if (right - left == 1)
      return nums[right] > nums[left] ? right : left;
    int mid = (right - left) / 2 + left;
    if (nums[mid] > nums[mid + 1])
      return findLocalMaximum(nums, left, mid);
    else
      return findLocalMaximum(nums, mid + 1, right);
  }
};

int main()
{
  vector<int> nums{1, 2, 1, 3, 5, 6, 4};
  cout << Solution().findPeakElement(nums) << endl;
  return 0;
}

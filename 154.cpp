#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    return findMin(nums, 0, nums.size() - 1);
  }
  int findMin(vector<int> &nums, int left, int right)
  {
    if(left == right)
      return nums[left];
    if (right - left == 1)
      return nums[left] < nums[right] ? nums[left] : nums[right];

    int middle = (right - left) / 2 + left;
    if (nums[left] > nums[right]) {
      if (nums[left] > nums[middle]) {
        return findMin(nums, left, middle);
      } else {
        return findMin(nums, middle, right);
      }
    } else if(nums[left] == nums[right]) {
      if (nums[left] > nums[middle]) {
        return findMin(nums, left, middle);
      } else if(nums[left] < nums[middle]) {
        return findMin(nums, middle, right);
      } else {
        return min(findMin(nums, left, middle), findMin(nums, middle, right));
      }
    } else {
      return nums[left];
    }
  }
};

int main()
{
  vector<int> x{2,2,2,0,2};
  cout << Solution().findMin(x) << endl;
  return 0;
}

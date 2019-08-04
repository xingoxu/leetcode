#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    return findKthLargest(nums, 0, nums.size() - 1, k);
  }
  int findKthLargest(vector<int> &nums, int start, int end, int k)
  {
    if (end == start)
      return nums[start];
    if (end - start == 1)
    {
      if (k == 1)
        return nums[start] > nums[end] ? nums[start] : nums[end];
      else
      {
        return nums[start] < nums[end] ? nums[start] : nums[end];
      }
    }
    int middle = split(nums, start, end);
    int rightAmount = (end - middle + 1);
    if (rightAmount == k)
      return findSmallest(nums, middle, end);

    if (rightAmount > k)
      return findKthLargest(nums, middle, end, k);
    else
      return findKthLargest(nums, start, middle - 1, k - rightAmount);
  }
  int split(vector<int> &nums, int start, int end)
  {
    int middle = (end - start) / 2 + start;
    middle = nums[middle];
    while (start < end)
    {
      while (nums[start] < middle)
      {
        ++start;
      }
      while (nums[end] > middle)
      {
        end--;
      }
      if (start >= end)
      {
        break;
      }
      auto tmp = nums[start];
      nums[start] = nums[end];
      nums[end] = tmp;
      ++start;
      end--;
    }
    if(nums[start] < middle)
      return start + 1;
    return start;
  }
  int findSmallest(vector<int> &nums, int start, int end)
  {
    int smallest = INT_MAX;
    for (int i = start; i <= end; i++)
    {
      smallest = min(smallest, nums[i]);
    }
    return smallest;
  }
};

int main()
{
  vector<int> nums = {5,2,4,1,3,6,0};

  cout << Solution().findKthLargest(nums, 4) << endl;
  return 0;
}
// Runtime: 8 ms, faster than 87.33% of C++ online submissions for Search in Rotated Sorted Array II.
// Memory Usage: 9 MB, less than 5.09% of C++ online submissions for Search in Rotated Sorted Array II.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
  bool search(vector<int> &nums, int target)
  {
    return _search(nums, 0, nums.size() - 1, target);
  }
  bool _search(vector<int> &nums, int start,int end,int target) {
    int length = end - start + 1;
    if(length <= 0) {
      return false;
    }
    if (length == 1 && nums[start] == target)
      return true;
    else if (length == 1)
      return false;
    
    if (length == 2) {
      if (nums[start] == target ||nums[end] == target)
        return true;
      return false;
    }

    int newStart, newEnd;
    int middle = length / 2 + start;
    if (length % 2 == 1)
    {
      if (nums[middle] == target)
      {
        return true;
      }
    }

    if (nums[middle] >= nums[start] && nums[start] <= target && nums[middle] >= target) {
      newStart = start;
      newEnd = middle;
    } else if (nums[middle] <= nums[end] && nums[middle] <= target && nums[end] >= target) {
      newStart = middle;
      newEnd = end;
    } else if (nums[middle] > nums[start]) {
      newStart = middle;
      newEnd = end;
    }
    else if(nums[middle] < nums[end])
    {
      newStart = start;
      newEnd = middle;
    }
    else
    {
      if (nums[start] != target && nums[end] != target)
        return _search(nums, start + 1, end - 1, target);
      else
        return true;
    }

    return _search(nums, newStart, newEnd, target);
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{1,1,1,3,1}; // -4 -1 -1 0 1 2
  cout << s->search(x, 3) << endl;
  return 0;
}

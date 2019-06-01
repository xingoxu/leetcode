#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    return {findFirst(nums, 0, nums.size() - 1, target), findEnd(nums, 0, nums.size() - 1, target)};
  }
  int findFirst(vector<int> &nums, int start, int end, int target)
  {
    int length = end - start + 1;
    if (length <= 0)
    {
      return -1;
    }
    if (length == 1 && nums[start] == target)
      return start;
    else if (length == 1)
      return -1;

    if (length == 2)
    {
      if (nums[start] == target)
        return start;
      if (nums[end] == target)
        return end;
      return -1;
    }

    int newStart, newEnd;
    int middle = length / 2 + start;

    if (nums[middle] >= target)
    {
      newStart = start;
      newEnd = middle;
    }
    else
    {
      newStart = middle + 1;
      newEnd = end;
    }

    return findFirst(nums, newStart, newEnd, target);
  }
  int findEnd(vector<int> &nums, int start, int end, int target)
  {
    int length = end - start + 1;
    if (length <= 0)
    {
      return -1;
    }
    if (length == 1 && nums[start] == target)
      return start;
    else if (length == 1)
      return -1;

    if (length == 2)
    {
      if (nums[end] == target)
        return end;
      if (nums[start] == target)
        return start;

      return -1;
    }

    int newStart, newEnd;
    int middle = length / 2 + start;

    if (nums[middle] > target)
    {
      newStart = start;
      newEnd = middle - 1;
    }
    else
    {
      newStart = middle;
      newEnd = end;
    }

    return findEnd(nums, newStart, newEnd, target);
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{5, 7, 7, 8, 8, 10}; // -4 -1 -1 0 1 2
  cout << s->searchRange(x, 8)[1] << endl;
  return 0;
}

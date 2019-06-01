#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    return _search(nums, 0, nums.size() - 1, target);
  }
  int _search(vector<int> &nums, int start,int end,int target) {
    int length = end - start + 1;
    if(length <= 0) {
      return -1;
    }
    if (length == 1 && nums[start] == target)
      return start;
    else if (length == 1)
      return -1;
    
    if (length == 2) {
      if (nums[start] == target) return start;
      if (nums[end] == target)
        return end;
      return -1;
    }

    int newStart, newEnd;
    int middle = length / 2 + start;
    if (length % 2 == 1)
    {
      if (nums[middle] == target)
      {
        return middle;
      }
    }

    if (nums[middle] > nums[start] && nums[start] <= target && nums[middle] >= target) {
      newStart = start;
      newEnd = middle;
    } else if (nums[middle] < nums[end] && nums[middle] <= target && nums[end] >= target) {
      newStart = middle;
      newEnd = end;
    } else if (nums[middle] > nums[start]) {
      newStart = middle;
      newEnd = end;
    }
    else
    {
      newStart = start;
      newEnd = middle;
    }

    return _search(nums, newStart, newEnd, target);
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{4,5,6,7,0,1,2}; // -4 -1 -1 0 1 2
  cout << s->search(x, 3) << endl;
  return 0;
}

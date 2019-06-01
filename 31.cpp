#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int size = nums.size();
    int i = size - 2;
    for (; i >= 0; i--)
    {
      if (nums[i + 1] > nums[i])
      {
        break;
      }
    }
    sort(nums.begin() + i + 1, nums.end());
    if (i == -1)
      return;
    int j = i + 1;
    for (; j < size; j++)
    {
      if (nums[j] > nums[i])
      {
        break;
      }
    }
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
    sort(nums.begin() + i + 1, nums.end());
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3, 2, 2, 3}; // -4 -1 -1 0 1 2
  s->nextPermutation(x);
  return 0;
}

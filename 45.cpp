// Runtime: 44 ms, faster than 11.43% of C++ online submissions for Jump Game II.
// Memory Usage: 75.1 MB, less than 5.01% of C++ online submissions for Jump Game II.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    map<int, int> cache;
    if(nums.size() <= 1)
      return 0;
    return _jump(0, nums, cache);
  }
  int _jump(int index, vector<int> &nums, map<int, int> &cache)
  {
    int numsSize = nums.size();
    if (nums[index] + index >= numsSize - 1)
    {
      cache[index] = 1;
      return 1;
    }
    if (cache[index] > 0)
      return cache[index];

    int minimalSize = INT16_MAX;
    for (int i = nums[index] + index; i > index; i--)
    {
      int result = _jump(i, nums, cache);
      if (result == 1)
      {
        minimalSize = 1;
        break;
      }
      else if (result < minimalSize)
      {
        minimalSize = result;
      }
    }
    minimalSize += 1;
    cache[index] = minimalSize;
    return minimalSize;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{2, 3, 1, 1, 4}; // -4 -1 -1 0 1 2

  cout << s->jump(x) << endl;
  return 0;
}

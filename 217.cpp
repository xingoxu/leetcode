#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, bool> m;

public:
  bool containsDuplicate(vector<int> &nums)
  {
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (m[nums[i]])
        return true;
      else
        m[nums[i]] = true;
    }
    return false;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  cout << Solution().containsDuplicate(nums) << endl;
  return 0;
}
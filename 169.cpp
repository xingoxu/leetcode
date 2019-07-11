#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, int> map;

public:
  int majorityElement(vector<int> &nums)
  {
    int size = nums.size();
    for (auto x : nums)
    {
      if (++map[x] > size / 2)
        return x;
    }
    return 0;
  }
};

int main()
{
  vector<int> nums{
      2, 2, 1, 1, 1, 2, 2};
  cout << Solution().majorityElement(nums) << endl;

  return 0;
}

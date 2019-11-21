#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    vector<int> result;
    for (int i = nums.size() - 1; i >= 0;--i) {
      auto index = abs(nums[i]) - 1;
      if (nums[index] < 0)
        result.push_back(index + 1);
      else
        nums[index] = -nums[index];
    }
    return result;
  }
};

int main()
{
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  auto result = Solution().findDuplicates(nums);
  for (auto &x : result)
    cout << x << ' ';
  cout << endl;
  return 0;
}
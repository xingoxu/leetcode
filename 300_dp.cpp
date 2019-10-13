
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution
{

public:
  int lengthOfLIS(vector<int> &nums)
  {
    vector<int> result(nums.size());
    int finalMax = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      int maxResult = 1;
      for (int j = 0; j < i; ++j)
      {
        if(nums[i]>nums[j]) {
          maxResult = max(maxResult, result[j] + 1);
        }
      }
      result[i] = maxResult;
      finalMax = max(finalMax, maxResult);
    }
    return finalMax;
  }
};

int main()
{
  vector<int> nums{1, 3, 6, 7, 9, 4, 10, 5, 6};
  cout << Solution().lengthOfLIS(nums) << endl;
  return 0;
}
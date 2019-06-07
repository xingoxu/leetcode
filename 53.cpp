// Runtime: 8 ms, faster than 91.54% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.4 MB, less than 52.34% of C++ online submissions for Maximum Subarray.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int length = nums.size();
    int largest = 0, sum = 0;
    for (int i = 0; i < length; i++)
    {
      sum = sum + nums[i];
      if (sum > largest)
      {
        largest = sum;
      }
      if (sum < 0)
        sum = 0;
    }
    if (largest == 0)
    {
      largest = INT_MIN;
      for (int i = 0; i < length; i++)
      {
        if (nums[i] > largest)
          largest = nums[i];
      }
    }
    return largest;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{-1}; // -4 -1 -1 0 1 2

  cout << s->maxSubArray(x) << endl;
  return 0;
}

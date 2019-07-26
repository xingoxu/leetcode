// O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int s, vector<int> &nums)
  {
    int sum = 0;
    int minimal = INT_MAX;
    for (int right = nums.size() - 1, left = nums.size() - 1; left >= 0; left--)
    {
      sum += nums[left];
      if (sum >= s)
      {
        do
        {
          sum -= nums[right];
          right--;
        } while (sum >= s);

        int lengthNow = right - left + 2;
        if (lengthNow < minimal){
          minimal = lengthNow;
        }
      }
    }
    return minimal == INT_MAX ? 0 : minimal;
  }
};

int main()
{
  vector<int> x{1, 2, 3, 4, 5};

  cout << Solution().minSubArrayLen(11, x) << endl;
  return 0;
}
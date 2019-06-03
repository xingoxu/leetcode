#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    if (nums.size() == 0)
      return 1;
    if (nums.size() == 1 && nums[0] != 1)
      return 1;
    if (nums.size() == 1 && nums[0] == 1)
      return 2;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] <= nums.size() && nums[i] > 0)
      {
        if (nums[i] - 1 <= i)
          nums[nums[i] - 1] = nums[i];
        else
        {
          int temp = nums[i];
          while (temp <= nums.size() && temp > 0 && temp - 1 > i)
          {
            int newTemp = nums[temp - 1];

            nums[temp - 1] = temp;
            if (newTemp == temp)
              break;
            temp = newTemp;
          }
          if (temp <= nums.size() && temp > 0 && temp - 1 <= i)
            nums[temp - 1] = temp;
        }
      }
    }
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != i + 1)
        return i + 1;
    }
    return nums.size() + 1;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{4,2}; // -4 -1 -1 0 1 2

  cout << s->firstMissingPositive(x) << endl;
  return 0;
}

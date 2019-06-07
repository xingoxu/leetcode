

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    if (nums.size() <= 1)
      return true;
    int lastCanJump = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
      if (i < lastCanJump && nums[i] + i >= lastCanJump)
        lastCanJump = i;
    }
    return lastCanJump == 0;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3, 2, 1, 0, 4};

  cout << s->canJump(x) << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
  int thirdMax(vector<int> &nums)
  {
    set<int, greater<int>> set;
    for (auto &x : nums)
      set.insert(x);
    int count = 0, last = 0;
    for (auto &x : set)
    {
      if(++count == 3)
        return x;
      last = max(last, x);
    }
    return last;
  }
};

int main()
{
  vector<int> nums = {2, 1};
  cout << Solution().thirdMax(nums) << endl;
  return 0;
}
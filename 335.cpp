// TODO: understand
// https://leetcode.com/problems/self-crossing/discuss/79175/The-best-submission-in-C-searching-for-the-crossing-patterns-is-the-key

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  bool isSelfCrossing(vector<int> &x)
  {
    for (int i = 3; i < x.size(); i++)
    {
      if (x[i - 1] <= x[i - 3] && x[i] >= x[i - 2])
        return true;
      if (i > 3 && x[i] + x[i - 4] >= x[i - 2] && x[i - 1] == x[i - 3])
        return true;
      if (i > 4 && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 1] <= x[i - 3] && x[i] + x[i - 4] >= x[i - 2] && x[i - 4] <= x[i - 2])
        return true;
    }
    return false;
  }
};

int main()
{
  vector<int> x{1, 2, 3, 4};
  cout << Solution().isSelfCrossing(x) << endl;
  return 0;
}

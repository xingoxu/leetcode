// Runtime: 4 ms, faster than 95.00% of C++ online submissions for Ugly Number II.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Ugly Number II.

#include <iostream>
#include <vector>
using namespace std;

vector<int> result{1};
int it = 1;
int l2 = 0, l3 = 0, l5 = 0;

class Solution
{
public:
  int nthUglyNumber(int n)
  {
    if (result.size() > n)
      return result[n - 1];

    result.resize(n);
    for (; it < n; ++it)
    {
      result[it] = min(result[l2] * 2, min(result[l3] * 3, result[l5] * 5));
      if (result[it] == result[l2] * 2)
        ++l2;
      if (result[it] == result[l3] * 3)
        ++l3;
      if (result[it] == result[l5] * 5)
        ++l5;
    }
    return result[n - 1];
  }
};

int main()
{

  cout << Solution().nthUglyNumber(10) << endl;

  return 0;
}

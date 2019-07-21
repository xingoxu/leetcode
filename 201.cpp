#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int rangeBitwiseAnd(int m, int n)
  {
    int diff = n - m;
    if (diff == 0)
      return m;
    int i = 1;
    while (diff > 1)
    {
      i = (i << 1) + 1;
      diff = diff >> 1;
    }
    i = ~i;
    m = m & i;
    m = m & n;
    return m;
  }
};

int main()
{
  cout << Solution().rangeBitwiseAnd(1, 2) << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  int countDigitOne(int n)
  {
    int ones = 0;
    for (long long m = 1; m <= n; m *= 10)
    {
      int a = n / m, b = n % m;

      ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
  }
};

int main()
{
  cout << Solution().countDigitOne(3141592) << endl;
  return 0;
}
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Four.
// Memory Usage: 8.3 MB, less than 14.29% of C++ online submissions for Power of Four.

#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
  bool isPowerOfFour(int num)
  {
    return num > 0 && (pow(4, (int)(log10(num) / log10(4))) == num);
  }
};

int main()
{
  cout << Solution().isPowerOfFour(16) << endl;
  return 0;
}
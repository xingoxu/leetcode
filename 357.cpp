// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Numbers with Unique Digits.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Count Numbers with Unique Digits.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
      if(n == 0)
        return 0;
      int ret = 10;
      int multiple = 9;
      int available = 9;
      for (int i = 2; i <= 10 && i <= n; ++i)
      {
        multiple *= (available--);
        ret += multiple;
      }
      return ret;
    }
};


int main()
{
  cout << Solution().countNumbersWithUniqueDigits(3) << endl;
  return 0;
}

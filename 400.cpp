// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Nth Digit.
// Memory Usage: 8.5 MB, less than 25.00% of C++ online submissions for Nth Digit.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int findNthDigit(int n)
  {
    long i = 9;
    int count = 1;
    while (true)
    {
      if (i > n)
      {
        i -= pow(10, count - 1) * count * 9;
        n -= i;
        if (n % count > 0)
        {
          auto target = to_string(n / count + (int)pow(10, count - 1));
          return target[n % count - 1] - '0';
        }
        else
        {
          auto target = to_string(n / count + (int)pow(10, count - 1) - 1);
          return target[target.size() - 1] - '0';
        }
      }
      ++count;
      i += pow(10, count - 1) * count * 9;
    }
    return 0;
  }
};

int main()
{
  cout << Solution().findNthDigit(13) << endl;
  return 0;
}
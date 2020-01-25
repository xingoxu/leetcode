#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  int largestPalindrome(int n)
  {
    if (n == 1)
      return 9;
    int upper = pow(10, n) - 1;
    int lower = pow(10, n - 1);
    cout << upper << ' ' << lower << endl;
    for (int i = upper; i >= lower; i--)
    {
      long cand = buildPalindrome(i);
      for (long j = upper; j * j >= cand; j--)
      {
        if (cand % j == 0 && cand / j <= upper)
        {
          return cand % 1337;
        }
      }
    }
    return -1;
  }

  long buildPalindrome(int n)
  {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stol(to_string(n) + s);
  }
};

int main()
{
  cout << Solution().largestPalindrome(2) << endl;
  return 0;
}
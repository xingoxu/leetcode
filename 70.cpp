#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int first = 1;
    int second = 2;
    int now = first + second;
    for (int i = 3; i <= n; i++)
    {
      now = first + second;
      first = second;
      second = now;
    }
    return now;
  }
  // actually it is a fibnacci
  int old_climbStairs(int n)
  {
    if (n <= 2)
      return n;
    return old_climbStairs(n - 1) + old_climbStairs(n - 2);
  }
};

int main()
{
  Solution s;

  cout << s.climbStairs(10) << endl;

  return 0;
}

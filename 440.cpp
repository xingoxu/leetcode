#include <iostream>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

class Solution
{
  int calcSteps(int n, long n1, long n2)
  {
    int count = 0;
    while (n1 <= n)
    {
      if (n + 1 < n2)
      {
        count += n + 1 - n1;
      }
      else
      {
        count += n2 - n1;
      }
      n1 *= 10;
      n2 *= 10;
    }
    return count;
  }

public:
  int findKthNumber(int n, int k)
  {
    int now = 1;
    k -= 1;
    while (k > 0)
    {
      auto step = calcSteps(n, now, now + 1);
      if (step > k)
      {
        k -= 1;
        now *= 10;
      }
      else
      {
        k -= step;
        ++now;
      }
    }
    return now;
  }
};

int main()
{
  cout << Solution().findKthNumber(13, 2) << endl;
  return 0;
}
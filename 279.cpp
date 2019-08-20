// Runtime: 8 ms, faster than 90.35% of C++ online submissions for Perfect Squares.
// Memory Usage: 8.9 MB, less than 90.38% of C++ online submissions for Perfect Squares.

#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

unordered_map<int, int> cache;

class Solution
{
public:
  int numSquares(int n)
  {
    if (n == 0)
      return 0;
    auto it = cache.find(n);
    if (it != cache.end())
    {
      return it->second;
    }
    int sqrRoot = sqrt(n);
    int min = INT_MAX;
    for (int i = sqrRoot;; i--)
    {
      int sqr = pow(i, 2);
      if (sqr == 0 || n / sqr > min)
      {
        break;
      }
      int child = numSquares(n - sqr);
      if (child < min)
        min = child;
    }
    cache[n] = min + 1;
    return min + 1;
  }
};

int main()
{
  cout << Solution().numSquares(59) << endl;

  return 0;
}

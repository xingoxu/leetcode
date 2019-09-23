// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.
// Memory Usage: 8.7 MB, less than 6.67% of C++ online submissions for Integer Break.

#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, int> cache;

public:
  int integerBreak(int n)
  {
    if(n == 1)
      return 1;
    auto it = cache.find(n);
    if (it != cache.end())
    {
      return it->second;
    }
    int result = 0;
    for (int i = 1; i <= n / 2; ++i)
    {
      result = max(result, i * (n - i));
      result = max(result, i * integerBreak(n - i));
    }
    cache[n] = result;
    return result;
  }
};

int main()
{
  cout << Solution().integerBreak(10) << endl;
  return 0;
}
#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

unordered_map<int, int> cache;
class Solution
{
public:
  int fib(int N)
  {
    if(N == 0 || N == 1)
      return N;
    auto p = cache.find(N);
    if (p != cache.end())
      return p->second;
    return cache[N] = fib(N - 1) + fib(N - 2);
  }
};

int main()
{
  cout << Solution().fib(4) << endl;
  return 0;
}
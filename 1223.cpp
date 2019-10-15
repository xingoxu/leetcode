
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  // n times index
  long long cache[5001][16][6];
  long long mod = 1000000000 + 7;

public:
  int dieSimulator(int n, vector<int> &rollMax)
  {
    if (n == 0)
      return 0;
    memset(cache, -1, sizeof(cache));
    return dfs(0, 0, n, rollMax);
  }
  long long dfs(int index, int times, int n, vector<int> &rollMax)
  {
    if (n == 0)
      return 1;
    if(cache[n][times][index] != -1)
      return cache[n][times][index];
    long long ret = 0;
    for (int i = 0; i < 6; ++i)
    {
      if (i == index)
      {
        if (times < rollMax[i])
        {
          ret += dfs(i, times + 1, n - 1, rollMax);
        }
      }
      else
        ret += dfs(i, 1, n - 1, rollMax);
    }
    return cache[n][times][index] = ret % mod;
  }
};

int main()
{
  int n = 100;
  vector<int> rollMax{7, 5, 15, 5, 1, 7};
  cout << Solution().dieSimulator(n, rollMax) << endl;
  return 0;
}

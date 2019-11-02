
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  vector<vector<int>> dp;
  int getMoneyAmount(int lower, int higher)
  {
    if (higher <= lower)
      return 0;

    if (dp[lower][higher] != 0)
      return dp[lower][higher];

    int minCost = INT_MAX;
    for (int i = lower; i <= higher; ++i)
    {
      minCost = min(minCost, i + max(getMoneyAmount(lower, i - 1), getMoneyAmount(i + 1, higher)));
    }
    return dp[lower][higher] = minCost;
  }

public:
  int getMoneyAmount(int n)
  {
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
    return getMoneyAmount(1, n);
  }
};

int main()
{

  cout << Solution().getMoneyAmount(10) << endl;
  return 0;
}

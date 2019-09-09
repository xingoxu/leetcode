// Runtime: 360 ms, faster than 7.42% of C++ online submissions for Coin Change.
// Memory Usage: 59.1 MB, less than 15.69% of C++ online submissions for Coin Change.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, int> cache;
  int coinChange(vector<int> &coins, int coinPos, int amount)
  {
    if (amount == 0)
      return 0;
    auto it = cache.find(amount);
    if (it != cache.end())
    {
      return it->second;
    }
    int minCoins = INT_MAX;
    for (int i = coinPos; i >= 0; --i)
    {
      if(coins[i] <= amount) {
        auto result = coinChange(coins, coinPos, amount - coins[i]);
        if(result != -1){
          minCoins = min(minCoins, result + 1);
        }
      }
    }
    int result;
    if (minCoins == INT_MAX)
      result = -1;
    else
      result = minCoins;
    // cout << amount << ' ' << result << endl;
    cache[amount] = result;
    return result;
  }

public:
  int coinChange(vector<int> &coins, int amount)
  {
    sort(coins.begin(), coins.end());
    return coinChange(coins, coins.size() - 1, amount);
  }
};

int main()
{
  vector<int> coins{186, 419, 83, 408};
  int amount = 6249;
  cout << Solution().coinChange(coins, amount) << endl;
  return 0;
}
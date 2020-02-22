#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  unordered_map<int, unordered_map<int, int>> cache;
  int change(int amount, vector<int> &coins, int index)
  {
    int sum = 0;
    if (cache.count(amount) > 0 && cache[amount].count(index) > 0)
      return cache[amount][index];
    for (int i = index; i < coins.size(); ++i)
    {
      if (amount < coins[i])
        continue;
      if (amount == coins[i])
        sum += 1;
      else
        sum += change(amount - coins[i], coins, i);
    }
    return cache[amount][index] = sum;
  }

public:
  int change(int amount, vector<int> &coins)
  {
    if (amount == 0)
      return 1;
    if (coins.size() <= 0)
      return 0;
    sort(coins.begin(), coins.end(), greater<int>());

    return change(amount, coins, 0);
  }
};

int main()
{
  vector<int> coins{10};
  cout << Solution().change(10, coins) << endl;
  return 0;
}
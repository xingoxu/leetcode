#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int pricesSize = prices.size();
    if (pricesSize == 0)
      return 0;
    for (int i = 1; i < pricesSize; i++)
    {
      prices[i - 1] = prices[i] - prices[i - 1];
    }
    if (pricesSize - 1 == 1)
      return prices[0] > 0 ? prices[0] : 0;


    int result = 0;
    for (int i = 0; i < pricesSize - 2; i++)
    {
      int childResult = maxProfit(prices, 0, i) + maxProfit(prices, i + 1, pricesSize - 2);
      if (childResult > result)
      {
        result = childResult;
      }
    }
    return result;
  }
  int maxProfit(vector<int> &difference, int left, int right)
  {

    int result = 0;
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
      int &now = difference[i];
      sum += now;
      if (sum > result)
      {
        result = sum;
      }
      if (sum < 0)
      {
        sum = 0;
      }
    }
    return result;
  }
};

int main()
{
  vector<int> prices = {1, 2, 4};
  cout << Solution().maxProfit(prices)
       << endl;

  return 0;
}

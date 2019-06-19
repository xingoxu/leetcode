#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int pricesSize = prices.size();
      int sum = 0;
      for (int i = 1; i < pricesSize; i++)
      {
        int difference = prices[i] - prices[i - 1];
        if (difference > 0)
          sum += difference;
      }
      return sum;
    }
};

int main()
{
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << Solution().maxProfit(prices)
       << endl;

  return 0;
}

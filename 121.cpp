#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int result = 0;
      int pricesSize = prices.size();
      if (pricesSize == 0)
        return 0;
      vector<int> difference(pricesSize - 1);
      for (int i = 1; i < pricesSize; i++)
      {
        difference[i - 1] = prices[i] - prices[i - 1];
      }

      int sum = 0, left = 0, bestI;
      for (int i = 0; i < pricesSize - 1; i++)
      {
        int &now = difference[i];
        sum += now;
        if(sum > result){
          result = sum;
          bestI = i;
        }
        if (sum < 0)
        {
          sum = 0;
          left = i;
        }
      }
      return result;
    }
};

int main()
{
  vector<int> prices = {7,6,4,3,1};
  cout << Solution().maxProfit(prices)
       << endl;

  return 0;
}

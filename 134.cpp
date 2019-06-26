#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int length = gas.size();
    int sum = 0, startIndex = -1, singleSum = 0;
    for (int i = 0; i < length; i++)
    {
      int diff = gas[i] - cost[i];
      sum += diff;
      singleSum += diff;
      if (singleSum >= 0 && startIndex == -1)
        startIndex = i;
      else if (singleSum < 0)
      {
        startIndex = -1;
        singleSum = 0;
      }
    }
    if (sum < 0)
      startIndex = -1;
    return startIndex;
  }
};

int main()
{
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  cout << Solution().canCompleteCircuit(gas, cost) << endl;
  return 0;
}

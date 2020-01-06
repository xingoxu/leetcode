// Runtime: 60 ms, faster than 83.38% of C++ online submissions for Teemo Attacking.
// Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Teemo Attacking.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration)
  {
    if (timeSeries.size() <= 0)
      return 0;
    int ret = 0, start = -1;
    for (int i = 0; i < timeSeries.size(); ++i)
    {
      auto &timeNow = timeSeries[i];
      auto next = ((i == timeSeries.size() - 1) ? INT_MAX : timeSeries[i + 1]);

      if (timeNow + duration > next)
      {
        if(start == -1)
          start = timeNow;
      }
      else
      {
        if(start == -1)
          ret += duration;
        else
          ret += timeNow + duration - start;
        start = -1;
      }
    }

    return ret;
  }
};

int main()
{
  vector<int> timeSeries{1, 4};
  cout << Solution().findPoisonedDuration(timeSeries, 2) << endl;
  return 0;
}
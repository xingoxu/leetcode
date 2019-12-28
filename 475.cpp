// Runtime: 80 ms, faster than 72.78% of C++ online submissions for Heaters.
// Memory Usage: 11 MB, less than 100.00% of C++ online submissions for Heaters.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int findRadius(vector<int> &houses, vector<int> &heaters)
  {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int hIndex = heaters.size() - 1, houseIndex = houses.size() - 1;
    if (houseIndex <= -1 || hIndex <= -1)
      return 0;
    int ret = 0;
    while (houseIndex >= 0)
    {
      auto distance = abs(heaters[hIndex] - houses[houseIndex]);
      if (distance > ret)
      {
        if (hIndex > 0)
        {
          auto oneStepDistance = abs(heaters[hIndex - 1] - houses[houseIndex]);
          if (oneStepDistance <= ret)
            --hIndex;
          else if (oneStepDistance > distance)
          {
            ret = distance;
          }
          else
          {
            do {
              --hIndex;
              if (hIndex > 0)
                oneStepDistance = abs(heaters[hIndex - 1] - houses[houseIndex]);
              distance = abs(heaters[hIndex] - houses[houseIndex]);
            } while (hIndex > 0 && oneStepDistance < distance);
            ret = max(ret, distance);
          }
        }
        else
        {
          ret = distance;
        }
      }
      --houseIndex;
    }
    return ret;
  }
};

int main()
{

  vector<int> houses{264817709, 474833169, 817129560, 998097157};
  vector<int> heaters{197493099, 404280278, 505795335, 893351816};
  cout << Solution().findRadius(houses, heaters) << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int numberOfBoomerangs(vector<vector<int>> &points)
  {
    int count = 0;
    for (auto &start : points)
    {
      unordered_map<int, int> distance;
      for (auto &end : points)
        if (start != end)
        {
          int dis = pow(start[0] - end[0], 2) + pow(start[1] - end[1], 2);
          auto p = distance.find(dis);
          if (p == distance.end())
            distance[dis] = 1;
          else
          {
            count += p->second * 2;
            distance[dis] = p->second + 1;
          }
          // (1+n)n
        }
    }
    return count;
  }
};

int main()
{
  vector<vector<int>> points{{0, 0}, {1, 0}, {2, 0}};
  cout << Solution().numberOfBoomerangs(points) << endl;
  return 0;
}
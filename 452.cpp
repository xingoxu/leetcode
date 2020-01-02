// Runtime: 148 ms, faster than 41.46% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
// Memory Usage: 26.9 MB, less than 100.00% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    if(points.size() <= 0)
      return 0;
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    int start = points[0][0], end = points[0][1], count = 1;
    for (auto &p : points)
    {
      if(p[0] > end) {
        ++count;
        start = p[0];
        end = p[1];
        continue;
      }
      start = p[0];
      if (p[1] < end)
      {
        end = p[1];
      }
    }
    return count;
  }
};

int main()
{
  vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << Solution().findMinArrowShots(points) << endl;
  return 0;
}
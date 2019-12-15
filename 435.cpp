// Runtime: 8 ms, faster than 99.79% of C++ online submissions for Non-overlapping Intervals.
// Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Non-overlapping Intervals.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    int left = INT_MAX, ret = 0;
    for (int i = intervals.size() - 1; i >= 0; --i)
    {
      if (left < intervals[i][1])
        ++ret;
      else
        left = intervals[i][0];
    }
    return ret;
  }
};

int main()
{

  vector<vector<int>> intervals = {{1, 2}, {2, 3}};

  cout << Solution().eraseOverlapIntervals(intervals) << endl;
  return 0;
}
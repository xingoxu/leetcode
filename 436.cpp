// Runtime: 92 ms, faster than 94.39% of C++ online submissions for Find Right Interval.
// Memory Usage: 20.4 MB, less than 100.00% of C++ online submissions for Find Right Interval.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  int binSearch(vector<pair<int, int>> &position, int first)
  {
    int left = 0, right = position.size() - 1;
    while (left <= right)
    {
      int mid = (right + left) / 2;
      if (first > position[mid].first)
      {
        left = mid + 1;
      }
      else if (first < position[mid].first)
      {
        right = mid - 1;
      }
      else
      {
        return position[mid].second;
      }
    }
    if (left > right && left < position.size())
      return position[left].second;
    return -1;
  }

public:
  vector<int> findRightInterval(vector<vector<int>> &intervals)
  {
    vector<pair<int, int>> position(intervals.size());
    for (int i = intervals.size() - 1; i >= 0; --i)
      position[i] = {intervals[i][0], i};
    sort(position.begin(), position.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.first < b.first;
    });
    vector<int> result(intervals.size());
    for (int i = intervals.size() - 1; i >= 0; --i)
      result[i] = binSearch(position, intervals[i][1]);
    return result;
  }
};

int main()
{
  vector<vector<int>> input = {{4,5}, {2, 3}, {3, 4}};
  auto result = Solution().findRightInterval(input);
  for (auto &r : result)
    cout << r << ' ';
  cout << endl;
  return 0;
}

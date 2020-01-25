#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  vector<vector<int>> _rects;
  vector<int> pointsIndex;
  int totalPoints = 0;

public:
  Solution(vector<vector<int>> &rects)
  {
    _rects = rects;
    for (auto &rect : rects)
    {
      totalPoints += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
      pointsIndex.push_back(totalPoints);
    }
  }

  vector<int> pick()
  {
    int i = pointsIndex.size() - 1;
    int rd = rand() % totalPoints + 1;
    // why?
    for (; i < pointsIndex.size(); ++i)
      if (rd <= pointsIndex[i])
        break;
    auto &rect = _rects[i];
    int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
    int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
    return {x, y};
  }
};

int main()
{
  vector<vector<int>> rects = {{-2, -2, -1, -1}, {1, 0, 3, 0}};
  Solution *obj = new Solution(rects);
  auto param_1 = obj->pick();
  cout << param_1[0] << ' ' << param_1[1] << endl;
  param_1 = obj->pick();
  cout << param_1[0] << ' ' << param_1[1] << endl;
  return 0;
}
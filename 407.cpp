// Runtime: 36 ms, faster than 84.92% of C++ online submissions for Trapping Rain Water II.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Trapping Rain Water II.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

auto comp = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first > b.first;
};

class Solution
{
  int rowSize;
  int columnSize;

  void addPoint(int x, int y, vector<vector<int>> &heightMap, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> &pq)
  {
    if (x >= 0 && x < rowSize && y >= 0 && y < columnSize && heightMap[x][y] != -1)
    {
      pq.push({heightMap[x][y], {x, y}});
      heightMap[x][y] = -1;
    }
  }

public:
  int trapRainWater(vector<vector<int>> &heightMap)
  {
    if (heightMap.size() <= 0)
      return 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> wall(comp);

    rowSize = heightMap.size(), columnSize = heightMap[0].size();

    for (int i = rowSize - 1; i >= 0; --i)
    {
      wall.push({heightMap[i][0], {i, 0}});
      wall.push({heightMap[i][columnSize - 1], {i, columnSize - 1}});
      heightMap[i][0] = -1;
      heightMap[i][columnSize - 1] = -1;
    }
    for (int i = columnSize - 2; i > 0; --i)
    {
      wall.push({heightMap[rowSize - 1][i], {rowSize - 1, i}});
      wall.push({heightMap[0][i], {0, i}});
      heightMap[rowSize - 1][i] = -1;
      heightMap[0][i] = -1;
    }

    int lowestWall = INT_MIN, ret = 0;
    while (!wall.empty())
    {
      auto minNode = wall.top();
      wall.pop();
      lowestWall = max(lowestWall, minNode.first);
      if (lowestWall > minNode.first)
      {
        ret += lowestWall - minNode.first;
      }
      auto &pos = minNode.second;
      // cout << pos.first << ' ' << pos.second << ' ' << minNode.first << endl;

      addPoint(pos.first - 1, pos.second, heightMap, wall);
      addPoint(pos.first, pos.second - 1, heightMap, wall);
      addPoint(pos.first + 1, pos.second, heightMap, wall);
      addPoint(pos.first, pos.second + 1, heightMap, wall);
    }
    return ret;
  }
};

int main()
{
  vector<vector<int>> heightMap = {
      {1, 3, 3, 1, 3, 2},
      {3, 2, 1, 3, 2, 3},
      {3, 3, 3, 2, 3, 1}};
  auto result = Solution().trapRainWater(heightMap);
  cout << result << endl;
  return 0;
}
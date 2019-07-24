
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
  bool findCircle(vector<vector<int>> &map, int i, int start)
  {
    auto &level = map[i];
    for (int iterator = level.size() - 1; iterator >= 0; iterator--)
    {
      if (level[iterator] == start || findCircle(map, level[iterator], start))
        return true;
    }
    return false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<vector<int>> map(numCourses);

    for (auto &prerequisite : prerequisites)
    {
      map[prerequisite[0]].push_back(prerequisite[1]);
      if (findCircle(map, prerequisite[0], prerequisite[0]))
      {
        cout << prerequisite[0] << endl;
        return false;
      }
    }
    return true;
  }
};

int main()
{
  vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 1}, {3, 2}};

  cout << Solution().canFinish(4, pre)
       << endl;
  return 0;
}

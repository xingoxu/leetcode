// TODO find a faster solution
// Runtime: 12 ms, faster than 5.57% of C++ online submissions for Integer Replacement.
// Memory Usage: 11.7 MB, less than 14.29% of C++ online submissions for Integer Replacement.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int integerReplacement(int n)
  {
    // first input, second level
    queue<pair<int, int>> bfs;
    bfs.push({n, 0});
    while (!bfs.empty())
    {
      auto p = bfs.front();
      if (p.first == 1)
      {
        return p.second;
      }
      bfs.pop();
      if (p.first % 2 == 0)
        bfs.push({p.first / 2, p.second + 1});
      else
      {
        bfs.push({p.first - 1, p.second + 1});
        if (p.first < INT_MAX)
          bfs.push({p.first + 1, p.second + 1});
        else
          bfs.push({(int)(((long)p.first + 1) / 2), p.second + 2});
      }
    }
    return 0;
  }
};

int main()
{
  cout << Solution().integerReplacement(INT_MAX) << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gi = 0, si = 0, ret = 0;
    while (gi < g.size() && si < s.size())
    {
      if(s[si] >= g[gi])
        ++si, ++gi, ++ret;
      else
        ++si;
    }
    return ret;
  }
};

int main()
{
  vector<int> g{1, 2};
  vector<int> s{1, 2, 3};

  cout << Solution().findContentChildren(g, s) << endl;
  return 0;
}
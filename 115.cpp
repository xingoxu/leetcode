// Runtime: 104 ms, faster than 5.29% of C++ online submissions for Distinct Subsequences.
// Memory Usage: 218.6 MB, less than 5.04% of C++ online submissions for Distinct Subsequences.
// TODO: to see a nicer solution https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C%2B%2B-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
  unordered_map<string, int> cache;
  int numDistinct(string s, string t, int sLeft, int tLeft)
  {
    if (tLeft >= t.size())
    {
      return 1;
    }
    if (sLeft >= s.size())
    {
      return 0;
    }
    string key = to_string(sLeft) + "@" + to_string(tLeft);
    auto it = cache.find(key);
    if (it != cache.end())
    {
      return it->second;
    }
    int result = 0;
    for (int i = sLeft; i < s.size(); i++)
    {
      if (s[i] == t[tLeft])
      {
        result += numDistinct(s, t, i + 1, tLeft + 1);
      }
    }
    cache[key] = result;
    return result;
  }

public:
  int numDistinct(string s, string t)
  {
    return numDistinct(s, t, 0, 0);
  }
};

int main()
{
  cout << Solution().numDistinct("babgbag",
                                 "bag")
       << endl;

  return 0;
}

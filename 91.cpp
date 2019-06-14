// Runtime: 4 ms, faster than 88.36% of C++ online submissions for Decode Ways.
// Memory Usage: 17 MB, less than 6.15% of C++ online submissions for Decode Ways.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int numDecodings(string s)
  {
    vector<int> cache(s.size(), -1);
    return numDecodings(s, cache, 0);
  }
  int numDecodings(string s, vector<int> &cache, int left)
  {
    if (left >= s.size())
    {
      return 0;
    }
    if (s[left] == '0')
      return 0;
    if (left == s.size() - 1)
    {
      return 1;
    }
    if (cache[left] >= 0)
      return cache[left];

    int result = numDecodings(s, cache, left + 1);
    // cout << result << endl;
    bool hasSecondRoute = stoi(s.substr(left, 2)) <= 26;
    if (hasSecondRoute)
    {
      result += numDecodings(s, cache, left + 2);
      if (left + 2 >= s.size())
      {
        result += 1;
      }
    }
    cache[left] = result;
    return result;
  }
};

int main()
{
  Solution s;
  cout << s.numDecodings("2626") << endl;

  return 0;
}

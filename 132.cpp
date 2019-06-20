// Runtime: 432 ms, faster than 14.66% of C++ online submissions for Palindrome Partitioning II.
// Memory Usage: 274.5 MB, less than 6.82% of C++ online submissions for Palindrome Partitioning II.
// TODO: find a faster algorithm

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
  int minCut(string s)
  {
    return minCut(s, 0, s.size() - 1);
  }
  unordered_map<string, int> cache;
  int minCut(string s, int left, int right)
  {
    if (left >= right)
      return 0;
    string key = to_string(left) + "#" + to_string(right);
    const auto &it = cache.find(key);
    if (it != cache.end()) {
      return it->second;
    }
    int ret = INT_MAX;
    for (int i = right; i >= left; i--)
    {
      bool isPalindrome = true;
      for (int j = i, k = left; j >= k; j--, k++)
      {
        if (s[j] != s[k])
        {
          isPalindrome = false;
          break;
        }
      }
      if (isPalindrome)
      {
        if (i == right)
        {
          cache[key] = 0;
          return 0;
        }
        ret = min(ret, 1 + minCut(s, i + 1, right));
      }
    }
    cache[key] = ret;
    return ret;
  }
};

int main()
{
  cout << Solution().minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi")
       << endl;

  return 0;
}

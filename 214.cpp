// KMP
// Runtime: 4 ms, faster than 95.16% of C++ online submissions for Shortest Palindrome.
// Memory Usage: 10.2 MB, less than 36.15% of C++ online submissions for Shortest Palindrome.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
  vector<int> computePrefixFunction(string p)
  {
    int length = p.size() / 2 + 1;
    vector<int> result(length);
    result[0] = 0;
    int k = 0;
    for (int q = 1; q < length; ++q)
    {
      while (k > 0 && p[k] != p[q])
        k = result[k - 1];
      if (p[k] == p[q])
        ++k;
      result[q] = k;
    }
    return result;
  }
  int kmpMatcher(string s, string p)
  {
    int sLength = s.size();
    int pLength = p.size();
    auto prefixs = computePrefixFunction(p);
    int q = 0;
    for (int i = sLength - 1; i >= 0; i--)
    {
      while (q > 0 && p[q] != s[i])
        q = prefixs[q - 1];
      if (p[q] == s[i])
        ++q;
      if (q - 1 >= i)
      {
        return (q - 1 == i) ? (i * 2) : ((q - 1) * 2 - 1);
      }
      // q = prefixs[q];
    }
    return 0;
  }

public:
  string shortestPalindrome(string s)
  {
    auto index = kmpMatcher(s, s);
    stringstream ss;
    for (int i = s.size() - 1; i > index; i--)
    {
      ss << s[i];
    }
    ss << s;
    return ss.str();
  }
};

int main()
{
  cout << Solution().shortestPalindrome("aacecaaa")
       << endl;
  return 0;
}

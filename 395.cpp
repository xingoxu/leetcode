// nlog(n)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
// Memory Usage: 9 MB, less than 54.55% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  int longestSubstring(string &s, int k, int left, int right) {
    if (right < left)
      return 0;
    vector<int> dict(26);
    for (int i = left; i <= right;++i)
      ++dict[s[i] - 'a'];
    int breakpoint = left;
    while(breakpoint <= right && dict[s[breakpoint]-'a'] >= k)
      ++breakpoint;
    if(breakpoint > right)
      return right - left + 1;
    int leftSize = longestSubstring(s, k, left, breakpoint - 1);
    while(breakpoint <= right && dict[s[breakpoint]-'a'] < k)
      ++breakpoint;
    return max(leftSize, longestSubstring(s, k, breakpoint, right));
  }

public:
  int longestSubstring(string s, int k)
  {
    return longestSubstring(s, k, 0, s.size() - 1);
  }
};

int main()
{
  cout << Solution().longestSubstring("aaabb", 3) << endl;
  return 0;
}
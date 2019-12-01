// Runtime: 28 ms, faster than 95.22% of C++ online submissions for Find All Anagrams in a String.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Find All Anagrams in a String.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> dict(26);
    for (auto &x : p)
      ++dict[x - 'a'];
    int left = 0, right = 0;
    vector<int> ret;
    for (auto &x : s)
    {
      if (--dict[x - 'a'] < 0)
      {
        while (left <= right && dict[x - 'a'] < 0)
          ++dict[s[left++] - 'a'];
      }
      if (right - left + 1 == p.size())
      {
        ret.push_back(left);
      }
      ++right;
    }
    return ret;
  }
};

int main()
{
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  auto result = Solution().findAnagrams("abab", "ab");
  for (auto &x : result)
    cout << x << ' ';
  cout << endl;
  return 0;
}
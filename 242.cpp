// Runtime: 8 ms, faster than 97.79% of C++ online submissions for Valid Anagram.
// Memory Usage: 9.4 MB, less than 92.54% of C++ online submissions for Valid Anagram.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;
    vector<int> map(26);
    for (int i = 0; i < s.size(); ++i)
    {
      ++map[s[i] - 'a'];
    }
    for (int i = 0; i < t.size(); ++i)
    {
      if (--map[t[i] - 'a'] < 0)
        return false;
    }
    return true;
  }
};

int main()
{
  cout << Solution().isAnagram("rat", "car") << endl;
  return 0;
}
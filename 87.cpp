#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  string s1;
  string s2;
  std::hash<std::string> str_hash;
  unordered_map<size_t, bool> cache;

  // is s1[s1s, s1e] a scrambling of s2[s2s, s2e]?
  bool isScrambling(int s1s, int s1e, int s2s, int s2e)
  {
    string hashStr = s1.substr(s1s, s1e - s1s + 1) + "#" + s2.substr(s2s, s2e - s2s + 1);
    auto it = cache.find(str_hash(hashStr));
    if (it != cache.end())
    {
      return it->second;
    }
    bool ret = false;
    if ((s1e - s1s) != (s2e - s2s))
    {
      ret = false;
    }
    else if (s1e < s1s || s2e < s2s)
    {
      ret = false;
    }
    else if (s1.substr(s1s, (s1e - s1s + 1)) == s2.substr(s2s, (s2e - s2s + 1)))
    {
      ret = true;
    } //identity scrambling
    else if (s1e == s1s)
    {
      ret = s1[s1s] == s2[s2s];
    }
    else
    {
      for (int k = 0; k < (s1e - s1s); k++)
      {
        if (isScrambling(s1s, s1s + k, s2s, s2s + k) && isScrambling(s1s + k + 1, s1e, s2s + k + 1, s2e))
        {
          ret = true;
          break;
        }
        if (isScrambling(s1s, s1s + k, (s2e - k), s2e) && isScrambling(s1s + k + 1, s1e, s2s, s2e - k - 1))
        {
          ret = true;
          break;
        }
      }
    }
    cache[str_hash(hashStr)] = ret;
    return ret;
  }

public:
  bool isScramble(string is1, string is2)
  {
    if (is1.length() == 0 || is2.length() == 0)
      return false;
    s1 = is1;
    s2 = is2;
    return isScrambling(0, s1.length() - 1, 0, s2.length() - 1);
  }
};
int main()
{
  vector<vector<char>> x = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  cout << Solution().isScramble("abb", "bab") << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<char, char> map;
  unordered_map<char, char> reverse_map;

public:
  bool isIsomorphic(string s, string t)
  {
    for (int i = s.size() - 1; i >= 0; i--)
    {
      auto cursor = map.find(s[i]);
      auto reverse_cursor = reverse_map.find(t[i]);
      if (cursor != map.end())
      {
        if (cursor->second != t[i])
          return false;
      }
      else
      {
        map[s[i]] = t[i];
      }
      if (reverse_cursor != reverse_map.end())
      {
        if (reverse_cursor->second != s[i])
          return false;
      }
      else
      {
        reverse_map[t[i]] = s[i];
      }
    }
    return true;
  }
};

int main()
{
  cout << Solution().isIsomorphic("paper", "title")
       << endl;
  return 0;
}

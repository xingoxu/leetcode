// Runtime: 96 ms, faster than 35.31% of C++ online submissions for Longest Word in Dictionary through Deleting.
// Memory Usage: 16.4 MB, less than 46.15% of C++ online submissions for Longest Word in Dictionary through Deleting.
// TODO: Is there a faster solution?

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  string findLongestWord(string s, vector<string> &d)
  {
    int index = 0;
    vector<int> pos(d.size(), 0);
    while (index < s.size())
    {
      auto chCurrent = s[index];
      for (int i = 0; i < d.size();++i) {
        if(d[i][pos[i]] == chCurrent)
          ++pos[i];
      }
      ++index;
    }

    vector<string> result;
    for (int i = 0; i < d.size(); ++i)
    {
      if (d[i].size() == pos[i])
        result.push_back(d[i]);
    }
    sort(result.begin(), result.end(), [](string &a, string &b) {
      if(a.size() != b.size())
        return a.size() > b.size();
      return a < b;
    });

    return result.size() > 0 ? result[0] : "";
  }
};

int main()
{
  vector<string> dict{"a", "b", "c"};
  cout << Solution().findLongestWord("abpcplea", dict);
  return 0;
}
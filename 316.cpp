
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
  string result;
  string origin;

public:
  string removeDuplicateLetters(string s)
  {
    origin = s;
    result = "";
    vector<int> cnt(26, 0);

    for (auto ch : s)
      ++cnt[ch - 'a'];

    dfs(result, cnt, 0, 0);
    return result;
  }
  void dfs(string current, vector<int> cnt, int stMap, int pos)
  {
    if (pos >= origin.size())
    {
      if (current.size() > result.size())
        result = current;
      if (current.size() == result.size() && comp(current, result))
      {
        result = current;
      }
      return;
    }
    auto nowCh = origin[pos];
    if (current.size() > 0)
    {
      auto lastCh = current[current.size() - 1];
      if (lastCh > nowCh && cnt[lastCh - 'a'] > 0)
        return;
    }
    cnt[nowCh - 'a']--;

    dfs(current, cnt, stMap, pos + 1);
    int p = (1 << (nowCh - 'a'));
    if ((stMap & p) == 0)
    {
      dfs(current + nowCh, cnt, stMap | p, pos + 1);
    }
  }
  bool comp(string current, string result)
  {
    for (int i = 0; i < current.size(); ++i)
    {
      if (result[i] > current[i])
        return true;
      else if (result[i] < current[i])
        return false;
    }
    return false;
  }
};

int main()
{
  cout << Solution().removeDuplicateLetters("mitnlruhznjfyzmtmfnstsxwktxlboxutbic") << endl;
  return 0;
}
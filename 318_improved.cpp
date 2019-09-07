// Runtime: 44 ms, faster than 92.19% of C++ online submissions for Maximum Product of Word Lengths.
// Memory Usage: 12.9 MB, less than 80.00% of C++ online submissions for Maximum Product of Word Lengths.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    vector<int> preCompileRepeat(words.size(), 0);
    for (int i = words.size() - 1; i >= 0; --i)
    {
      for(auto c: words[i]) {
        preCompileRepeat[i] |= (1 << (c - 'a'));
      }
    }
    int ret = 0;
    for (int i = words.size() - 1; i >= 0; --i)
    {
      int wordsISize = words[i].size();
      for (int j = i; j >= 0; --j)
      {
        bool hasRepeat = (preCompileRepeat[j] & preCompileRepeat[i]) != 0;
        if (hasRepeat)
          continue;
        ret = max(ret, (int)words[j].size() * wordsISize);
      }
    }
    return ret;
  }
};

int main()
{
  vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  cout << Solution().maxProduct(words) << endl;
  return 0;
}
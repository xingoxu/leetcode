// Runtime: 116 ms, faster than 25.96% of C++ online submissions for Maximum Product of Word Lengths.
// Memory Usage: 13 MB, less than 80.00% of C++ online submissions for Maximum Product of Word Lengths.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    bool repeat[26];
    memset(repeat, false, sizeof(repeat));
    vector<int> maxArray(words.size(), 0);
    int ret = 0;
    for (int i = words.size() - 1; i >= 0; --i)
    {
      int wordISize = words[i].size();
      for (int j = wordISize - 1; j >= 0; --j)
      {
        repeat[words[i][j] - 'a'] = true;
      }

      for (int j = i; j >= 0; --j)
      {
        bool hasRepeat = false;
        int wordJSize = words[j].size();
        for (int k = wordJSize - 1; k >= 0; --k)
        {
          if (repeat[words[j][k] - 'a'])
          {
            hasRepeat = true;
            break;
          }
        }
        if (hasRepeat)
          continue;
        maxArray[i] = max(maxArray[i], wordJSize * wordISize);
        maxArray[j] = max(maxArray[j], wordJSize * wordISize);
      }
      ret = max(ret, maxArray[i]);
      memset(repeat, false, sizeof(repeat));
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
// Runtime: 68 ms, faster than 5.49% of C++ online submissions for Unique Substrings in Wraparound String.
// Memory Usage: 10.2 MB, less than 14.29% of C++ online submissions for Unique Substrings in Wraparound String.
// TODO: find a faster solution

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<char, int> cache;

public:
  int findSubstringInWraproundString(string p)
  {
    int sum = 0, last = 0;
    for (int i = 0; i < p.size(); ++i)
    {
      auto &ch = p[i];
      auto lastCh = i > 0 ? p[i - 1] : 'A';
      if (ch - lastCh == 1 || (lastCh == 'z' && ch == 'a'))
      {
        ++last;
        char _lastCh = (ch - last + 1 >= 'a') ? ch - last + 1 : ch - last + 1 + 26;
        if (cache[_lastCh] >= last)
          continue;
        for (int j = last-1; j >=0; --j)
        {
          char _lastCh = ch - j < 'a' ? ch - j + 26 : ch - j;
          // cout << _lastCh << endl;
          if (j + 1 > cache[_lastCh])
          {
            sum += 1;
            cache[_lastCh] = j + 1;
          } else {
            break;
          }
        }
      } else {
        last = 1;
        if (cache[ch] >= 1)
          continue;
        cache[ch] = max(1, cache[ch]);
        sum += 1;
      }
    }
    return sum;
  }
};

int main()
{
  cout << Solution().findSubstringInWraproundString("cac") << endl;
  return 0;
}
// Runtime: 660 ms, faster than 5.42% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 12.7 MB, less than 85.71% of C++ online submissions for Repeated Substring Pattern.

// TODO find a faster solution

#include <iostream>
using namespace std;

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    string tp = "";
    int vIndex = 0, cIndex = 0;
    for (int i = 0; i < s.size(); ++i)
    {
      auto &ch = s[i];
      if (vIndex >= tp.size())
        vIndex = 0;
      if (tp != "" && tp[vIndex] == ch)
        ++vIndex;
      else
      {
        vIndex = 0;
        tp += s[cIndex++];
        i = cIndex - 1;
      }
    }

    return vIndex == tp.size();
  }
};

int main()
{
  cout << Solution().repeatedSubstringPattern("abacababacab") << endl;
  return 0;
}
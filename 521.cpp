#include <iostream>
#include <unordered_set>
#include <math.h>
using namespace std;

class Solution
{
public:
  int findLUSlength(string a, string b)
  {
    if (a.size() != b.size())
      return max(a.size(), b.size());
    for (int i = a.size() - 1; i >= 0; --i)
    {
      if (a[i] != b[i])
      {
        return max((int)a.size() - i - 1, i + 1);
      }
    }
    return -1;
  }
};

int main()
{
  cout << Solution().findLUSlength("aba", "cdc") << endl;
  return 0;
}
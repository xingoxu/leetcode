#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution
{
public:
  bool detectCapitalUse(string word)
  {
    bool capital = true;
    int count = 0;
    for (auto &ch : word)
    {
      if (count > 0)
      {
        if (!capital && ch >= 'A' && ch <= 'Z')
          return false;
        if (capital && count == 1)
          capital = ch >= 'A' && ch <= 'Z';
        else if (capital && ch >= 'a' && ch <= 'z')
          return false;
      }
      else
        capital = ch >= 'A' && ch <= 'Z';
      ++count;
    }
    return true;
  }
};

int main()
{
  cout << Solution().detectCapitalUse("USA") << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    vector<int> hash(26, 0);
    for (auto &ch : s)
    {
      ++hash[ch - 'a'];
    }
    for (auto &ch : t)
    {
      if (--hash[ch - 'a'] < 0)
        return ch;
    }
    return 0;
  }
};

int main()
{
  cout << Solution().findTheDifference("abcd", "abcde") << endl;
  return 0;
}

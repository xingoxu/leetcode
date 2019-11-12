#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int longestPalindrome(string s)
  {
    unordered_map<char, int> count;
    for (auto &ch : s)
      ++count[ch];
    int ret = 0;
    bool hasOdd = false;
    for (auto &pair: count)
    {
      if (pair.second <= 0)
        continue;
      if(pair.second % 2 == 1) {
        hasOdd = true;
        ret += pair.second - 1;
      } else
        ret += pair.second;
    }
    return hasOdd ? ret + 1 : ret;
  }
};

int main()
{
  cout << Solution().longestPalindrome("AAAAA") << endl;
  return 0;
}
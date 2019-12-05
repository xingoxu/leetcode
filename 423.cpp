#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  string originalDigits(string s)
  {
    vector<vector<string>> dict = {
        {"z", "zero", "0"},
        {"w", "two", "2"},
        {"u", "four", "4"},
        {"x", "six", "6"},
        {"g", "eight", "8"},
        {"o", "one", "1"},
        {"t", "three", "3"},
        {"f", "five", "5"},
        {"s", "seven", "7"},
        {"i", "nine", "9"},
    };
    vector<int> count(26, 0);
    string ret;
    for (auto &x : s)
      ++count[x - 'a'];
    for (auto &kv : dict)
    {
      int c = count[kv[0][0] - 'a'];
      if (c == 0)
        continue;
      for (int i = 0; i < c; ++i)
        ret += kv[2];
      for (auto &ch : kv[1])
        count[ch - 'a'] -= c;
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
};

int main()
{
  cout << Solution().originalDigits("fviefuro") << endl;
  return 0;
}
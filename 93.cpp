// Runtime: 4 ms, faster than 88.55% of C++ online submissions for Restore IP Addresses.
// Memory Usage: 8.8 MB, less than 32.48% of C++ online submissions for Restore IP Addresses.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<string> restoreIpAddresses(string s)
  {
    return restoreIpAddresses(s, 0, 1);
  }
  vector<string> restoreIpAddresses(string s, int left, int level)
  {
    if (left >= s.size())
      return {};
    if (level == 4)
    {
      if (s.size() - left > 3)
        return {};
      else
      {
        vector<string> result;
        if ((s.size() - left > 1 && s[left] != '0' && stoi(s.substr(left)) <= 255) || (s.size() - left == 1))
          result.push_back("." + s.substr(left));
        return result;
      }
    }

    vector<string> result;
    for (int i = 1; i <= 3; i++)
    {
      if (i > 1 && s[left] == '0')
        continue;
      string numNowS = s.substr(left, i);
      if (stoi(numNowS) > 255)
        continue;

      const vector<string> &childResult = restoreIpAddresses(s, left + i, level + 1);
      if (childResult.size() <= 0)
      {
        continue;
      }

      string prefix = numNowS;
      if (level != 1)
        prefix = "." + prefix;

      for (int j = childResult.size() - 1; j >= 0; j--)
      {
        result.push_back(prefix + childResult[j]);
      }
    }
    return result;
  }
};

int main()
{
  const vector<string> &result = Solution().restoreIpAddresses("0000");

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }

  return 0;
}
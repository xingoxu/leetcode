// Runtime: 92 ms, faster than 13.68% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 155.4 MB, less than 5.03% of C++ online submissions for Palindrome Partitioning.
// TODO: find a faster algorithm

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
  vector<vector<string>> partition(string s) {
    return partition(s, 0, s.size() - 1);
  }
  // unordered_map<string, vector<vector<string>>> cache;
  vector<vector<string>> partition(string s, int left, int right)
  {
    if (left == right) {
      return {{s.substr(left, 1)}};
    }
    // string key = to_string(left) + "#" + to_string(right);
    // const auto &it = cache.find(key);
    // if (it != cache.end()) {
    //   return it->second;
    // }
    vector<vector<string>> result;
    for (int i = right; i >= left; i--)
    {
      bool isPalindrome = true;
      for (int j = i, k = left; j >= k; j--, k++)
      {
        if (s[j] != s[k])
        {
          isPalindrome = false;
          break;
        }
      }
      if (isPalindrome)
      {
        const string now = s.substr(left, i - left + 1);
        if (i == right)
        {
          result.push_back({now});
        }
        const auto &childResults = partition(s, i + 1, right);
        for (int i = 0; i < childResults.size(); i++)
        {
          auto childResult = childResults[i];
          childResult.insert(childResult.begin(), now);
          result.push_back(childResult);
        }
      }
    }
    // cache[key] = ret;
    return result;
  }
};

int main()
{
  const auto &result = Solution().partition("aab");
  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size();j++) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}

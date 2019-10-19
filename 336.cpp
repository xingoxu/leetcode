#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<string, int> dict;
  bool isPalindrome(string x)
  {
    int left = 0, right = x.size() - 1;
    while (left < right)
    {
      if (x[left] != x[right])
        return false;
      ++left, --right;
    }
    return true;
  }

public:
  vector<vector<int>> palindromePairs(vector<string> &words)
  {
    for (int i = words.size() - 1; i >= 0; --i)
    {
      auto word = words[i];
      reverse(word.begin(), word.end());
      dict[word] = i;
    }

    vector<vector<int>> ret;

    for (int i = 0; i < words.size(); ++i)
    {
      for (int j = 0; j < words[i].size(); ++j)
      {
        auto left = words[i].substr(0, j);
        auto right = words[i].substr(j, words[i].size() - j);

        if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
        {
          ret.push_back({i, dict[left]});
        }
        if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
        {
          ret.push_back({dict[right], i});
        }
      }
    }

    if (dict.find("") != dict.end())
    {
      for (int i = words.size() - 1; i >= 0; --i)
      {
        if (i == dict[""])
          continue;
        if (isPalindrome(words[i]))
          ret.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self)
      }
    }

    return ret;
  }
};

int main()
{
  vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
  auto result = Solution().palindromePairs(words);
  for (auto pair : result)
  {
    for (auto x : pair)
    {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}
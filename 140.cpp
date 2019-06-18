// Your runtime beats 90.87 % of cpp submissions.
// Your memory usage beats 61.26 % of cpp submissions.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, vector<string>> cache;
  vector<string> wordBreak(string s, vector<string> &wordDict, int sLeft)
  {
    auto iterator = cache.find(sLeft);
    if (iterator != cache.end())
      return iterator->second;

    vector<string> result;
    for (int i = 0; i < wordDict.size(); i++)
    {
      string &word = wordDict[i];
      int wordSize = word.size();
      if (sLeft + wordSize > s.size())
        break;
      bool wordResult = true;
      for (int j = 0; j < wordSize; j++)
      {
        if (s[sLeft + j] != word[j])
        {
          wordResult = false;
          break;
        }
      }
      if (wordResult)
      {
        if (sLeft + wordSize == s.size()) {
          result.push_back(word);
          break;
        }
        else
        {
          const vector<string> &childResult = wordBreak(s, wordDict, sLeft + wordSize);
          for (int i = 0; i < childResult.size();i++) {
            result.push_back(word + " " + childResult[i]);
          }
        }
      }
    }
    cache[sLeft] = result;
    return result;
  }

public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    cache.clear();
    sort(wordDict.begin(), wordDict.end(), [](string a, string b) {
      return a.size() < b.size();
    });

    return wordBreak(s, wordDict, 0);
  }
};

int main()
{
  string s = "pineapplepenapple";
  vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};

  const vector<string> &result = Solution().wordBreak(s, wordDict);

  for (int i = 0; i < result.size();i++) {
    cout << result[i] << endl;
  }

  return 0;
}
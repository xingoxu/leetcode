// Runtime: 4 ms, faster than 97.95% of C++ online submissions for Word Break.
// Memory Usage: 10.5 MB, less than 78.37% of C++ online submissions for Word Break.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, int> cache;
  bool wordBreak(string s, vector<string> &wordDict, int sLeft)
  {
    if (sLeft >= s.size())
      return true;
    
    if(cache[sLeft] > 0)
      return cache[sLeft] == 1;

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
      if (wordResult && wordBreak(s, wordDict, sLeft + wordSize))
      {
        cache[sLeft] = 1;
        return true;
      }
    }
    cache[sLeft] = 2;
    return false;
  }

public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    cache.clear();
    sort(wordDict.begin(), wordDict.end(), [](string a, string b) {
      return a.size() < b.size();
    });
    
    return wordBreak(s, wordDict, 0);
  }
};

int main()
{
  string s = "bccdbacdbdacddabbaaaadababadad";
  vector<string> wordDict = {"cbc", "bcda", "adb", "ddca", "bad", "bbb", "dad", "dac", "ba", "aa", "bd", "abab", "bb", "dbda", "cb", "caccc", "d", "dd", "aadb", "cc", "b", "bcc", "bcd", "cd", "cbca", "bbd", "ddd", "dabb", "ab", "acd", "a", "bbcc", "cdcbd", "cada", "dbca", "ac", "abacd", "cba", "cdb", "dbac", "aada", "cdcda", "cdc", "dbc", "dbcb", "bdb", "ddbdd", "cadaa", "ddbc", "babb"};

  cout << Solution().wordBreak(s, wordDict) << endl;
  return 0;
}
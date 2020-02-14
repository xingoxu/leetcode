#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  unordered_map<int, unordered_map<int, int>> cache;
  // TLE
  int _longestPalindromeSubseq(string word, int left, int right)
  {
    // cout << left << ' ' << right << endl;
    // cout << word[left] << ' ' << word[right] << endl;
    if (left == right)
      return 1;
    if (left + 1 == right)
    {
      if (word[left] == word[right])
        return 2;
      else
        return 1;
    }
    if (cache.count(left) > 0 && cache[left].count(right) > 0)
    {
      // cout << left << ' ' << right << endl;
      return cache[left][right];
    }
    if (word[left] == word[right])
      return cache[left][right] = _longestPalindromeSubseq(word, left + 1, right - 1) + 2;
    else
      return cache[left][right] = max(_longestPalindromeSubseq(word, left, right - 1), _longestPalindromeSubseq(word, left + 1, right));
  }

public:
  // Your runtime beats 76.35 % of cpp submissions.
  int _longestPalindromeSubseq(string word)
  {
    // return _longestPalindromeSubseq(word, 0, word.size() - 1);
    // dp[i][j] = word[i] == word[j] ? dp[i+1][j-1]+2 : max(dp[i+1][j], dp[i][j-1])
    vector<vector<int>> dp(word.size(), vector<int>(word.size()));

    for (int i = word.size() - 1; i >= 0; --i)
    {
      for (int j = i; j < word.size(); ++j)
      {
        if (i == j)
        {
          dp[i][j] = 1;
          continue;
        }
        else if (i + 1 == j)
        {
          dp[i][j] = word[i] == word[j] ? 2 : 1;
          continue;
        }
        dp[i][j] = word[i] == word[j] ? dp[i + 1][j - 1] + 2 : max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
    return dp[0][word.size() - 1];
  }

  // Runtime: 68 ms, faster than 69.21% of C++ online submissions for Longest Palindromic Subsequence.
  // Memory Usage: 69 MB, less than 100.00% of C++ online submissions for Longest Palindromic Subsequence.
  int longestPalindromeSubseq(string word)
  {
    vector<int> dp(word.size(), 1);

    for (int i = word.size() - 1; i >= 0; --i)
    {
      vector<int> next(word.size(), 1);
      for (int j = i + 1; j < word.size(); ++j)
      {
        if (i + 1 == j)
        {
          next[j] = word[i] == word[j] ? 2 : 1;
          continue;
        }
        next[j] = word[i] == word[j] ? dp[j - 1] + 2 : max(dp[j], next[j - 1]);
      }
      dp = next;
    }
    return dp[word.size() - 1];
  }
};

int main()
{
  cout << Solution().longestPalindromeSubseq("bbbab") << endl;
  return 0;
}
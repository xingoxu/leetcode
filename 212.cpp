// Runtime: 44 ms, faster than 89.04% of C++ online submissions for Word Search II.
// Memory Usage: 37.4 MB, less than 48.89% of C++ online submissions for Word Search II.

#include <iostream>
#include <vector>
using namespace std;

struct Trie
{
  vector<Trie *> next = vector<Trie *>(26, NULL);
  string word = "";
};

class Solution
{
  void dfs(vector<vector<char>> &board, Trie* cursor, int x, int y, vector<string> &result)
  {
    auto originCh = board[x][y];
    if (board[x][y] == '*' || cursor == NULL || cursor->next[originCh - 'a'] == NULL)
      return;
    cursor = cursor->next[originCh - 'a'];
    if (cursor->word != "")
    {
      result.push_back(cursor->word);
      cursor->word = "";
    }
    board[x][y] = '*';

    if (x + 1 < board.size())
    {
      dfs(board, cursor, x + 1, y, result);
    }
    if (x - 1 >= 0)
    {
      dfs(board, cursor, x - 1, y, result);
    }
    if (y + 1 < board[x].size())
    {
      dfs(board, cursor, x, y + 1, result);
    }
    if (y - 1 >= 0)
    {
      dfs(board, cursor, x, y - 1, result);
    }
    board[x][y] = originCh;
  }

  Trie *compileWords(vector<string> &words)
  {
    auto root = new Trie();
    for (auto &word : words)
    {
      auto p = root;
      for (auto ch : word)
      {
        int nextIndex = ch - 'a';
        if (!p->next[nextIndex])
        {
          p->next[nextIndex] = new Trie();
        }
        p = p->next[nextIndex];
      }
      p->word = word;
    }
    return root;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
  {
    vector<string> ret;
    auto root = compileWords(words);
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[i].size(); j++)
      {
        dfs(board, root, i, j, ret);
      }
    }
    return ret;
  }
};

int main()
{
  Solution s;
  vector<vector<char>> x = {
      {'o', 'a', 'a', 'n'},
      {'e', 't', 'a', 'e'},
      {'i', 'h', 'k', 'r'},
      {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};
  auto result = s.findWords(x, words);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }

  return 0;
}

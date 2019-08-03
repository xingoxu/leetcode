#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  bool exist(vector<vector<char>> &board, string word, vector<vector<int>> &route, int x, int y, int wordPointer)
  {
    if (board[x][y] != word[wordPointer])
      return false;
    if (wordPointer >= word.size() - 1)
      return true;
    route[x][y] = 1;

    bool result = false;
    if (x + 1 < board.size() && route[x + 1][y] != 1)
    {
      result = result || exist(board, word, route, x + 1, y, wordPointer + 1);
    }
    if (x - 1 >= 0 && route[x - 1][y] != 1)
    {
      result = result || exist(board, word, route, x - 1, y, wordPointer + 1);
    }
    if (y + 1 < board[x].size() && route[x][y + 1] != 1)
    {
      result = result || exist(board, word, route, x, y + 1, wordPointer + 1);
    }
    if (y - 1 >= 0 && route[x][y - 1] != 1)
    {
      result = result || exist(board, word, route, x, y - 1, wordPointer + 1);
    }
    route[x][y] = 0;
    return result;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
  {
    vector<vector<pair<int, int>>> startCache(26);
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[i].size(); j++)
      {
        auto currentChar = board[i][j];
        startCache[(currentChar - 'a')].push_back({i, j});
      }
    }
    vector<vector<int>> route(board.size());
    for (int i = 0; i < route.size(); i++)
    {
      route[i].resize(board[i].size());
    }
    vector<string> ret;
    for (int i = 0; i < words.size(); i++)
    {
      auto currentWord = words[i];
      if (currentWord == "")
      {
        ret.push_back(currentWord);
        continue;
      }
      auto &start = startCache[(currentWord[0] - 'a')];
      for (int j = 0; j < start.size(); j++)
      {
        auto [x, y] = start[j];
        if (exist(board, currentWord, route, x, y, 0))
        {
          ret.push_back(currentWord);
          break;
        }
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

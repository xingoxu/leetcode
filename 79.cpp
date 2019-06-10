#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool exist(vector<vector<char>> &board, string word)
  {
    if (word == "")
      return true;
    vector<vector<int>> route(board.size());
    for (int i = 0; i < route.size(); i++)
    {
      route[i].resize(board[i].size());
    }
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[i].size(); j++)
      {
        if (board[i][j] == word[0] && exist(board, word, route, i, j, 0))
        {
          return true;
        }
      }
    }
    return false;
  }
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
};

int main()
{
  Solution s;
  vector<vector<char>> x = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};

  cout << s.exist(x, "ABCCED") << endl;

  return 0;
}

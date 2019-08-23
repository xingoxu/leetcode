// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 8.7 MB, less than 78.57% of C++ online submissions for Game of Life.

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  void gameOfLife(vector<vector<int>> &board)
  {
    if (board.size() <= 0 || board[0].size() <= 0)
      return;
    gameOfLife(board, 0, 0);
  }
  void gameOfLife(vector<vector<int>> &board, int x, int y)
  {
    int sum = 0;
    if (x - 1 >= 0)
      sum += board[x - 1][y];
    if (y - 1 >= 0)
      sum += board[x][y - 1];
    if (x - 1 >= 0 && y - 1 >= 0)
      sum += board[x - 1][y - 1];
    if (x + 1 < board.size())
      sum += board[x + 1][y];
    if (y + 1 < board[x].size())
      sum += board[x][y + 1];
    if (x + 1 < board.size() && y + 1 < board[x].size())
      sum += board[x + 1][y + 1];
    if (x - 1 >= 0 && y + 1 < board[x].size())
      sum += board[x - 1][y + 1];
    if (x + 1 < board.size() && y - 1 >= 0)
      sum += board[x + 1][y - 1];

    if (board[x][y] == 1)
    {
      if (sum < 2)
      {
        sum = 0;
      }
      else if (sum > 3)
      {
        sum = 0;
      }
      else
      {
        sum = 1;
      }
    }
    else
    {
      if (sum == 3)
      {
        sum = 1;
      }
      else
      {
        sum = 0;
      }
    }
    if (y + 1 < board[x].size())
    {
      gameOfLife(board, x, y + 1);
    }
    else if (x + 1 < board.size())
    {
      gameOfLife(board, x + 1, 0);
    }

    board[x][y] = sum;
  }
};

int main()
{
  vector<vector<int>> board{
      {0, 1, 0},
      {0, 0, 1},
      {1, 1, 1},
      {0, 0, 0}};
  Solution().gameOfLife(board);
  for (int i = 0; i < board.size(); ++i)
  {
    for (int j = 0; j < board[i].size(); ++j)
    {
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
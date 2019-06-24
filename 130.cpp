#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  void flipONearBoarder(vector<vector<char>> &board, int i, int j)
  {
    board[i][j] = 'F';
    int rowSize = board.size();
    int columns = board[0].size();

    if (i + 1 <= rowSize - 1 && board[i + 1][j] == 'O')
      flipONearBoarder(board, i + 1, j);
    if (j + 1 <= columns - 1 && board[i][j + 1] == 'O')
      flipONearBoarder(board, i, j + 1);
    if (i - 1 >= 0 && board[i - 1][j] == 'O')
      flipONearBoarder(board, i - 1, j);
    if (j - 1 >= 0 && board[i][j - 1] == 'O')
      flipONearBoarder(board, i, j - 1);
  }

public:
  void solve(vector<vector<char>> &board)
  {
    int rowSize = board.size();
    if (rowSize <= 0)
      return;
    for (int i = 0; i <= rowSize - 1; i++)
    {
      int columnSize = board[i].size();
      if (board[i][0] == 'O')
        flipONearBoarder(board, i, 0);
      if (board[i][columnSize-1] == 'O')
        flipONearBoarder(board, i, columnSize - 1);
    }
    int columnSize = board[0].size();
    for (int i = 1; i <= columnSize - 2; i++)
    {
      int columnSize = board[i].size();
      if (board[0][i] == 'O')
        flipONearBoarder(board, 0, i);
      if (board[rowSize - 1][i] == 'O')
        flipONearBoarder(board, rowSize - 1, i);
    }

    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[i].size(); j++)
      {
        if(board[i][j] == 'O')
          board[i][j] = 'X';
        if(board[i][j] == 'F')
          board[i][j] = 'O';
      }
    }
  }
};

int main()
{
  vector<vector<char>> board{
    {'O'}

  };
  Solution().solve(board);
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      cout
          << board[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}

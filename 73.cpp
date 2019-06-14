#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int rows = matrix.size();
    if (rows == 0)
      return;
    int columns = matrix[0].size();
    if (columns == 0)
      return;
    bool clearFirstRow = false, clearFirstColumn = false;
    for (int i = 0; i < columns; i++)
    {
      if (matrix[0][i] == 0)
      {
        clearFirstRow = true;
        break;
      }
    }
    for (int i = 0; i < rows; i++)
    {
      if (matrix[i][0] == 0)
      {
        clearFirstColumn = true;
        break;
      }
    }
    for (int i = 1; i < rows; i++)
    {
      for (int j = 1; j < columns; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < rows; i++)
    {
      if (matrix[i][0] == 0)
      {
        for (int j = 0; j < columns; j++)
        {
          matrix[i][j] = 0;
        }
      }
      if (clearFirstColumn)
        matrix[i][0] = 0;
    }
    for (int j = 1; j < columns; j++)
    {
      if (matrix[0][j] == 0)
      {
        for (int i = 0; i < rows; i++)
        {
          matrix[i][j] = 0;
        }
      }
      if (clearFirstRow)
        matrix[0][j] = 0;
    }
    if (clearFirstRow || clearFirstColumn)
      matrix[0][0] = 0;
  }
};

int main()
{
  Solution s;

  vector<vector<int>> input = {
      {0, 1, 2, 0},
      {3, 4, 5, 2},
      {1, 3, 1, 5}};

  s.setZeroes(input);

  for (int i = 0; i < input.size(); i++)
  {
    for (int j = 0; j < input[i].size(); j++)
    {
      cout << input[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}

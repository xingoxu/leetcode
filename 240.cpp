// Runtime: 128 ms, faster than 26.16% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 13 MB, less than 53.33% of C++ online submissions for Search a 2D Matrix II.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{

public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    if (matrix.size() == 0)
      return false;
    int rowStart = 0, rowEnd = matrix.size() - 1;
    findRow(matrix, target, rowStart, rowEnd);
    for (int i = rowStart; i <= rowEnd; ++i)
    {
      if (searchRow(matrix[i], target, 0, matrix[i].size() - 1))
        return true;
    }
    return false;
  }
  void findRow(vector<vector<int>> &matrix, int target, int &rowStart, int &rowEnd)
  {
    int rowStartStart = rowStart,
        rowStartEnd = rowEnd,
        rowEndStart = rowStart,
        rowEndEnd = rowEnd;
    while (rowStartStart != rowStartEnd || rowEndStart != rowEndEnd)
    {
      int rowStartMiddle = (rowStartEnd - rowStartStart) / 2 + rowStartStart;
      int rowEndMiddle = (rowEndEnd - rowEndStart) / 2 + rowEndStart;

      if(matrix[rowEndMiddle].size() == 0 || matrix[rowStartMiddle].size() == 0)
        return;

      if (matrix[rowEndMiddle][0] > target)
      {
        rowEndEnd = rowEndMiddle;
      }
      else
      {
        rowEndStart = rowEndMiddle;
      }
      if (matrix[rowStartMiddle][matrix[rowStartMiddle].size() - 1] < target)
      {
        rowStartStart = rowStartMiddle;
      }
      else
      {
        rowStartEnd = rowStartMiddle;
      }
      if (rowEndEnd - rowEndStart == 1)
      {
        if (matrix[rowEndEnd][0] > target)
        {
          rowEndEnd = rowEndStart;
        }
        else
        {
          rowEndStart = rowEndEnd;
        }
      }
      if(rowStartEnd-rowStartStart == 1) {
        if (matrix[rowStartStart][matrix[rowStartStart].size() - 1] < target)
        {
          rowStartStart = rowStartEnd;
        }
        else
        {
          rowStartEnd = rowStartStart;
        }
      }
    }
    rowStart = rowStartStart;
    rowEnd = rowEndEnd;
  }
  bool searchRow(vector<int> &row, int target, int start, int end)
  {
    if(end < start)
      return false;
    if (start == end)
      return row[start] == target;
    if (end - start == 1)
      return row[start] == target || row[end] == target;
    int middle = (end - start) / 2 + start;
    if (row[middle] == target)
      return true;
    if (row[middle] < target)
    {
      return searchRow(row, target, middle, end);
    }
    else
    {
      return searchRow(row, target, start, middle);
    }
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {1, 4, 7, 11, 15},
      {2, 5, 8, 12, 19},
      {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24},
      {18, 21, 23, 26, 30}};
  cout << Solution().searchMatrix(matrix, 5) << endl;
  cout << Solution().searchMatrix(matrix, 20) << endl;
  return 0;
}
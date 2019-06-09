#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(matrix.size() <= 0)
        return false;
      int rowNumber = searchFirst(matrix, target, 0, matrix.size() - 1);
      if (matrix[rowNumber].size() <=0)
        return false;
      return searchRow(matrix[rowNumber], target, 0, matrix[rowNumber].size() - 1);
    }
    int searchFirst(vector<vector<int>> &matrix, int target,int start ,int end)
    {
      if(start == end)
        return start;
      if(start == end -1) {
        if (target >= matrix[end][0] )
          return end;
          else
            return start;
      }

      int middle = (start + end) / 2;
      if(matrix[middle][0] > target)
        return searchFirst(matrix, target, start, middle - 1);
      else
        return searchFirst(matrix, target, middle, end);
    }
    bool searchRow(vector<int> &row,int target,int start,int end) {
      if (start == end) {
        return row[start] == target;
      }
      if (start == end -1) {
        return row[start] == target || row[end] == target;
      }
      int middle = (start + end) / 2;
      if (row[middle] == target)
        return true;
      if (row[middle] > target)
        return searchRow(row, target, start, middle - 1);
      else
        return searchRow(row, target, middle + 1, end);
    }
};

int main()
{
  Solution s;

  vector<vector<int>> input = {
    { 1, 3, 5, 7 },
    { 10, 11, 16, 20 },
    { 23, 30, 34, 50 }
  };
  cout << s.searchMatrix(input, 13) << endl;

  return 0;
}

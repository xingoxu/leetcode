

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    vector<int> result;
    if (matrix.size() <= 0)
      return result;
    result = goRight(matrix, 0, 0, matrix[0].size() - 1, result);
    return result;
  }
  vector<int> goRight(vector<vector<int>> &matrix, int x, int y, int rightMax, vector<int> result)
  {
    if (y > rightMax) {
      return result;
    }
    for (int i = y; i <= rightMax; i++)
    {
      result.push_back(matrix[x][i]);
    }
    int matrixRightMax = matrix[0].size() - 1;

    return goDown(matrix, x + 1, rightMax, matrix.size() - 1 - (matrixRightMax - rightMax), result);
  }
  vector<int> goDown(vector<vector<int>> &matrix, int x, int y, int downMax, vector<int> result) {

    if(x > downMax) {
      return result;
    }
    for (int i = x; i <= downMax;i++) {
      result.push_back(matrix[i][y]);
    }
    int matrixDownMax = matrix.size() - 1;
    return goLeft(matrix, downMax, y - 1, 0 + (matrixDownMax - downMax), result);
  }
  vector<int> goLeft(vector<vector<int>> &matrix, int x, int y, int leftMin, vector<int> result) {
    if(y < leftMin) {
      return result;
    }
    for (int i = y; i >= leftMin;i--) {
      result.push_back(matrix[x][i]);
    }
    return goUp(matrix, x - 1, leftMin, 0 + (leftMin - 0) + 1, result);
  }
  vector<int> goUp(vector<vector<int>> &matrix, int x, int y, int upMin, vector<int> result) {
    if(x < upMin) {
      return result;
    }
    for (int i = x; i >= upMin;i--) {
      result.push_back(matrix[i][y]);
    }
    int matrixRightMax = matrix[0].size() - 1;
    return goRight(matrix, upMin, y + 1, matrixRightMax - (upMin - 0), result);
  }
};

int main()
{
  Solution *s = new Solution();

  vector<vector<int>> x{
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
  };

  vector<int> result = s->spiralOrder(x);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }
  return 0;
}

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 9.2 MB, less than 5.20% of C++ online submissions for Spiral Matrix II.


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n) {
    if(n <= 0)
      return {};
    if (n == 1)
      return {{1}};
    vector<vector<int>> result(n);
    for (int i = 0; i < n;i++) {
      vector<int> initArray(n);
      result[i] = initArray;
    }
    goRight(result, 0, 0, result[0].size() - 1, 1);
    return result;
  }
  void goRight(vector<vector<int>> &matrix, int x, int y, int rightMax, int count)
  {
    if (y > rightMax) {
      return;
    }
    for (int i = y; i <= rightMax; i++)
    {
      matrix[x][i] = count++;
    }
    int matrixRightMax = matrix[0].size() - 1;

    return goDown(matrix, x + 1, rightMax, matrix.size() - 1 - (matrixRightMax - rightMax), count);
  }
  void goDown(vector<vector<int>> &matrix, int x, int y, int downMax, int count) {

    if(x > downMax) {
      return;
    }
    for (int i = x; i <= downMax;i++) {
      matrix[i][y] = count++;
    }
    int matrixDownMax = matrix.size() - 1;
    return goLeft(matrix, downMax, y - 1, 0 + (matrixDownMax - downMax), count);
  }
  void goLeft(vector<vector<int>> &matrix, int x, int y, int leftMin, int count) {
    if(y < leftMin) {
      return;
    }
    for (int i = y; i >= leftMin;i--) {
      matrix[x][i] = count++;
    }
    return goUp(matrix, x - 1, leftMin, 0 + (leftMin - 0) + 1, count);
  }
  void goUp(vector<vector<int>> &matrix, int x, int y, int upMin, int count) {
    if(x < upMin) {
      return;
    }
    for (int i = x; i >= upMin;i--) {
      matrix[i][y] = count++;
    }
    int matrixRightMax = matrix[0].size() - 1;
    return goRight(matrix, upMin, y + 1, matrixRightMax - (upMin - 0), count);
  }
};

int main()
{
  Solution *s = new Solution();

  vector<vector<int>> result2 = s->generateMatrix(4);

  for (int i = 0; i < result2.size(); i++)
  {
    vector<int> inner = result2[i];
    for (int j = 0; j < inner.size(); j++)
    {
      cout << inner[j] << ' ';
    }
    cout << endl;
  }
  return 0;
}

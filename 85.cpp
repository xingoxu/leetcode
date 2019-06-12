#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    int maxArea = 0;
    vector<int> result;
    for (int i = 0; i < matrix.size(); i++)
    {
      int size = matrix[i].size();
      result.resize(size);
      for (int j = 0; j < size; j++)
      {
        if (matrix[i][j] == '1')
        {
          result[j]++;
        }
        else
        {
          result[j] = 0;
        }
      }
      int area = largestRectangleArea(result);
      if (area > maxArea)
      {
        maxArea = area;
      }
    }
    return maxArea;
  }
  int largestRectangleArea(vector<int> &heights)
  {
    stack<int> pointerStack;
    int biggestArea = 0;
    int heightsSize = heights.size();
    for (int i = 0; i < heightsSize; i++)
    {
      while (!pointerStack.empty() && heights[pointerStack.top()] > heights[i])
      {
        int top = pointerStack.top();
        pointerStack.pop();

        int length = pointerStack.empty() ? i : i - pointerStack.top() - 1;
        int area = length * heights[top];
        if (area > biggestArea)
        {
          biggestArea = area;
        }
      }
      pointerStack.push(i);
    }
    while (!pointerStack.empty())
    {
      int top = pointerStack.top();
      pointerStack.pop();

      int length = pointerStack.empty() ? heightsSize : heightsSize - pointerStack.top() - 1;
      int area = length * heights[top];
      if (area > biggestArea)
      {
        biggestArea = area;
      }
    }
    return biggestArea;
  }
};

// Driver program to test above function
int main()
{
  vector<vector<char>> x = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  cout << Solution().maximalRectangle(x) << endl;

  return 0;
}
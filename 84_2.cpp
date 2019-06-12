#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
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
  vector<int> x = {2, 1, 5, 6, 2, 3};
  cout << Solution().largestRectangleArea(x) << endl;

  return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // time excceeded
    int outdated_largestRectangleArea(vector<int>& heights) {
      if (heights.size() == 0)
        return 0;
      return largestRectangleArea(heights, 0, heights.size() - 1);
    }
    int largestRectangleArea(vector<int> &heights, int start, int end)
    {
      if(start == end)
        return heights[start];
      string key;
      key += start;
      key += "-";
      key += end;
      int left = largestRectangleArea(heights, start, end - 1);
      int right = largestRectangleArea(heights, start + 1, end);

      int min = INT_MAX;
      for (int i = start; i <= end; i++)
      {
        if(heights[i]<min)
          min = heights[i];
      }
      int result = max(left, right);
      result = max(result, min * (end - start + 1));
      return result;
    }
};

int main()
{
  vector<int> x = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
  cout << Solution().largestRectangleArea(x) << endl;

  return 0;
}

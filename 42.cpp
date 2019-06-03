#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    int left = 0, right = height.size() - 1;
    int sum = 0;
    while (left < right) {
      while (left < right)
      {
        if (height[left] <= height[left + 1])
        {
          left++;
        }
        else
          break;
      }
      while (right > 0)
      {
        if (height[right] <= height[right - 1])
        {
          right--;
        }
        else
          break;
      }
      int secondHeight = height[left] < height[right] ? height[left] : height[right];
      for (int i = left; i <= right; i++)
      {
        if (height[i] >= secondHeight){
          height[i] = height[i] - secondHeight;
        } else {
          sum += secondHeight - height[i];
          height[i] = 0;
        }
      }
    }
    return sum;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{0,1,0,2,1,0,1,3,2,1,2,1}; // -4 -1 -1 0 1 2

  cout << s->trap(x) << endl;
  return 0;
}

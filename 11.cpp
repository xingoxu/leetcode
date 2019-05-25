#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int length = height.size();
    int left = 0;
    int right = length - 1;
    int maxHeight = 0;
    int secondHeight = 0;

    int maxArea = 0;

    while (left < right)
    {
      if (height[left] > height[right])
      {
        maxHeight = height[left];
        secondHeight = height[right];
      }
      else
      {
        maxHeight = height[right];
        secondHeight = height[left];
      }

      if (secondHeight * (right - left) > maxArea) {
        maxArea = secondHeight * (right - left);
      }

      while ((left < length) && height[left] <= secondHeight)
        left++;
      while (right >= 0 && height[right] <= secondHeight)
        right--;
    }
    return maxArea;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> a{1, 8, 6, 2, 5, 4, 8, 3, 7};

  cout << s->maxArea(a) << endl;
  return 0;
}
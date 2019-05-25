#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int numLength = nums.size();
    sort(nums.begin(), nums.end());

    int diff = INT16_MAX;
    int sum = 0;

    for (int i = 0; i < numLength - 2; i++)
    {
      for (int j = i + 1, k = numLength - 1; j < k;)
      {
        int tSum = nums[i] + nums[j] + nums[k];
        int tDiff = abs(tSum - target);
        if (tDiff < diff)
        {
          sum = tSum;
          diff = tDiff;
        }
        if (tSum - target > 0)
        {
          k--;
        }
        else
        {
          j++;
        }
      }
    }
    return sum;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x
{6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10}; 

  cout << s->threeSumClosest(x, -52) << endl;
  return 0;
}
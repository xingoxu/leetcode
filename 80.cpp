#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int leftPointer = -1;

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int leftNum = leftPointer < 0 ? nums[0] : nums[leftPointer];

      if (nums[i] == leftNum)
      {
        count++;
      }
      else
      {
        count = 1;
      }
      if (count > 2)
      {
        continue;
      }
      else
      {
        int temp = nums[++leftPointer];
        nums[leftPointer] = nums[i];
        nums[i] = temp;
      }
    }

    return leftPointer + 1;
  }
};

int main()
{
  Solution s;
  vector<int> x = { 0,0,1,1,1,1,2,3,3,4,4,4,5 };
  int len = s.removeDuplicates(x);
  cout << len << endl;

  for (int i = 0; i < len; i++) {
    cout << x[i] << ' ';
  }
  cout << endl;

  return 0;
}

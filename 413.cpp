#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int numberOfArithmeticSlices(vector<int> &A)
  {
    int count = 0;
    int ret = 0;
    for (int i = A.size() - 3; i >= 0; --i)
    {
      if (A[i] - A[i + 1] != A[i + 1] - A[i + 2])
      {
        count = 0;
      }
      else
      {
        ret += ++count;
      }
    }
    return ret;
  }
};

int main()
{
  vector<int> nums = {1, 3, 5, 7, 9};
  cout << Solution().numberOfArithmeticSlices(nums) << endl;
  return 0;
}
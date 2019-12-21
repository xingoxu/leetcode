
#include <iostream>
#include <vector>
using namespace std;

class Solution
{

public:
  int minMoves(vector<int> &nums)
  {
    int size = nums.size();
    if (size <= 1)
      return 0;
    long sum = 0;
    int minNum = INT_MAX;
    for (auto &x : nums){
      sum += x;
      minNum = min(minNum, x);
    }
    return sum - (minNum * size);
  }
};

int main()
{
  vector<int> nums = {-100, 0, 100};
  cout << Solution().minMoves(nums) << endl;
  return 0;
}

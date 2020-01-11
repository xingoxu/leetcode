#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  bool find132pattern(vector<int> &nums)
  {
    stack<int> st;
    int size = nums.size();
    vector<int> minNums(size);
    int minNum = INT_MAX;
    for (int i = 0; i < size; ++i)
    {
      minNum = min(minNum, nums[i]);
      minNums[i] = minNum;
    }

    for (int i = size - 1; i >= 0; --i)
    {
      if (st.empty() || st.top() >= nums[i])
        st.push(nums[i]);
      else
      {
        while (!st.empty() && st.top() <= minNums[i])
          st.pop();
        if (!st.empty() && st.top() < nums[i])
          return true;
        else
          st.push(nums[i]);
      }
    }
    return false;
  }
};

int main()
{
  vector<int> nums{3, 5, 4};
  cout << Solution().find132pattern(nums) << endl;
  return 0;
}

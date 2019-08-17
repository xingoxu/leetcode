// Runtime: 60 ms, faster than 53.32% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 13.5 MB, less than 36.07% of C++ online submissions for Sliding Window Maximum.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    deque<int> dq;
    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (!dq.empty() && nums[dq.front()] < nums[i])
      {
        dq = deque<int>();
      }
      while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();

      dq.push_back(i);

      if (dq.front() < i - k + 1)
        dq.pop_front();
      
      if(i >= k - 1)
        ret.push_back(nums[dq.front()]);
    }
    return ret;
  }
};

int main()
{
  vector<int> input{
      1, 3, -1, -3, 5, 3, 6, 7};
  auto result = Solution().maxSlidingWindow(input, 3);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ' ';
  }
  cout << endl;
  return 0;
}
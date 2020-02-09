#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    if (nums.size() == 0)
      return {};
    stack<pair<int, int>> st;
    vector<int> ret(nums.size(), -1);
    for (int i = 0; i < nums.size(); ++i)
    {
      while (!st.empty() && st.top().second < nums[i])
      {
        ret[st.top().first] = nums[i];
        st.pop();
      }
      st.push({i, nums[i]});
    }
    for (int i = 0; i < nums.size() - 1; ++i)
    {
      while (!st.empty() && st.top().second < nums[i])
      {
        ret[st.top().first] = nums[i];
        st.pop();
      }
      st.push({i, nums[i]});
    }
    return ret;
  }
};

int main()
{
  vector<int> nums{1, 2, 1};
  auto result = Solution().nextGreaterElements(nums);
  for (auto &num : result)
    cout << num << ' ';
  cout << endl;
  return 0;
}
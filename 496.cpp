#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> ret;
    stack<int> st;
    for (auto &num : nums2)
    {
      while ((!st.empty()) && st.top() < num)
      {
        ret[st.top()] = num;
        st.pop();
      }
      st.push(num);
    }
    for (auto &num : nums1)
    {
      auto it = ret.find(num);
      if (it != ret.end())
      {
        num = it->second;
      }
      else
        num = -1;
    }
    return nums1;
  }
};

int main()
{
  vector<int> nums{2, 4};
  vector<int> num2{1, 2, 3, 4};
  auto result = Solution().nextGreaterElement(nums, num2);
  for (auto &num : result)
    cout << num << ' ';
  cout << endl;
  return 0;
}
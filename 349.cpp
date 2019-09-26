// Runtime: 20 ms, faster than 79.55% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.6 MB, less than 51.61% of C++ online submissions for Top K Frequent Elements.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, bool> x;
    vector<int> result;
    for (auto num : nums1)
      x[num] = true;
    for (auto num : nums2)
      if (x[num])
      {
        result.push_back(num);
        x[num] = false;
      }
    return result;
  }
};

int main()
{
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  auto result = Solution().intersection(nums1, nums2);
  for (auto x : result)
  {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}

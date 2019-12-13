// Runtime: 32 ms, faster than 43.49% of C++ online submissions for Find K Pairs with Smallest Sums.
// Memory Usage: 15.4 MB, less than 20.00% of C++ online submissions for Find K Pairs with Smallest Sums.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    if (nums1.size() == 0 || nums2.size() == 0)
      return {};
    auto comp = [](vector<int> a, vector<int> b) {
      return (a[0] + a[1]) > (b[0] + b[1]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    for (auto &x : nums1)
      pq.push({x, nums2[0], 0});

    vector<vector<int>> ret;
    while (ret.size() < k && pq.size() > 0)
    {
      auto pair = pq.top();
      pq.pop();
      ret.push_back({pair[0], pair[1]});
      if (pair[2] + 1 < nums2.size())
        pq.push({pair[0], nums2[pair[2] + 1], pair[2] + 1});
    }
    return ret;
  }
};

int main()
{
  vector<int> nums1{1, 1, 2};
  vector<int> nums2{1, 2, 3};
  int k = 10;

  auto result = Solution().kSmallestPairs(nums1, nums2, k);
  for (auto &x : result)
  {
    cout << x[0] << ' ' << x[1] << endl;
  }
  return 0;
}

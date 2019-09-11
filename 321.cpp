// Runtime: 20 ms, faster than 96.45% of C++ online submissions for Create Maximum Number.
// Memory Usage: 14.5 MB, less than 80.00% of C++ online submissions for Create Maximum Number.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print(const vector<int> &result)
{
  for (int i = 0; i < result.size(); ++i)
    cout << result[i] << ' ';
  cout << endl;
}

class Solution
{
  vector<int> maxNumber(vector<int> &nums, int k)
  {
    vector<int> ret(k);
    int iterator = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      while (iterator > 0 && nums[i] > ret[iterator - 1] && (nums.size() - i) >= (k - iterator + 1))
        --iterator;
      if (iterator < k)
        ret[iterator++] = nums[i];
    }
    return ret;
  }
  vector<int> merge(const vector<int> &a, const vector<int> &b)
  {
    int ai = 0, bi = 0, iterator = 0;
    vector<int> ret(a.size() + b.size());
    while (ai < a.size() || bi < b.size())
    {
      if (greater(a, ai, b, bi))
        ret[iterator] = a[ai++];
      else
        ret[iterator] = b[bi++];

      ++iterator;
    }
    return ret;
  }
  bool greater(const vector<int> &a, int ai, const vector<int> &b, int bi)
  {
    while (ai < a.size() && bi < b.size())
    {
      if (a[ai] != b[bi])
        return a[ai] > b[bi];
      ++ai, ++bi;
    }
    return bi >= b.size();
  }

public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
  {
    vector<int> ret(k, 0);
    for (int i = max(0, k - (int)nums2.size()); i <= k && i <= nums1.size(); ++i)
    {
      // print(maxNumber(nums1, i));
      // print(maxNumber(nums2, k - i));
      const auto &candiate = merge(maxNumber(nums1, i), maxNumber(nums2, k - i));
      // print(candiate);
      if (greater(candiate, 0, ret, 0))
        ret = candiate;
    }
    return ret;
  }
};

int main()
{
  vector<int> nums1{5, 5, 1};
  vector<int> nums2{4, 0, 1};
  int k = 3;
  auto result = Solution().maxNumber(nums1, nums2, k);
  print(result);
  return 0;
}
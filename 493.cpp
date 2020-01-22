// Runtime: 1476 ms, faster than 5.09% of C++ online submissions for Reverse Pairs.
// Memory Usage: 105 MB, less than 9.09% of C++ online submissions for Reverse Pairs.
// TODO: existing faster solution ?

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  int reversePairs(vector<int> &nums, int l, int r)
  {
    if (l >= r)
      return 0;
    int result = 0;
    int mid = (l + r) / 2;
    vector<int> left(mid - l + 1);
    vector<int> right(r - mid);

    for (int i = l; i <= mid;++i) {
      left[i - l] = nums[i];
    }
    for (int i = mid + 1; i <= r; ++i)
      right[i - mid - 1] = nums[i];

    // nlogn
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int lp = 0, rp = 0;
    // n
    while (lp < left.size())
    {
      if (rp < right.size() && (long)left[lp] > (long)2 * right[rp])
        ++rp;
      else {
        result += rp;
        ++lp;
      }
    }
    // cout << result << endl;

    return reversePairs(nums, l, mid) + reversePairs(nums, mid + 1, r) + result;
  }

public:
  int reversePairs(vector<int> &nums)
  {
    return reversePairs(nums, 0, nums.size() - 1);
  }
};

int main()
{
  vector<int> nums{1,3,2,3,1};
  cout << Solution().reversePairs(nums) << endl;
  return 0;
}
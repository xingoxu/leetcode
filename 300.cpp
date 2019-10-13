#include <iostream>
#include <vector>
using namespace std;

//MaxV 代表该长度递增子序列最小元素

class Solution
{
  /* 返回MaxV[i]中刚刚大于x的那个元素的下标 */
  int binSearch(vector<int> MaxV, int size, int x)
  {
    int left = 0, right = size - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (MaxV[mid] == x)
        return mid;
      else if (MaxV[mid] < x)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return left;
  }

public:
  int lengthOfLIS(vector<int> &nums)
  {
    if(nums.size() == 0)
      return 0;
    vector<int> MaxV(nums.size());
    MaxV[0] = nums[0];             /* init */
    int len = 1;
    for (int i = 1; i < nums.size(); ++i) /* 寻找arr[i]属于哪个长度LIS的最大元素 */
    {
      cout << nums[i] << ' ' << MaxV[len - 1] << endl;
      if (nums[i] > MaxV[len - 1]) /* 大于最大的自然无需查找，否则二分查其位置 */
      {
        MaxV[len++] = nums[i];
      }
      else
      {
        int pos = binSearch(MaxV, len, nums[i]);
        MaxV[pos] = nums[i];
      }
    }
    return len;
  }
};

int main()
{
  vector<int> nums{4, 10, 4, 3, 8, 9};

  cout << Solution().lengthOfLIS(nums) << endl;
  return 0;
}
// Runtime: 192 ms, faster than 60.39% of C++ online submissions for Russian Doll Envelopes.
// Memory Usage: 382.2 MB, less than 16.67% of C++ online submissions for Russian Doll Envelopes.

#include <iostream>
#include <vector>
using namespace std;

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
  int lengthOfLIS(vector<vector<int>> &envelopes)
  {
    vector<int> MaxV(envelopes.size());
    MaxV[0] = envelopes[0][1]; /* init */
    int len = 1;
    for (int i = 1; i < envelopes.size(); ++i) /* 寻找arr[i]属于哪个长度LIS的最大元素 */
    {
      if (envelopes[i][1] > MaxV[len - 1]) /* 大于最大的自然无需查找，否则二分查其位置 */
      {
        MaxV[len++] = envelopes[i][1];
      }
      else
      {
        int pos = binSearch(MaxV, len, envelopes[i][1]);
        MaxV[pos] = envelopes[i][1];
      }
    }
    return len;
  }

public:
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    if (envelopes.size() == 0)
      return 0;
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
      if (a[0] == b[0])
        return b[1] - a[1] < 0;
      else
        return a[0] - b[0] < 0;
    });

    return lengthOfLIS(envelopes);
  }
};

int main()
{
  vector<vector<int>> envelopes{{5, 4}, {6, 4}, {6, 7}, {2, 3}};

  cout << Solution().maxEnvelopes(envelopes) << endl;
  return 0;
}
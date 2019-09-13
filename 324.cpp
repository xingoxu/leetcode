
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

class Solution {
  int getIndex(int x, int n) {
    return (x * 2 + 1) % (n | 1);
  }

public:
    void wiggleSort(vector<int>& nums) {
      if (nums.empty()) {
        return;
      }
      int nLength  = nums.size();
      nth_element(nums.begin(), nums.begin() + ((nLength) / 2), nums.end());

      int middle = nums[nLength / 2];
      // 0 2 4 6  1 3 5 7 9
      int left = 0, mid = 0, right = nLength - 1;
      while (mid <= right)
      {
        auto m = nums[getIndex(mid, nLength)];
        if (m > middle)
        {
          swap(nums[getIndex(mid++, nLength)], nums[getIndex(left++, nLength)]);
        }
        else if (m < middle)
        {
          swap(nums[getIndex(mid, nLength)], nums[getIndex(right--, nLength)]);
        } else {
          mid++;
        }
      }

    }
};

int main()
{
  vector<int> nums1{1};
  Solution().wiggleSort(nums1);
  print(nums1);
  return 0;
}
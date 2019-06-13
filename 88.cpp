#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int rightPointer = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0)
    {
      if (nums1[m] > nums2[n])
      {
        nums1[rightPointer] = nums1[m--];
      }
      else
      {
        nums1[rightPointer] = nums2[n--];
      }
      rightPointer--;
    }
    while (n >= 0)
    {
      nums1[rightPointer--] = nums2[n--];
    }
  }
};

int main()
{

  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  Solution().merge(nums1, 3, nums2, 3);

  for (int i = 0; i < nums1.size();i++) {
    cout << nums1[i] << ' ';
  }
  cout << endl;

  return 0;
}
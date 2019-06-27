// Runtime: 12 ms, faster than 54.40% of C++ online submissions for Maximum Gap.
// Memory Usage: 10.9 MB, less than 5.72% of C++ online submissions for Maximum Gap.
// it's a naive solution
// while its worst time complexity is O(n^2)

#include <iostream>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

class Solution
{
public:
  int maximumGap(vector<int> &nums)
  {
    int size = nums.size();
    if (size < 2)
      return 0;
    int minNum = INT_MAX, maxNum = INT_MIN;
    for (auto &x : nums)
    {
      if (x > maxNum)
        maxNum = x;
      if (x < minNum)
        minNum = x;
    }
    if (maxNum == minNum)
      return 0;
    int interval = ceil(double(maxNum - minNum) / (double)(size - 1));
    vector<list<int>> bucket(size);
    for (auto &now : nums)
    {
      int bucketIndex = (now - minNum) / interval;
      insertListWithInsertionSort(bucket[bucketIndex], now);
    }
    int before = 0, ret = 0;
    for (auto &list : bucket)
    {
      for(auto &num: list) {
        if (before != 0)
          ret = max(ret, num - before);
        before = num;
      }
    }
    return ret;
  }
  void insertListWithInsertionSort(list<int> &list, int &num) {
    auto it = list.begin();
    while (it != list.end())
    {
      if(*it < num) {
        it++;
      } else {
        break;
      }
    }
    list.insert(it, num);
  }
};

int main()
{
  vector<int> x{3, 6, 9, 1};
  cout << Solution().maximumGap(x) << endl;
  return 0;
}

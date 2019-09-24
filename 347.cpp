// Runtime: 20 ms, faster than 79.55% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.6 MB, less than 51.61% of C++ online submissions for Top K Frequent Elements.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
  int findKthLargest(vector<int> &nums, int start, int end, int k)
  {
    if (end == start)
      return nums[start];
    if (end - start == 1)
    {
      if (k == 1)
        return nums[start] > nums[end] ? nums[start] : nums[end];
      else
      {
        return nums[start] < nums[end] ? nums[start] : nums[end];
      }
    }
    int middle = split(nums, start, end);
    int rightAmount = (end - middle + 1);
    if (rightAmount == k)
      return findSmallest(nums, middle, end);

    if (rightAmount > k)
      return findKthLargest(nums, middle, end, k);
    else
      return findKthLargest(nums, start, middle - 1, k - rightAmount);
  }
  int split(vector<int> &nums, int start, int end)
  {
    int middle = (end - start) / 2 + start;
    middle = nums[middle];
    while (start < end)
    {
      while (nums[start] < middle)
      {
        ++start;
      }
      while (nums[end] > middle)
      {
        end--;
      }
      if (start >= end)
      {
        break;
      }
      auto tmp = nums[start];
      nums[start] = nums[end];
      nums[end] = tmp;
      ++start;
      end--;
    }
    if (nums[start] < middle)
      return start + 1;
    return start;
  }
  int findSmallest(vector<int> &nums, int start, int end)
  {
    int smallest = INT_MAX;
    for (int i = start; i <= end; i++)
    {
      smallest = min(smallest, nums[i]);
    }
    return smallest;
  }

public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> times;
    for (auto &num : nums)
      ++times[num];
    vector<int> timesFind;

    for (auto time : times)
      timesFind.push_back(time.second);

    int line = findKthLargest(timesFind, 0, timesFind.size() - 1, k);
    vector<int> result;
    for (auto time : times)
      if (time.second >= line)
        result.push_back(time.first);
    return result;
  }
};

int main()
{
  vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
  auto result = Solution().topKFrequent(nums, 1);
  for (auto x : result)
  {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}

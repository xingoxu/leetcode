// Runtime: 16 ms, faster than 54.87% of C++ online submissions for Majority Element II.
// Memory Usage: 10.8 MB, less than 6.67% of C++ online submissions for Majority Element II.
// TODO ?


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {

    auto setA = exec(nums, false);
    const auto &setB = exec(nums, true);
    for(auto x : setB) {
      setA.insert(x);
    }
    return vector<int>(setA.begin(), setA.end());
  }

  unordered_set<int> exec(vector<int> &nums, bool isReverse)
  {
    vector<vector<int>> storage{{INT_MAX, 0}, {INT_MAX, 0}, {INT_MAX, 0}, {INT_MAX, 0}};
    int numLength = nums.size(), iterator = 0;
    if (isReverse)
      iterator = numLength - 1;
    for (; iterator >= 0 && iterator < numLength; isReverse ? iterator-- : ++iterator)
    {
      int &x = nums[iterator];
      bool appeared = false;
      int smallestI, smallestTimes = INT_MAX;
      for (int i = 0; i < 4; ++i)
      {
        if (x == storage[i][0])
        {
          appeared = true;
          ++storage[i][1];
        }
        if (storage[i][1] < smallestTimes)
        {
          smallestI = i;
          smallestTimes = storage[i][1];
        }
      }
      // cout << storage[smallestI][0] << endl;
      if (!appeared)
      {
        storage[smallestI][0] = x;
        storage[smallestI][1] = 1;
      }
    }

    unordered_set<int> ret;
    for (int i = 0; i < 4; ++i)
    {
      if (storage[i][1] > nums.size() / 3)
      {
        ret.insert(storage[i][0]);
      }
    }
    return ret;
  }
};

int main()
{
  vector<int> input{1,2,2,3,3,4,4,5,1,1,1,1};
  auto result = Solution().majorityElement(input);
  for (int i = 0; i < result.size(); ++i)
  {
    cout << result[i] << ' ';
  }
  cout << endl;
  return 0;
}
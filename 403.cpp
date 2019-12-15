// Runtime: 56 ms, faster than 78.38% of C++ online submissions for Frog Jump.
// Memory Usage: 19.4 MB, less than 40.00% of C++ online submissions for Frog Jump.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, unordered_map<int, bool>> cache;
  bool canCross(vector<int> &stones, int index, int k)
  {
    if (index == stones.size() - 1)
      return true;

    if (cache.count(index) > 0 && cache[index].count(k) > 0)
      return cache[index][k];

    bool result = false;
    for (int i = index + 1; i < stones.size(); ++i)
    {
      if (stones[i] - stones[index] > k + 1)
        break;
      else if (stones[i] - stones[index] == k + 1)
        result = result || canCross(stones, i, k + 1);
      else if (stones[i] - stones[index] == k)
        result = result || canCross(stones, i, k);
      else if (stones[i] - stones[index] == k - 1)
        result = result || canCross(stones, i, k - 1);
      else if (result)
        break;
    }

    return cache[index][k] = result;
  }

public:
  bool canCross(vector<int> &stones)
  {
    return canCross(stones, 0, 0);
  }
};

int main()
{
  vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
  cout << Solution().canCross(stones) << endl;
  return 0;
}
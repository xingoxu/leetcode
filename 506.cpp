#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
  vector<string> findRelativeRanks(vector<int> &nums)
  {
    vector<int> index(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i)
    {
      index[i] = i;
    }
    sort(index.begin(), index.end(), [&nums](int &a, int &b) {
      return nums[a] > nums[b];
    });

    vector<string> ret(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i)
    {
      switch (i)
      {
      case 0:
        ret[index[i]] = "Gold Medal";
        break;
      case 1:
        ret[index[i]] = "Silver Medal";
        break;
      case 2:
        ret[index[i]] = "Bronze Medal";
        break;
      default:
        ret[index[i]] = to_string(i + 1);
        break;
      }
    }
    return ret;
  }
};

int main()
{
  vector<int> nums = {5, 4, 3, 2, 1};
  auto res = Solution().findRelativeRanks(nums);
  for (auto &re : res)
  {
    cout << re << ' ';
  }
  cout << endl;
  return 0;
}
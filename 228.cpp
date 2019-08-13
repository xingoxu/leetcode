// Runtime: 16 ms, faster than 59.77% of C++ online submissions for Basic Calculator II.
// Memory Usage: 10.3 MB, less than 82.14% of C++ online submissions for Basic Calculator II.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  vector<string> summaryRanges(vector<int> &nums)
  {
    int length = nums.size();
    if (length <= 0)
      return {};
    vector<int> ret{nums[0], nums[0]};
    vector<string> summary;
    for (int i = 1; i < length; ++i)
    {
      if(nums[i] == ret[1]+1) {
        ret[1] = nums[i];
      }
      else
      {
        if(ret[0] == ret[1]) {
          summary.push_back(to_string(ret[0]));
        } else {
          summary.push_back(to_string(ret[0]) + "->" + to_string(ret[1]));
        }
        ret[0] = ret[1] = nums[i];
      }
    }
    if(ret[0] == ret[1]) {
      summary.push_back(to_string(ret[0]));
    } else {
      summary.push_back(to_string(ret[0]) + "->" + to_string(ret[1]));
    }
    return summary;
  }
};

int main()
{
  vector<int> input{0, 1, 2, 4, 5, 7};
  auto result = Solution().summaryRanges(input);
  for (int i = 0; i < result.size(); ++i)
  {
    cout << result[i] << ' ';
  }
  cout << endl;
  return 0;
}
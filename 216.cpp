// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.
// Memory Usage: 8.7 MB, less than 85.05% of C++ online submissions for Combination Sum III.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  vector<vector<int>> _result;
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> ret;
    combinationSum3(k, 0, n, ret);
    return _result;
  }
  void combinationSum3(int k, int startN, int n, vector<int> &result)
  {
    if (k == 1 && n > 0 && n <= 9 && result[result.size() - 1] != n)
    {
      result.push_back(n);
      _result.push_back(result);
      return;
    }
    else if (k == 1)
    {
      return;
    }
    for (int i = startN + 1; i <= n / k && i <= 9; ++i)
    {
      vector<int> copy(result);
      copy.push_back(i);
      combinationSum3(k - 1, i, n - i, copy);
    }
  }
};

int main()
{
  auto ret = Solution().combinationSum3(2, 18);
  for (int i = 0; i < ret.size(); i++)
  {
    for (int j = 0; j < ret[i].size(); j++)
    {
      cout << ret[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
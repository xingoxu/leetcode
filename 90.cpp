#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    if (nums.size() == 0)
      return {{}};
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    result = subsetsWithDup(nums, 0, result);
    result.push_back({});
    return result;
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums, int left, vector<vector<int>> &result)
  {
    if (left == nums.size() - 1)
    {
      return {{nums[left]}};
    }

    result = subsetsWithDup(nums, left + 1, result);

    int resultSize = result.size();
    for (int i = 0; i < resultSize; i++)
    {
      if (result[i][0] == nums[left])
      {
        result[i].insert(result[i].begin(), nums[left]);
        continue;
      }
      vector<int> row = result[i];
      row.insert(row.begin(), nums[left]);
      result.push_back(row);
    }

    vector<int> self = {nums[left]};
    result.push_back(self);
    return result;
  }
};

int main()
{
  Solution s;
  vector<int> x = {1, 1, 2, 2};
  vector<vector<int>> result = s.subsetsWithDup(x);

  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}

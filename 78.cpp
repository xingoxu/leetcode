#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> result;
    result = goNext(nums, 0, result);
    result.push_back({});
    return result;
  }
  vector<vector<int>> goNext(vector<int> &nums, int left, vector<vector<int>> &result)
  {
    if (nums.size() == left + 1)
      return {{nums[left]}};

    result = goNext(nums, left + 1, result);
    int resultSize = result.size();
    for (int i = 0; i < resultSize; i++)
    {
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
  vector<int> x = {1, 2, 3, 4};
  vector<vector<int>> result = s.subsets(x);

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

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int numLength = nums.size();
    vector<vector<int>> result;
    if (numLength <= 0)
      return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < numLength; i++)
    {
      for (int l = i + 1; l < numLength; l++)
      {
        for (int j = l + 1, k = numLength - 1; j < k;)
        {
          int sum = nums[i] + nums[j] + nums[k] + nums[l] - target;
          if (sum == 0)
          {
            result.push_back({nums[i], nums[j], nums[k], nums[l]});

            j++;
            k--;

            while (j < k && j < numLength && nums[j] == nums[j - 1])
              j++;
            while (j < k && nums[k] == nums[k + 1])
              k--;
          }
          else if (sum < 0)
          {
            j++;
          }
          else
          {
            k--;
          }
        }
        while (l < numLength - 1 && nums[l] == nums[l + 1])
          l++;
      }
      while (i < numLength - 1 && nums[i] == nums[i + 1])
        i++;
    }
    return result;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{-1,0,1,2,-1,-4}; // -4 -1 -1 0 1 2 

  vector<vector<int>> result = s->fourSum(x, -1);

  for (int i = 0; i < result.size(); i++)
  {
    cout << '[' << result[i][0];
    cout << ',' << result[i][1] << ',' << result[i][2] << ',' << result[i][3] << ']' << endl;
  }

  // cout << s->fourSum(x) << endl;
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    return _combine(n, k, 1);
  }
  vector<vector<int>> _combine(int n, int k, int start)
  {
    if(k <= 0)
      return {{}};

    vector<vector<int>> result;

    int up = n - k + 1;
    for (int i = start; i <= up; i++)
    {
      const vector<vector<int>> &childResult = _combine(n, k - 1, i + 1);

      for (int j = 0; j < childResult.size(); j++)
      {
        vector<int> row = childResult[j];
        row.insert(row.begin(), i);

        result.push_back(row);
      }

    }

    return result;
  }
};

int main()
{
  Solution s;

  vector<vector<int>> input = s.combine(4, 2);

  for (int i = 0; i < input.size(); i++)
  {
    for (int j = 0; j < input[i].size(); j++)
    {
      cout << input[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}

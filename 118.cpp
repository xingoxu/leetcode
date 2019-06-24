
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> result(numRows);
    for (int i = 0; i < numRows;i++) {
      result[i].resize(i + 1);
      for (int j = 0; j <= i; j++)
      {
        if(i == 0 || j == 0 || j == i) {
          result[i][j] = 1;
        }
        else {
          result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
      }
    }
    return result;
  }
};

int main()
{
  const auto &result = Solution().generate(0);

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

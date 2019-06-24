
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1);
    for (int i = 0; i <= rowIndex; i++)
    {
      for (int j = i; j >=0; j--)
      {
        if(i == 0 || j == 0 || j == i) {
          result[j] = 1;
        }
        else {
          result[j] = result[j] + result[j - 1];
        }
      }
    }
    return result;
  }
};

int main()
{
  const auto &result = Solution().getRow(3);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ' ';
  }
  cout << endl;

  return 0;
}

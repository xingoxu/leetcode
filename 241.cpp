// Runtime: 4 ms, faster than 85.06% of C++ online submissions for Different Ways to Add Parentheses.
// Memory Usage: 13 MB, less than 83.33% of C++ online submissions for Different Ways to Add Parentheses.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  vector<int> diffWaysToCompute(string input)
  {
    vector<int> ret;
    for (int i = 0; i < input.size(); ++i)
    {
      if (input[i] > '9' || input[i] < '0')
      {
        const auto &frontResult = diffWaysToCompute(input.substr(0, i));
        const auto &backResult = diffWaysToCompute(input.substr(i + 1));

        for (int j = 0; j < frontResult.size(); ++j)
        {
          for (int k = 0; k < backResult.size(); ++k)
          {
            ret.push_back(calc(frontResult[j], backResult[k], input[i]));
          }
        }
      }
    }
    if (ret.size() == 0)
      return {stoi(input)};
    else
      return ret;
  }
  int calc(int a, int b, char _operator)
  {
    switch (_operator)
    {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    }
    return 0;
  }
};

int main()
{
  auto result = Solution().diffWaysToCompute("2-1-1");
  for (int i = 0; i < result.size(); ++i)
  {
    cout << result[i] << ' ';
  }
  cout << endl;
  return 0;
}
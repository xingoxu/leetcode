
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
  string num;
  int target;
  vector<string> result;

public:
  vector<string> addOperators(string n, int t)
  {
    num = n;
    target = t;
    result = vector<string>();
    addOperators(0, "", 0, 0);
    return result;
  }
  void addOperators(int pos, string expression, long previousResult, long previousNum)
  {
    if (pos >= num.size())
    {
      if (previousResult == target)
        result.push_back(expression);
      return;
    }

    for (int i = 1; i <= num.size() - pos; ++i)
    {
      if (i > 1 && num[pos] == '0')
      {
        break;
      }
      string currentS = num.substr(pos, i);
      long current = stol(currentS);
      if (pos == 0)
      {
        addOperators(i, currentS, current, current);
        continue;
      }
      addOperators(pos + i, expression + "+" + currentS, previousResult + current, current);
      addOperators(pos + i, expression + "-" + currentS, previousResult - current, 0 - current);
      addOperators(pos + i, expression + "*" + currentS, previousResult - previousNum + previousNum * current, previousNum * current);
    }
  }
};

int main()
{
  auto result = Solution().addOperators("3456237490", 9191);
  for (int i = 0; i < result.size(); ++i)
  {
    cout << result[i] << endl;
  }
  return 0;
}
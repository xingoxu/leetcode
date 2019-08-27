// Runtime: 4 ms, faster than 92.49% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 18.3 MB, less than 25.00% of C++ online submissions for Remove Invalid Parentheses.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
  string input;
  unordered_set<string> result;

public:
  vector<string> removeInvalidParentheses(string s)
  {
    input = s;
    result = unordered_set<string>();
    int leftRemain = 0, rightRemain = 0;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == '(')
      {
        ++leftRemain;
      }
      else if (s[i] == ')')
      {
        if (leftRemain > 0)
          leftRemain--;
        else
          rightRemain++;
      }
    }
    addValidParentheses(0, "", 0, leftRemain, rightRemain);
    return vector<string>(result.begin(), result.end());
  }
  void addValidParentheses(int pos, string previous, int isValid, int leftRemain, int rightRemain)
  {
    if (pos >= input.size())
    {
      if (isValid == 0)
        result.insert(previous);
      return;
    }
    if (isValid < 0)
      return;
    if (leftRemain < 0 || rightRemain < 0)
      return;
    const bool isSameChar = (pos > 0 && input[pos] == input[pos - 1]);
    switch (input[pos])
    {
    case '(':
    {
      addValidParentheses(pos + 1, previous + '(', isValid + 1, leftRemain, rightRemain);
      if (leftRemain > 0)
      {
        addValidParentheses(pos + 1, previous, isValid, leftRemain - 1, rightRemain);
      }
      break;
    }
    case ')':
    {
      addValidParentheses(pos + 1, previous + ')', isValid - 1, leftRemain, rightRemain);
      if (rightRemain > 0)
      {
        addValidParentheses(pos + 1, previous, isValid, leftRemain, rightRemain - 1);
      }
      break;
    }
    default:
    {
      addValidParentheses(pos + 1, previous + input[pos], isValid, leftRemain, rightRemain);
      break;
    }
    }
  }
};

int main()
{
  auto result = Solution().removeInvalidParentheses("()))((()");
  for (int i = 0; i < result.size(); ++i)
  {
    cout << result[i] << endl;
  }
  return 0;
}
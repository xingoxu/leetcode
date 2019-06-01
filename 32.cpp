#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int length = s.size();
    int stack = 0;
    int count = 0;
    int max = 0;
    for (int i = 0; i < length; i++)
    {
      if (s[i] == '(')
      {
        stack++;
      }
      else
      {
        stack--;
      }
      if (stack >= 0 && s[i] == ')') {

      }

      if (stack >= 0)
      {
        count++;
      }
      else
      {
        stack = 0;
        count = 0;
      }

      int countResult = count - stack;
      if (count > 0 && countResult > max)
      {
        max = countResult;
      }
    }
    return max;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3, 2, 2, 3}; // -4 -1 -1 0 1 2
  cout << s->longestValidParentheses("()(()()(((()") << endl;
  return 0;
}

// Runtime: 56 ms, faster than 15.78% of C++ online submissions for Basic Calculator.
// Memory Usage: 286.5 MB, less than 9.52% of C++ online submissions for Basic Calculator.
// TODO ？

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    int index = 0;
    return calculate(s, index);
  }
  int calculate(string s, int &index)
  {
    int result = 0;
    string number = "";
    char _operator = 0;
    while (index < s.size())
    {
      // cout << s[index] << ' ' << number << endl;
      if (s[index] == ' ')
      {
      }
      else if (s[index] >= '0' && s[index] <= '9')
      {
        number += s[index];
      }
      else if (s[index] != '(' && s[index] != ')')
      {
        if (_operator != 0)
        {
          // cout << result << _operator << number << endl;
          result = calc(result, stoi(number), _operator);
        }
        else
        {
          result = stoi(number);
        }
        number = "";
        _operator = s[index];
      }
      else if (s[index] == '(')
      {
        number = to_string(calculate(s, ++index));
      }
      else
      {
        // )
        break;
      }
      ++index;
    }
    if (_operator != 0)
      return calc(result, stoi(number), _operator);
    else
      return stoi(number);
  }
  int calc(int a, int b, char _operator) {
    return _operator == '+' ? a + b : a - b;
  }
};

int main()
{
  cout << Solution().calculate("(1)")
       << endl;
  return 0;
}
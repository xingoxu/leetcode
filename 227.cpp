// Runtime: 16 ms, faster than 59.77% of C++ online submissions for Basic Calculator II.
// Memory Usage: 10.3 MB, less than 82.14% of C++ online submissions for Basic Calculator II.

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
    int resultHigher = 0;
    char _operatorHigher = 0;
    while (index < s.size())
    {
      if (s[index] == ' ')
      {
      }
      else if (s[index] >= '0' && s[index] <= '9')
      {
        number += s[index];
      }
      else
      {
        if (_operator == 0 && _operatorHigher == 0)
        {
          result = stoi(number);
          resultHigher = result;
          switch (s[index])
          {
          case '+':
          case '-':
            _operator = s[index];
            break;
          case '*':
          case '/':
            _operatorHigher = s[index];
            break;
          }
          number = "";
        }
        else
        {
          switch (s[index])
          {
          case '+':
          case '-':
          {
            if (_operatorHigher != 0)
            {
              resultHigher = calc(resultHigher, stoi(number), _operatorHigher);
              if (_operator != 0)
                result = calc(result, resultHigher, _operator);
              else
                result = resultHigher;
            }
            else
            {
              result = calc(result, stoi(number), _operator);
            }
            _operatorHigher = 0;
            _operator = s[index];
            break;
          }
          case '*':
          case '/':
          {
            if (_operatorHigher != 0)
            {
              resultHigher = calc(resultHigher, stoi(number), _operatorHigher);
            }
            else
            {
              resultHigher = stoi(number);
            }
            _operatorHigher = s[index];
            break;
          }
          }
          number = "";
        }
      }
      ++index;
    }
    if (_operatorHigher != 0)
    {
      resultHigher = calc(resultHigher, stoi(number), _operatorHigher);
      if(_operator != 0)
        return calc(result, resultHigher, _operator);
      else
        return resultHigher;
    }
    else if (_operator != 0)
    {
      return calc(result, stoi(number), _operator);
    }
    else
      return stoi(number);
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
    case '/':
      return a / b;
    }
    return 0;
  }
};

int main()
{
  cout << Solution().calculate(" 2*3+4")
       << endl;
  return 0;
}
#include <iostream>
using namespace std;

class Solution
{
public:
  int myAtoi(string str)
  {
    int index = 0;
    while (str[index] == ' ')
    {
      index++;
    }
    bool isMinus = false;
    if ((int)str[index] <= 57 && (int)str[index] >= 48)
    {
    }
    else if (str[index] == '-')
    {
      isMinus = true;
    }
    else if (str[index] == '+')
    {
    }
    else
    {
      return 0;
    }

    if (index == (str.size() - 1) && !((int)str[index] <= 57 && (int)str[index] >= 48))
    {
      return 0;
    }

    if (str[index] == '+' || str[index] == '-')
    {
      if (!((int)str[index + 1] <= 57 && (int)str[index + 1] >= 48))
      {
        return 0;
      }
    }

    try
    {
      return stoi(str);
    }
    catch (exception e)
    {
      return isMinus ? INT_MIN : INT_MAX;
    }
  }
};

int main()
{
  Solution *s = new Solution();

  cout << s->myAtoi("+1") << endl;
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isNumber(string s)
  {
    int start = 0;
    int end = s.size() - 1;
    while (start <= end && s[start] == ' ')
    {
      start++;
    }
    while (end >= 0 && s[end] == ' ')
    {
      end--;
    }
    if (start > end)
      return false;
    int countNumber = 0;
    int countExponent = 0;
    int countSign = 0;
    int countDecimalPoint = 0;
    int countOthers = 0;
    int indexE = INT_MAX;
    int indexDecimalPoint = -1;
    int indexSign = -1;
    for (int i = start; i <= end; i++)
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        countNumber++;
      }
      else if (s[i] == 'e')
      {
        countExponent++;
        indexE = i;
      }
      else if (s[i] == '+' || s[i] == '-')
      {
        indexSign = i;
        countSign++;
      }
      else if (s[i] == '.')
      {
        countDecimalPoint++;
        indexDecimalPoint = i;
      }
      else
      {
        countOthers++;
      }
    }
    if (countOthers > 0 || countExponent > 1 || countDecimalPoint > 1 || countSign > 2)
      return false;
    if (countSign == 2 && s[indexSign - 1] != 'e')
      return false;
    if (countSign == 2 && (s[start] != '+' && s[start] != '-'))
      return false;
    if (countExponent > 0 && (indexE == start || indexE == end))
      return false;
    if (countDecimalPoint > 0 && (indexDecimalPoint > indexE - 1))
      return false;
    if (indexSign == end)
      return false;
    if (countSign == 1 && countExponent == 0 && indexSign != start)
      return false;
    if (countSign == 1 && indexSign > start && s[indexSign - 1] != 'e')
      return false;
    if (countDecimalPoint > 0 && countNumber <= 0)
      return false;
    if (indexE == start + 1 && (s[start] < '0' || s[start] > '9'))
      return false;
    return true;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<vector<int>> x{
      {1, 3, 1},
      {1, 5, 1},
      {4, 2, 1}};

  // cout << "0 " << s->isNumber("0") << endl;
  // cout << "0.1 " << s->isNumber("0.1") << endl;
  // cout << "abc " << s->isNumber("abc") << endl;
  // cout << "1 a " << s->isNumber("1 a") << endl;
  // cout << "2e10 " << s->isNumber("2e10") << endl;
  // cout << " -90e3    " << s->isNumber(" -90e3   ") << endl;
  // cout << " 1e " << s->isNumber(" 1e") << endl;
  // cout << "e3 " << s->isNumber("e3") << endl;
  // cout << " 6e-1 " << s->isNumber(" 6e-1") << endl;
  // cout << " 99e2.5  " << s->isNumber(" 99e2.5 ") << endl;
  // cout << "53.5e93 " << s->isNumber("53.5e93") << endl;
  // cout << " --6  " << s->isNumber(" --6 ") << endl;
  // cout << "-+3 " << s->isNumber("-+3") << endl;
  // cout << "95a54e53 " << s->isNumber("95a54e53") << endl;
  cout << " -.7e+0435 " << s->isNumber(" -.7e+0435") << endl;

  return 0;
}

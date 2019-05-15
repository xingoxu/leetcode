// O(s.length * numRows)
// TODO: There maybe a method which is only O(s.length) I think

#include <iostream>
#include <string>
using namespace std;

static string *resultArray;
class Solution
{
public:
  string convert(string s, int numRows)
  {
    resultArray = new string[numRows];
    for (int i = 0; i < numRows; i++)
    {
      resultArray[i] = "";
    }
    int stringSize = s.size();
    int countX = 0;
    int countY = 0;
    for (int i = 0; i < stringSize; i++)
    {
      if (countX >= (numRows + (numRows - 2)))
      {
        countX = 0;
        countY = 0;
      }

      if (countX < numRows)
      {
        resultArray[countY] += s[i];
        countY++;
      }
      else
      {
        if (countY == numRows) {
          countY--;
        }
        countY--;
        for (int j = 0; j < numRows; j++)
        {
          if (j == countY)
          {
            resultArray[countY] += s[i];
          }
          else
          {
            resultArray[j] += ' ';
          }
        }
      }

      countX++;
    }

    string result;
    for (int i = 0; i < numRows; i++)
    {
      int stringLength = resultArray[i].size();
      for (int j = 0; j < stringLength; j++)
      {
        if (resultArray[i][j] == ' '){
          continue;
        } else {
          result += resultArray[i][j];
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution *s = new Solution();

  cout << s->convert("PAYPALISHIRING", 3) << endl;
  return 0;
}
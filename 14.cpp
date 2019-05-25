#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    int stringLength = strs.size();
    if (stringLength == 0)
      return "";
    string result = strs[0];
    for (int i = 1; i < stringLength; i++)
    {
      result = _longestTwoPrefix(result, strs[i]);
    }
    return result;
  }
  string _longestTwoPrefix(string x, string y)
  {
    int i = 0;
    string result = "";
    int lengthX = x.size();
    int lengthY = y.size();
    while (i < lengthX && i < lengthY)
    {
      if (x[i] != y[i])
      {
        return result;
      }
      result += x[i];
      i++;
    }
    return result;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<string> x{"flower", "flow", "flight"};

  cout << s->longestCommonPrefix(x) << endl;
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    int digit = (((int)num.size()) - (int)k);
    string result = num;
    int before = 0;
    for (int i = 1; i < num.size(); ++i)
    {
      while (before >= 0 && result[before] > num[i] && k > 0)
      {
        --before, --k;
      }
      result[++before] = num[i];
    }
    for (int i = 0; i < digit; ++i)
    {
      if(result[i] != '0') {
        return result.substr(i, digit - i);
      }
    }
    return "0";
  }
};

int main()
{
  cout << Solution().removeKdigits("1432219", 3) << endl;
  return 0;
}
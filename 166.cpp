#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  string fractionToDecimal(int numerator, int denominator)
  {
    unordered_map<long, int> remainDict;
    bool isMinus = (numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0) || (numerator == 0);
    isMinus = !isMinus;
    long num = labs(numerator);
    long deno = labs(denominator);

    string ret = to_string(num / deno);
    long remainder = num % deno;
    string decimalPart = ".";
    while (remainder != 0 && remainDict.find(remainder) == remainDict.end())
    {
      remainDict[remainder] = decimalPart.size();
      remainder *= 10;
      decimalPart += to_string(remainder / deno);
      remainder = remainder % deno;
    }
    string prefix = isMinus ? "-" : "";
    ret = prefix + ret;
    if (remainder == 0)
    {
      if (decimalPart.size() == 1)
        return ret;
      else
        return ret + decimalPart;
    }
    else
    {
      decimalPart.insert(remainDict[remainder], "(");
      return ret + decimalPart + ")";
    }
  }
};

int main()
{
  cout << Solution().fractionToDecimal(-1, INT_MIN) << endl;
  return 0;
}
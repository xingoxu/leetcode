// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Additive Number.
// Memory Usage: 8.6 MB, less than 50.00% of C++ online submissions for Additive Number.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
  string input;
  int inputLength = 0;

public:
  bool isAdditiveNumber(string num)
  {
    input = num;
    inputLength = num.size();
    if (inputLength <= 2)
      return false;

    int ret = false;
    for (int i = 1;i <= inputLength; ++i)
    {
      if (input[0] == '0' && i > 1)
        break;
      long a;
      try
      {
        a = stol(input.substr(0, i));
      }
      catch (exception e)
      {
        break;
      }
      for (int j = 1;i + j <= inputLength; ++j)
      {
        if (input[i] == '0' && j > 1)
          break;
        if (i + j >= input.size())
          continue;
        long b;
        try
        {
          b = stol(input.substr(i, j));
        }
        catch (exception e)
        {
          break;
        }
        ret = ret || isAdditive(i + j, a, b);
        if (ret)
          return ret;
      }
    }
    return ret;
  }
  bool isAdditive(int startPos, long previousA, long previousB)
  {
    if (startPos >= input.size())
      return true;

    bool result = false;
    auto add = to_string(previousA + previousB);
    if (input[startPos] == '0' && add.size() > 1)
      return false;
    long next;
    try
    {
      next = stol(add);
    }
    catch (exception e)
    {
      return false;
    }
    for (int x = 0; x < add.size(); ++x)
    {
      if (add[x] != input[startPos])
        return false;
      ++startPos;
    }
    return isAdditive(startPos, previousB, next);
  }
};

int main()
{
  cout << Solution().isAdditiveNumber("121474836472147483648") << endl;
  return 0;
}
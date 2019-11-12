#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  string toHex(int num)
  {
    if (num == 0)
      return "0";
    vector<string> chars(16);
    bool isMinus = num < 0;
    long numOp = num;
    if (isMinus)
      numOp = numOp * (-1);
    for (int i = 0; i <= 9; ++i)
      chars[i] = to_string(i);
    for (int i = 0; i <= 5; ++i)
      chars[10 + i] = char('a' + i);

    queue<int> numbers;
    while (numOp != 0)
    {
      if (isMinus)
        numbers.push(15 - numOp % 16);
      else
        numbers.push(numOp % 16);
      numOp /= 16;
    }
    while (isMinus && numbers.size() < 8)
      numbers.push(15);

    string ret;
    bool needAdd = isMinus;
    while (numbers.size() != 0)
    {
      if (needAdd)
      {
        if (numbers.front() + 1 >= 16)
          ret = "0" + ret;
        else
        {
          needAdd = false;
          ret = chars[numbers.front() + 1] + ret;
        }
      }
      else
        ret = chars[numbers.front()] + ret;
      numbers.pop();
    }
    return ret;
  }
};

int main()
{
  cout << Solution().toHex(-2147483648) << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
  bool isValidSerialization(string preorder)
  {
    auto result = parseLeft(0, preorder);
    return result == (preorder.size() - 1 + 2);
  }
  int parseLeft(int pos, string &order)
  {
    if(pos >= order.size())
      return -1;
    stringstream ss;
    while (pos < order.size() && order[pos] != ',')
    {
      ss << order[pos++];
    }
    if (ss.str() == "#")
      return pos + 1;
    auto leftResult = parseLeft(pos + 1, order);
    if (leftResult == -1 || leftResult >= order.size())
      return -1;
    return parseLeft(leftResult, order);
  }
};

int main()
{
  cout << Solution().isValidSerialization("9,#,#,1") << endl;
  return 0;
}
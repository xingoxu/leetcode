// Runtime: 20 ms, faster than 5.90% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.
// Memory Usage: 9.2 MB, less than 25.00% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.
// It's o(n) so I think there won't be so much places can be optimized.

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
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
  int countSegments(string s)
  {
    int count = 0;
    bool isSpace = true;
    for (auto &x : s)
      if (x == ' ')
        isSpace = true;
      else if (x != ' ' && isSpace)
      {
        ++count;
        isSpace = false;
      }
    return count;
  }
};

int main()
{
  cout << Solution().countSegments("Hello, my name is John") << endl;
  return 0;
}
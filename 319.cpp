// Runtime: 4 ms, faster than 49.80% of C++ online submissions for Bulb Switcher.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Bulb Switcher.

#include <iostream>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
      int i = 1;
      while (i * i <= n)
      {
        ++i;
      }
      return i - 1;
    }
};

int main()
{
  cout << Solution().bulbSwitch(878787) << endl;
  return 0;
}
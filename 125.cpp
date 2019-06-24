// Runtime: 8 ms, faster than 80.46% of C++ online submissions for Triangle.
// Memory Usage: 9.6 MB, less than 98.29% of C++ online submissions for Triangle.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  bool shouldSkipThisChar(char x) {
    return !((
        (x >= 'A' && x <= 'Z') ||
        (x >= 'a' && x <= 'z') ||
        (x >= '0' && x <= '9')));
  }

public:
  bool isPalindrome(string s)
  {
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
      if (shouldSkipThisChar(s[left]))
      {
        ++left;
        continue;
      }
      if (shouldSkipThisChar(s[right]))
      {
        --right;
        continue;
      }

      int leftCode = s[left] >= 'a' ? s[left] - 'a' : s[left] - 'A';
      int rightCode = s[right] >= 'a' ? s[right] - 'a' : s[right] - 'A';
      if (leftCode != rightCode)
      {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
};

int main()
{

  cout << Solution().isPalindrome("race a car") << endl;

  return 0;
}

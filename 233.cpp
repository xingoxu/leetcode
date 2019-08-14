// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
// Memory Usage: 8.1 MB, less than 92.00% of C++ online submissions for Power of Two.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
      if (n == INT_MIN || n == 0)
      {
        return false;
      }
      return (n & (-n)) == n;
    }
};

int main()
{
  cout << Solution().isPowerOfTwo(INT_MIN) << endl;
  return 0;
}
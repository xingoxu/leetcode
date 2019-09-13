#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
      return n == 0 ? false : pow(3, (int)(log10(n) / log10(3))) == n;
    }
};

int main() {
  cout << Solution().isPowerOfThree(10) << endl;
  return 0;
}
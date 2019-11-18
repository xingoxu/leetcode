#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
      int x = -(double)1 / 2 + sqrt((double)1 / 4 + (double)2 * n);
      return x;
    }
};

int main()
{
  cout << Solution().arrangeCoins(1804289383) << endl;
  return 0;
}
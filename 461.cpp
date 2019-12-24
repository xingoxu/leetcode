#include <iostream>
#include <math.h>
using namespace std;

class Solution
{

public:
  int hammingDistance(int x, int y)
  {
    int ret = y < 0 ? 1 : 0;
    auto exclusiveOr = x ^ y;

    while (exclusiveOr != 0 && exclusiveOr != -1)
    {
      if((exclusiveOr & 1))
        ++ret;
      exclusiveOr = exclusiveOr >> 1;
    }
    return ret;
  }
};

int main()
{
  cout << Solution().hammingDistance(3, 7) << endl;
  return 0;
}

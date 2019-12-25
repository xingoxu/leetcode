#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int findComplement(int num)
  {
    int ret = 0, count = 0;
    while (num != 0)
    {
      if ((num & 1) == 0)
        ret += (1 << count);

      num = num >> 1;
      ++count;
    }
    return ret;
  }
};

int main()
{
  cout << Solution().findComplement(1) << endl;
  return 0;
}
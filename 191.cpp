
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int count = 0;
    for (int i = 0; i < 32;i++) {
      if ((n & 1) == 1) {
        ++count;
      }
      n = n >> 1;
    }
    return count;
  }
};

int main()
{
  cout << Solution().hammingWeight(00000000000000000000000000001011)
       << endl;
  return 0;
}

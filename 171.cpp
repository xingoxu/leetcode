#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  int titleToNumber(string s)
  {
    int sum = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
      int index = s.size() - i - 1;
      int num = s[i] - 'A' + 1;
      sum += pow(26, index) * num;
    }
    return sum;
  }
};

int main()
{
  cout << Solution().titleToNumber("AB") << endl;

  return 0;
}

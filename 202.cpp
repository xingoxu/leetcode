
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution
{
  unordered_map<int, bool> map;

public:
  bool isHappy(int n)
  {
    if (n == 1)
      return true;
    int start = n;
    do
    {
      int sum = 0;
      while (start != 0)
      {
        sum += pow(start % 10, 2);
        start /= 10;
      }
      cout << sum << endl;
      start = sum;

      if (map[start])
      {
        return false;
      }
      map[start] = true;
    } while (start != 1);
    return true;
  }
};

int main()
{
  cout << Solution().isHappy(3)
       << endl;
  return 0;
}

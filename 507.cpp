#include <iostream>
#include <unordered_set>
#include <math.h>
using namespace std;

class Solution
{
public:
  bool checkPerfectNumber(int num)
  {
    int sum = 1;
    for (int i = 2; i <= sqrt(num); ++i)
      if (num % i == 0)
        sum += i + (i == num / i ? 0 : num / i);
    return sum == num && num != 1;
  }
};

int main()
{
  cout << Solution().checkPerfectNumber(28) << endl;
  return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
  int rand10()
  {
    int result = 40;
    while(result >= 40)
      result = 7 * (rand7() - 1) + (rand7() - 1);
    return result % 10 + 1;
  }
};

int main()
{
  return 0;
}
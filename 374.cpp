
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int guess(int num);

class Solution
{
public:
  int guessNumber(int n)
  {
    int lower = 1, higher = n;
    while (true)
    {
      int middle = (higher - lower) / 2 + lower;
      int guessRet = guess(middle);
      if(guessRet == -1) {
        higher = middle - 1;
      } else if (guessRet == 1) {
        lower = middle + 1;
      } else
        return middle;
    }
  }
};

int main()
{
  // cout << Solution().guessNumber(2) << endl;
  return 0;
}

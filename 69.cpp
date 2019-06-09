#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x == 0 || x == 1)
      return x;
    if (x > 46340*46340)
      return 46340;
    return _findSqrt(1, x / 2 + 1, x);
  }
  int _findSqrt(int start, int end, int target)
  {
    if (start == end || start == end - 1)
      return start;

    int middle = start + end;
    middle /= 2;
    if (middle > 46340)
      middle = 46340;
    int compare = middle * middle;
    if (compare > target)
      return _findSqrt(start, middle, target);
    if (compare < target)
      return _findSqrt(middle, end, target);
    return middle;
  }
};

int main()
{
  Solution s;

  cout << s.mySqrt(65536) << endl;

  return 0;
}

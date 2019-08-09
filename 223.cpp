// Runtime: 8 ms, faster than 89.24% of C++ online submissions for Rectangle Area.
// Memory Usage: 8.3 MB, less than 52.17% of C++ online submissions for Rectangle Area.

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class Solution
{
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
  {
    int overlapX = getOverlapLine(A, C, E, G);
    int overlapY = getOverlapLine(B, D, F, H);
    return (long)(C - A) * (D - B) + (long)(G - E) * (H - F) - (long)overlapX * overlapY;
  }
  int getOverlapLine(int a, int b, int c, int d)
  {
    if (b <= c)
    {
      return 0;
    }
    if (a >= d)
    {
      return 0;
    }
    if(a < c) {
      if(d < b) {
        return d - c;
      } else {
        return b - c;
      }
    } else {
      if(d < b) {
        return d - a;
      } else {
        return b - a;
      }
    }
  }
};

int main()
{
  cout << Solution().computeArea(
              -3,
              0,
              3,
              4,
              0,
              -1,
              9,
              2)
       << endl;
  return 0;
}
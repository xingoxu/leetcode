// https://leetcode.com/problems/poor-pigs/discuss/94273/Solution-with-detailed-explanation

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest)
  {
    int rounds = minutesToTest / minutesToDie;
    return ceil(log10f(buckets) / log10f(rounds + 1));
  }
};

int main()
{
  cout << Solution().poorPigs(4, 15, 15) << endl;
  return 0;
}
// https://leetcode-cn.com/problems/smallest-good-base/solution/shu-xue-fang-fa-fen-xi-dai-ma-by-zerotrac/
// TODO

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  string smallestGoodBase(string n)
  {
    using ull = unsigned long long;
    // num - 1 is the largest possible base
    ull num = stoll(n);
    // this loop will iterate length from max possible value to min value
    // when base == 2, we have longest length of '1'
    // 2^0 + 2^1 + ... + 2^(len - 1) == num -> 2^len == num + 1 -> len = log(num + 1) base on 2
    // log(num + 1) / log(2) == log (num + 1) base on 2
    cout << log(num + 1) / log(2) << endl;
    for (int len = log(num + 1) / log(2); len >= 2; len--)
    {
      // use binary search to find possible base
      // b^0 + b^1 + .... + b^(len - 1) == num ->
      // b^(len - 1) <= num + 1 ->
      // b <= pow(num + 1, 1.0 / (len - 1))
      ull l = 2, r = pow(num + 1, 1.0 / (len - 1)) + 1;
      while (l < r)
      {
        ull sum = 0, base = l + (r - l) / 2, val = 1;
        for (int i = 0; i < len; i++, val *= base)
          sum += val;
        if (sum == num)
          return to_string(base);
        else if (sum < num)
          l = base + 1;
        else
          r = base;
      }
    }
    return to_string(num - 1);
  }
};

int main()
{
  cout << Solution().smallestGoodBase("4681") << endl;
  return 0;
}
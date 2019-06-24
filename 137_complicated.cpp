// https://blog.csdn.net/yutianzuijin/article/details/50597413

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // origin -> output
        // 00 0 00
        // 01 0 01
        // 10 0 10
        // 00 1 01
        // 01 1 10
        // 10 1 00
        // low_bit = old_low & ~old_high & ~input + ~old_low & ~old_high & input
        // high_bit = old_low & ~old_high & input + old_high & ~old_low & ~input
        //    ↓
        // 00 0 0
        // 01 0 0
        // 10 0 1
        // 01 1 0
        // 00 1 1
        // 10 1 0
        // high bit now rely on the new low bit
        // high_bit = ~low & ~input & old_high + input & ~low & ~old_high
        int high = 0, low = 0;
        for (int i = 0; i < nums.size(); i++)
        {
          int &input = nums[i];
          low = (low & ~high & ~input) + (~low & ~high & input);
          high = (~low & ~input & high) + (input & ~low & ~high);
        }

        // 00->01->10->00
        // when all number exists three times, high == low == 0
        // when there is one number exists one time, high == 0 and low == 1
        // so we can return low;
        return low;
    }
};

int main()
{
  vector<int> x{-2, -2, 1, 1, -3, 1, -3, -3, -4, -2};

  cout << Solution().singleNumber(x) << endl;

  return 0;
}

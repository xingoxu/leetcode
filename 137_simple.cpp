// https://blog.csdn.net/yutianzuijin/article/details/50597413

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      vector<int> bits(32, 0);
      for(auto num : nums) {
        for (int i = 0; i < 32;i++) {
          bits[i] += num >> i & 0x1;
        }
      }

      int result = 0;
      for (int i = 0; i < 32; i++)
      {
        result = result | (bits[i]%3 << i);
      }

      return result;
    }
};

int main()
{
  vector<int> x{-2, -2, 1, 1, -3, 1, -3, -3, -4, -2};

  cout << Solution().singleNumber(x) << endl;

  return 0;
}

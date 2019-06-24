#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      int xorResult = 0;
      for (auto num : nums)
        xorResult ^= num;
      int lastBit = xorResult & (-xorResult);
      vector<int> result = {0, 0};
      for (auto num : nums)
      {
        if((num & lastBit) == 0) {
          result[0] ^= num;
        }else {
          result[1] ^= num;
        }
      }
      return result;
    }
};

int main()
{
  vector<int> x{1,2,1,3,2,5};

  cout << Solution().singleNumber(x)[0] << endl;
  cout << Solution().singleNumber(x)[1] << endl;

  return 0;
}

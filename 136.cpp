
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int result = 0;
      for (auto num : nums)
        result ^= num;
      return result;
    }
};

int main()
{
  vector<int> x{1,2,1,2,5};

  cout << Solution().singleNumber(x) << endl;

  return 0;
}

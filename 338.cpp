// Runtime: 56 ms, faster than 50.03% of C++ online submissions for Counting Bits.
// Memory Usage: 9.4 MB, less than 97.56% of C++ online submissions for Counting Bits.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> result(num + 1, 0);
      int exp = 1;
      for (int i = 1; i < num + 1; ++i)
      {
        if(i == exp) {
          result[i] = 1;
          exp *= 2;
          continue;
        }
        result[i] = result[i - (exp / 2)] + result[exp / 2];
      }
      return result;
    }
};


int main()
{
  auto result = Solution().countBits(5);
  for(auto route: result)
    cout << route << ' ';
  cout << endl;
  return 0;
}
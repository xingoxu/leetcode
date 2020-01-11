// Runtime: 124 ms, faster than 39.73% of C++ online submissions for Can I Win.
// Memory Usage: 25 MB, less than 80.00% of C++ online submissions for Can I Win.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, bool> cache;
  bool canIWin(int isUsed, int maxChoosableInteger, int desiredTotal)
  {
    if (cache.count(isUsed) > 0)
      return cache[isUsed];
    for (int i = 1; i <= maxChoosableInteger; ++i)
    {
      if(((isUsed >> i) & 1) == 1)
        continue;
      // can't use hashmap here since we should memorize isUsed status here.
      // isUsed[i] = true;
      if (desiredTotal - i <= 0 || !canIWin(isUsed | (1 << i), maxChoosableInteger, desiredTotal - i))
      {
        // isUsed[i] = false;
        return cache[isUsed] = true;
      }
      // isUsed[i] = false;
    }
    return cache[isUsed] = false;
  }

public:
  bool canIWin(int maxChoosableInteger, int desiredTotal)
  {
    int sum = 0;
    for (int i = 1; i <= maxChoosableInteger; ++i)
      sum += i;
    if (sum < desiredTotal)
      return false;
    int isUsed = 0;
    return canIWin(isUsed, maxChoosableInteger, desiredTotal);
  }
};

int main()
{
  cout << Solution().canIWin(5, 50) << endl;
  return 0;
}
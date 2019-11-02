// Runtime: 80 ms, faster than 32.68% of C++ online submissions for Lexicographical Numbers.
// Memory Usage: 12.9 MB, less than 9.09% of C++ online submissions for Lexicographical Numbers.

#include <iostream>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

class Solution {
  list<int> removeZero(int n)
  {
    list<int> ret;
    while(n % 10 == 0)
      ret.push_front(n /= 10);
    return ret;
  }

public:
    vector<int> lexicalOrder(int n) {
      vector<int> ret;
      for (int i = 1; i <= 9; ++i)
      {
        if (i > n)
          break;
        int initNum = i * pow(10, (int)log10(n));
        if (initNum > n)
          initNum /= 10;
        int maxNum = initNum / i * (i + 1) - 1;
        int afterMaxNum = 0;
        if (maxNum > n)
        {
          afterMaxNum = maxNum / 10;
          maxNum = n;
        }

        for (int j = initNum; j <= maxNum; ++j)
        {
          auto result = removeZero(j);
          ret.insert(ret.end(), result.begin(), result.end());
          ret.push_back(j);
        }
        for (int j = maxNum / 10 + 1; j <= afterMaxNum; ++j)
        {
          auto result = removeZero(j);
          ret.insert(ret.end(), result.begin(), result.end());
          ret.push_back(j);
        }
      }

      return ret;
    }
};

int main()
{

  auto result = Solution().lexicalOrder(201);
  for(auto &x : result)
    cout << x << ' ';
  cout << endl;
  return 0;
}

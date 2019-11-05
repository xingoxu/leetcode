#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
      vector<int> remain(n);
      for (int i = 1; i <= n;++i)
        remain[i - 1] = i;
      bool isFromLeft = true;
      while (remain.size() != 1)
      {
        vector<int> next(n / 2);
        int wIndex = isFromLeft ? 0 : (n / 2 - 1);
        int count = -1;
        for (int i = remain.size() - 1; i >= 0; --i)
        {
          ++count;
          if (count % 2 == 0)
            continue;
          int rIndex = isFromLeft ? (remain.size() - i - 1) : i;
          next[wIndex] = remain[rIndex];
          if (isFromLeft)
            ++wIndex;
          else
            --wIndex;
        }
        n = n / 2;
        remain = next;
        isFromLeft = !isFromLeft;
      }
      return remain[0];
    }
};

int main () {
  cout << Solution().lastRemaining(1000000000) << endl;
  return 0;
}
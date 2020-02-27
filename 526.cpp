// Runtime: 44 ms, faster than 80.62% of C++ online submissions for Beautiful Arrangement.
// Memory Usage: 19.1 MB, less than 50.00% of C++ online submissions for Beautiful Arrangement.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  int _used = 0;
  unordered_map<int, unordered_map<int, int>> cache;
  int NUM;
  int _countArrangement(int pos)
  {
    int result = 0;
    if (cache.count(_used) > 0 && cache[_used].count(pos) > 0)
      return cache[_used][pos];

    for (int i = 1; i <= NUM; ++i)
    {
      if ((_used & (1 << i)) != 0)
        continue;
      if (i % pos == 0 || pos % i == 0)
      {
        _used = (_used | (1 << i));
        if (pos != NUM)
          result += _countArrangement(pos + 1);
        else
          result += 1;
        _used = (_used & ~(1 << i));
      }
    }
    return cache[_used][pos] = result;
  }

public:
  int countArrangement(int N)
  {
    NUM = N;
    _used = 0;
    return _countArrangement(1);
  }
};

int main()
{
  cout << Solution().countArrangement(14) << endl;
  return 0;
}
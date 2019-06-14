#include <iostream>
#include <vector>
using namespace std;

vector<int> cache;
class Solution
{

public:
  int numTrees(int n) {
    int originSize = cache.size();
    cache.resize(n + 1);
    for (int i = originSize; i <= n; i++)
    {
      cache[i] = 0;
    }
    return _numTrees(n);
  }
  int _numTrees(int n)
  {
    if (n == 0 || n == 1)
    {
      return 1;
    }
    if (n == 2)
    {
      return 2;
    }
    if(cache[n] >0)
      return cache[n];

    int result = 0;
    // I can use half here to improve the effiency
    // Still killed 100%
    for (int i = 0; i <= n - 1; i++)
    {
      result += _numTrees(i) * _numTrees(n - 1 - i);
    }
    cache[n] = result;
    return result;
  }
};

int main()
{
  vector<vector<char>> x = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  cout << Solution().numTrees(10) << endl;

  return 0;
}